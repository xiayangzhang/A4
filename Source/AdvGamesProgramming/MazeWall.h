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
    int section;
    
    void GenerateWalls(float Width,float Length,float WallHeight);

    float RandomFloat(float a, float b);

};
