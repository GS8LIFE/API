#pragma once
#include <EngineCore\EngineCore.h>
class PokemonContentCore : public EngineCore
{
public:
	// constrcuter destructer
	PokemonContentCore();
	~PokemonContentCore();

	// delete Function
	PokemonContentCore(const PokemonContentCore& _Other) = delete;
	PokemonContentCore(PokemonContentCore&& _Other) noexcept = delete;
	PokemonContentCore& operator=(const PokemonContentCore& _Other) = delete;
	PokemonContentCore& operator=(PokemonContentCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

private:

};
