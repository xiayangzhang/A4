// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigationNode.h"
#include "GameFramework/Character.h"
#include "AIManager.h"
#include "Perception/AIPerceptionComponent.h"
#include "HealthComponent.h"
#include "Room.h"
#include "EnemyCharacter.generated.h"

UENUM()
enum class AgentState : uint8
{
    PATROL,
    ENGAGE,
    EVADE,
    ATTEND
};

UCLASS()
class ADVGAMESPROGRAMMING_API AEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AEnemyCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere)
    TArray<ANavigationNode*> Path;
    UPROPERTY(VisibleAnywhere)
    ANavigationNode* CurrentNode;
    UPROPERTY(VisibleAnywhere)
    AAIManager* Manager;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UAIPerceptionComponent* PerceptionComponent;
    
    //step 1
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UAIPerceptionComponent* HearComponent;

    UPROPERTY(VisibleAnywhere)
    AgentState CurrentAgentState;
    UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
    AActor* DetectedActor;
    UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
    bool bCanSeeActor;

    UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
    bool bNoticedActor;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bOutOfAmmo;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bIsReloading;

    UPROPERTY(EditAnywhere,BlueprintReadWrite)
    ARoom* RoomBelong;
    
    UHealthComponent* HealthComponent;

    UPROPERTY(EditAnywhere, meta = (UIMin = "10.0", UIMax = "1000.0", ClampMin = "10.0", ClampMax = "1000.0"))
    float PathfindingNodeAccuracy;

    UFUNCTION(BlueprintCallable)
    void AgentPatrol();
    UFUNCTION(BlueprintCallable)
    void AgentEngage();
    UFUNCTION(BlueprintCallable)
    void AgentEvade();
    
    //step 3
    UFUNCTION(BlueprintCallable)
    void AgentAttend();
    //
    UFUNCTION()
    void SensePlayer(AActor* ActorSensed, FAIStimulus Stimulus);
    
    UFUNCTION(BlueprintImplementableEvent)
    void Fire(FVector FireDirection);
    UFUNCTION(BlueprintImplementableEvent)
    void Reload();

    void SetRoom(ARoom* room);

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

    void MoveAlongPath();

};
