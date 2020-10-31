// Fill out your copyright notice in the Description page of Project Settings.

#include "KismetProceduralMeshLibrary.h"
#include "NavigationSystem.h"
#include "MazeBuilder.h"

// Sets default values
AMazeBuilder::AMazeBuilder()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

//   FloorMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("floor"));
//     //WallMeshs = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("floor"));
//
//    FloorMesh->AttachTo(this->RootComponent);
//  //  WallMeshs->AttachTo(this->RootComponent);
//
//    WallVertices = TArray<FVector>();
//
//    MapWidth =5000.0f;
//    mapLength =5000.0f;
//
//    WallHeight= 200.0f;
//    WallWidth =40.0f;
//    totalVertices = 0;
//    doorwidth = 200.0f;
}

// Called when the game starts or when spawned
void AMazeBuilder::BeginPlay()
{
//    Super::BeginPlay();
//   // ClearMeshData();
//   Generatefloor();
//   GenerateMaze();
//   const FVector loaction = FVector(mapLength - 100.0f, MapWidth - 100.0f, 0.0f);
//   const FRotator rotaction = GetActorRotation();
//   GetWorld()->SpawnActor<AActor>(endgame, loaction, rotaction);
//
//  // UKismetProceduralMeshLibrary::CalculateTangentsForMesh(WallVertices, WallTriangles, WallUVCoords, WallNormals, WallTangents);
//
// // WallMeshs->CreateMeshSection(0, WallVertices, WallTriangles, TArray<FVector>(),WallUVCoords, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
//
//    FNavigationSystem::UpdateComponentData(*FloorMesh);
//    //FNavigationSystem::UpdateComponentData(*WallMeshs);

}

// Called every frame
void AMazeBuilder::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AMazeBuilder::GenerateMaze(){
//    UE_LOG(LogTemp, Warning, TEXT("GenerateMaze"));
//    //Generate edge
//   // GenerateWalls(MapWidth,0,0,WallWidth);
//  //  GenerateWalls(MapWidth,0,mapLength-WallWidth,mapLength);
//   // GenerateWalls(MapWidth,MapWidth-WallWidth,0,mapLength);
//  //  GenerateWalls(WallWidth,0,0,mapLength);
//
//    MazeSplit(FVector2D(0, 0),FVector2D(MapWidth, mapLength));
//

}

void AMazeBuilder::Generatefloor(){
//   UE_LOG(LogTemp, Warning, TEXT("Generatefloor"));
//    //FloorMesh->ClearAllMeshSections();
//
//    TArray<FVector> Vertices;
//        Vertices.Add(FVector(0.0f, 0.0f, 0.0f));
//        Vertices.Add(FVector(0.0f, mapLength, 0.0f));
//        Vertices.Add(FVector(MapWidth, mapLength, 0.0f));
//        Vertices.Add(FVector(MapWidth, 0.0f, 0.0f));
//
//        TArray<int32> Triangles;
//        Triangles.Add(0);
//        Triangles.Add(1);
//        Triangles.Add(3);
//        Triangles.Add(3);
//        Triangles.Add(1);
//        Triangles.Add(2);
//
//    TArray<FVector2D> UVCoords;
//    UVCoords.Add(FVector2D(0.0f, 0.0f));
//    UVCoords.Add(FVector2D(0.0f, 1.0f));
//    UVCoords.Add(FVector2D(1.0f, 1.0f));
//    UVCoords.Add(FVector2D(1.0f, 0.0f));
//    FloorMesh->CreateMeshSection(0, Vertices, Triangles,  TArray<FVector>(), UVCoords, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
//
//  //  FloorMesh->SetMaterial(0,floorMaterial);
}


void AMazeBuilder::GenerateWalls(float far,float close,float left,float right){
//
    
//    FVector BoxRadius = FVector((right-left)/2,(far-close)/2,WallHeight);
//    TArray<FVector> TempVertices;
//    TArray<int32> TempTriangles;
//    TArray<FVector2D> TempUVCoords;
//    TArray<FVector> TempNormals;
//    TArray<FProcMeshTangent> TempTangents;
//    UKismetProceduralMeshLibrary::GenerateBoxMesh(BoxRadius,TempVertices,TempTriangles,TempNormals,TempUVCoords,TempTangents);
//
//    //TArray<FVector> NewVertices;
//    FVector BoxPos = FVector(left+(right-left)/2,close+(far-close)/2,0);
//    TArray<FVector> NewVertices;
//    for (int i = 0; i < TempVertices.Num(); i++) {
//        FVector Vertice =TempVertices[i]+BoxPos ;
//
//        NewVertices.Add(Vertice);
//    }
////    TArray<FVector2D> NewUVCoords;
////    for (int i = 0; i < TempUVCoords.Num(); i++) {
////        FVector2D newUV =FVector2D(TempUVCoords[i].X*WallHeight, TempUVCoords[i].Y*WallHeight) ;
////          NewUVCoords.Add(newUV);
////      }
//
//
//
//    WallMeshs->CreateMeshSection(section, NewVertices, TempTriangles, TempNormals, TempUVCoords, TArray<FColor>(), TempTangents, true);
//    WallMeshs->SetMaterial(section,WallMaterial);
//
//    section+=1;
//    FVector wallpos =FVector(left+(right-left)/2,close+(far-close)/2,WallHeight);
//    GenWallTop(wallpos,false);

}
void AMazeBuilder::ClearMeshData(){
//   UE_LOG(LogTemp, Warning, TEXT("ClearMeshData"));
//    WallVertices.Empty();
//    WallTriangles.Empty();
}

void AMazeBuilder::AddTriangle(int32 V1, int32 V2, int32 V3)
{
//
//    WallTriangles.Add(totalVertices+V1);
//    WallTriangles.Add(totalVertices+V2);
//    WallTriangles.Add(totalVertices+V3);
}



void AMazeBuilder::MazeSplit(FVector2D Botleft,FVector2D TopRight){
//
//    if(TopRight.X-Botleft.X<10*doorwidth||TopRight.Y-Botleft.Y<10*doorwidth){
//
//        ARoom* newRoom;
//        FVector RoomPos =FVector(
//                                 (TopRight.X-Botleft.X)/2+Botleft.X
//        ,(TopRight.Y-Botleft.Y)/2+Botleft.Y,0);
//        newRoom = GetWorld()->SpawnActor<ARoom>(BPRoom,RoomPos,FRotator(0.f, 0.f, 0.f));
//        newRoom->Pos = RoomPos;
//        newRoom->RoomLength =TopRight.Y-Botleft.Y;
//        newRoom->RoomWidth =TopRight.X-Botleft.X;
//        newRoom->init();
//
//        return;
  //  }

// 
//    float RandY = RandomFloat(TopRight.Y-5*doorwidth,Botleft.Y+doorwidth*5);
//    float RandX=RandomFloat(TopRight.X-5*doorwidth,Botleft.X+doorwidth*5);
//    
//    int RandDoor = rand()% 4 + 1;
//    
//    
//    float TOPDoorPos = RandomFloat(TopRight.X-doorwidth*2,RandX+doorwidth*2);
//    float BOTDoorPos = RandomFloat(RandX-doorwidth*2,Botleft.X+doorwidth*2);
//    float LEFTDoorPos = RandomFloat(RandY-doorwidth*2,Botleft.Y+doorwidth*2);
//    float RightDoorPos = RandomFloat(TopRight.Y-doorwidth,RandY+doorwidth);
//
//    
//     //top
//    if(RandDoor == 1){
//        GenerateWalls(TopRight.X,RandX,RandY-WallWidth/2,RandY+WallWidth/2);
//
//    }else{
//         GenerateWalls(TopRight.X,TOPDoorPos+doorwidth/2,RandY-WallWidth/2,RandY+WallWidth/2);
//         GenerateWalls(TOPDoorPos-doorwidth/2,RandX,RandY-WallWidth/2,RandY+WallWidth/2);
//    }
//    //bot
//    if(RandDoor == 2){
//    GenerateWalls(RandX,Botleft.X,RandY-WallWidth/2,RandY+WallWidth/2);
//    }else{
//        GenerateWalls(RandX,BOTDoorPos+doorwidth/2,RandY-WallWidth/2,RandY+WallWidth/2);
//        GenerateWalls(BOTDoorPos-doorwidth/2,Botleft.X,RandY-WallWidth/2,RandY+WallWidth/2);
//    }
//    //left
//    if(RandDoor == 3){
//    GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,Botleft.Y,RandY);
//    }else{
//        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,Botleft.Y,LEFTDoorPos-doorwidth/2);
//        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,LEFTDoorPos+doorwidth/2,RandY);
//    }
//    //right
//    if(RandDoor == 4){
//    GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,RandY,TopRight.Y);
//    }else{
//        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,RandY,RightDoorPos-doorwidth/2);
//        GenerateWalls(RandX+WallWidth/2,RandX-WallWidth/2,RightDoorPos+doorwidth/2,TopRight.Y);
//    }
//    
//    
//    
//    MazeSplit(FVector2D(Botleft.X, RandY),FVector2D(RandX, TopRight.Y));
//  
//    MazeSplit(FVector2D(RandX, RandY),FVector2D(TopRight.X, TopRight.Y));
//
//    MazeSplit(FVector2D(Botleft.X, Botleft.Y),FVector2D(RandX, RandY));
//    
//    MazeSplit(FVector2D(RandX, Botleft.Y),FVector2D(TopRight.X, RandY));
//
//     return;
}



float AMazeBuilder::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void AMazeBuilder::GenWallTop(FVector pos,bool HorOrVer) {
    
//        UStaticMesh* NeWallTop = wallTop;
//        
//        TArray<FVector> TopVertices;
//        TArray<int32> TopTriangles;
//        TArray<FVector2D> TopUVCoords;
//        TArray<FVector> TopNormals;
//        TArray<FProcMeshTangent> TopTangents;
//        
//        
//    UKismetProceduralMeshLibrary::GetSectionFromStaticMesh
//    (
//       wallTop,
//        0,
//        0,
//        TopVertices,
//        TopTriangles,
//        TopNormals,
//        TopUVCoords,
//        TopTangents
//     );
//    pos.Z-=RandomFloat(0,10.0f);
//    TArray<FVector> NewVertices;
//    for (int i = 0; i < TopVertices.Num(); i++) {
//        FVector Vertice =TopVertices[i]+pos ;
//        NewVertices.Add(Vertice);
//    }
    
  //  WallMeshs->CreateMeshSection(section, NewVertices, TopTriangles, TopNormals, TopUVCoords, TArray<FColor>(), TopTangents, false);
    
    
       section+=1;
    
}
