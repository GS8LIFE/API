#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// 설명 :
class Title : public AActor
{
public:
	// constrcuter destructer
	Title();
	~Title();

	// delete Function
	Title(const Title& _Other) = delete;
	Title(Title&& _Other) noexcept = delete;
	Title& operator=(const Title& _Other) = delete;
	Title& operator=(Title&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// 상태 주요 업데이트
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// 상태 함수들
	void Idle(float _DeltaTime);
	void Attack(float _DeltaTime);
	void Move(float _DeltaTime);
	// 상태 시작 함수들
	void IdleStart();
	void waitStart();
	void attackStart();
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

