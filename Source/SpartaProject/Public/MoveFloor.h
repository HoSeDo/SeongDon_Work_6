// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveFloor.generated.h"

UCLASS()
class SPARTAPROJECT_API AMoveFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMoveFloor();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// 이동 방향 (예: X=1, Z=1 이면 대각선 위)
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MoveDirection = FVector(0.0f, 0.0f, 0.0f);

	// 실제 이동 속도 (초당 이동 유닛)
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 0.0f;

	// 최대 왕복 범위
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxRange = 500.0f;

private:
	FVector StartLocation;
	float StateDirection = 1.0f;

public:	
	
	virtual void Tick(float DeltaTime) override;


};
