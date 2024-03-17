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
	static int score;
	static int Level;
	static int CellCount;
	static int downCount;
	static bool firing;
	static bool stageclear;
	static bool DownLevel;
	static bool Endbool;
	static bool gameover;

	static int Score1value;
	static int Score2value;
	static int Score3value;
	static int Score4value;
	static int Score5value;
	static int Score6value;
	static int Score7value;
	static int Score8value;
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
	start,
	Move,
	LMove,
	fire,
	wave,
	end
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