#include "PlayLevel.h"
#include "Dragon.h"
#include "DragonTool.h"
#include "Dragon2.h"
#include "Dragon2Tool.h"
#include "Ceil.h"
#include "shooter.h"
#include "arrow.h"
#include <EngineCore\EngineCore.h>
#include "Enum.h"
int a = 270;
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
		Renderer1->SetPosition({317,286});
		Renderer1->SetScale({320,548});

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
}

void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown('Q'))
	{
		
	
}