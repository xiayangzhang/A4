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
    WallMeshs->AttachTo(this->RootComponent);
   // WallTopMeshs = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("WallTopMeshs"));
   // WallTopMeshs->AttachTo(this->RootComponent);
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
    
        WallMeshs->ClearAllMeshSections();
       // WallTopMeshs->ClearAllMeshSections();

       // FVector BoxRadius = FVector((right-left)/2,(far-close)/2,WallHeight);
        TArray<FVector> TempVertices;
        TArray<int32> TempTriangles;
        TArray<FVector2D> TempUVCoords;
        TArray<FVector> TempNormals;
        TArray<FProcMeshTangent> TempTangents;
    
     FVector BoxRadius = FVector(Length/2,Width/2,WallHeight/2);
    
        UKismetProceduralMeshLibrary::GenerateBoxMesh(BoxRadius,TempVertices,TempTriangles,TempNormals,TempUVCoords,TempTangents);

//        WallMeshs->CreateMeshSection(0, TempVertices, TempTriangles, TempNormals, TempUVCoords, TArray<FColor>(), TempTangents, true);
  
    
    int TopPos =-Length/2+100;
   // int base =-Length/2+150;
    
//    while(base<Length/2-150){
//
//        GenerateWallTops(base,-Width/2,WallHeight/2+RandomFloat(0,-5),3);
//        GenerateWallTops(base, Width/2,WallHeight/2+RandomFloat(0,-5),3);
//
//        base+=RandomFloat(100,300);
//
//    }
    
    // while(TopPos<Length/2-100){
    //     int RandMesh =1 + rand()%2;

    //     GenerateWallTops(TopPos,0,WallHeight/2+RandomFloat(-20,-50),RandMesh);
    //     TopPos+=RandomFloat(60,40);

    // }
    //GenerateWallTops(Length/2-200,0,WallHeight/2+RandomFloat(0,-5),3);
    GenerateWallTops(-Length/2+70,0,WallHeight/2+RandomFloat(-20,-50),2);
    GenerateWallTops(Length/2-70,0,WallHeight/2+RandomFloat(-20,-50),1);
    GenerateWallTops(-Length/2+70,0,WallHeight/2+RandomFloat(-20,-50),1);
    GenerateWallTops(Length/2-70,0,WallHeight/2+RandomFloat(-20,-50),2);
    //GenerateWallTops(0,0,WallHeight/2,2);
       WallMeshs->CreateMeshSection(1, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, false);

}
float AMazeWall::RandomFloat(float a, float b){
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void AMazeWall::GenerateWallTops(float LengthOffSet,float WidthOffSet,float HeightOffSet,int MeshIndex){
    
            UStaticMesh* NeWallTop =wallTop1;
            if(MeshIndex==1){
                NeWallTop = wallTop1;
    }
           if(MeshIndex==2){
                 NeWallTop = wallTop2;
    }
         if(MeshIndex==3){
                 NeWallTop = wallTop3;
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
    //TopVertices
        for (int i = 0; i < TopVertices.Num(); i++) {
            FVector Vertice =TopVertices[i]+pos ;
            Vertices.Add(Vertice);
        }
//
//       // TArray<FVector> NewVertices;
//    //TopVertices
//        for (int i = 0; i < TopVertices.Num(); i++) {
//           // FVector Vertice =TopVertices[i]+pos ;
//            Vertices.Add(TopVertices[i]+pos);
//        }
//
//    for (int i = 0; i < TopTriangles.Num(); i++) {
//        Triangles.Add(TopTriangles[i]+TopVertices.Num());
//    }
//
//    for (int i = 0; i < TopNormals.Num(); i++) {
//         //FVector Triangles =TopTriangles[i]+TopVertices.Num() ;
//         Normals.Add(TopNormals[i]+pos);
//     }
//
//    for (int i = 0; i < TopUVCoords.Num(); i++) {
//         //FVector Triangles =TopTriangles[i]+TopVertices.Num() ;
//         UVCoords.Add(TopUVCoords[i]);
//     }
//    for (int i = 0; i < TopTangents.Num(); i++) {
//         //FVector Triangles =TopTriangles[i]+TopVertices.Num() ;
//         Tangents.Add(TopTangents[i]);
//     }
    section+=1;

        WallMeshs->CreateMeshSection(section, NewVertices, TopTriangles, TopNormals, TopUVCoords, TArray<FColor>(), TopTangents, false);
   // section+=1;

    
    
    
    
    
}
