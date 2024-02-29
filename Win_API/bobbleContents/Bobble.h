#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
// ���� :
class Bobble : public AActor
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

