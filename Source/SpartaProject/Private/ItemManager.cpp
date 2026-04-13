// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManager.h"
#include "Item.h" 
#include "Engine/World.h"

// Sets default values
AItemManager::AItemManager()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemManager::BeginPlay()
{
	Super::BeginPlay();
	
    if (!ItemClass) return;

    FVector ManagerLocation = GetActorLocation();

    //도전2 랜덤 스폰 로직
    for (int32 i = 0; i < SpawnCount; i++)
    {
        // 랜덤 좌표 계산
        FVector RandomLocation = ManagerLocation + FVector(
            FMath::RandRange(-SpawnRadius, SpawnRadius),
            FMath::RandRange(-SpawnRadius, SpawnRadius),
            100.0f //바닥에 안 파묻히도록 아이템 매니저 위치보다 z위치 100.0f 만큼 올림 
        );

        // 소환 설정값 생성
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        // 아이템 소환
        AItem* SpawnedItem = GetWorld()->SpawnActor<AItem>(
            ItemClass,
            RandomLocation,
            FRotator::ZeroRotator,
            SpawnParams
        );

        // 소환 성공 시 랜덤 회전 속도 
        if (SpawnedItem)
        {
            float RndSpeed = FMath::RandRange(180.0f, 360.0f);
            SpawnedItem->SetRotationSpeed(RndSpeed);

            UE_LOG(LogTemp, Warning, TEXT("Item %d Spawned at: %s"), i, *RandomLocation.ToString());
        }
    }

}

// Called every frame
void AItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::SetRotationSpeed(float NewSpeed)
{
    RotationSpeed = NewSpeed;
}