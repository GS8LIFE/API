#include "MovieSeen.h"
#include <EngineCore\EngineCore.h>
MovieSeen::MovieSeen()
{
}

MovieSeen::~MovieSeen()
{
}

void MovieSeen::BeginPlay()
{
	AActor::BeginPlay();
	FVector WindowScale = GEngine->MainWindow.GetWindowScale();
	Renderer = CreateImageRenderer(RenderOrder::Title);

	Renderer->SetImage("Title1.png");
	Renderer->SetPosition(WindowScale.Half2D());
	Renderer->SetScale(WindowScale);
	Renderer->CreateAnimation("zero", "Title1.png", 0, 0, 0.03f, false);
	Renderer->CreateAnimation("1", "Title1.png", 0, 100, 0.03f, false);
	Renderer->CreateAnimation("2", "Title2.png", 0, 99, 0.03f, false);
	Renderer->CreateAnimation("3", "Title3.png", 0, 99, 0.03f, false);
	Renderer->CreateAnimation("4", "Title4.png", 0, 99, 0.03f, false);
	Renderer->CreateAnimation("5", "Title5.png", 0, 99, 0.03f, false);
	Renderer->CreateAnimation("6", "Title6.png", 0, 99, 0.03f, false);
	Renderer->CreateAnimation("7", "Title7.png", 0, 66, 0.03f, false);
	Renderer->CreateAnimation("select", "Title_select.png", 0, 129, 0.03f, true);

	Renderer->ChangeAnimation("1");
	StateChange(movie::one);
}

void MovieSeen::zeroStart()
{
	Renderer->ChangeAnimation("zero");
}
void MovieSeen::OneStart()
{
	Renderer->ChangeAnimation("1");
}
void MovieSeen::twostart()
{
	Renderer->ChangeAnimation("2");
}
void MovieSeen::threestart()
{
	Renderer->ChangeAnimation("3");
}
void MovieSeen::fourstart()
{
	Renderer->ChangeAnimation("4");
}
void MovieSeen::fivestart()
{
	Renderer->ChangeAnimation("5");
}
void MovieSeen::sixstart()
{
	Renderer->ChangeAnimation("6");
}
void MovieSeen::sevenstart()
{
	Renderer->ChangeAnimation("7");
}
void MovieSeen::selectstart()
{
	Renderer->ChangeAnimation("select");
}
void MovieSeen::StateChange(movie _State)
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

void MovieSeen::StateUpdate(float _DeltaTime)
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
void MovieSeen::zero(float _DeltaTime)
{
	if (
		UEngineInput::IsDown(VK_SPACE)
		)
	{

		StateChange(movie::one);
		return;
	}
}
void MovieSeen::one(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::two);
		return;
	}
}
void MovieSeen::two(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::three);
		return;
	}
}
void MovieSeen::three(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::four);
		return;
	}
}
void MovieSeen::four(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::five);
		return;
	}
}
void MovieSeen::five(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::six);
		return;
	}
}
void MovieSeen::six(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::seveen);
		return;
	}
}
void MovieSeen::seven(float _DeltaTime)
{
	if (
		Renderer->IsCurAnimationEnd()
		)
	{

		StateChange(movie::selectEnum);
		return;
	}
}
void MovieSeen::select(float _DeltaTime)
{
	if (
		true == Renderer->IsCurAnimationEnd()
		)
	{

	}
}
void MovieSeen::Tick(float _DeltaTime)
{
	if (UEngineInput::IsDown('R'))
	{
		StateChange(movie::zero);
	}
	StateUpdate(_DeltaTime);
}