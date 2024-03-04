#include "Bobblefire.h"
#include <vector>
#include "EnginePlatform/EngineInput.h"
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
Bobblefire::Bobblefire()
{

}
Bobblefire::~Bobblefire()
{

}
void Bobblefire::AddMoveVector(const FVector& _DirDelta)
{
	MoveVector += _DirDelta * MoveAcc;
}
void Bobblefire::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(RenderOrder::bobble);
	Renderer->SetImage("Bobble.png");
	Renderer->SetTransform({ {0,0}, {72, 72} });
	Renderer->CreateAnimation("S", "Bobble.png", 0, 0, 0.1f, true);
	Renderer->CreateAnimation("Y", "Bobble.png", 25, 25, 0.2f, true);
	Renderer->CreateAnimation("R", "Bobble.png", 49, 49, 0.2f, true);
	Renderer->CreateAnimation("G", "Bobble.png", 73, 73, 0.2f, true);
	Renderer->CreateAnimation("P", "Bobble.png", 98, 98, 0.2f, true);
	Renderer->CreateAnimation("O", "Bobble.png", 123, 123, 0.2f, true);
	Renderer->CreateAnimation("B", "Bobble.png", 148, 148, 0.2f, true);
	Renderer->CreateAnimation("W", "Bobble.png", 173, 173, 0.2f, true);

	Renderer->SetAngle(Angle);
	StateChange(NowState::Idle);
}
void Bobblefire::get_bubble(char _color)
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

void Bobblefire::IdleStart()
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

void Bobblefire::fireStart()
{
	fireAngle = Angle;
}

void Bobblefire::StateChange(NowState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case NowState::Idle:
			IdleStart();
			break;
		case NowState::fire:
			fireStart();
			break;
		default:
			break;
		}
	}
	State = _State;
}

void Bobblefire::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case NowState::Idle:
		Idle(_DeltaTime);
		break;
	case NowState::fire:
		fire(_DeltaTime);
		break;
	default:
		break;
	}
}
void Bobblefire::fire(float _DeltaTime)
{


	FVector MovePos = FVector::Zero;
	MovePos.X = 5 * cos(fireAngle * PI / 180);
	MovePos.Y = 5 * sin(fireAngle * PI / 180);

}

void Bobblefire::Idle(float _DeltaTime)
{
	CoolTime += _DeltaTime;
	if (UEngineInput::IsDown(VK_SPACE))
	{
		StateChange(NowState::fire);
		return;
	}
}
void Bobblefire::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);
	if (UEngineInput::IsPress(VK_SPACE))
	{
		fire(_DeltaTime);
	}
}
