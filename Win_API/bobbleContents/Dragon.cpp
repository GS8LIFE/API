#include "Dragon.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enums.h"
Dragon::Dragon()
{

}

Dragon::~Dragon()
{
}
void Dragon::BeginPlay()
{
	AActor::BeginPlay();
	
	Renderer = CreateImageRenderer(RenderOrder::dragon);
	Renderer->SetImage("BobbleDragon.png");
	Renderer->SetTransform({ {297,445}, {60, 60} });
	Renderer->CreateAnimation("idle", "BobbleDragon.png", 0, 0, 0.1f, true);
	Renderer->CreateAnimation("wait", "BobbleDragon.png", 0, 2, 0.1f, true);
	Renderer->CreateAnimation("attack", "BobbleDragon.png", 2, 5, 0.1f, false);
	Renderer->CreateAnimation("end", "BobbleDragon.png", 11, 14, 0.1f, true);

	StateChange(NowState::Idle);
}

void Dragon::IdleStart()
{
	Renderer->ChangeAnimation("Idle");
}

void Dragon::waitStart()
{
	Renderer->ChangeAnimation("wait");
}

void Dragon::attackStart()
{
	Renderer->ChangeAnimation("attack");
}

void Dragon::endStart()
{
	Renderer->ChangeAnimation("end");
	BGMPlayer = UEngineSound::SoundPlay("endbgm.mp3");
}
void Dragon::StateChange(NowState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case NowState::Idle:
			IdleStart();
			break;
		case NowState::end:
			endStart();
			break;
		case NowState::Attack:
			attackStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void Dragon::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::Attack:
		Attack(_DeltaTime);
		break;
	case NowState::end:
		end(_DeltaTime);
		break;
	default:
		break;
	}


}
void Dragon::Attack(float _DeltaTime)
{
	if (Endbool == true)
	{
		StateChange(NowState::end);
		return;
	}
	if (true == Renderer->IsCurAnimationEnd())
	{
		Renderer->ChangeAnimation("Idle");
		if (firing == false)
		{
		StateChange(NowState::Idle);
		return;
		}
	}
}

void Dragon::Idle(float _DeltaTime)
{
	if (Endbool == true)
	{
		StateChange(NowState::end);
		return;
	}
	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		StateChange(NowState::Attack);
		return;
	}
}

void Dragon::end(float _DeltaTime)
{
	cooltime += _DeltaTime;

	if (cooltime >= 3.5f)
	{
		StateChange(NowState::Idle);
		nextlevel.nextLevel();
		Endbool = false;
		return;
	}
}
void Dragon::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);
	
}