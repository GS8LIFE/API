#include "PokemonContents/PokemonContentsCore.h"
#include "TestTitleLevel.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

PokemonContents::PokemonContents() 
{
}

PokemonContents::~PokemonContents() 
{
}

void PokemonContents::BeginPlay()
{
	// 800 / 600은 너무 작죠.
	// MainWindow.SetWindowScale({1280, 720});

	// 중요한건 크기가 아니라 비율
	MainWindow.SetWindowScale({ 1280/* * 1.5f*/, 720/* * 1.5f*/ });

	UEngineCore::BeginPlay();

	// D:\Project\GM\WIn\App
	UEngineDirectory NewDir;

	// D:\Project\GM\WIn
	NewDir.MoveParent();

	// D:\Project\GM\WIn\ContentsResources
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({".png", ".bmp"}, true);

	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	// 리로스를 여기서 로드할수도 있다.

	// 우리가 제공하는건 Level
	CreateLevel<UTestTitleLevel>("Title");
	ChangeLevel("Title");
}

void PokemonContents::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}
