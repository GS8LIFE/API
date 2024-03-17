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
	Score1->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score1->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score1->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score1->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score1->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score1->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score1->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score1->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score1->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score1->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score2 = CreateImageRenderer(RenderOrder::Scores);
	Score2->SetImage("Score.png");
	Score2->SetPosition({ 116,20 });  //16씩 옮겨야 붙음
	Score2->SetScale({ 18,18 });
	Score2->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score2->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score2->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score2->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score2->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score2->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score2->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score2->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score2->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score2->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score3 = CreateImageRenderer(RenderOrder::Scores);
	Score3->SetImage("Score.png");
	Score3->SetPosition({ 132,20 });
	Score3->SetScale({ 18,18 });
	Score3->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score3->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score3->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score3->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score3->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score3->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score3->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score3->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score3->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score3->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score4 = CreateImageRenderer(RenderOrder::Scores);
	Score4->SetImage("Score.png");
	Score4->SetPosition({ 148,20 });
	Score4->SetScale({ 18,18 });
	Score4->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score4->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score4->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score4->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score4->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score4->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score4->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score4->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score4->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score4->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score5 = CreateImageRenderer(RenderOrder::Scores);
	Score5->SetImage("Score.png");
	Score5->SetPosition({ 164,20 });
	Score5->SetScale({ 18,18 });
	Score5->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score5->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score5->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score5->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score5->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score5->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score5->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score5->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score5->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score5->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score6 = CreateImageRenderer(RenderOrder::Scores);
	Score6->SetImage("Score.png");
	Score6->SetPosition({ 180,20 });
	Score6->SetScale({ 18,18 });
	Score6->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score6->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score6->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score6->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score6->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score6->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score6->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score6->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score6->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score6->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score7 = CreateImageRenderer(RenderOrder::Scores);
	Score7->SetImage("Score.png");
	Score7->SetPosition({ 196,20 });
	Score7->SetScale({ 18,18 });
	Score7->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score7->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score7->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score7->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score7->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score7->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score7->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score7->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score7->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score7->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);

	Score8 = CreateImageRenderer(RenderOrder::Scores);
	Score8->SetImage("Score.png");
	Score8->SetPosition({ 212,20 });
	Score8->SetScale({ 18,18 });
	Score8->CreateAnimation("0", "Score.png", 0, 0, 0.1f, true);
	Score8->CreateAnimation("1", "Score.png", 1, 1, 0.1f, true);
	Score8->CreateAnimation("2", "Score.png", 2, 2, 0.1f, true);
	Score8->CreateAnimation("3", "Score.png", 3, 3, 0.1f, true);
	Score8->CreateAnimation("4", "Score.png", 4, 4, 0.1f, true);
	Score8->CreateAnimation("5", "Score.png", 5, 5, 0.1f, true);
	Score8->CreateAnimation("6", "Score.png", 6, 6, 0.1f, true);
	Score8->CreateAnimation("7", "Score.png", 7, 7, 0.1f, true);
	Score8->CreateAnimation("8", "Score.png", 8, 8, 0.1f, true);
	Score8->CreateAnimation("9", "Score.png", 9, 9, 0.1f, true);
}



void Score::Tick(float _DeltaTime) {

	int Score8remain = score % 10000000;
	int Score7remain = score % 1000000;
	int Score6remain = score % 100000;
	int Score5remain = score % 10000;
	int Score4remain = score % 1000;
	int Score3remain = score % 100;
	int Score2remain = score % 10;

	int Score8value = score / 10000000;
	int Score7value = Score8remain / 1000000;
	int Score6value = Score7remain / 100000;
	int Score5value = Score6remain / 10000;
	int Score4value = Score5remain / 1000;
	int Score3value = Score4remain / 100;
	int Score2value = Score3remain / 10;
	int Score1value = Score2remain;

	
	Score8->ChangeAnimation(std::to_string(Score1value));
	Score7->ChangeAnimation(std::to_string(Score2value));
	Score6->ChangeAnimation(std::to_string(Score3value));
	Score5->ChangeAnimation(std::to_string(Score4value));
	Score4->ChangeAnimation(std::to_string(Score5value));
	Score3->ChangeAnimation(std::to_string(Score6value));
	Score2->ChangeAnimation(std::to_string(Score7value));
	Score1->ChangeAnimation(std::to_string(Score8value));
	ULevel::Tick(_DeltaTime);
}



