// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "destoryFloor.generated.h"

UCLASS()
class SPARTAPROJECT_API AdestoryFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AdestoryFloor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	//스태틱 메쉬하고 머테리얼을 BP에서 수정가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Settings")
	float DestroyDelay = 3.0f;

	FTimerHandle DestroyTimerHandle;

	UFUNCTION()
	void OnTimerExpired();

	UFUNCTION(BlueprintCallable, Category = "Item|Events")
	void StartDestructionSequence();

public:	
	virtual void Tick(float DeltaTime) override;

};
