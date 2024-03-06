#pragma once
#include <EngineCore\Actor.h>
#include "Enums.h"
#include <EngineBase/EngineRandom.h>
#include <EngineBase/EngineMath.h>
#include <cmath>
#include "arrow.h"
#include "Bobble.h"
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
	FVector get_collide_locate()
	{
		return locate;
	}
	void setfireAng(float _Angle)
	{
		FireAng = _Angle;
	}
	void setAngle(float* _Angle, float _Value);
	void setlocate(FVector* _Angle, FVector _Value);

	char get_bubble(std::map<int, std::vector<char>> _map);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// ���� �ֿ� ������Ʈ
	void StateChange(NowState _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void Idle(float _DeltaTime);
	void fire();

	// ���� ���� �Լ���
	void IdleStart();
	void fireStart();

	

	NowState State = NowState::Idle;
	std::string CurAnimationName = "Idle";


private:
	FVector now = FVector::Zero;
	FVector MoveVector = FVector::Zero;
	FVector MoveAcc = FVector::Right * 500.0f;
	UCollision* BodyCollision;
	FVector locate = float4::Zero;
	FVector* locatePtr = &locate;
	UImageRenderer* Renderer = nullptr;
	int count = 0;
	int WaitTime = 0;
	float CoolTime = 0.0f;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;
	char color = '.';
	float AlphaTime = 0.0f;
	bool Dir = false;
	float FireAng = 0.0f;
	float* FireAngPtr = &FireAng;
	float speed = 2;
	void AddMoveVector(const FVector& _DirDelta);

};

