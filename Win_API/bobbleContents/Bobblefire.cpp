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
	Renderer->CreateAnimation("R", "Bobble.png", 50, 50, 0.2f, true);
	Renderer->CreateAnimation("G", "Bobble.png", 73, 73, 0.2f, true);
	Renderer->CreateAnimation("P", "Bobble.png", 98, 98, 0.2f, true);
	Renderer->CreateAnimation("O", "Bobble.png", 123, 123, 0.2f, true);
	Renderer->CreateAnimation("B", "Bobble.png", 148, 148, 0.2f, true);
	Renderer->CreateAnimation("W", "Bobble.png", 173, 173, 0.2f, true);

	//발사 버블 충돌 체크
	BodyCollision = CreateCollision(ColliderOrder::firebobble);
	BodyCollision->SetScale({ 32, 32 });
	BodyCollision->SetColType(ECollisionType::CirCle);
	
	StateChange(NowState::Idle);
}

char Bobblefire::get_bubble(std::map<int, std::vector<char>> _map)
{
	std::vector<char> colors;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			char bobbleColor = _map[i][j];
			if (bobbleColor != '.' && bobbleColor != '/')
			{
				colors.push_back(bobbleColor);
			}
		}
	}
	int choice = RandomInt(0, colors.size()-1);
  	return colors[choice];
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
void Bobblefire::setAngle(float* _Ptr, float _ang)
{
	*_Ptr = 90-_ang;
}
void Bobblefire::fireStart()
{
	setAngle(FireAngPtr, FireAng);
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
		fire();
		break;
	default:
		break;
	}
}
void Bobblefire::fire()
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
			MovePos.X += speed * cos(FireAng * DToR) * -1;
			MovePos.Y += speed * sin(FireAng * DToR);
			now.X -= MovePos.X;
			now.Y += MovePos.Y;
		}
		else
		{
			MovePos.X += speed * cos(FireAng * DToR);
			MovePos.Y += speed * sin(FireAng * DToR) * -1;
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
	std::vector<UCollision*> Result;
	if (true == BodyCollision->CollisionCheck(ColliderOrder::bobble, Result))
	{
		// 이런식으로 상대를 사용할수 있다.
		UCollision* Collision = Result[0];
		AActor* Ptr = Collision->GetOwner();
		Bobble* bobble = dynamic_cast<Bobble*>(Ptr);

		if (nullptr == bobble)
		{
			MsgBoxAssert("터져야겠지....");
		}

		Destroy();
	}
	AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);

}
