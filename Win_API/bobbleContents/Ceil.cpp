#include "Ceil.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>

Ceil::Ceil()
{
}

Ceil::~Ceil()
{
}

void Ceil::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer();
	Renderer->SetOrder(-9);
	Renderer->SetAlpha(100);
	Renderer->SetImage("ceil.png");
	Renderer->CreateAnimation("Idle", "Ceil.png", 0, 11, 1.0f, false);
	Renderer->SetPosition({ 350,70 });//↓
	Renderer->SetScale({ 300,1700 }); //발사대 위치와 크기
	Renderer->ChangeAnimation("Idle");


}

void Ceil::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);



	if (EngineInput::IsDown('Q'))
	{
		Renderer->ChangeAnimation("Attack");

	}
}