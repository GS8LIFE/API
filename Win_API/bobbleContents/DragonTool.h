#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// ���� :
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

	// ���� �ֿ� ������Ʈ
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void Idle(float _DeltaTime);
	void Attack(float _DeltaTime);

	// ���� ���� �Լ���
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

