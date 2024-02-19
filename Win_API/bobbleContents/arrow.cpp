#include "arrow.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
arrow::arrow()
{
}

arrow::~arrow()
{
}
void arrow::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::Arrow);
	Renderer->SetImage("arrow.png");
	Renderer->SetTransform({ {328,415}, {200, 200} });
	Renderer->CreateAnimation("idle", "arrow.png", 0, 0, 0.05f, false);
	Renderer->CreateAnimation("Rmove", "arrow.png", 0, 63, 0.05f, false);
	Renderer->CreateAnimation("Lmove", "arrow.png", 65, 127, 0.05f, false);



	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void arrow::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void arrow::RMoveStart()
{
	Renderer->ChangeAnimation("Rmove");
}
void arrow::LMoveStart()
{
	Renderer->ChangeAnimation("Lmove");
}
void arrow::StateChange(NowState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case NowState::Idle:
			IdleStart();
			break;
		case NowState::Move:
			RMoveStart();
			break;
		case NowState::LMove:
			LMoveStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void arrow::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::Move:
		RMove(_DeltaTime);
		break;
	case NowState::LMove:
		LMove(_DeltaTime);
		break;
	default:
		break;
	}


}
void arrow::RMove(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void arrow::LMove(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_LEFT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void arrow::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsPress(VK_LEFT))
	{
		StateChange(NowState::LMove);
		return;
	}
	if (true == UEngineInput::IsPress(VK_RIGHT))
	{
		StateChange(NowState::Move);
		return;
	}
}
void arrow::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}