#include "Dragon2.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
#include "arrow.h"
Dragon2::Dragon2()
{
}

Dragon2::~Dragon2()
{
}
void Dragon2::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::dragon);
	Renderer->SetImage("BobbleDragon.png");
	Renderer->SetTransform({ {385,445}, {60, 60} });
	Renderer->CreateAnimation("idle", "BobbleDragon.png", 23, 23, 0.3f, false);
	Renderer->CreateAnimation("wait", "BobbleDragon.png", 0, 2, 0.3f, true);
	Renderer->CreateAnimation("attack", "BobbleDragon.png", 27, 28, 0.3f, true);
	Renderer->CreateAnimation("Rmove", "BobbleDragon.png", 29, 36, 0.05f, true);
	Renderer->CreateAnimation("Lmove", "BobbleDragon.png", 43, 50, 0.05f, true);


	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void Dragon2::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void Dragon2::RMoveStart()
{
	Renderer->ChangeAnimation("Rmove");
}

void Dragon2::LMoveStart()
{
	Renderer->ChangeAnimation("Lmove");
}
void Dragon2::StateChange(NowState _State)
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

void Dragon2::StateUpdate(float _DeltaTime)
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

void Dragon2::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsPress(VK_LEFT) && true == UEngineInput::IsPress(VK_RIGHT))
	{
			if (true == UEngineInput::IsPress(VK_LEFT) && Angle >= -90)
			{
				StateChange(NowState::LMove);
				return;
			}
	}
	if (true == UEngineInput::IsPress(VK_LEFT) && Angle >= -90)
	{
		StateChange(NowState::LMove);
		return;
	}
	if (true == UEngineInput::IsPress(VK_RIGHT) && Angle <= 90)
	{
		StateChange(NowState::Move);
		return;
	}
}

void Dragon2::LMove(float _DeltaTime)
{
	if (Angle >= -90)
	{
		if (true == UEngineInput::IsFree(VK_LEFT))
		{
			StateChange(NowState::Idle);
			return;
		}
	}
	else if (Angle <= -90)
	{
		StateChange(NowState::Idle);
		return;
	}
}
void Dragon2::RMove(float _DeltaTime)
{
	if (Angle <= 90) {
		if (true == UEngineInput::IsFree(VK_RIGHT))
		{
			StateChange(NowState::Idle);
			return;
		}
	}
	else if(Angle >=90)
	{
		StateChange(NowState::Idle);
		return;
	}

}
void Dragon2::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);

}
