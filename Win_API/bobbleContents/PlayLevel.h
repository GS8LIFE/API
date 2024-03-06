#pragma once
#include <EngineCore\Level.h>
#include <EngineCore/Actor.h>
#include "Enums.h"
#include <EnginePlatform/EngineInput.h>
#include "Bobblefire.h"
#include "Bobble.h"
// Ό³Έν :
class arrow;
class PlayLevel : public ULevel , public AActor , public Enums
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();
	void fire_bobble();
	void fired_bobble();
	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;
	void set_collide_locate(FVector _collideLocate)
	{
		collideLocate = _collideLocate;
	}

	void set_map_vector();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool cur_bobble = false;
	bool fire = false;
	char next = '.';
private:
	int x = 0;
	int y = 0;
	bool firing = false;
	char now;
	std::map<int, std::vector<char>> map;
	arrow* Arrow = nullptr;
	Bobblefire* firebobble = nullptr;
	Bobble* nextbobble = nullptr;
	FVector collideLocate = FVector::Zero - FVector{ 0.0f, 0.0f, 0.0f, 0.0f };
};

