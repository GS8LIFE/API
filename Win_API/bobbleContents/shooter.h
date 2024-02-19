#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// ���� :
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

	// ���� �ֿ� ������Ʈ
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);

	// ���� ���� �Լ���
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

