#pragma once
#include <EngineCore\Level.h>
#include <EngineCore/Actor.h>
#include "Enums.h"
#include <EnginePlatform/EngineInput.h>
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool cur_bobble = false;
	bool fire = false;
private:
	arrow* Arrow = nullptr;

};

