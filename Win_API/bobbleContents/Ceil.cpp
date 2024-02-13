#include "ceil.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>

ceil::ceil()
{
}

ceil::~ceil()
{
}

void ceil::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer();
	Renderer->SetOrder(-9);
	Renderer->SetAlpha(100);
	Renderer->SetImage("ceil.png");
	Renderer->CreateAnimation("Idle", "ceil.png", 0, 11, 1.0f, false);
	Renderer->SetPosition({ 350,70 });//↓
	Renderer->SetScale({ 300,1700 }); //발사대 위치와 크기


}

void ceil::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
//버블5번 쏘면 1번 내려오게 하기
}