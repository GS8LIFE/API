#pragma once
#include <EngineCore/Level.h>
#include <EngineCore\Actor.h>
#include "Enums.h"
// ���� :
class MovieSeen : public AActor
{
public:
	// constrcuter destructer
	MovieSeen();
	~MovieSeen();

	// delete Function
	MovieSeen(const MovieSeen& _Other) = delete;
	MovieSeen(MovieSeen&& _Other) noexcept = delete;
	MovieSeen& operator=(const MovieSeen& _Other) = delete;
	MovieSeen& operator=(MovieSeen&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// ���� �ֿ� ������Ʈ
	void StateChange(movie _State);
	void StateUpdate(float _DeltaTime);

	// ���� �Լ���
	void zero(float _DeltaTime);
	void one(float _DeltaTime);
	void two(float _DeltaTime);
	void three(float _DeltaTime);
	void four(float _DeltaTime);
	void five(float _DeltaTime);
	void six(float _DeltaTime);
	void seven(float _DeltaTime);
	void select(float _DeltaTime);
	// ���� ���� �Լ���
	void zeroStart();
	void OneStart();
	void twostart();
	void threestart();
	void fourstart();
	void fivestart();
	void sixstart();
	void sevenstart();
	void selectstart();
	movie State = movie::one;
	std::string CurAnimationName = "one";



private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

