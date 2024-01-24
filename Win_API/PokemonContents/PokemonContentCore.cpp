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

// ���ӽ���
void PokemonContentCore::BeginPlay()
{
	// "Title Level" + "�� ����ٰ� ������ �����ϴ�";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void PokemonContentCore::Tick(float _DeltaTime)
{
	// �÷��̾� �������� �Ѵ�.
}

void PokemonContentCore::End()
{
}