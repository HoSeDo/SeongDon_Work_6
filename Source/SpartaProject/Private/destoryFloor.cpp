#include "destoryFloor.h"

AdestoryFloor::AdestoryFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

}

void AdestoryFloor::StartDestructionSequence()
{
    //도전1 타이머 시스템 
    // details Settings 에 입력한 시간만큼 destory합니다 기본값 3초
    GetWorld()->GetTimerManager().SetTimer(
        DestroyTimerHandle,
        this,
        &AdestoryFloor::OnTimerExpired,
        DestroyDelay,
        false
    );
}

void AdestoryFloor::OnTimerExpired()
{
    // 시간이 지나면 파괴
    this->Destroy();
}

void AdestoryFloor::BeginPlay()
{
	Super::BeginPlay();

    //게임 시작 순간 타이머시스템 불러오기
    StartDestructionSequence();

}

void AdestoryFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

