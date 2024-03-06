#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// ���� :
class Dragon2Tool : public AActor
{
public:
	// constrcuter destructer
	Dragon2Tool();
	~Dragon2Tool();

	// delete Function
	Dragon2Tool(const Dragon2Tool& _Other) = delete;
	Dragon2Tool(Dragon2Tool&& _Other) noexcept = delete;
	Dragon2Tool& operator=(const Dragon2Tool& _Other) = delete;
	Dragon2Tool& operator=(Dragon2Tool&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// ���� �ֿ� ������Ʈ
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void Idle(float _DeltaTime);
	void RMove(float _DeltaTime);
	void LMove(float _DeltaTime);

	// ���� ���� �Լ���
	void IdleStart();
	void RMoveStart();
	void LMoveStart();

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

