#pragma once
#include <EngineCore\Actor.h>

// Ό³Έν :
class ATestPlayer : public AActor
{
public:
	// constrcuter destructer
	ATestPlayer();
	~ATestPlayer();

	// delete Function
	ATestPlayer(const ATestPlayer& _Other) = delete;
	ATestPlayer(ATestPlayer&& _Other) noexcept = delete;
	ATestPlayer& operator=(const ATestPlayer& _Other) = delete;
	ATestPlayer& operator=(ATestPlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

