// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"
class AEnemyCharacter;

UCLASS()
class ADVGAMESPROGRAMMING_API ARoom : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    ARoom();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 randomSeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Pos;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RoomWidth;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RoomLength;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int RoomID;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool HasEnemy;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AEnemyCharacter> Enemy;


    
    
 //   UFUNCTION(BlueprintImplementableEvent)
    void init(int32 seed);
    
    UFUNCTION(BlueprintCallable)
    void GenEnemy();
    
   UFUNCTION(BlueprintCallable)
   FVector GenRandomPos();
    UFUNCTION(BlueprintCallable)
    float RandomFloat(float a, float b);

    UFUNCTION(BlueprintCallable)
     int RandomInt(int a, int b);

    UFUNCTION(BlueprintImplementableEvent)
    void GenObj();
};
