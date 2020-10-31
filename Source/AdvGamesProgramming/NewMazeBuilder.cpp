// Fill out your copyright notice in the Description page of Project Settings.

#include "KismetProceduralMeshLibrary.h"
#include "NavigationSystem.h"
//#include "MazeWall.h"
#include "NewMazeBuilder.h"

// Sets default values
ANewMazeBuilder::ANewMazeBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    FloorMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("floor"));
    FloorMesh->AttachTo(this->RootComponent);

    MapWidth =5000.0f;
    mapLength =5000.0f;
       
    WallHeight= 200.0f;
    WallWidth =40.0f;
    doorwidth = 200.0f;
}

// Called when the game starts or when spawned
void ANewMazeBuilder::BeginPlay()
{
    Super::BeginPlay();
    Generatefloor();
    GenerateMaze();
    FNavigationSystem::UpdateComponentData(*FloorMesh);

}

// Called every frame
void ANewMazeBuilder::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
void ANewMazeBuilder::Generatefloor()
{
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
       
       TArray<FVector2D> UVCoords;
       UVCoords.Add(FVector2D(0.0f, 0.0f));
       UVCoords.Add(FVector2D(0.0f, 1.0f));
       UVCoords.Add(FVector2D(1.0f, 1.0f));
       UVCoords.Add(FVector2D(1.0f, 0.0f));
       FloorMesh->CreateMeshSection(0, Vertices, Triangles,  TArray<FVector>(), UVCoords, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
       
}
void ANewMazeBuilder::GenerateMaze()
{

    GenerateWall( FVector(WallWidth/2,mapLength/2,WallHeight/2),mapLength,false);
    
    GenerateWall(FVector(mapLength-WallWidth/2,mapLength/2,WallHeight/2),mapLength,false);
    
    GenerateWall(FVector(MapWidth/2,WallWidth/2,WallHeight/2),mapLength,true);
    
    GenerateWall(FVector(MapWidth/2,mapLength-WallWidth/2,WallHeight/2),mapLength,true);
    
    MazeSplit(FVector2D(0, 0),FVector2D(MapWidth, mapLength),FVector2D(0, 0));
}

void ANewMazeBuilder::MazeSplit(FVector2D Botleft,FVector2D TopRight,FVector2D Door)
{
   
    if(TopRight.X-Botleft.X<6*doorwidth||TopRight.Y-Botleft.Y<6*doorwidth){
       
        ARoom* newRoom;
        FVector RoomPos =FVector(
                                 (TopRight.X-Botleft.X)/2+Botleft.X
        ,(TopRight.Y-Botleft.Y)/2+Botleft.Y,0);
        newRoom = GetWorld()->SpawnActor<ARoom>(BPRoom,RoomPos,FRotator(0.f, 0.f, 0.f));
        newRoom->Pos = RoomPos;
        newRoom->RoomLength =TopRight.Y-Botleft.Y;
        newRoom->RoomWidth =TopRight.X-Botleft.X;
        newRoom->init();
    
        return;
    }
    float RandY = RandomFloat(TopRight.Y-2*doorwidth,Botleft.Y+doorwidth*2);
    
    while(RandY>(Door.Y-2*doorwidth)&&RandY<(Door.Y+2*doorwidth)){
        RandY = RandomFloat(TopRight.Y-2*doorwidth,Botleft.Y+doorwidth*2);
    }
    
    float RandX = RandomFloat(TopRight.X-2*doorwidth,Botleft.X+doorwidth*2);
    while(RandX>(Door.X-2*doorwidth)&&RandX<(Door.X+2*doorwidth)){
          RandX = RandomFloat(TopRight.X-2*doorwidth,Botleft.X+doorwidth*2);
      }
    int RandDoor =1 + rand()%4;
    //int RandDoor = 3;

    float TOPDoorPos = RandomFloat(TopRight.X-doorwidth,RandX+doorwidth);
    float BOTDoorPos = RandomFloat(RandX-doorwidth,Botleft.X+doorwidth);
    float LEFTDoorPos = RandomFloat(RandY-doorwidth,Botleft.Y+doorwidth);
    float RightDoorPos = RandomFloat(TopRight.Y-doorwidth,RandY+doorwidth);

    
    if(RandDoor == 1){
  GenerateWall(FVector((TopRight.X-RandX)/2+RandX,RandY,WallHeight/2),(TopRight.X-RandX),true);
    }else{
GenerateWall(FVector((TopRight.X-(TOPDoorPos+doorwidth/2))/2+(TOPDoorPos+doorwidth/2),RandY,WallHeight/2),(TopRight.X-(TOPDoorPos+doorwidth/2)),true);
GenerateWall(FVector(((TOPDoorPos-doorwidth/2)-RandX)/2+RandX,RandY,WallHeight/2),((TOPDoorPos-doorwidth/2)-RandX),true);

    
    }
    //bot
    if(RandDoor == 2){
    GenerateWall(FVector((RandX-Botleft.X)/2+Botleft.X,RandY,WallHeight/2),(RandX-Botleft.X),true);

    }else{
GenerateWall(FVector((RandX-(BOTDoorPos+doorwidth/2))/2+(BOTDoorPos+doorwidth/2),RandY,WallHeight/2),(RandX-(BOTDoorPos+doorwidth/2)),true);
GenerateWall(FVector(((BOTDoorPos-doorwidth/2)-Botleft.X)/2+Botleft.X,RandY,WallHeight/2),((BOTDoorPos-doorwidth/2)-Botleft.X),true);
    }
    //left
    if(RandDoor == 3){
        GenerateWall(FVector(RandX,(RandY-Botleft.Y)/2+Botleft.Y,WallHeight/2),(RandY-Botleft.Y),false);
    }else{
GenerateWall(FVector(RandX,((LEFTDoorPos-doorwidth/2)-Botleft.Y)/2+Botleft.Y,WallHeight/2),((LEFTDoorPos-doorwidth/2)-Botleft.Y),false);
GenerateWall(FVector(RandX,RandY-(RandY-(LEFTDoorPos+doorwidth/2))/2,WallHeight/2),(RandY-(LEFTDoorPos+doorwidth/2)),false);

    }
    //right
    if(RandDoor == 4){
        GenerateWall(FVector(RandX,(TopRight.Y-RandY)/2+RandY,WallHeight/2),(TopRight.Y-RandY),false);
    }else{
       GenerateWall(FVector(RandX,((RightDoorPos-doorwidth/2)-RandY)/2+RandY,WallHeight/2),((RightDoorPos-doorwidth/2)-RandY),false);
        GenerateWall(FVector(RandX,TopRight.Y-(TopRight.Y-(RightDoorPos+doorwidth/2))/2,WallHeight/2),(TopRight.Y-(RightDoorPos+doorwidth/2)),false);
    }
    //bot right
    //  MazeSplit(FVector2D(Botleft.X, RandY),FVector2D(RandX, TopRight.Y),FVector2D(RightDoorPos, BOTDoorPos));
    MazeSplit(FVector2D(Botleft.X, RandY),FVector2D(RandX, TopRight.Y),FVector2D(BOTDoorPos, RightDoorPos));
    //top right
     // MazeSplit(FVector2D(RandX, RandY),FVector2D(TopRight.X, TopRight.Y),FVector2D(RightDoorPos, TOPDoorPos));
    MazeSplit(FVector2D(RandX, RandY),FVector2D(TopRight.X, TopRight.Y),FVector2D(TOPDoorPos, RightDoorPos));
//bot left
    // MazeSplit(FVector2D(Botleft.X, Botleft.Y),FVector2D(RandX, RandY),FVector2D(LEFTDoorPos, BOTDoorPos));
    MazeSplit(FVector2D(Botleft.X, Botleft.Y),FVector2D(RandX, RandY),FVector2D(BOTDoorPos, LEFTDoorPos));
   //top left
     // MazeSplit(FVector2D(RandX, Botleft.Y),FVector2D(TopRight.X, RandY),FVector2D(LEFTDoorPos, TOPDoorPos));
 MazeSplit(FVector2D(RandX, Botleft.Y),FVector2D(TopRight.X, RandY),FVector2D(TOPDoorPos, LEFTDoorPos));
       return;
}

void ANewMazeBuilder::GenerateWall(FVector pos,float WallLength,bool Rotation){
    
    //   AMazeWall* newWall =  GetWorld( )->SpawnActor<AMazeWall>(BPWalls, pos, FRotator(0.0f, 0, 00.f));
     AMazeWall* newWall =  GetWorld( )->SpawnActor<AMazeWall>(BPWalls, pos, FRotator(0.0f, 0.0f, 00.f));
    newWall->GenerateWalls(WallWidth,WallLength+WallWidth/2, WallHeight);
 if(Rotation==false)
    {
        newWall->SetActorRotation(FRotator(0.0f, 90.0f, 00.f), ETeleportType::ResetPhysics);
    }
}


float ANewMazeBuilder::RandomFloat(float a, float b){
    float random = ((float) rand()) / (float) RAND_MAX;
       float diff = b - a;
       float r = random * diff;
       return a + r;
    
}


