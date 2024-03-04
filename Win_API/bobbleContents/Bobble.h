#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
#include <EngineBase/EngineRandom.h>

// 설명 :
class Bobble : public AActor, public UEngineRandom, public Enum
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
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	// 상태 주요 업데이트
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// 상태 함수들
	void Idle(float _DeltaTime);
	void wait(float _DeltaTime);
	
	// 상태 시작 함수들
	void IdleStart();
	void waitStart();

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	void AddMoveVector(const FVector& _DirDelta);
	FVector MoveVector = FVector::Zero;
	FVector MoveAcc = FVector::Right * 500.0f;
	float CoolTime = 0.0f;
	int WaitTime = 0;
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;
	char color = '.';
	float AlphaTime = 0.0f;
	bool Dir = false;
	

};

