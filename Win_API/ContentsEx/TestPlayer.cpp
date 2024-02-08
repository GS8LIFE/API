#include "TestPlayer.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"

ATestPlayer::ATestPlayer() 
{
}

ATestPlayer::~ATestPlayer() 
{
}

void ATestPlayer::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer();
	Renderer->SetImage("Player_Right.png");
	// Renderer->SetTransColor({255, 255, 255, 255});
	Renderer->SetTransform({ {0,0}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {64,64}, {32, 32} });
	Renderer->CreateAnimation("Idle", "Player_Right.png", 0, 12, 0.5f, true);
	Renderer->CreateAnimation("Attack", "Player_Right.png", 26, 32, 0.5f, true);
	Renderer->ChangeAnimation("Idle");

}

void ATestPlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	EngineDebug::OutPutDebugText(UContentsHelper::GetMousePos().ToString());

	AlphaTime += _DeltaTime;
	if (1.0f <= AlphaTime)
	{
		Dir = !Dir;
		AlphaTime = 0.0f;
	}

	if (true == Dir)
	{
		Renderer->SetAlpha(AlphaTime);
	}
	else
	{
		Renderer->SetAlpha(1.0f - AlphaTime);
	}


	if (EngineInput::IsDown('Q'))
	{
		Renderer->ChangeAnimation("Attack");
	}

	//// 어떻게 편하게 쓸까?
	//// 테스트 코드
	//AnimationTime -= _DeltaTime;

	//if (0 >= AnimationTime)
	//{
	//	AnimationFrame++;
	//	AnimationTime = 1.0f;
	//}

	//Renderer->SetImageIndex(AnimationFrame);
}