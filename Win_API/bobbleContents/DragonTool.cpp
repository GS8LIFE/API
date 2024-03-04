#include "DragonTool.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
DragonTool::DragonTool()
{
}

DragonTool::~DragonTool()
{
}
void DragonTool::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(wheel);
	Renderer->SetImage("DragonTool.png");
	Renderer->SetTransform({ {325,427}, {60, 60} });
	Renderer->CreateAnimation("idle", "DragonTool.png", 0, 0, 0.05f, false);
	Renderer->CreateAnimation("Attack", "DragonTool.png", 0, 3, 0.1f, true);



	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void DragonTool::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}
void DragonTool::AttackStart()
{
	Renderer->ChangeAnimation("Attack");
}
void DragonTool::StateChange(NowState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case NowState::Idle:
			IdleStart();
			break;
		case NowState::Attack:
			AttackStart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void DragonTool::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::Attack:
		Attack(_DeltaTime);
		break;
	default:
		break;
	}


}
void DragonTool::Attack(float _DeltaTime)
{
	if (true == Renderer->IsCurAnimationEnd())
	{
		StateChange(NowState::Idle);
		return;
	}
}
void DragonTool::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsPress(VK_SPACE))
	{
		StateChange(NowState::Attack);
		return;
	}
}
void DragonTool::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}