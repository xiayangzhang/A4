// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.h"
#include "MazeWall.h"
#include "EnemyCharacter.h"
#include "KismetProceduralMeshLibrary.h"
#include "NewMazeBuilder.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ANewMazeBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewMazeBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UProceduralMeshComponent* FloorMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
       float MapWidth;
       
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       float mapLength;
       
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       float WallHeight;
       
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       float WallWidth;
       
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       float doorwidth;
    
        int RoomID;
    
    TArray<ARoom*> Rooms;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<ARoom> BPRoom;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AEnemyCharacter> Enemy;
       
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AMazeWall> BPWalls;

    void GenerateMaze();
    
    void Generatefloor();

    void GenerateWall(FVector pos,float WallLength,bool Rotation);
    
    void MazeSplit(FVector2D botleft,FVector2D TopRight,FVector2D Door);

    float RandomFloat(float a, float b);

};
