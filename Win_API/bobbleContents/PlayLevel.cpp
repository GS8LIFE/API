#include "PlayLevel.h"
#include "Dragon.h"
#include "DragonTool.h"
#include "Dragon2.h"
#include "Dragon2Tool.h"
#include "Ceil.h"
#include "shooter.h"
#include "arrow.h"
#include "Bobble.h"
#include <EngineCore\EngineCore.h>
#include "Enum.h"
PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::BeginPlay()
{
	ULevel::BeginPlay();


	FVector WindowScale = GEngine->MainWindow.GetWindowScale();

	AActor* Back = SpawnActor<AActor>();
	UImageRenderer* Renderer = Back->CreateImageRenderer(RenderOrder::Map);
	Renderer->SetImage("map.png");
	Renderer->SetPosition(WindowScale.Half2D());
	Renderer->SetScale(WindowScale);

	AActor* borderline = SpawnActor<AActor>();
	UImageRenderer* Renderer1 = borderline->CreateImageRenderer(RenderOrder::Map);
	Renderer1->SetImage("border.png");
	Renderer1->SetPosition({ 317,286 });
	Renderer1->SetScale({ 320,548 });

	AActor* bar = SpawnActor<AActor>();
	UImageRenderer* Renderer3 = bar->CreateImageRenderer(RenderOrder::Map);
	Renderer3->SetAlpha(100);
	Renderer3->SetImage("bar.png");
	Renderer3->SetTransform({ {325,400}, {272, 60} });

	arrow* Arrow = SpawnActor<arrow>();
	shooter* Shooter = SpawnActor<shooter>();
	Ceil* ceiling = SpawnActor<Ceil>();
	Dragon* Player = SpawnActor<Dragon>();
	Dragon2* Player2 = SpawnActor<Dragon2>();
	Dragon2Tool* Dragon2T = SpawnActor<Dragon2Tool>();
	DragonTool* Dragon1T = SpawnActor<DragonTool>();

	std::map<int, std::vector<char>> map;
	map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
	map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
	map[2] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'R', '.' };
	map[3] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', '/' };
	map[4] = { 'B', 'G', 'G', 'R', 'R', 'Y', 'Y', 'R' };

	for (int row_idx = 0; row_idx < map.size(); ++row_idx)
	{
		const auto& row = map[row_idx];

		// . 혹은 / 이면 다음으로 넘김 (색이 없으므로)
		for (int col_idx = 0; col_idx < row.size(); ++col_idx)
		{
			char col = row[col_idx];
			if (col == '.' || col == '/')
			{
				continue;
			}
			
			if (row_idx % 2 == 1)
			{
				Bobble* NewB = SpawnActor<Bobble>();
				NewB->SetActorLocation({ 221 + (32 * col_idx), 65 + (32 * row_idx) });
			}
			else
			{
				Bobble* NewB = SpawnActor<Bobble>();
				NewB->SetActorLocation({ 205 + (32 * col_idx), 65 + (32 * row_idx) });
			}

			//버블 추가하는 코드
		}
	}
}

	void PlayLevel::Tick(float _DeltaTime) {
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown('Q'))
	{
	}	
}