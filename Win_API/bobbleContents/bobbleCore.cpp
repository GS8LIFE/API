#include "bobbleContents/bobbleCore.h"
#include "PlayLevel.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

bobbleCore::bobbleCore()
{
}

bobbleCore::~bobbleCore()
{
}

void bobbleCore::BeginPlay()
{
	MainWindow.SetWindowScale({ 700, 1000 });

	UEngineCore::BeginPlay();


	UEngineDirectory NewDir;
	NewDir.MoveParent();
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("BobbleDragon.png", 8, 6);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("Dragon"));

	UEngineResourcesManager::GetInst().CuttingImage("map.png", 1, 9);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("map"));

	UEngineResourcesManager::GetInst().CuttingImage("border.png", 1, 10);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("border"));

	UEngineResourcesManager::GetInst().CuttingImage("shotting.png", 4, 3);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("shotting"));

	UEngineResourcesManager::GetInst().CuttingImage("ceil.png", 12, 10);
	UEngineResourcesManager::GetInst().LoadFolder(NewDir.AppendPath("ceil"));

	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");
}

void bobbleCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}
