#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// ���� :
class arrow : public AActor , public Enum
{
public:
	// constrcuter destructer
	arrow();
	~arrow();

	// delete Function
	arrow(const arrow& _Other) = delete;
	arrow(arrow&& _Other) noexcept = delete;
	arrow& operator=(const arrow& _Other) = delete;
	arrow& operator=(arrow&& _Other) noexcept = delete;

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
	UImageRenderer* DirRenderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

