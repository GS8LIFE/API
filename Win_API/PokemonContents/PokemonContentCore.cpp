#include "PokemonContentCore.h"
#include "PokemonPlayer.h"
#include "TitleLevel.h"

PokemonContentCore::PokemonContentCore()
	: EngineCore()
{
}

PokemonContentCore::~PokemonContentCore()
{
}

// ���ӽ���
void PokemonContentCore::Start()
{
	// "Title Level" + "�� ����ٰ� ������ �����ϴ�";

	//std::string_view _Name = "AAAAA";
	//std::string ErrorText = "�̹� �����ϴ� �̸��� ������ �� ������� �߽��ϴ�" + _Name;
	//MessageBoxA(nullptr, ErrorText.c_str(), "ġ���� ����", MB_OK); 
	//assert(false);

	//std::string ErrorText;
	//ErrorText = std::string("Title Level") + std::string("�� ����ٰ� ������ �����ϴ�");

	CreateLevel<UTitleLevel>("Title");
	// CreateLevel<UTitleLevel>("Title");

	int a = 0;
}

void PokemonContentCore::Update()
{

	int a = 0;
}

void PokemonContentCore::End()
{
	int a = 0;
}