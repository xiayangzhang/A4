// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KismetProceduralMeshLibrary.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "MazeWall.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AMazeWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
     UProceduralMeshComponent* WallMeshs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
     UProceduralMeshComponent* WallTopMeshs;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
       UStaticMesh* wallTop1;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
       UStaticMesh* wallTop2;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UStaticMesh* wallTop3;
    int section;
    
    TArray<FVector> Vertices;
    TArray<int32> Triangles;
    TArray<FVector2D> UVCoords;
    TArray<FVector> Normals;
    TArray<FProcMeshTangent> Tangents;
    
    
    
    void GenerateWalls(float Length,float Width,float WallHeight);

    float RandomFloat(float a, float b);

     void GenerateWallTops(float LengthOffSet,float WidthOffSet,float HeightOffSet,int MeshIndex);
};
