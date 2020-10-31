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

void AMazeWall::GenerateWalls(float Width,float Length,float WallHeight){
    
//
       // FVector BoxRadius = FVector((right-left)/2,(far-close)/2,WallHeight);
        TArray<FVector> TempVertices;
        TArray<int32> TempTriangles;
        TArray<FVector2D> TempUVCoords;
        TArray<FVector> TempNormals;
        TArray<FProcMeshTangent> TempTangents;
    
     FVector BoxRadius = FVector(Width/2,Length/2,WallHeight/2);
    
UKismetProceduralMeshLibrary::GenerateBoxMesh(BoxRadius,TempVertices,TempTriangles,TempNormals,TempUVCoords,TempTangents);
//
//        //TArray<FVector> NewVertices;
//        FVector BoxPos = FVector(left+(right-left)/2,close+(far-close)/2,0);
//        TArray<FVector> NewVertices;
//        for (int i = 0; i < TempVertices.Num(); i++) {
//            FVector Vertice =TempVertices[i]+BoxPos ;
//
//            NewVertices.Add(Vertice);
//        }
        WallMeshs->CreateMeshSection(section, TempVertices, TempTriangles, TempNormals, TempUVCoords, TArray<FColor>(), TempTangents, true);
    //WallMeshs->SetMaterial(section,WallMaterial);
//
//        section+=1;
//
//        FVector wallpos =FVector(left+(right-left)/2,close+(far-close)/2,WallHeight);
//       // GenWallTop(wallpos,false);
//

}
float AMazeWall::RandomFloat(float a, float b){
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
