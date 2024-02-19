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

	Renderer = CreateImageRenderer(RenderOrder::border);
	Renderer->SetImage("Ceil.png");
	Renderer->SetTransform({ {318,35}, {260, 700} });
	Renderer->CreateAnimation("idle", "Ceil.png", 0, 0, 0.05f, false);


	Renderer->ChangeAnimation("idle");
}

void Ceil::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
//버블5번 쏘면 1번 내려오게 하기
}