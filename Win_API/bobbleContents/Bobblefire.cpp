#include "Bobblefire.h"
#include <vector>
#include "EnginePlatform/EngineInput.h"
#include <EngineBase\EngineDebug.h>
#include "Enums.h"

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
	Renderer->SetScale({ 72,72 });
	Renderer->CreateAnimation("S", "Bobble.png", 0, 0, 0.1f, true);
	Renderer->CreateAnimation("Y", "Bobble.png", 25, 25, 0.2f, true);
	Renderer->CreateAnimation("R", "Bobble.png", 49, 49, 0.2f, true);
	Renderer->CreateAnimation("G", "Bobble.png", 73, 73, 0.2f, true);
	Renderer->CreateAnimation("P", "Bobble.png", 98, 98, 0.2f, true);
	Renderer->CreateAnimation("O", "Bobble.png", 123, 123, 0.2f, true);
	Renderer->CreateAnimation("B", "Bobble.png", 148, 148, 0.2f, true);
	Renderer->CreateAnimation("W", "Bobble.png", 173, 173, 0.2f, true);

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
	FireAng = Angle;
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
	if (now.X > 104 || now.X < -120) // -120 좌측 104 우측
	{
 		if (FireAng > 0) // 180도
		{
			FireAng = 180 - FireAng;
		}
		else
		{
			UEngineDebug::OutPutDebugText("튕기는 각도가 음수로 떨어졌습니다.");
		}
	}
	if (now.Y < -345) //천장까지 거리
	{
		now.Y = 0;
	}
	if (FireAng < 0)
	{
		MovePos.X += 1 * cos(FireAng * DToR) * -1;
		MovePos.Y += 1 * sin(FireAng * DToR);
		now.X -= MovePos.X;
		now.Y += MovePos.Y;
	}
	else
	{
		MovePos.X += 1 * cos(FireAng * DToR);
		MovePos.Y += 1 * sin(FireAng * DToR) * -1;
		now.X += MovePos.X;
		now.Y += MovePos.Y;
	}
	AddActorLocation(MovePos);
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

	if (true == UEngineInput::IsDown('Q'))
	{
		FireAng = FireAng;
	}
	AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);

}
