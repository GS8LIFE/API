#include "ContentExCore.h"
#include "TestTitleLevel.h"
#include "TestPlayLevel.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

UContentExCore::UContentExCore() 
{
}

UContentExCore::~UContentExCore() 
{
}

void UContentExCore::BeginPlay()
{
	// 800 / 600은 너무 작죠.
	// MainWindow.SetWindowScale({1280, 720});

	// 중요한건 크기가 아니라 비율
	//MainWindow.SetWindowPosition({500, 100});
	MainWindow.SetWindowScale({ 720/* * 1.5f*/, 900/* * 1.5f*/ });

	UEngineCore::BeginPlay();

	// D:\Project\GM\WIn\App
	UEngineDirectory NewDir;

	// D:\Project\GM\WIn
	NewDir.MoveParent();

	// D:\Project\GM\WIn\ContentsResources
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// 엔진만의 규칙을 정할거냐.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Player_Right.png", 13, 8);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("PlayLevel\\TestFolderAnimation"));

	// 리로스를 여기서 로드할수도 있다.

	// 우리가 제공하는건 Level
	CreateLevel<UTestTitleLevel>("Title");
	CreateLevel<UTestPlayLevel>("Play");
	ChangeLevel("Play");
}

void UContentExCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}
