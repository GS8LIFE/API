#include "Dragon2Tool.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
Dragon2Tool::Dragon2Tool()
{
}

Dragon2Tool::~Dragon2Tool()
{
}
void Dragon2Tool::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(1);
	Renderer->SetImage("Dragon2Tool.png");
	Renderer->SetTransform({ {430,945}, {60, 60} });
	Renderer->CreateAnimation("idle", "Dragon2Tool.png", 0, 0, 0.1f, false);
	Renderer->CreateAnimation("move", "Dragon2Tool.png", 0, 7, 1.0f, true);



	Renderer->ChangeAnimation("idle");
	StateChange(NowState::Idle);
}

void Dragon2Tool::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void Dragon2Tool::MoveStart()
{
	Renderer->ChangeAnimation("move");
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
			MoveStart();
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
		Move(_DeltaTime);
		break;
	default:
		break;
	}


}
void Dragon2Tool::Move(float _DeltaTime)
{
	{

	}
	if (true == UEngineInput::IsFree(VK_RIGHT))
	{

		StateChange(NowState::Idle);
		return;
	}


}

void Dragon2Tool::Idle(float _DeltaTime)
{


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