#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// 설명 :
class shooter : public AActor
{
public:
	// constrcuter destructer
	shooter();
	~shooter();

	// delete Function
	shooter(const shooter& _Other) = delete;
	shooter(shooter&& _Other) noexcept = delete;
	shooter& operator=(const shooter& _Other) = delete;
	shooter& operator=(shooter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// 상태 주요 업데이트
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// 상태 함수들
	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);

	// 상태 시작 함수들
	void IdleStart();
	void MoveStart();

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

