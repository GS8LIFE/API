#include "TestTitleLevel.h"
#include "TestTitleLogo.h"

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
		ATestTitleLogo* Logo = SpawnActor<ATestTitleLogo>();
	}


}
void UTestTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}