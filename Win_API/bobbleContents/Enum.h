#pragma once
class Enum
{
public:
	float* AnglePtr = &Angle;
protected:
	float Angle = 0.0f;
};



enum class NowState
{
	None,
	Idle,
	Attack,
	wait,
	Move,
	LMove,
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