#include "PlayLevel.h"
#include "Ceil.h"
#include <EngineCore\EngineCore.h>

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		FVector WindowScale = GEngine->MainWindow.GetWindowScale();

		AActor* Back = SpawnActor<AActor>();
		UImageRenderer* Renderer = Back->CreateImageRenderer();
		Renderer->SetOrder(-10);
		Renderer->SetAlpha(100);
		Renderer->SetImage("map.png");
		Renderer->SetPosition(WindowScale.Half2D());
		Renderer->SetScale(WindowScale);

		AActor* borderline = SpawnActor<AActor>();
		UImageRenderer* Renderer1 = borderline->CreateImageRenderer();
		Renderer1->SetOrder(-8);
		Renderer1->SetAlpha(100);
		Renderer1->SetImage("border.png");
		Renderer1->SetPosition({348,592});//↓
		Renderer1->SetScale({350,1134}); //border의 위치와 크기

		AActor* shotting = SpawnActor<AActor>();
		UImageRenderer* Renderer2 = shotting->CreateImageRenderer();
		Renderer2->SetOrder(-3);
		Renderer2->SetAlpha(100);
		Renderer2->SetImage("shotting.png");
		Renderer2->SetPosition({ 350,920 });//↓
		Renderer2->SetScale({ 150,100 }); //발사대 위치와 크기

	}

	Ceil* Player = SpawnActor<Ceil>();

}

void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (EngineInput::IsDown('Q'))
	{

	}
}