#pragma once
#include <EngineCore\EngineCore.h>

// Ό³Έν :
class bobbleCore : public UEngineCore
{
public:
	// constrcuter destructer
	bobbleCore();
	~bobbleCore();

	// delete Function
	bobbleCore(const bobbleCore& _Other) = delete;
	bobbleCore(bobbleCore&& _Other) noexcept = delete;
	bobbleCore& operator=(const bobbleCore& _Other) = delete;
	bobbleCore& operator=(bobbleCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

