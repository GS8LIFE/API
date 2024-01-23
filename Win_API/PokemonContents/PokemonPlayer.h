#pragma once
// Ό³Έν :
class PokemonPlayer
{
public:
	// constrcuter destructer
	PokemonPlayer();
	~PokemonPlayer();

	// delete Function
	PokemonPlayer(const PokemonPlayer& _Other) = delete;
	PokemonPlayer(PokemonPlayer&& _Other) noexcept = delete;
	PokemonPlayer& operator=(const PokemonPlayer& _Other) = delete;
	PokemonPlayer& operator=(PokemonPlayer&& _Other) noexcept = delete;

protected:

private:

};

