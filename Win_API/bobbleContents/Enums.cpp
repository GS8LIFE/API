#include "Enums.h"

//static �ʱ�ȭ
int helper::Level = 1;
int helper::CellCount = 0; //õ���� ������������ �󸶳� ���� �i����
int helper::downCount = 0;
int helper::score = 0;

static int Score1value = 0;
static int Score2value = 0;
static int Score3value = 0;
static int Score4value = 0;
static int Score5value = 0;
static int Score6value = 0;
static int Score7value = 0;
static int Score8value = 0;

bool helper::firing = false; //���� ������  ������� �ִ��� (�׷��ٸ� �巡���� ������ �δ� ����� �� �� ������)
bool helper::stageclear = false;  //���������� Ŭ����Ǹ� �ʿ��� ��� �ִϸ��̼ǵ鿡�� ���� ��ȯ

bool helper::Endbool = false;
bool helper::gameover = false;
bool helper::DownLevel = false;
//static �ʱ�ȭ