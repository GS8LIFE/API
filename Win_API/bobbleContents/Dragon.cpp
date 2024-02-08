#include "Dragon.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>

Dragon::Dragon() 
{
}

Dragon::~Dragon() 
{
}

void Dragon::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer();
	Renderer->SetImage("BobbleCeil.png");
	Renderer->SetTransform({ {320,940}, {100, 100} }); //Dragon 위치와 크기
	Renderer->CreateAnimation("Idle", "BobbleCeil.png", 0, 2, 0.2f, true);
	Renderer->CreateAnimation("Attack", "BobbleCeil.png", 22, 24, 0.2f, true);
	Renderer->ChangeAnimation("Idle");

}

void Dragon::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);



	if (EngineInput::IsDown('Q'))
	{
		Renderer->ChangeAnimation("Attack");

	}
}