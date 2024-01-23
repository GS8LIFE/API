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
	void EngineStart() override;
	void EngineUpdate() override;
	void EngineEnd() override;

private:

};