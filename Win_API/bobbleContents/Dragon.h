#pragma once
#include <EngineCore\Actor.h>

// Ό³Έν :
class Dragon : public AActor
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

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

};

