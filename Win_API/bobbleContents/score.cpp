#include "Score.h"
#include "Dragon.h"
#include "DragonTool.h"
#include "Dragon2.h"
#include "Dragon2Tool.h"
#include "Ceil.h"
#include "shooter.h"
#include "arrow.h"
#include "Bobble.h"
#include "Bobblefire.h"
#include <EngineCore\EngineCore.h>





Score::Score()
{

}

Score::~Score()
{

}

void Score::BeginPlay()
{
	AActor::BeginPlay();

	
	Score1 = CreateImageRenderer(RenderOrder::Scores);
	Score1->SetImage("Score.png");
	Score1->SetPosition({ 317,286 });
	Score1->SetScale({ 16,16 });

	Score2 = CreateImageRenderer(RenderOrder::Scores);
	Score2->SetImage("Score.png");
	Score2->SetPosition({ 317,286 });
	Score2->SetScale({ 16,16 });

	Score3 = CreateImageRenderer(RenderOrder::Scores);
	Score3->SetImage("Score.png");
	Score3->SetPosition({ 317,286 });
	Score3->SetScale({ 16,16 });

	Score4 = CreateImageRenderer(RenderOrder::Scores);
	Score4->SetImage("Score.png");
	Score4->SetPosition({ 317,286 });
	Score4->SetScale({ 16,16 });

	Score5 = CreateImageRenderer(RenderOrder::Scores);
	Score5->SetImage("Score.png");
	Score5->SetPosition({ 317,286 });
	Score5->SetScale({ 16,16 });

	Score6 = CreateImageRenderer(RenderOrder::Scores);
	Score6->SetImage("Score.png");
	Score6->SetPosition({ 317,286 });
	Score6->SetScale({ 16,16 });

	Score7 = CreateImageRenderer(RenderOrder::Scores);
	Score7->SetImage("Score.png");
	Score7->SetPosition({ 317,286 });
	Score7->SetScale({ 16,16 });

	Score8 = CreateImageRenderer(RenderOrder::Scores);
	Score8->SetImage("Score.png");
	Score8->SetPosition({ 317,286 });
	Score8->SetScale({ 16,16 });
}



void Score::Tick(float _DeltaTime) {


	ULevel::Tick(_DeltaTime);
}



