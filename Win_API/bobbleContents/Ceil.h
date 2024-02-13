#pragma once
#include <EngineCore\Actor.h>

// Ό³Έν :
class ceil : public AActor
{
public:
	// constrcuter destructer
	ceil();
	~ceil();

	// delete Function
	ceil(const ceil& _Other) = delete;
	ceil(ceil&& _Other) noexcept = delete;
	ceil& operator=(const ceil& _Other) = delete;
	ceil& operator=(ceil&& _Other) noexcept = delete;

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

