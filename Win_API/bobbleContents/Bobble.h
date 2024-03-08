#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
#include <EngineBase/EngineRandom.h>
#include "PlayLevel.h"

// 설명 :
class Bobble : public AActor, public UEngineRandom, public Enums
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
	void setmap(std::map<int, std::vector<char>> _map);
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
	UCollision* BodyCollision;
	UImageRenderer* Renderer = nullptr;
	FVector MoveVector = FVector::Zero;
	FVector MoveAcc = FVector::Right * 500.0f;
	std::map<int, std::vector<char>> map;
	float CoolTime = 0.0f;
	int WaitTime = 0;
	float AnimationTime = 0.0f;
	void AddMoveVector(const FVector& _DirDelta);
	int AnimationFrame = 0;
	char color = '.';
	float AlphaTime = 0.0f;
	bool Dir = false;
	

};

