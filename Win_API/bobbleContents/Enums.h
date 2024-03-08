#pragma once
#include <iostream>
#include <map>
#include <vector>
class Enums 
{
public:
	float* AnglePtr = &Angle;
	std::map<int, std::vector<char>> nowmap;

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