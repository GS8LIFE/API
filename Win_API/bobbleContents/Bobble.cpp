#include "Bobble.h"
#include <vector>
#include "EnginePlatform/EngineInput.h"
#include <EngineBase\EngineDebug.h>
#include "Enums.h"
Bobble::Bobble()
{

}
Bobble::~Bobble()
{

}
void Bobble::AddMoveVector(const FVector& _DirDelta)
{
	MoveVector += _DirDelta * MoveAcc;
}
void Bobble::BeginPlay()
{
	AActor::BeginPlay();
	Renderer = CreateImageRenderer(RenderOrder::bobble);
	Renderer->SetImage("Bobble.png");
	Renderer->SetTransform({ {0,0}, {72, 72} });
	Renderer->CreateAnimation("S", "Bobble.png", 1, 1, 0.1f, true);
	Renderer->CreateAnimation("Y", "Bobble.png", 26, 26, 0.2f, true);
	Renderer->CreateAnimation("R", "Bobble.png", 50, 50, 0.2f, true);
	Renderer->CreateAnimation("G", "Bobble.png", 74, 74, 0.2f, true);
	Renderer->CreateAnimation("P", "Bobble.png", 99, 99, 0.2f, true);
	Renderer->CreateAnimation("O", "Bobble.png", 124, 124, 0.2f, true);
	Renderer->CreateAnimation("B", "Bobble.png", 149, 149, 0.2f, true);
	Renderer->CreateAnimation("W", "Bobble.png", 174, 174, 0.2f, true);

	Renderer->CreateAnimation("Smove", "Bobble.png", 1, 3, 0.2f, true);
	Renderer->CreateAnimation("Ymove", "Bobble.png", 26, 28, 0.2f, true);
	Renderer->CreateAnimation("Rmove", "Bobble.png", 50, 51, 0.2f, true);
	Renderer->CreateAnimation("Gmove", "Bobble.png", 74, 76, 0.2f, true);
	Renderer->CreateAnimation("Pmove", "Bobble.png", 99, 101, 0.2f, true);
	Renderer->CreateAnimation("Omove", "Bobble.png", 124, 126, 0.2f, true);
	Renderer->CreateAnimation("Bmove", "Bobble.png", 149, 151, 0.2f, true);
	Renderer->CreateAnimation("Wmove", "Bobble.png", 174, 176, 0.2f, true);
	StateChange(NowState::Idle);
}
void Bobble::get_bubble(char _color)
{
	color = _color;
	switch (color)
	{
	case 'S':
		Renderer->ChangeAnimation("S");
		break;
	case 'R':
		Renderer->ChangeAnimation("R");
		break;
	case 'P':
		Renderer->ChangeAnimation("P");
		break;
	case 'B':
		Renderer->ChangeAnimation("B");
		break;
	case 'Y':
		Renderer->ChangeAnimation("Y");
		break;
	case 'G':
		Renderer->ChangeAnimation("G");
		break;
	case 'O':
		Renderer->ChangeAnimation("O");
		break;
	case 'W':
		Renderer->ChangeAnimation("W");
		break;
	default:
		break;
	}
	WaitTime = RandomInt(1, 10);
}

void Bobble::IdleStart()
{
	switch (color)
	{
	case 'S':
		Renderer->ChangeAnimation("S");
		break;
	case 'R':
		Renderer->ChangeAnimation("R");
		break;
	case 'P':
		Renderer->ChangeAnimation("P");
		break;
	case 'B':
		Renderer->ChangeAnimation("B");
		break;
	case 'Y':
		Renderer->ChangeAnimation("Y");
		break;
	case 'G':
		Renderer->ChangeAnimation("G");
		break;
	case 'O':
		Renderer->ChangeAnimation("O");
		break;
	case 'W':
		Renderer->ChangeAnimation("W");
		break;
	default:
		break;
	}
}

void Bobble::waitStart()
{
		switch (color)
		{
		case 'S':
			Renderer->ChangeAnimation("Smove");
			break;
		case 'R':
			Renderer->ChangeAnimation("Rmove");
			break;
		case 'P':
			Renderer->ChangeAnimation("Pmove");
			break;
		case 'B':
			Renderer->ChangeAnimation("Bmove");
			break;
		case 'Y':
			Renderer->ChangeAnimation("Ymove");
			break;
		case 'G':
			Renderer->ChangeAnimation("Gmove");
			break;
		case 'O':
			Renderer->ChangeAnimation("Omove");
			break;
		case 'W':
			Renderer->ChangeAnimation("Wmove");
			break;
		default:
			break;
		}
}

void Bobble::StateChange(NowState _State)
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
		default:
			break;
		}
	}
	State = _State;
}

void Bobble::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::wait:
		wait(_DeltaTime);
		break;
	default:
		break;
	}
}
void Bobble::wait(float _DeltaTime)
{
	CoolTime += _DeltaTime;
	if (CoolTime >= 1.4)
	{
		StateChange(NowState::Idle);
		CoolTime = 0;
		WaitTime = RandomInt(1, 10);
		return;
	}

}

void Bobble::Idle(float _DeltaTime)
{
	CoolTime += _DeltaTime;
	if (WaitTime <= CoolTime)
	{
		StateChange(NowState::wait);
		CoolTime = 0;
		return;
	}
}
void Bobble::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}	

}
