// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.h"
#include "EnemyCharacter.h"
#include "KismetProceduralMeshLibrary.h"
#include "MazeBuilder.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AMazeBuilder : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    AMazeBuilder();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    
    UPROPERTY(VisibleAnywhere)
    UProceduralMeshComponent* FloorMesh;
    UPROPERTY(VisibleAnywhere)
     UProceduralMeshComponent* WallMeshs;
    
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSubclassOf<AActor> endgame;
    int totalVertices;
    
    int RoomID;
    
    TArray<FVector> WallVertices;
    TArray<int32> WallTriangles;

    TArray<ARoom*> Rooms;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<ARoom> BPRoom;

     UPROPERTY(EditAnywhere, BlueprintReadWrite)
     TSubclassOf<AEnemyCharacter> Enemy;
    
    void GenerateMaze();
    
    void GenerateWalls(float far,float close,float left,float right);
      
    void GenerateDoor(float far,float close,float left,float right);
   
    UFUNCTION(BlueprintCallable)
    void Generatefloor();
    
    void ClearMeshData();
    
    void MazeSplit(FVector2D botleft,FVector2D TopRight);
    
    void AddTriangle(int32 V1, int32 V2, int32 V3);

    float RandomFloat(float a, float b);
};
