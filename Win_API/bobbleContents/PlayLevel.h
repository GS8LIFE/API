#pragma once
#include <EngineCore\Level.h>
#include <EngineCore/Actor.h>
#include "Enums.h"
#include <EnginePlatform/EngineInput.h>
#include "Bobblefire.h"
#include "Bobble.h"
#include <EnginePlatform\EngineSound.h>
// 설명 :
class arrow;
class PlayLevel : public ULevel , public AActor , public helper 
{
public:
	// constrcuter destructer
	
	PlayLevel();
	~PlayLevel();
	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;
	
	void set_collide_locate(FVector _collideLocate)
	{
		collideLocate = _collideLocate;
	}
	void all_down();
	void set_map_vector();
	void fire_bobble();
	void fired_bobble();
	void nextLevel();
	void PreLevel();
	// 버블 방문 함수
	void visit(int _row, int _col, char _Color);
	void visit(int _row, int _col);  //천장에 달려있는 버블을 위한 visit
	void remove_visited_bubbles();
	void remove_not_visited_bubbles();
	void remove_hanging_bubbles();
	void remove_bobble(int _row,int _col,char _Color);

	//버블에게 맵에 있는 버블 업데이트
	std::map<int, std::vector<char>>* getnowmap()
	{
		return &map;
	}
	std::map<int, std::vector<char>> getmap();

	int check_x(int _x,int _y);
	void mapLevel();
protected:
	char next = '.';
	bool cur_bobble = false;
	bool fire = false;
	bool all_down_switch = false;
	static bool DownLevel;
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	//static

private:
	int nowlevel = 0;
	int x = 0;
	int y = 0;
	char now;

	std::map<std::pair<int, int>, std::vector<Bobble*>> nowbobble;
	std::vector<std::pair<int, int>> visited;
	std::map<int, std::vector<char>> map;
	arrow* Arrow = nullptr;
	Bobblefire* firebobble = nullptr; 
	Bobble* bobblePtr = nullptr;
	Bobble* nextbobble = nullptr;
	FVector collideLocate = FVector::Zero - FVector{ 0.0f, 0.0f, 0.0f, 0.0f };

	UEngineSoundPlayer BGMPlayer;
	UEngineSoundPlayer powPlayer;
	UEngineSoundPlayer shootPlayer;
	UEngineSoundPlayer hangpowPlayer;
	UEngineSoundPlayer downPlayer;

};

