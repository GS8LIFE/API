#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform\EngineSound.h>
// Ό³Έν :
class TitleLevel : public ULevel
{
public:
	// constrcuter destructer
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UEngineSoundPlayer BGMPlayer;
};

