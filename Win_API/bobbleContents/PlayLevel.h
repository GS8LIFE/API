#pragma once
#include <EngineCore\Level.h>

// ���� :
class PlayLevel : public ULevel
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();
	void fire_bobble();
	void fired_bobble();
	void AddMoveVector(const FVector& _DirDelta);
	FVector MoveVector = FVector::Zero;
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

};

