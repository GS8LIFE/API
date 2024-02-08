#include "TestPlayLevel.h"
#include "TestPlayer.h"
#include <EngineCore\EngineCore.h>

UTestPlayLevel::UTestPlayLevel() 
{
}

UTestPlayLevel::~UTestPlayLevel() 
{
}

void UTestPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		FVector WindowScale = GEngine->MainWindow.GetWindowScale();

		// ���⼭ ��ġ�� ���������ٰ� �̳༮��ġ�� 0,0�ΰ� �ƴ���
		AActor* Back = SpawnActor<AActor>();
		UImageRenderer* Renderer = Back->CreateImageRenderer();
		Renderer->SetOrder(-10);
		// 
		Renderer->SetAlpha(100);
		Renderer->SetImage("Title.png");
		Renderer->SetPosition(WindowScale.Half2D());
		Renderer->SetScale(WindowScale);
		Renderer->SetImageCuttingTransform({ { 0, 0 }, {100, 100} });
	}

	ATestPlayer* Player = SpawnActor<ATestPlayer>();
	Player->SetActorLocation({200, 200});

}

void UTestPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}