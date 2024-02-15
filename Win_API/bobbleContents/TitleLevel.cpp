#include "TitleLevel.h"
#include <EngineCore\EngineCore.h>
TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::BeginPlay()
{
	AActor* Title = SpawnActor<AActor>();
	ULevel::BeginPlay();
	
		FVector WindowScale = GEngine->MainWindow.GetWindowScale();
		UImageRenderer* Renderer = Title -> CreateImageRenderer(5);
		Renderer->SetImage("Title1.png");
		Renderer->SetPosition(WindowScale.Half2D());
		Renderer->SetScale(WindowScale);
		Renderer->CreateAnimation("zero", "Title1.png", 0, 0, 0.05f, false);
		Renderer->CreateAnimation("1", "Title1.png", 0, 100, 0.05f, false);
		Renderer->CreateAnimation("2", "Title2.png", 0, 99, 0.05f, false);
		Renderer->CreateAnimation("3", "Title3.png", 0, 99, 0.05f, false);
		Renderer->CreateAnimation("4", "Title4.png", 0, 99, 0.05f, false);
		Renderer->CreateAnimation("5", "Title5.png", 0, 99, 0.05f, false);
		Renderer->CreateAnimation("6", "Title6.png", 0, 99, 0.05f, false);
		Renderer->CreateAnimation("7", "Title7.png", 0, 99, 0.05f, false);
		Renderer->CreateAnimation("select", "Title_select.png", 0, 129, 0.1f, true);

		Renderer->ChangeAnimation("1");
		StateChange(movie::one);
}

void TitleLevel::zeroStart()
{
	Renderer->ChangeAnimation("zero");
}
void TitleLevel::OneStart()
{
	Renderer->ChangeAnimation("1");
}
void TitleLevel::twostart()
{
	Renderer->ChangeAnimation("2");
}
void TitleLevel::threestart()
{
	Renderer->ChangeAnimation("3");
}
void TitleLevel::fourstart()
{
	Renderer->ChangeAnimation("4");
}
void TitleLevel::fivestart()
{
	Renderer->ChangeAnimation("5");
}
void TitleLevel::sixstart()
{
	Renderer->ChangeAnimation("6");
}
void TitleLevel::sevenstart()
{
	Renderer->ChangeAnimation("7");
}
void TitleLevel::selectstart()
{
	Renderer->ChangeAnimation("select");
}
void TitleLevel::StateChange(movie _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case movie::zero:
			zeroStart();
			break;
		case movie::one:
			OneStart();
			break;
		case movie::two:
			twostart();
			break;
		case movie::three:
			threestart();
			break;
		case movie::four:
			fourstart();
			break;
		case movie::five:
			fivestart();
			break;
		case movie::six:
			sixstart();
			break;
		case movie::seveen:
			sevenstart();
			break;
		case movie::selectEnum:
			selectstart();
			break;
		default:
			break;
		}
	}

	State = _State;


}

void TitleLevel::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case movie::zero:
		zero(_DeltaTime);
		break;
	case movie::one:
		one(_DeltaTime);
		break;
	case movie::two:
		two(_DeltaTime);
		break;
	case movie::three:
		three(_DeltaTime);
		break;
	case movie::four:
		four(_DeltaTime);
		break;
	case movie::five:
		five(_DeltaTime);
		break;
	case movie::six:
		six(_DeltaTime);
		break;
	case movie::seveen:
		seven(_DeltaTime);
		break;
	case movie::selectEnum:
		select(_DeltaTime);
		break;
	default:
		break;
	}


}
void TitleLevel::zero(float _DeltaTime)
{
	if (
		UEngineInput::IsDown(VK_SPACE)
		)
	{

		StateChange(movie::one);
		return;
	}
}
void TitleLevel::one(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::two);
		return;
	}
}
void TitleLevel::two(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::three);
		return;
	}
}
void TitleLevel::three(float _DeltaTime)
{
	if ( 
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::four);
		return;
	}
}
void TitleLevel::four(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::five);
		return;
	}
}
void TitleLevel::five(float _DeltaTime)
{
	if ( 
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::six);
		return;
	}
}
void TitleLevel::six(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::seveen);
		return;
	}
}
void TitleLevel::seven(float _DeltaTime)
{
	if ( 
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::selectEnum);
		return;
	}
}
void TitleLevel::select(float _DeltaTime)
{
	if (
		true == Renderer->IsCurAnimationEnd()
		)
	{

	}
}
void TitleLevel::Tick(float _DeltaTime)
{
	if (UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("Play");
	}
	StateUpdate(_DeltaTime);
}