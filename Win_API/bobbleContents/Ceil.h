#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// Ό³Έν :
class Ceil : public AActor, public helper
{
public:
	// constrcuter destructer
	Ceil();
	~Ceil();
	int hello = 770;
	// delete Function
	Ceil(const Ceil& _Other) = delete;
	Ceil(Ceil&& _Other) noexcept = delete;
	Ceil& operator=(const Ceil& _Other) = delete;
	Ceil& operator=(Ceil&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	int ceilH = 0;
	int collide = 32;
	int High = 35;
	float AlphaTime = 0.0f;
	bool Dir = false;
};

