#include "TitleLevel.h"
#include <EngineCore\EngineCore.h>
#include "MovieSeen.h"
#include "PlayLevel.h"
TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	BGMPlayer = UEngineSound::SoundPlay("Title.mp3");
	MovieSeen* Movie = SpawnActor<MovieSeen>();
}
void TitleLevel::Tick(float _DeltaTime)
{
	if (UEngineInput::IsDown('P'))
	{
		GEngine->CreateLevel<PlayLevel>("Level1");
		GEngine->ChangeLevel("Level1");
		GEngine->DestroyLevel("Title");
		
	}
}