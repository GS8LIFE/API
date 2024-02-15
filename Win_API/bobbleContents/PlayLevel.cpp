#include "PlayLevel.h"
#include "Dragon.h"
#include "Dragon2.h"
#include "Dragon2Tool.h"
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

		AActor* ceil = SpawnActor<AActor>();
		UImageRenderer* Renderer3 = ceil->CreateImageRenderer();
		Renderer3->SetAlpha(100);
		Renderer3->SetImage("ceil.png");
		Renderer3->CreateAnimation("Idle", "ceil.png", 0, 11, 1.0f, false);
		Renderer3->SetPosition({ 350,70 });//↓
		Renderer3->SetScale({ 300,1700 }); //발사대 위치와 크기
	}

	Dragon* Player = SpawnActor<Dragon>();
	Dragon2* Player2 = SpawnActor<Dragon2>();
	Dragon2Tool* Dragon2T = SpawnActor<Dragon2Tool>();
}

void PlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown('Q'))
	{

	}
}