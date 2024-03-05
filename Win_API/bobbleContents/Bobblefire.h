#pragma once
#include <EngineCore\Actor.h>
#include "Enum.h"
#include <EngineBase/EngineRandom.h>
#include <EngineBase/EngineMath.h>
#include <cmath>
#include "arrow.h"

// ���� :
class Bobblefire :public UEngineRandom, public arrow , public UEngineMath
{
public:
	// constrcuter destructer
	Bobblefire();
	~Bobblefire();
	
	// delete Function
	Bobblefire(const Bobblefire& _Other) = delete;
	Bobblefire(Bobblefire&& _Other) noexcept = delete;
	Bobblefire& operator=(const Bobblefire& _Other) = delete;
	Bobblefire& operator=(Bobblefire&& _Other) noexcept = delete;
	void get_bubble(char _color);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void setAngle(float* _Angle, float _Value);

	// ���� �ֿ� ������Ʈ
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void Idle(float _DeltaTime);
	void fire(float _DeltaTime);

	// ���� ���� �Լ���
	void IdleStart();
	void fireStart();

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";

private:
	void AddMoveVector(const FVector& _DirDelta);
	FVector now = FVector::Zero;
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
	float FireAng = 0.0f;


};

