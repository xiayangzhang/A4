// Fill out your copyright notice in the Description page of Project Settings.

#include "Room.h"
#include "EnemyCharacter.h"
#include "Components/LineBatchComponent.h"
// Sets default values
ARoom::ARoom()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
void ARoom::GenEnemy()
{
//    AEnemyCharacter* NewEnemy = GetWorld()->SpawnActor<AEnemyCharacter>(Enemy, GenRandomPos(), FRotator(0.0f, 0.f, 0.f));
//    NewEnemy->SetRoom(this);
//    HasEnemy = true;
//    UE_LOG(LogTemp, Display, TEXT("GenEnemy"));

}
FVector ARoom::GenRandomPos()
{
    float x = Pos.X+RandomFloat(-RoomWidth/2+100.0f,RoomWidth/2-100.0f);
    float y = Pos.Y+RandomFloat(-RoomLength/2+100.0f,RoomLength/2-100.0f);
    
    return FVector(x,y,20);
}

float ARoom::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
//void ARoom::init()
//{
////     ULineBatchComponent* const LineBatcher = GetWorld()->PersistentLineBatcher;
////    FVector Widthstart = FVector(Pos.X-RoomWidth/2,Pos.Y,20.0f);
////    FVector Widthend =  FVector(Pos.X+RoomWidth/2,Pos.Y,20.0f);
////
////   LineBatcher->DrawLine(Widthstart, Widthend, FLinearColor::Red, 10, 0.f);
////
////    ULineBatchComponent* const LineBatcherLength = GetWorld()->PersistentLineBatcher;
////     FVector Lengstart = FVector(Pos.X,Pos.Y-RoomLength/2,20.0f);
////     FVector Lengend =  FVector(Pos.X,Pos.Y+RoomLength/2,20.0f);
////
////    LineBatcherLength->DrawLine(Lengstart, Lengend, FLinearColor::Blue, 10, 0.f);
//
//    //GenEnemy();
//}
