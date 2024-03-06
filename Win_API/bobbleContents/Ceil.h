#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// Ό³Έν :
class Ceil : public AActor
{
public:
	// constrcuter destructer
	Ceil();
	~Ceil();

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
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

