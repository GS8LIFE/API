#pragma once
#include <EngineCore\EngineCore.h>

// Ό³Έν :
class PokemonContents : public UEngineCore
{
public:
	// constrcuter destructer
	PokemonContents();
	~PokemonContents();

	// delete Function
	PokemonContents(const PokemonContents& _Other) = delete;
	PokemonContents(PokemonContents&& _Other) noexcept = delete;
	PokemonContents& operator=(const PokemonContents& _Other) = delete;
	PokemonContents& operator=(PokemonContents&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

