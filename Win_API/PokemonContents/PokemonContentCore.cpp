#include "PokemonContentCore.h"
#include "PokemonPlayer.h"
#include "TitleLevel.h"
#include "PlayLevel.h"

PokemonContentCore::PokemonContentCore()
	: EngineCore()
{
}

PokemonContentCore::~PokemonContentCore()
{
}

// 게임시작
void PokemonContentCore::BeginPlay()
{
	// "Title Level" + "을 만들다가 에러가 났습니다";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void PokemonContentCore::Tick(float _DeltaTime)
{
	// 플레이어 움직여야 한다.
}

void PokemonContentCore::End()
{
}