// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemManager.generated.h"

UCLASS()
class SPARTAPROJECT_API AItemManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemManager();

protected:
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
    USceneComponent* SceneRoot;

    // 에디터에서 어떤 아이템을 스폰할지 선택하는 칸 (BP로 된 모든 것을 소환가능)
    UPROPERTY(EditAnywhere, Category = "SpawnSettings")
    TSubclassOf<class AItem> ItemClass;

    // 스폰 개수
    UPROPERTY(EditAnywhere, Category = "SpawnSettings")
    int32 SpawnCount = 10;

    // 스폰 범위
    UPROPERTY(EditAnywhere, Category = "SpawnSettings")
    float SpawnRadius = 1000.0f;

public:	
	virtual void Tick(float DeltaTime) override;

};
