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
	Score1->SetPosition({ 100,20 });
	Score1->SetScale({ 18,18 });

	Score2 = CreateImageRenderer(RenderOrder::Scores);
	Score2->SetImage("Score.png");
	Score2->SetPosition({ 116,20 });  //16씩 옮겨야 붙음
	Score2->SetScale({ 18,18 });

	Score3 = CreateImageRenderer(RenderOrder::Scores);
	Score3->SetImage("Score.png");
	Score3->SetPosition({ 136,20 });
	Score3->SetScale({ 18,18 });

	Score4 = CreateImageRenderer(RenderOrder::Scores);
	Score4->SetImage("Score.png");
	Score4->SetPosition({ 100,20 });
	Score4->SetScale({ 18,18 });

	Score5 = CreateImageRenderer(RenderOrder::Scores);
	Score5->SetImage("Score.png");
	Score5->SetPosition({ 100,20 });
	Score5->SetScale({ 18,18 });

	Score6 = CreateImageRenderer(RenderOrder::Scores);
	Score6->SetImage("Score.png");
	Score6->SetPosition({ 100,20 });
	Score6->SetScale({ 18,18 });

	Score7 = CreateImageRenderer(RenderOrder::Scores);
	Score7->SetImage("Score.png");
	Score7->SetPosition({ 100,20 });
	Score7->SetScale({ 18,18 });

	Score8 = CreateImageRenderer(RenderOrder::Scores);
	Score8->SetImage("Score.png");
	Score8->SetPosition({ 100,20 });
	Score8->SetScale({ 18,18 });
}



void Score::Tick(float _DeltaTime) {


	ULevel::Tick(_DeltaTime);
}



