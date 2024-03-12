#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
// ���� :
class Dragon : public AActor, public helper
{
public:
	// constrcuter destructer
	Dragon();
	~Dragon();

	// delete Function
	Dragon(const Dragon& _Other) = delete;
	Dragon(Dragon&& _Other) noexcept = delete;
	Dragon& operator=(const Dragon& _Other) = delete;
	Dragon& operator=(Dragon&& _Other) noexcept = delete;

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

