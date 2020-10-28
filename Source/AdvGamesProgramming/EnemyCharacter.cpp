// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "EngineUtils.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
     // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    CurrentAgentState = AgentState::PATROL;
    PathfindingNodeAccuracy = 100.0f;
    bOutOfAmmo = false;
    bIsReloading = false;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();
    PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyCharacter::SensePlayer);
    
    HearComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyCharacter::SensePlayer);

    HealthComponent = FindComponentByClass<UHealthComponent>();
    DetectedActor = nullptr;
    bCanSeeActor = false;

    //step 8
    bNoticedActor = false;
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //MoveAlongPath();
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::AgentPatrol()
{
    //if (Path.Num() == 0 && Manager != NULL)
    //{
//        Path = Manager->GeneratePath(CurrentNode, Manager->AllNodes[FMath::RandRange(0, Manager->AllNodes.Num() - 1)]);
//    }
}

void AEnemyCharacter::AgentEngage()
{
//    if (bCanSeeActor)
    //{
//        Path.Empty();
//
//        FVector DirectionToTarget = DetectedActor->GetActorLocation() - GetActorLocation();
//        Fire(DirectionToTarget);
//    //    if (Path.Num() == 0)
//        //{
//            Path = Manager->GeneratePath(CurrentNode, Manager->FindNearestNode(DetectedActor->GetActorLocation()));
//    //    }
    //}
    
}

void AEnemyCharacter::AgentEvade()
{
    
    //if (bCanSeeActor)
    //{
        //FVector DirectionToTarget = DetectedActor->GetActorLocation() - GetActorLocation();
        //Fire(DirectionToTarget);
    //    if (Path.Num() == 0)
        //{
        //    Path.Empty();

         //   Path = Manager->GeneratePath(CurrentNode, Manager->FindFurthestNode(DetectedActor->GetActorLocation()));
    //    }
    //}
}

void AEnemyCharacter::SensePlayer(AActor* SensedActor, FAIStimulus Stimulus)
{
     UE_LOG(LogTemp, Display, TEXT("Sense  %s"), *SensedActor->GetName())
    //step 13-> setp14 bp player tag

         if (SensedActor->ActorHasTag("player")) {
             if (Stimulus.WasSuccessfullySensed())
             {
                 UE_LOG(LogTemp, Warning, TEXT("Player Detected"))
                     DetectedActor = SensedActor;

                 //step 12
//                 for (AEnemyCharacter* AllEnemy : Manager->AllAgents) {
//                     if (AllEnemy->bNoticedActor == false) {
//                         AllEnemy->bNoticedActor = true;
//                         AllEnemy->DetectedActor = SensedActor;
//                     }
//                 }
                 //

                 bCanSeeActor = true;
                 bNoticedActor = true;
             }
             else
             {
                 UE_LOG(LogTemp, Warning, TEXT("Player Lost"))
                     bCanSeeActor = false;
                 bNoticedActor = false;
             }
         }
}

void AEnemyCharacter::MoveAlongPath()
{
//    if (Path.Num() > 0 && Manager != NULL)
//    {
//        //UE_LOG(LogTemp, Display, TEXT("Current Node: %s"), *CurrentNode->GetName())
//        if ((GetActorLocation() - CurrentNode->GetActorLocation()).IsNearlyZero(PathfindingNodeAccuracy))
//        {
//            UE_LOG(LogTemp, Display, TEXT("At Node %s"), *CurrentNode->GetName())
//            CurrentNode = Path.Pop();
//        }
//        else
//        {
//            FVector WorldDirection = CurrentNode->GetActorLocation() - GetActorLocation();
//            WorldDirection.Normalize();
//            AddMovementInput(WorldDirection, 1.0f);
//
//            //Get the AI to face in the direction of travel.
//            FRotator FaceDirection = WorldDirection.ToOrientationRotator();
//            FaceDirection.Roll = 0.f;
//            FaceDirection.Pitch = 0.f;
//            SetActorRotation(FaceDirection);
//        }
//    }
}
//step 4
void AEnemyCharacter::AgentAttend() {
    //step 11
    //if (bNoticedActor&!bCanSeeActor)
    //{
    //    if (Path.Num() == 0)
    //    {
    Path.Empty();

            Path = Manager->GeneratePath(CurrentNode, Manager->FindNearestNode(DetectedActor->GetActorLocation()));
    //    }
//    }
    //

}

void AEnemyCharacter::SetRoom(ARoom* room)
{
    RoomBelong =room;
}

