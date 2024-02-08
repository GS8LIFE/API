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
	// 800 / 600�� �ʹ� ����.
	// MainWindow.SetWindowScale({1280, 720});

	// �߿��Ѱ� ũ�Ⱑ �ƴ϶� ����
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

	// �������� ��Ģ�� ���Ұų�.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Player_Right.png", 13, 8);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("PlayLevel\\TestFolderAnimation"));

	// ���ν��� ���⼭ �ε��Ҽ��� �ִ�.

	// �츮�� �����ϴ°� Level
	CreateLevel<UTestTitleLevel>("Title");
	CreateLevel<UTestPlayLevel>("Play");
	ChangeLevel("Play");
}

void UContentExCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}
