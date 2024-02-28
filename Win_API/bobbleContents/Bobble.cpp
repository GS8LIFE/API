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
void Bobble::BeginPlay()
{
	AActor::BeginPlay();
	
		UImageRenderer* Renderer = CreateImageRenderer(RenderOrder::bobble);
		Renderer->SetImage("Bobble.png");
		Renderer->SetTransform({ {0,0}, {72, 72} });
		Renderer->CreateAnimation("idle", "Bobble.png", 1, 1, 0.1f, true);
		Renderer->CreateAnimation("R", "Bobble.png", 11, 12, 0.2f, true);



	// 맵에 있는 백터의 원소값을 받아서 해당하는 색을 채워줌



}


void Bobble::get_bubble(char _color)
{
	
	switch (_color)
	{
	case 'S':
		break;
	case 'R':
		
		break;
	case 'P':
		break;
	case 'B':
		break;
	case 'Y':
		break;
	case 'G':
		break;
	case 'O':
		break;
	case 'W':
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