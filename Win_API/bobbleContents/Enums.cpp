#include "Enums.h"

//static �ʱ�ȭ
int helper::Level = 1;
int helper::CellCount = 0; //õ���� ������������ �󸶳� ���� �i����
int helper::downCount = 0;
bool helper::firing = false; //���� ������  ������� �ִ��� (�׷��ٸ� �巡���� ������ �δ� ����� �� �� ������)
bool helper::stageclear = false;  //���������� Ŭ����Ǹ� �ʿ��� ��� �ִϸ��̼ǵ鿡�� ���� ��ȯ

bool helper::End = false;
bool helper::DownLevel = false;
//static �ʱ�ȭ