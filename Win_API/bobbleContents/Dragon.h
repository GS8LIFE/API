#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// 설명 :
class Dragon : public AActor, public helper
{
public:
	// constrcuter destructer
	Dragon();
	~Dragon();

	// delete Function
	Dragon(const Dragon& _Other) = delete;
	Dragon(Dragon&& _Other) noexcept = delete;
	Dragon& operator=(const Dragon& _Other) = delete;
	Dragon& operator=(Dragon&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// 상태 주요 업데이트
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// 상태 함수들
	void Idle(float _DeltaTime);
	void Attack(float _DeltaTime);

	// 상태 시작 함수들
	void IdleStart();
	void waitStart();
	void attackStart();

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

