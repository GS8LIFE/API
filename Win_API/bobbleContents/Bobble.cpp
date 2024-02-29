#include "Bobble.h"
#include <vector>
#include "EnginePlatform/EngineInput.h"
#include <EngineBase\EngineDebug.h>
#include "Enum.h"
Bobble::Bobble()
{

}
Bobble::~Bobble()
{

}



void Bobble::get_bubble(char _color)
{
	UImageRenderer* Renderer = CreateImageRenderer(RenderOrder::bobble);
	Renderer->SetImage("Bobble.png");
	Renderer->SetTransform({ {0,0}, {72, 72} });
	Renderer->CreateAnimation("S", "Bobble.png", 1, 1, 0.1f, true);
	Renderer->CreateAnimation("Y", "Bobble.png", 26, 26, 0.2f, true);
	Renderer->CreateAnimation("R", "Bobble.png", 51, 51, 0.2f, true);
	Renderer->CreateAnimation("G", "Bobble.png", 76, 76, 0.2f, true);
	Renderer->CreateAnimation("P", "Bobble.png", 101, 101, 0.2f, true);
	Renderer->CreateAnimation("O", "Bobble.png", 126, 126, 0.2f, true);
	Renderer->CreateAnimation("B", "Bobble.png", 151, 151, 0.2f, true);
	Renderer->CreateAnimation("W", "Bobble.png", 176, 176, 0.2f, true);
	switch (_color)
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

int main()
{

}

void Bobble::Tick(float _DeltaTime)
{
	if (true == UEngineInput::IsDown('Q'))
	{
	}
	if (true == UEngineInput::IsDown('W'))
	{

	}

}