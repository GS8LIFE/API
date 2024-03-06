#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// ���� :
class Dragon2 : public AActor , public Enums
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

	FVector MoveVector;
};

