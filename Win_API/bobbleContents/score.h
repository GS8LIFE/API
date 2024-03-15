#pragma once
#include <EngineCore\Level.h>
#include <EngineCore/Actor.h>
#include "Enums.h"
#include <EnginePlatform/EngineInput.h>
#include "Bobblefire.h"
#include "Bobble.h"
#include <EnginePlatform\EngineSound.h>
// Ό³Έν :
class arrow;
class Score : public ULevel, public AActor, public helper
{
public:
	// constrcuter destructer

	Score();
	~Score();
	// delete Function
	Score(const Score& _Other) = delete;
	Score(Score&& _Other) noexcept = delete;
	Score& operator=(const Score& _Other) = delete;
	Score& operator=(Score&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	//static

private:

	UImageRenderer* Score1 = nullptr;
	UImageRenderer* Score2 = nullptr;
	UImageRenderer* Score3 = nullptr;
	UImageRenderer* Score4 = nullptr;
	UImageRenderer* Score5 = nullptr;
	UImageRenderer* Score6 = nullptr;
	UImageRenderer* Score7 = nullptr;
	UImageRenderer* Score8 = nullptr;

};

