#include "Enums.h"

//static 초기화
int helper::Level = 1;
int helper::CellCount = 0; //천장이 내려오기전에 얼마나 많이 쐇는지
int helper::downCount = 0;
bool helper::firing = false; //지금 버블이  쏘아지고 있는지 (그렇다면 드래곤이 버블을 부는 모션을 할 수 없도록)
bool helper::stageclear = false;  //스테이지가 클리어되면 필요한 모든 애니메이션들에게 값을 반환
//static 초기화