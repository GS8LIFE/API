#include "shooter.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enums.h"
shooter::shooter()
{
}

shooter::~shooter()
{
}
void shooter::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::Shooter);
	Renderer->SetImage("shotting.png");
	Renderer->SetTransform({ {320,422}, {110, 80} });
	Renderer->CreateAnimation("idle", "shotting.png", 0, 0, 0.05f, false);
	Renderer->CreateAnimation("move", "shotting.png", 0, 11, 0.05f, true);



	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void shooter::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void shooter::MoveStart()
{
	Renderer->ChangeAnimation("move");
}
void shooter::StateChange(NowState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case NowState::Idle:
			IdleStart();
			break;
		case NowState::Move:
			MoveStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void shooter::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::Move:
		Move(_DeltaTime);
		break;
	default:
		break;
	}


}
void shooter::Move(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_RIGHT) && true == UEngineInput::IsFree(VK_LEFT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void shooter::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsPress(VK_RIGHT) || true == UEngineInput::IsPress(VK_LEFT))
	{
		StateChange(NowState::Move);
		return;
	}
}
void shooter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}