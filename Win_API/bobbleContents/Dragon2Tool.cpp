#include "Dragon2Tool.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enums.h"
Dragon2Tool::Dragon2Tool()
{
}

Dragon2Tool::~Dragon2Tool()
{
}
void Dragon2Tool::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::wheel);
	Renderer->SetImage("Dragon2Tool.png");
	Renderer->SetTransform({ {375,445}, {40, 40} });
	Renderer->CreateAnimation("idle", "Dragon2Tool.png", 0, 0, 0.05f, false);
	Renderer->CreateAnimation("Rmove", "Dragon2Tool.png", 0, 7, 0.05f, true);
	Renderer->CreateAnimation("Lmove", "Dragon2Tool_Left.png", 0, 7, 0.05f, true);



	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void Dragon2Tool::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void Dragon2Tool::RMoveStart()
{
	Renderer->ChangeAnimation("Rmove");
}
void Dragon2Tool::LMoveStart()
{
	Renderer->ChangeAnimation("Lmove");
}
void Dragon2Tool::StateChange(NowState _State)
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

void Dragon2Tool::StateUpdate(float _DeltaTime)
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
void Dragon2Tool::RMove(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void Dragon2Tool::LMove(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_LEFT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void Dragon2Tool::Idle(float _DeltaTime)
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
void Dragon2Tool::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}