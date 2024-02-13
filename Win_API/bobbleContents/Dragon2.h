#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// 설명 :
class Dragon2 : public AActor
{
public:
	// constrcuter destructer
	Dragon2();
	~Dragon2();

	// delete Function
	Dragon2(const Dragon2& _Other) = delete;
	Dragon2(Dragon2&& _Other) noexcept = delete;
	Dragon2& operator=(const Dragon2& _Other) = delete;
	Dragon2& operator=(Dragon2&& _Other) noexcept = delete;

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

