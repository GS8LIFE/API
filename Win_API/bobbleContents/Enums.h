#pragma once
#include <iostream>
#include <map>
#include <vector>
class helper
{
public:
	float* AnglePtr = &Angle;

	std::map<int, std::vector<char>> nowmap;
	std::map<int, std::vector<char>>* nowmapPtr;
	void setnowmap(std::map<int, std::vector<char>>* _mapPtr)
	{
		nowmapPtr = new std::map<int, std::vector<char>>(*_mapPtr);
		nowmap = *nowmapPtr;
	}
protected:
	float Angle = 0.0f;
};

enum class ColliderOrder
{
	bobble,
	firebobble,
	Ceil
};

enum class NowState
{
	None,
	Idle,
	Attack,
	wait,
	Move,
	LMove,
	fire
};
enum RenderOrder
{
	Map,
	border,
	Shooter,
	Arrow,
	wheel,
	dragon,
	bobble,
	others,
	Title
};


enum movie
{
	zero,
	one,
	two,
	three,
	four,
	five,
	six,
	seveen,
	selectEnum
};