#pragma once
#include <iostream>
#include <map>
#include <vector>

class helper
{
public:
	float* AnglePtr = &Angle;

	std::map<int, std::vector<char>> nowmap;
	void setnowmap(std::map<int, std::vector<char>>* _mapPtr)
	{
	}

	void setLevel(int _level)
	{
		Level = _level;
	}

	int getLevel()
	{
		return Level;
	}
protected:
	static int Level;
	static int CellCount;
	static int downCount;
	static bool firing;
	static bool stageclear;
	static bool DownLevel;
	static bool End;
	int* LevelPtr = &Level;
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
	fire,
	wave
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
	Scores,
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