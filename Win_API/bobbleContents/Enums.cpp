#include "Enums.h"

//static 초기화
int helper::Level = 1;
int helper::CellCount = 0; //천장이 내려오기전에 얼마나 많이 쐇는지
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

bool helper::firing = false; //지금 버블이  쏘아지고 있는지 (그렇다면 드래곤이 버블을 부는 모션을 할 수 없도록)
bool helper::stageclear = false;  //스테이지가 클리어되면 필요한 모든 애니메이션들에게 값을 반환

bool helper::Endbool = false;
bool helper::gameover = false;
bool helper::DownLevel = false;
//static 초기화