#pragma once

enum class NowState
{
	None,
	Idle,
	Attack,
	wait,
	Move,
};
enum RenderOrder
{
	Map,
	Monster,
	Player,
	Title
};