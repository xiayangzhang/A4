// Fill out your copyright notice in the Description page of Project Settings.

#include "KismetProceduralMeshLibrary.h"
#include "NavigationSystem.h"
#include "MazeBuilder.h"

// Sets default values
AMazeBuilder::AMazeBuilder()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

   FloorMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("wall"));
     WallMeshs = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("floor"));

    FloorMesh->AttachTo(this->RootComponent);
    WallMeshs->AttachTo(this->RootComponent);

    WallVertices = TArray<FVector>();
    
    MapWidth =5000.0f;
    mapLength =5000.0f;
    
    WallHeight= 200.0f;
    WallWidth =40.0f;
    totalVertices = 0;
    doorwidth = 200.0f;
}

// Called when the game starts or when spawned
void AMazeBuilder::BeginPlay()
{
    Super::BeginPlay();
    ClearMeshData();
   Generatefloor();
   GenerateMaze();
   const FVector loaction = FVector(mapLength - 100.0f, MapWidth - 100.0f, 0.0f);
   const FRotator rotaction = GetActorRotation();
   GetWorld()->SpawnActor<AActor>(endgame, loaction, rotaction);

 WallMeshs->CreateMeshSection(0, WallVertices, WallTriangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
    
    FNavigationSystem::UpdateComponentData(*FloorMesh);
    //FNavigationSystem::UpdateComponentData(*WallMeshs);

}

// Called every frame
void AMazeBuilder::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AMazeBuilder::GenerateMaze(){
    UE_LOG(LogTemp, Warning, TEXT("GenerateMaze"));
    //Generate edge
    GenerateWalls(MapWidth,0,0,WallWidth);
    GenerateWalls(MapWidth,0,mapLength-WallWidth,mapLength);
    GenerateWalls(MapWidth,MapWidth-WallWidth,0,mapLength);
    GenerateWalls(WallWidth,0,0,mapLength);
 
    MazeSplit(FVector2D(0, 0),FVector2D(MapWidth, mapLength));
    

}

void AMazeBuilder::Generatefloor(){
   UE_LOG(LogTemp, Warning, TEXT("Generatefloor"));
    FloorMesh->ClearAllMeshSections();

    TArray<FVector> Vertices;
        Vertices.Add(FVector(0.0f, 0.0f, 0.0f));
        Vertices.Add(FVector(0.0f, mapLength, 0.0f));
        Vertices.Add(FVector(MapWidth, mapLength, 0.0f));
        Vertices.Add(FVector(MapWidth, 0.0f, 0.0f));

        TArray<int32> Triangles;
        Triangles.Add(0);
        Triangles.Add(1);
        Triangles.Add(3);
        Triangles.Add(3);
        Triangles.Add(1);
        Triangles.Add(2);
    
        FloorMesh->CreateMeshSection(0, Vertices, Triangles,  TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}


void AMazeBuilder::GenerateWalls(float far,float close,float left,float right){
    if(far<close||right<left){
        return;
    }
   UE_LOG(LogTemp, Warning, TEXT("GenerateWalls"));

    WallVertices.Add(FVector(close, left, 0));
    WallVertices.Add(FVector(close, left, WallHeight));
    WallVertices.Add(FVector(close, right, 0));
    WallVertices.Add(FVector(close, right, WallHeight));
    WallVertices.Add(FVector(far, left, 0));
    WallVertices.Add(FVector(far, left, WallHeight));
    WallVertices.Add(FVector(far, right, WallHeight));
    WallVertices.Add(FVector(far, right, 0));

    //Back face of cube
    AddTriangle(0, 2, 3);
    AddTriangle(3, 1, 0);

    //Left face of cube
    AddTriangle(0, 1, 4);
    AddTriangle(4, 1, 5);

    //Front face of cube
    AddTriangle(4, 5, 7);
    AddTriangle(7, 5, 6);

    //Right face of cube
    AddTriangle(7, 6, 3);
    AddTriangle(3, 2, 7);

    //Top face
    AddTriangle(1, 3, 5);
    AddTriangle(6, 5, 3);

    //bottom face
    AddTriangle(2, 0, 4);
    AddTriangle(4, 7, 2);
    totalVertices+=8;

       
}
void AMazeBuilder::ClearMeshData(){
   UE_LOG(LogTemp, Warning, TEXT("ClearMeshData"));
    WallVertices.Empty();
    WallTriangles.Empty();
}

void AMazeBuilder::AddTriangle(int32 V1, int32 V2, int32 V3)
{
   
    WallTriangles.Add(totalVertices+V1);
    WallTriangles.Add(totalVertices+V2);
    WallTriangles.Add(totalVertices+V3);
}



void AMazeBuilder::MazeSplit(FVector2D Botleft,FVector2D TopRight){
    
    if(TopRight.X-Botleft.X<10*doorwidth||TopRight.Y-Botleft.Y<10*doorwidth){
       
        ARoom* newRoom;
        FVector RoomPos =FVector(
                                 (TopRight.X-Botleft.X)/2+Botleft.X
        ,(TopRight.Y-Botleft.Y)/2+Botleft.Y,0);
        newRoom = GetWorld()->SpawnActor<ARoom>(BPRoom,RoomPos,FRotator(0.f, 0.f, 0.f));
        newRoom->Pos = RoomPos;
        newRoom->RoomLength =TopRight.Y-Botleft.Y;
        newRoom->RoomWidth =TopRight.X-Botleft.X;
        newRoom->init();
        
       // AEnemyCharacter* NewEnemy = GetWorld()->SpawnActor<AEnemyCharacter>(Enemy, newRoom->GenRandomPos(), FRotator(0.f, 0.f, 0.f));
        //NewEnemy->RoomBleong = newRoom;
        
        return;
    }
//    if(TopRight.Y-Botleft.Y<10*doorwidth){
//            ARoom* newRoom;
//            FVector RoomPos =FVector((TopRight.X-Botleft.X)/2+Botleft.X,(TopRight.Y-Botleft.Y)/2-Botleft.Y,0);
//            newRoom = GetWorld()->SpawnActor<ARoom>(BPRoom,RoomPos,FRotator(0.f, 0.f, 0.f));
//            newRoom->Pos = RoomPos;
//            newRoom->RoomWidth =TopRight.X-Botleft.X;
//            newRoom->RoomLength =TopRight.Y-Botleft.Y;
//        newRoom->init();
//
//                  return;
//    }
 
    float RandY = RandomFloat(TopRight.Y-5*doorwidth,Botleft.Y+doorwidth*5);
    float RandX=RandomFloat(TopRight.X-5*doorwidth,Botleft.X+doorwidth*5);
    
    int RandDoor = rand()% 4 + 1;
    
    
    float TOPDoorPos = RandomFloat(TopRight.X-doorwidth,RandX+doorwidth);
    float BOTDoorPos = RandomFloat(RandX-doorwidth,Botleft.X+doorwidth);
    float LEFTDoorPos = RandomFloat(RandY-doorwidth,Botleft.Y+doorwidth);
    float RightDoorPos = RandomFloat(TopRight.Y-doorwidth,RandY+doorwidth);

    
     //top
    if(RandDoor == 1){
        GenerateWalls(TopRight.X,RandX,RandY-WallWidth/2,RandY+WallWidth/2);

    }else{
         GenerateWalls(TopRight.X,TOPDoorPos+doorwidth/2,RandY-WallWidth/2,RandY+WallWidth/2);
         GenerateWalls(TOPDoorPos-doorwidth/2,RandX,RandY-WallWidth/2,RandY+WallWidth/2);
    }
    //bot
    if(RandDoor == 2){
    GenerateWalls(RandX,Botleft.X,RandY-WallWidth/2,RandY+WallWidth/2);
    }else{
        GenerateWalls(RandX,BOTDoorPos+doorwidth/2,RandY-WallWidth/2,RandY+WallWidth/2);
        GenerateWalls(BOTDoorPos-doorwidth/2,Botleft.X,RandY-WallWidth/2,RandY+WallWidth/2);
    }
    //left
    if(RandDoor == 3){
    GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,Botleft.Y,RandY);
    }else{
        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,Botleft.Y,LEFTDoorPos-doorwidth/2);
        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,LEFTDoorPos+doorwidth/2,RandY);
    }
    //right
    if(RandDoor == 4){
    GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,RandY,TopRight.Y);
    }else{
        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,RandY,RightDoorPos-doorwidth/2);
        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,RightDoorPos+doorwidth/2,TopRight.Y);
    }
    
    
    
    MazeSplit(FVector2D(Botleft.X, RandY),FVector2D(RandX, TopRight.Y));
  
    MazeSplit(FVector2D(RandX, RandY),FVector2D(TopRight.X, TopRight.Y));

    MazeSplit(FVector2D(Botleft.X, Botleft.Y),FVector2D(RandX, RandY));
    
    MazeSplit(FVector2D(RandX, Botleft.Y),FVector2D(TopRight.X, RandY));

     return;
}



float AMazeBuilder::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}