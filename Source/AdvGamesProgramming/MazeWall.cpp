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
    
    //int TopPos =-Length/2+100;
for(int i = -Length/2+100;i<Length/2-120;i+=50)
{
	int RandMesh =1 + rand()%3;
	if(i%3==0)
	{
		RandMesh=3;
		i+=50;
		GenerateWallTops(i,0,Height/2+RandomFloat(0,-10),3);

	}else
	{
		GenerateWallTops(i,0,Height/2+RandomFloat(-30,-50),RandMesh);

	}
}

   GenerateWallTops(-Length/2+65,0,Height/2+RandomFloat(-30,-50),2);
  GenerateWallTops(Length/2-65,0,Height/2+RandomFloat(-30,-50),1);
   GenerateWallTops(-Length/2+65,0,Height/2+RandomFloat(-30,-50),1);
  GenerateWallTops(Length/2-65,0,Height/2+RandomFloat(-30,-50),2);
 
}
float AMazeWall::RandomFloat(float a, float b){
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void AMazeWall::GenerateWallTops(float LengthOffSet,float WidthOffSet,float HeightOffSet,int MeshIndex)
{
	UStaticMesh* NeWallTop =wallTop1;
	if(MeshIndex==1){
		NeWallTop = wallTop1;
	}
	if(MeshIndex==2){
		NeWallTop = wallTop2;
	}
	if(MeshIndex==3){
		NeWallTop = wallTop3;
		//HeightOffSet= 0.0f;
	}
	TArray<FVector> TopVertices;
	TArray<int32> TopTriangles;
	TArray<FVector2D> TopUVCoords;
	TArray<FVector> TopNormals;
	TArray<FProcMeshTangent> TopTangents;
	UKismetProceduralMeshLibrary::GetSectionFromStaticMesh
(
    NeWallTop,
    5,
    0,
    TopVertices,
    TopTriangles,
    TopNormals,
    TopUVCoords,
    TopTangents
 );
	FVector pos = FVector(LengthOffSet,WidthOffSet,HeightOffSet);

	TArray<FVector> NewVertices;
	for (int i = 0; i < TopVertices.Num(); i++) {
		FVector Vertice =TopVertices[i]+pos ;
		Vertices.Add(Vertice);
		NewVertices.Add(Vertice);
	}
	section+=1;
	WallMeshs->CreateMeshSection(section, NewVertices, TopTriangles, TopNormals, TopUVCoords, TArray<FColor>(), TopTangents, false);

}
