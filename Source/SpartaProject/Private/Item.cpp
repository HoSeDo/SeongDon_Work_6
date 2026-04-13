#include "Item.h"

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//기본적으로 Tick 마다 회전속도를 90을 갖고 있음
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	OnItemPickedUp();
}
//3번 프레임 독립성
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

	RunningTime += DeltaTime;

	FVector NewLocation = StartLocation;

	// 수식: 시작높이 + (폭 * sin(시간 * 속도))
	NewLocation.Z += (VerticalRange * FMath::Sin(RunningTime * VerticalSpeed));

	SetActorLocation(NewLocation);
}

// BlueprintCallable 함수 구현
void AItem::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}