#pragma once
#include <EngineCore\Level.h>

// Ό³Έν :
class UTestPlayLevel : public ULevel
{
public:
	// constrcuter destructer
	UTestPlayLevel();
	~UTestPlayLevel();

	// delete Function
	UTestPlayLevel(const UTestPlayLevel& _Other) = delete;
	UTestPlayLevel(UTestPlayLevel&& _Other) noexcept = delete;
	UTestPlayLevel& operator=(const UTestPlayLevel& _Other) = delete;
	UTestPlayLevel& operator=(UTestPlayLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

