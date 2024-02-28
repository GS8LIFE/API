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

	Renderer = CreateImageRenderer(RenderOrder::bobble);
	Renderer->SetImage("Bobble.png");
	Renderer->SetTransform({ {300,100}, {72, 72} });
	Renderer->CreateAnimation("idle", "Bobble.png", 1, 1, 0.1f, true);
	Renderer->CreateAnimation("wow", "Bobble.png", 1, 3, 0.2f, true);
	std::map<int, std::vector<char>> map;
	map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
	map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
	map[2] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'R', '.' };
	map[3] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', '/' };
	map[4] = { 'B', 'G', 'G', 'R', 'R', 'Y', 'Y', 'R' };

	// �ʿ� �ִ� ������ ���Ұ��� �޾Ƽ� �ش��ϴ� ���� ä����
	for (int row_idx = 0; row_idx < map.size(); ++row_idx)
	{
		const auto& row = map[row_idx];

		// . Ȥ�� / �̸� �������� �ѱ� (���� �����Ƿ�)
		for (int col_idx = 0; col_idx < row.size(); ++col_idx)
		{
			char col = row[col_idx];
			if (col == '.' || col == '/')
			{
				continue;
			}


			//���� �߰��ϴ� �ڵ�
		}
	}


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
		Renderer->ChangeAnimation("wow");
	}
	if (true == UEngineInput::IsDown('W'))
	{
		Renderer->ChangeAnimation("idle");
	}

}