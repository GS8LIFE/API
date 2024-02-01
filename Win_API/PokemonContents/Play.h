#pragma once
#include <EngineCore\Level.h>

// Ό³Έν :
class Play : public ULevel
{
public:
	// constrcuter destructer
	Play();
	~Play();

	// delete Function
	Play(const Play& _Other) = delete;
	Play(Play&& _Other) noexcept = delete;
	Play& operator=(const Play& _Other) = delete;
	Play& operator=(Play&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

