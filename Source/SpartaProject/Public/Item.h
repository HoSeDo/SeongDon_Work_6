#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

	void SetRotationSpeed(float NewSpeed);

protected:
	//4번 리플렉션 적용 좌표계 고정
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	//스태틱 메쉬하고 머테리얼을 BP에서 수정가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	//BP 에서 회전속도를 조절가능함 기본값은 cpp 에서 90을 받아옴
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	// 움직이는 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float VerticalRange = 30.0f; 

	// 움직이는 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float VerticalSpeed = 2.0f;  

	// 시작 위치 저장용 (기준점)
	FVector StartLocation;
	float RunningTime = 0.0f; // Sine 계산을 위한 시간 누적

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

	// 함수를 블루프린트에서 호출 가능하도록 설정
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	// 블루프린트에서 값만 반환하도록 설정
	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;

	// C++에서 호출되지만 구현은 블루프린트에서 수행
	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();
};
