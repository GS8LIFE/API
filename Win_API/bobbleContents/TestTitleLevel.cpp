#include "TestTitleLevel.h"
#include "TestTitleLogo.h"
#include "EngineCore\EngineCore.h"

UTestTitleLevel::UTestTitleLevel() 
{
}

UTestTitleLevel::~UTestTitleLevel() 
{
}

void UTestTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		// 여기서 위치가 안정해졌다고 이녀석위치가 0,0인건 아니죠
		ATestTitleLogo* Logo = SpawnActor<ATestTitleLogo>();
	}


}
void UTestTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}