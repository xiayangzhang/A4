// Fill out your copyright notice in the Description page of Project Settings.

#include "KismetProceduralMeshLibrary.h"
#include "NavigationSystem.h"
#include "MazeWall.h"

// Sets default values
AMazeWall::AMazeWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    WallMeshs = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Wall"));
    SetRootComponent(WallMeshs);
  
}

// Called when the game starts or when spawned
void AMazeWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeWall::GenerateWalls(float Width,float Length,float Height){
    
        WallMeshs->ClearAllMeshSections();
        TArray<FVector> TempVertices;
        TArray<int32> TempTriangles;
        TArray<FVector2D> TempUVCoords;
        TArray<FVector> TempNormals;
        TArray<FProcMeshTangent> TempTangents;
    
         FVector BoxRadius = FVector(Length/2,Width/2,Height/2);
        UKismetProceduralMeshLibrary::GenerateBoxMesh(BoxRadius,TempVertices,TempTriangles,TempNormals,TempUVCoords,TempTangents);    
        WallMeshs->CreateMeshSection(0, TempVertices, TempTriangles, TempNormals, TempUVCoords, TArray<FColor>(), TempTangents, true);
    WallWidth = Width;
    WallLength = Length;
    WalHeight = Height;   
    
    int TopPos =-Length/2+100;
	GenerateWallTops();
    // while(TopPos<Length/2-120){
    //     int RandMesh =1 + rand()%2;
    //
    //     GenerateWallTops(TopPos,0,WallHeight/2+RandomFloat(0,-50),RandMesh);
    //    TopPos+=RandomFloat(80,40);
    //
    // }
 //   GenerateWallTops(Length/2-200,0,WallHeight/2+RandomFloat(0,-5),3);
 //  GenerateWallTops(-Length/2+90,0,WallHeight/2+RandomFloat(-0,-50),2);
 // GenerateWallTops(Length/2-90,0,WallHeight/2+RandomFloat(-0,-50),1);
//   GenerateWallTops(-Length/2+90,0,WallHeight/2+RandomFloat(-0,-50),1);
 //  GenerateWallTops(Length/2-90,0,WallHeight/2+RandomFloat(-0,-50),2);
   // GenerateWallTops(0,0,WallHeight/2,2);
     
 //  WallMeshs->CreateMeshSection(1, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, false);

}
float AMazeWall::RandomFloat(float a, float b){
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


