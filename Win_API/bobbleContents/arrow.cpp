#include "arrow.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
arrow::arrow()
{
}

arrow::~arrow()
{
}
void arrow::BeginPlay()
{
	AActor::BeginPlay();

	//Renderer->SetTransform({ {328,415}, {200, 200} });
	//Renderer->CreateAnimation("idle", "arrow.png", 0, 0, 0.05f, false);
	//Renderer->CreateAnimation("Rmove", "arrow.png", 0, 63, 0.05f, false);
	//Renderer->CreateAnimation("Lmove", "arrow.png", 65, 127, 0.05f, false);
	
	DirRenderer = CreateImageRenderer(RenderOrder::Arrow);
	DirRenderer->SetImage("arrow.png");
	DirRenderer->SetTransform({ {328,410}, FVector{51, 93} *2 });
	


	StateChange(NowState::Idle);
}

void arrow::IdleStart()
{
}

void arrow::RMoveStart()
{
}
void arrow::LMoveStart()
{
}
void arrow::StateChange(NowState _State)
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

void arrow::StateUpdate(float _DeltaTime)
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

void arrow::RMove(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void arrow::LMove(float _DeltaTime)
{
	if (true == UEngineInput::IsFree(VK_LEFT))
	{
		StateChange(NowState::Idle);
		return;
	}
}
void arrow::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsPress(VK_LEFT))
	{
		StateChange(NowState::LMove);
		return;
	}
	if (true == UEngineInput::IsPress(VK_RIGHT))
	{
		StateChange(NowState::Move);
		return;
	}
}



void arrow::setAngle(float* _Angle, float _Value)
{
	*_Angle += _Value;
}
void arrow::Tick(float _DeltaTime) 
{
	AActor::Tick(_DeltaTime);

	//float4 Dir = float4::DegToDir(Angle);

	DirRenderer->SetAngle(Angle);
	if (true == UEngineInput::IsPress(VK_LEFT) && true == UEngineInput::IsPress(VK_RIGHT))
	{
			if (true == UEngineInput::IsPress(VK_LEFT) && Angle >= -80)	
			{
				setAngle(&Angle, -_DeltaTime * 80.0f);
			}
	}
		if (true == UEngineInput::IsPress(VK_LEFT) && Angle >= -80)
		{
			setAngle(&Angle, -_DeltaTime * 80.0f);
		}
		if (true == UEngineInput::IsPress(VK_RIGHT) && Angle <= 80)
		{
			setAngle(&Angle, _DeltaTime * 80.0f);
		}
	



	StateUpdate(_DeltaTime);

}