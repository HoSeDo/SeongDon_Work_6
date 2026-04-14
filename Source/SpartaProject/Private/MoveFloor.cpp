// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveFloor.h"

AMoveFloor::AMoveFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

}


void AMoveFloor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}


void AMoveFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // 방향 벡터 정규화 및 이동량 계산
    FVector SafeDirection = MoveDirection.GetSafeNormal();
    FVector CurrentLocation = GetActorLocation();

    // 다음 프레임에 가야 할 위치 계산
    FVector NewLocation = CurrentLocation + (SafeDirection * MoveSpeed * DeltaTime * StateDirection);

    // 시작점으로부터 얼마나 멀어졌는지 체크
    float DistanceMoved = FVector::Dist(StartLocation, NewLocation);

    // 왕복 및 위치 보정 로직
    if (DistanceMoved >= MaxRange)
    {
        // MaxRange에 도달하면? -> 방향을 반전
        StateDirection *= -1.0f;

        // 잔상 기능 방지 시작점에서 최대 거리만큼 떨어진 정확한 위치를 계산합니다.
        NewLocation = StartLocation + (SafeDirection * MaxRange * (StateDirection * -1.0f));
    }

    // 최종 위치 적용
    SetActorLocation(NewLocation);
}

