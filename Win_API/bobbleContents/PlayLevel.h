#pragma once
#include <EngineCore\Level.h>
#include <EngineCore/Actor.h>
#include "Enums.h"
#include <EnginePlatform/EngineInput.h>
#include "Bobblefire.h"
#include "Bobble.h"
// Ό³Έν :
class arrow;
class PlayLevel : public ULevel , public AActor , public helper
{
public:
	// constrcuter destructer
	
	PlayLevel();
	~PlayLevel();
	void fire_bobble();
	void fired_bobble();
	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;
	void set_collide_locate(FVector _collideLocate)
	{
		collideLocate = _collideLocate;
	}
	void remove_bobble(int _row,int _col,char _Color);
	void visit(int _row, int _col, char _Color);
	void remove_visited_bubbles();
//	void remove_hanging_bubbles();
	void set_map_vector();

	std::map<int, std::vector<char>>* getnowmap()
	{
		return &map;
	}
	int check_x(int _x,int _y);
	std::map<int, std::vector<char>> getmap();

	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool cur_bobble = false;
	bool fire = false;
	char next = '.';
private:
	int x = 0;
	int y = 0;
	bool firing = false;
	char now;
	int CellCount = 0;
	std::vector<std::pair<int, int>> visited;
	std::map<int, std::vector<char>> map;
	std::map<int, std::vector<char>>* mapPtr;
	std::map<std::pair<int, int>, std::vector<Bobble*>> nowbobble;
	arrow* Arrow = nullptr;
	Bobblefire* firebobble = nullptr; 
	Bobble* bobblePtr = nullptr;
	Bobble* nextbobble = nullptr;
	FVector collideLocate = FVector::Zero - FVector{ 0.0f, 0.0f, 0.0f, 0.0f };
};

