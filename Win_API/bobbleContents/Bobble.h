#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// 설명 :
class Bobble : public AActor
{
public:
	// constrcuter destructer
	Bobble();
	~Bobble();

	// delete Function
	Bobble(const Bobble& _Other) = delete;
	Bobble(Bobble&& _Other) noexcept = delete;
	Bobble& operator=(const Bobble& _Other) = delete;
	Bobble& operator=(Bobble&& _Other) noexcept = delete;
	void get_bubble(char _color);
protected:
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

