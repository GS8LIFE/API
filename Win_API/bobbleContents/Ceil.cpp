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
	Renderer->SetTransform({ {318,35}, {260, 805} });
	Renderer->CreateAnimation("idle", "Ceil.png", 0, 0, 0.05f, false);

	Renderer->ChangeAnimation("idle");

	BodyCollision = CreateCollision(ColliderOrder::Ceil);
	BodyCollision->SetTransform({ {318,collide}, {260, 700} });
	BodyCollision->SetScale({ 500, collide });
	BodyCollision->SetColType(ECollisionType::Rect);
}

void Ceil::Tick(float _DeltaTime)
{
	if (CellCount == 5)
	{
		std::string str;
		str = "down";
		downCount++;
		str = str + std::to_string(downCount);
		BodyCollision->AddScale({ 0.0f,64.0f });
		ceilH++;
		Renderer->CreateAnimation(str, "Ceil.png", ceilH, ceilH, 0.05f, false);
		Renderer->ChangeAnimation(str);
		CellCount = 0;
		return;
	}
//버블5번 쏘면 1번 내려오게 하기
}