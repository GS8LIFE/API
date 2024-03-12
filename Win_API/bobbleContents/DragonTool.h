#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// 설명 :
class DragonTool : public AActor, public helper
{
public:
	// constrcuter destructer
	DragonTool();
	~DragonTool();

	// delete Function
	DragonTool(const DragonTool& _Other) = delete;
	DragonTool(DragonTool&& _Other) noexcept = delete;
	DragonTool& operator=(const DragonTool& _Other) = delete;
	DragonTool& operator=(DragonTool&& _Other) noexcept = delete;

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
	void AttackStart();

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

