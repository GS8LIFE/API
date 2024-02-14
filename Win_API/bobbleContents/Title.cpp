#include "Title.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
Title::Title()
{
}

Title::~Title()
{
}
void Title::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::Player);
	Renderer->SetImage("Title.png");
	Renderer->SetTransform({ {450,940}, {100, 100} });
	Renderer->CreateAnimation("Animation", "Title.png", 0, 667, 0.1f, false);
	Renderer->CreateAnimation("select", "Title.png", 29, 36, 1.0f, true);


	Renderer->ChangeAnimation("Animation");
}

void Title::IdleStart()
{
	Renderer->ChangeAnimation("idle");
}

void Title::waitStart()
{
	Renderer->ChangeAnimation("wait");
}

void Title::attackStart()
{
	Renderer->ChangeAnimation("attack");
}

void Title::MoveStart()
{
	Renderer->ChangeAnimation("move");
}

void Title::StateChange(NowState _State)
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

void Title::StateUpdate(float _DeltaTime)
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
void Title::Attack(float _DeltaTime)
{
	{

	}
	if (true == UEngineInput::IsFree(VK_SPACE))
	{

		StateChange(NowState::Idle);
		return;
	}


}
void Title::Move(float _DeltaTime)
{
	{

	}
	if (true == UEngineInput::IsFree(VK_RIGHT))
	{

		StateChange(NowState::Idle);
		return;
	}


}
void Title::Idle(float _DeltaTime)
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
void Title::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}