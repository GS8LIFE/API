#include "Dragon2.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
Dragon2::Dragon2()
{
}

Dragon2::~Dragon2()
{
}
void Dragon2::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::Player);
	Renderer->SetImage("BobbleDragon.png");
	Renderer->SetTransform({ {450,940}, {100, 100} });
	Renderer->CreateAnimation("idle", "BobbleDragon.png", 23, 23, 0.1f, false);
	Renderer->CreateAnimation("wait", "BobbleDragon.png", 0, 2, 0.1f, true);
	Renderer->CreateAnimation("attack", "BobbleDragon.png", 27, 28, 1.0f, true);
	Renderer->CreateAnimation("move", "BobbleDragon.png", 29, 36, 1.0f, true);


	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void Dragon2::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void Dragon2::waitStart()
{
	Renderer->ChangeAnimation("wait");
}

void Dragon2::attackStart()
{
	Renderer->ChangeAnimation("attack");
}

void Dragon2::MoveStart()
{
	Renderer->ChangeAnimation("move");
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
		case NowState::wait:
			waitStart();
			break;
		case NowState::Attack:
			attackStart();
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

void Dragon2::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::Attack:
		Attack(_DeltaTime);
		break;
	case NowState::Move:
		Move(_DeltaTime);
		break;
	default:
		break;
	}


}
void Dragon2::Attack(float _DeltaTime)
{
	{

	}
	if (true == UEngineInput::IsFree(VK_SPACE))
	{
		
		StateChange(NowState::Idle);
		return;
	}


}
void Dragon2::Move(float _DeltaTime)
{
	{

	}
	if (true == UEngineInput::IsFree(VK_RIGHT))
	{

		StateChange(NowState::Idle);
		return;
	}


}
void Dragon2::Idle(float _DeltaTime)
{


	if (true == UEngineInput::IsPress(VK_SPACE))
	{
		StateChange(NowState::Attack);
		return;
	}

	if (true == UEngineInput::IsPress(VK_RIGHT))
	{

		StateChange(NowState::Move);
		return;
	}
}
void Dragon2::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}