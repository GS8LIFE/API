#include "PlayLevel.h"
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
#include "score.h"
#include <cmath>





PlayLevel::PlayLevel() 
{

}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::BeginPlay()
{
	ULevel::BeginPlay();
	//레벨 체크 및 맵에 있는 버블 초기화
	mapLevel();
	nowbobble.clear();

	FVector WindowScale = GEngine->MainWindow.GetWindowScale();
	AActor* Back = SpawnActor<AActor>();
	UImageRenderer* Renderer = Back->CreateImageRenderer(RenderOrder::Map);
	Renderer->SetImage("map.png");
	Renderer->SetPosition(WindowScale.Half2D());
	Renderer->SetScale(WindowScale);
	AActor* borderline = SpawnActor<AActor>();
	UImageRenderer* Renderer1 = borderline->CreateImageRenderer(RenderOrder::Map);
	Renderer1->SetImage("border.png");
	Renderer1->SetPosition({ 317,286 });
	Renderer1->SetScale({ 320,548 });

	AActor* bar = SpawnActor<AActor>();
	UImageRenderer* Renderer3 = bar->CreateImageRenderer(RenderOrder::Map);
	Renderer3->SetAlpha(100);
	Renderer3->SetImage("bar.png");
	Renderer3->SetTransform({ {325,400}, {272, 60} });

	Arrow = SpawnActor<arrow>();
	shooter* Shooter = SpawnActor<shooter>();
	Ceil* ceiling = SpawnActor<Ceil>();
	Dragon* Player = SpawnActor<Dragon>();
	Dragon2* Player2 = SpawnActor<Dragon2>();
	Dragon2Tool* Dragon2T = SpawnActor<Dragon2Tool>();
	DragonTool* Dragon1T = SpawnActor<DragonTool>();
	Score* Scorenow = SpawnActor<Score>();
	helper maphelper;
	maphelper.setnowmap(getnowmap());

	for (int row_idx = 0; row_idx < map.size(); ++row_idx)
	{
		const auto& row = map[row_idx];

		// . 혹은 / 이면 다음으로 넘김 (색이 없으므로)
		for (int col_idx = 0; col_idx < row.size(); ++col_idx)
		{
			char col = row[col_idx];
			if (col == '.' || col == '/')
			{
				continue;
			}
			
			if (row_idx % 2 == 1)
			{
				Bobble* NewB = SpawnActor<Bobble>();
				NewB->get_bubble(col);
				NewB->SetActorLocation({ 221 + (32 * col_idx), 65 + (32 * row_idx) });
				NewB->setmap(getmap(),row_idx,col_idx);
				NewB->getnowmap(maphelper.nowmap);
				nowbobble[{col_idx, row_idx}].push_back(NewB);
			}
			else
			{
				Bobble* NewB = SpawnActor<Bobble>();	
				NewB->get_bubble(col);
				NewB->SetActorLocation({ 205 + (32 * col_idx), 65 + (32 * row_idx) });
				NewB->setmap(getmap(), row_idx, col_idx);
				NewB->getnowmap(maphelper.nowmap);
				nowbobble[{col_idx, row_idx}].push_back(NewB);
				}
		}
	}
	fire_bobble();
	BGMPlayer = UEngineSound::SoundPlay("BGM.MP3");
}


int PlayLevel::check_x(int _x,int _y)
{
	if (_x > 0) 
	{
		if (y % 2 == 1)
		{	
			_x = ((int)collideLocate.X - 237) / 32 + 1;
		}
		else
		{
		_x = ((int)collideLocate.X - 221) / 32 + 1;
		}
	}
	return _x;
}

std::map<int, std::vector<char>> PlayLevel::getmap()
{
	return map;
}
void PlayLevel::set_map_vector()
{
	y = ((int)collideLocate.Y - 65 - (downCount * 32)) / 16 ;
	x = ((int)collideLocate.X - 205) / 16;
	if (y > 0)
	{
		y = ((int)collideLocate.Y - 81 - (downCount * 32)) / 32 + 1;
		if (y % 2 == 1)
		{
			x = ((int)collideLocate.X - 221) / 16;
			x = check_x(x,y);
		}
		else
		{
			x = check_x(x, y);
		}
	}
	else
	{
		x = check_x(x,y);
	}
}


void PlayLevel::fire_bobble()
{
	firebobble = SpawnActor<Bobblefire>();
	now = firebobble->get_bubble(map);
	firebobble->get_bubble(now);
	firebobble->SetActorLocation({ 328,410 });
	nextbobble = SpawnActor<Bobble>();
	next = firebobble->get_bubble(map);
	nextbobble->get_bubble(next);
	nextbobble->SetActorLocation({ 264,448 });
	cur_bobble = true;
}

void PlayLevel::remove_bobble(int _row, int _col, char _color)
{
	visited.clear();
	visit(_row, _col, _color);
	if (visited.size() >= 3)
	{
		remove_visited_bubbles();
	 	remove_hanging_bubbles();
	}

}
void PlayLevel::visit(int _row, int _col, char _color)
{
	char col;
	std::pair<int, int> p;
	p = std::make_pair(_row, _col);
	if (_row < 0 or _row >= 8  or _col < 0 or _col >= 11)
	{
		return;
	}
	if (_col % 2 && _row == 8)
	{
		col = map[_col][7];
	}
	else
	{
		col = map[_col][_row];
	}
	if (_color != col)
	{
		return;
	}
	if (map[_col][_row] == '/' || map[_col][_row] == '.')
	{
		return;
	}
	if (std::find(visited.begin(), visited.end(), p) != visited.end()) {
		return; // 이미 방문한 곳이면 함수를 빠져나감
	}

	// 방문 처리: (row_idx, col_idx)  visited 벡터에 추가
	visited.push_back(std::make_pair(_row, _col));


	int cols[6];
	int rows[6];
	if (_col % 2 == 1) 
	{
	int searchcols[] = { 0, -1, -1, 0, 1, 1 };
	std::copy(std::begin(searchcols), std::end(searchcols), std::begin(cols));
	int searchrows[] = { -1, 0, 1, 1, 1, 0 };
	std::copy(std::begin(searchrows), std::end(searchrows), std::begin(rows));
	}	
	else
	{
	int searchcols[] = { 0, -1, -1, 0, 1, 1 };
	std::copy(std::begin(searchcols), std::end(searchcols), std::begin(cols));
	int searchrows[] = { -1, -1, 0, 1, 0, -1 };
	std::copy(std::begin(searchrows), std::end(searchrows), std::begin(rows));
	}
	for (int i = 0; i < 6; i++) {
		visit(_row + rows[i], _col + cols[i], _color);
	}

}
void PlayLevel::visit(int _row, int _col)
{
	std::pair<int, int> p;
	p = std::make_pair(_row, _col);
	if (_row < 0 or _row >= 8 or _col < 0 or _col >= 11)
	{
		return;
	}
	auto a = map[_col][_row];
	if (map[_col][_row] == '/' || map[_col][_row] == '.')
	{
		return;
	}
	if (std::find(visited.begin(), visited.end(), p) != visited.end()) {
		return; // 이미 방문한 곳이면 함수를 빠져나감
	}

	// 방문 처리: (row_idx, col_idx)  visited 벡터에 추가
	visited.push_back(std::make_pair(_row, _col));

	int cols[6];
	int rows[6];
	if (_col % 2 == 1)
	{
		int searchcols[] = { 0, -1, -1, 0, 1, 1 };
		std::copy(std::begin(searchcols), std::end(searchcols), std::begin(cols));
		int searchrows[] = { -1, 0, 1, 1, 1, 0 };
		std::copy(std::begin(searchrows), std::end(searchrows), std::begin(rows));
	}
	else
	{
		int searchcols[] = { 0, -1, -1, 0, 1, 1 };
		std::copy(std::begin(searchcols), std::end(searchcols), std::begin(cols));
		int searchrows[] = { -1, -1, 0, 1, 0, -1 };
		std::copy(std::begin(searchrows), std::end(searchrows), std::begin(rows));
	}

	for (int i = 0; i < 6; i++) {
		visit(_row + rows[i], _col + cols[i]);
	}

}
void PlayLevel::remove_visited_bubbles()
{
	std::pair<int, int> p;
	
	for (int col = 0; col < 11; col++)
	{
		for (int row = 0; row < 8; row++)
		{
			p = std::make_pair(row, col);
			if (std::find(visited.begin(), visited.end(), p) != visited.end())
			{
				map[col][row] = '.';

				auto bobbles = nowbobble[{row, col}];
				for (auto bobble : bobbles) {
					bobble->Destroy();
					nowbobble.erase({ row,col });
					visitcount++;
				}

			}
		}
		powPlayer = UEngineSound::SoundPlay("pow.wav");
	}
	score += visitcount * 10;
	visitcount = 0;
}
void PlayLevel::remove_not_visited_bubbles()
{
	std::pair<int, int> p;
	bool soundBool = false;
	for (int col = 0; col < 11; col++)
	{
		for (int row = 0; row < 8; row++)
		{
			p = std::make_pair(row, col);
			if (std::find(visited.begin(), visited.end(), p) == visited.end())
			{
					map[col][row] = '.';
					auto bobbles = nowbobble[{row, col}]; // std::vector<Bobble*>
				for (auto bobble : bobbles) { // bobbles에서 원소들을 받아오는거기에 Bobble* 
					bobble->Destroy();
					hangcount++;
					soundBool = true;
				}
					nowbobble.erase({ row,col });
			}
		}
	}
	if (soundBool)
	{
		hangpowPlayer = UEngineSound::SoundPlay("hangpow.wav");
	}
	if (hangcount != 0)
	{
	score += pow(2, hangcount) * 10;
	hangcount = 0;
	}
}

void PlayLevel::all_down()
{

	for (int col = 0; col < 11; col++)
	{
		for (int row = 0; row < 8; row++)
		{
			{
				auto bobbles = nowbobble[{row, col}]; // std::vector<Bobble*>
				for (auto bobble : bobbles) { // bobbles에서 원소들을 받아오는거기에 Bobble* 
					bobble->AddActorLocation({ 0, 32 });
				}
			}
		}
	}
	downPlayer = UEngineSound::SoundPlay("down_sound.wav");
}


void PlayLevel::remove_hanging_bubbles()
{
	visited.clear();
	for (int row = 0; row < 8; row++)
	{
		if (map[0][row] != '.')
		{
			visit(row, 0);
		}
	} 
  	 remove_not_visited_bubbles();
}
void PlayLevel::fired_bobble()
{
	nextbobble->Destroy();
	firebobble = SpawnActor<Bobblefire>();
	firebobble->get_bubble(next);
	now = next;
	firebobble->SetActorLocation({ 328,410 });
	nextbobble = SpawnActor<Bobble>();
	next = firebobble->get_bubble(map);
	nextbobble->get_bubble(next);
	nextbobble->SetActorLocation({ 264,448 });
	cur_bobble = true;
}


void PlayLevel:: nextLevel()
{
	std::string str;
	str = "Level";
	if (Level < 0)
	{
		helper::Level = 0;
		return;
	}
	else if (Level >= 20)
	{
		helper::Level = 20;
		return;
	}
	str = str + std::to_string(Level);
	GEngine->DestroyLevel(str);
	helper::Level++;
	str = "Level";
	str = str + std::to_string(Level);
	GEngine->CreateLevel<PlayLevel>(str);
	GEngine->ChangeLevel(str);
}
void PlayLevel::PreLevel()
{
	std::string str;
	str = "Level";
	if (Level < 0 )
	{
		helper::Level = 0;
		return;
	}
	str = str + std::to_string(Level);
	GEngine->DestroyLevel(str);
	helper::Level--;
	str = "Level";
	str = str + std::to_string(Level);
	GEngine->CreateLevel<PlayLevel>(str);
	GEngine->ChangeLevel(str);
}

void PlayLevel::Tick(float _DeltaTime) {
	if (UEngineInput::IsDown('Z'))
	{
	GEngine->EngineDebugSwitch();
	}
	if (UEngineInput::IsDown('X'))
	{
		all_down();
		all_down_switch = false;
	}
	if (nowbobble.size() <= 0)
	{
		all_down_switch = false;
		BGMPlayer.Off();
		Endbool = true;
		downCount = 0;
		CellCount = 0;
	}
	if (all_down_switch)
	{
		all_down();
		all_down_switch = false;
	}

	ULevel::Tick(_DeltaTime);
	if (cur_bobble == true && true == UEngineInput::IsDown(VK_SPACE))
	{
		firebobble->setfireAng(Arrow->getangle());
		cur_bobble = false;
		firing = true;
		shootPlayer = UEngineSound::SoundPlay("shoot.wav");
	}
	if (UEngineInput::IsDown('L'))
	{
		nextLevel();
		BGMPlayer.Off();
		downCount = 0;
		CellCount = 0;
	}
	if (UEngineInput::IsDown('K'))
	{
		PreLevel();
		BGMPlayer.Off();
		downCount = 0;
		CellCount = 0;
	}
	else if (firing == true) 
	{
		if (firebobble->IsDestroy())
		{
 			set_map_vector();
			if (map[y][x] == '/' && y % 2 == 1   ) // 짝수는 8번째 자리가 없기에 8번째에 놓아졌을 때 7번째로 옮기는 작업 
			{

				Bobble* NewB = SpawnActor<Bobble>();
				NewB->get_bubble(now);
				NewB->SetActorLocation({ 221 + (32 * (x-1)), 65 + (32 * (y + downCount)) }); 
				NewB->setmap(getmap(),x,y);
				map[y][x] = now;
				nowbobble[{ x, y}].push_back(NewB);
			}
			else {
				if (y % 2 == 1)
				{
					Bobble* NewB = SpawnActor<Bobble>();
					NewB->get_bubble(now);
					NewB->SetActorLocation({ 221 + (32 * x), 65 + (32 * (y + downCount)) });
					NewB->setmap(getmap(),x,y);
					map[y][x] = now;
					nowbobble[{x, y}].push_back(NewB);
				} 
				else
				{
					Bobble* NewB = SpawnActor<Bobble>();
					NewB->get_bubble(now);
					NewB->SetActorLocation({ 205 + (32 * x), 65 + (32 * (y + downCount)) });
					NewB->setmap(getmap(),x,y);
					map[y][x] = now;
 					nowbobble[{x, y}].push_back(NewB);
				}
			}
 			remove_bobble(x, y, now);
			nowmap = getmap();
			CellCount++ ;
			if (CellCount == 6)
			{
				all_down_switch = true;
			}
			firing = false;
			if (CellCount == 5)
			{
				downPlayer = UEngineSound::SoundPlay("NextDown.wav");
			}
		}
		else if (firebobble->IsDestroy() == false)
		{
			set_collide_locate(firebobble->get_collide_locate());
		}
	}
	else if(cur_bobble == false )
	{
		fired_bobble();
	}	
}









void PlayLevel::mapLevel()
{
	switch (Level)
	{
	case 1:
		map[0] = { 'R', 'R', 'Y', 'Y', 'S', 'S', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'S', 'S', 'G', '/' };
		map[2] = { 'S', 'S', 'G', 'G', 'R', 'R', 'Y', 'Y' };
		map[3] = { 'S', 'G', 'G', 'R', 'R', 'Y', 'Y', '/' };
		map[4] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[5] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 2:
		map[0] = { '.', '.', '.', 'B', 'B', '.', '.', '.' };
		map[1] = { '.', '.', '.', 'S', '.', '.', '.', '/' };
		map[2] = { '.', '.', '.', 'R', '.', '.', '.', '.' };
		map[3] = { '.', '.', '.', 'S', '.', '.', '.', '/' };
		map[4] = { '.', '.', '.', 'G', '.', '.', '.', '.' };
		map[5] = { '.', '.', '.', 'P', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', 'G', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', 'S', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 3:
		map[0] = { 'G', '.', '.', '.', '.', '.', '.', 'G' };
		map[1] = { 'R', 'G', 'S', 'Y', 'R', 'G', 'S', '/' };
		map[2] = { 'Y', '.', '.', '.', '.', '.', '.', 'Y' };
		map[3] = { 'S', 'Y', 'R', 'G', 'S', 'Y', 'R', '/' };
		map[4] = { '.', '.', '.', 'R', '.', '.', '.', '.' };
		map[5] = { '.', '.', '.', 'G', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', 'R', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 4:
		map[0] = { '.', 'B', 'B', '.', '.', 'S', 'S', '.' };
		map[1] = { '.', 'S', '.', '.', '.', 'S', '.', '/' };
		map[2] = { '.', 'R', '.', '.', '.', 'P', '.', '.' };
		map[3] = { '.', 'P', '.', '.', '.', 'P', '.', '/' };
		map[4] = { '.', 'G', '.', '.', '.', 'G', '.', '.' };
		map[5] = { '.', 'R', '.', '.', '.', 'R', '.', '/' };
		map[6] = { '.', '.', 'P', '.', '.', '.', 'P', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 5:
		map[0] = { '.', 'R', '.', 'O', '.', 'P', '.', 'R' };
		map[1] = { 'G', '.', 'P', '.', 'G', '.', 'S', '/' };
		map[2] = { 'O', '.', 'G', '.', 'G', '.', 'Y', '.' };
		map[3] = { '.', 'P', '.', 'Y', '.', 'Y', '.', '/' };
		map[4] = { '.', 'S', '.', 'G', '.', 'Y', '.', '.' };
		map[5] = { 'R', '.', 'P', '.', 'G', '.', '.', '/' };
		map[6] = { '.', '.', 'R', '.', 'R', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', 'Y', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 6:
		map[0] = { 'R', 'Y', 'G', 'S', 'G', 'W', 'S', 'P' };
		map[1] = { 'S', '.', 'S', '.', 'W', '.', 'Y', '/' };
		map[2] = { '.', 'W', 'W', 'P', 'R', 'R', 'S', '.' };
		map[3] = { '.', 'Y', '.', 'W', '.', 'P', '.', '/' };
		map[4] = { '.', 'Y', 'R', 'W', 'Y', 'G', 'P', '.' };
		map[5] = { 'W', '.', 'R', '.', 'R', '.', 'S', '/' };
		map[6] = { 'S', 'G', 'G', 'W', 'Y', 'P', 'R', 'R' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 7:
		map[0] = { '.', '.', '.', 'P', 'Y', '.', '.', '.' };
		map[1] = { '.', '.', 'R', 'G', 'Y', '.', '.', '/' };
		map[2] = { '.', '.', '.', 'S', 'Y', '.', '.', '.' };
		map[3] = { '.', 'Y', 'O', '.', 'P', 'P', '.', '/' };
		map[4] = { '.', 'R', 'R', 'Y', 'R', 'O', 'P', '.' };
		map[5] = { '.', 'O', 'P', '.', 'P', 'S', '.', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 8:
		map[0] = { 'R', 'G', 'S', 'Y', 'P', 'W', 'R', 'G' };
		map[1] = { 'P', 'W', 'R', 'G', 'S', 'Y', 'P', '/' };
		map[2] = { 'R', 'G', 'S', 'Y', 'P', 'W', 'R', 'G' };
		map[3] = { 'P', 'W', 'R', 'G', 'S', 'Y', 'P', '/' };
		map[4] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[5] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 9:
		map[0] = { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' };
		map[1] = { 'O', '.', '.', '.', '.', '.', 'O', '/' };
		map[2] = { 'O', '.', '.', 'G', 'Y', 'B', 'S', 'P' };
		map[3] = { 'O', '.', '.', '.', 'S', 'Y', 'P', '/' };
		map[4] = { 'O', '.', '.', '.', '.', '.', 'G', 'R' };
		map[5] = { 'S', 'B', '.', '.', '.', '.', '.', '/' };
		map[6] = { 'G', 'S', 'S', 'Y', '.', '.', '.', '.' };
		map[7] = { 'R', 'Y', 'S', 'Y', 'G', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 10:
		map[0] = { 'B', '.', '.', '.', '.', '.', '.', 'R' };
		map[1] = { 'R', 'S', 'Y', 'G', 'O', 'P', 'B', '/' };
		map[2] = { 'B', '.', '.', '.', '.', '.', '.', 'R' };
		map[3] = { 'R', 'S', 'Y', 'G', 'O', 'P', 'B', '/' };
		map[4] = { 'B', '.', '.', '.', '.', '.', '.', 'R' };
		map[5] = { 'R', 'S', 'Y', 'G', 'O', 'P', 'B', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 11:
		map[0] = { '.', '.', '.', 'G', 'G', '.', '.', '.' };
		map[1] = { '.', '.', 'S', 'B', 'S', '.', '.', '/' };
		map[2] = { '.', '.', 'Y', 'P', 'O', 'O', '.', '.' };
		map[3] = { '.', 'S', 'W', 'Y', 'O', 'P', '.', '/' };
		map[4] = { '.', '.', 'O', 'S', 'R', 'W', '.', '.' };
		map[5] = { '.', '.', 'R', 'R', 'S', '.', '.', '/' };
		map[6] = { '.', '.', '.', 'O', 'B', '.', '.', '.' };
		map[7] = { '.', '.', '.', 'Y', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 12:
		map[0] = { '.', '.', '.', 'R', 'G', '.', '.', '.' };
		map[1] = { '.', '.', 'G', 'S', 'R', '.', '.', '/' };
		map[2] = { '.', '.', 'S', 'R', 'G', 'S', '.', '.' };
		map[3] = { '.', 'R', 'G', 'S', 'R', 'G', '.', '/' };
		map[4] = { '.', 'G', 'S', 'R', 'G', 'S', 'R', '.' };
		map[5] = { 'S', 'R', 'G', 'S', 'R', 'G', 'S', '/' };
		map[6] = { 'R', 'G', 'S', 'R', 'G', 'S', 'R', 'G' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 13:
		map[0] = { 'S', 'S', 'Y', 'R', 'R', 'Y', 'S', 'S' };
		map[1] = { 'W', 'S', 'Y', 'R', 'Y', 'S', 'P', '/' };
		map[2] = { 'G', 'G', 'S', 'Y', 'Y', 'S', 'O', 'O' };
		map[3] = { 'B', 'W', 'S', 'Y', 'S', 'G', 'G', '/' };
		map[4] = { 'P', 'B', 'W', 'S', 'S', 'O', 'W', 'B' };
		map[5] = { 'O', 'P', 'Y', 'S', 'R', 'O', 'W', '/' };
		map[6] = { 'G', 'P', 'G', 'R', 'Y', 'P', 'G', 'B' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 14:
		map[0] = { 'Y', '.', 'B', '.', '.', 'R', '.', 'Y' };
		map[1] = { 'S', '.', 'R', '.', 'Y', 'R', 'P', '/' };
		map[2] = { '.', 'Y', '.', 'O', 'R', '.', 'O', '.' };
		map[3] = { 'P', 'B', '.', '.', '.', 'R', '.', '/' };
		map[4] = { 'B', '.', 'S', 'R', 'G', 'O', '.', 'S' };
		map[5] = { 'R', '.', '.', '.', '.', '.', 'G', '/' };
		map[6] = { '.', 'P', 'B', 'P', 'Y', 'P', 'P', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 15:
		map[0] = { 'G', 'G', '.', 'S', 'S', '.', 'R', 'R' };
		map[1] = { 'Y', '.', '.', 'Y', '.', '.', 'P', '/' };
		map[2] = { 'P', '.', '.', 'B', '.', '.', 'B', '.' };
		map[3] = { 'B', '.', '.', 'W', '.', '.', 'Y', '/' };
		map[4] = { 'Y', '.', '.', 'O', '.', '.', 'P', '.' };
		map[5] = { 'B', '.', '.', 'O', '.', '.', 'Y', '/' };
		map[6] = { 'P', '.', '.', 'W', '.', '.', 'O', '.' };
		map[7] = { 'O', '.', '.', 'Y', '.', '.', 'P', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 16:
		map[0] = { 'R', 'G', 'S', 'Y', 'P', 'W', 'O', 'R' };
		map[1] = { 'P', 'W', 'O', 'R', 'G', 'S', 'Y', '/' };
		map[2] = { 'R', 'G', 'S', 'Y', 'P', 'W', 'O', 'R' };
		map[3] = { 'P', 'W', 'O', 'R', 'G', 'S', 'Y', '/' };
		map[4] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[5] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 17:
		map[0] = { 'R', 'G', 'R', '.', '.', 'Y', 'S', 'Y' };
		map[1] = { 'S', 'Y', 'S', '.', 'G', 'R', 'G', '/' };
		map[2] = { 'R', 'G', 'R', '.', '.', 'Y', 'S', 'Y' };
		map[3] = { 'S', 'Y', 'S', '.', 'G', 'R', 'G', '/' };
		map[4] = { 'R', 'G', 'R', '.', '.', 'Y', 'S', 'Y' };
		map[5] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 18:
		map[0] = { '.', '.', '.', '.', 'W', '.', '.', '.' };
		map[1] = { '.', '.', '.', 'W', '.', '.', '.', '/' };
		map[2] = { '.', 'G', '.', '.', 'W', '.', 'B', '.' };
		map[3] = { 'P', '.', '.', 'W', '.', '.', 'G', '/' };
		map[4] = { '.', 'S', '.', '.', 'W', '.', 'P', '.' };
		map[5] = { '.', 'R', '.', 'W', '.', 'S', '.', '/' };
		map[6] = { '.', '.', 'R', 'S', 'B', 'R', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 19:
		map[0] = { 'W', 'G', 'Y', 'W', 'G', 'Y', 'W', 'G' };
		map[1] = { 'Y', 'W', 'G', '.', 'W', 'G', 'Y', '/' };
		map[2] = { '.', 'G', 'Y', '.', '.', 'Y', 'W', '.' };
		map[3] = { '.', 'W', '.', '.', '.', 'G', '.', '/' };
		map[4] = { '.', 'G', 'Y', '.', '.', 'Y', 'W', '.' };
		map[5] = { 'Y', 'W', 'G', '.', 'W', 'G', 'Y', '/' };
		map[6] = { 'W', 'G', 'Y', 'W', 'G', 'Y', 'W', 'G' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	case 20:
		map[0] = { 'Y', '.', 'W', '.', '.', 'B', '.', 'R' };
		map[1] = { 'S', '.', 'G', '.', 'B', '.', 'Y', '/' };
		map[2] = { 'Y', '.', '.', 'P', 'W', '.', '.', 'R' };
		map[3] = { 'R', '.', 'B', 'W', 'S', '.', 'Y', '/' };
		map[4] = { 'Y', '.', '.', 'W', 'W', '.', '.', 'R' };
		map[5] = { 'S', '.', 'B', '.', 'P', '.', 'Y', '/' };
		map[6] = { 'Y', '.', 'B', '.', '.', 'B', '.', 'R' };
		map[7] = { 'R', '.', '.', '.', '.', '.', 'Y', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
		//
	default:
		map[0] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[1] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[2] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[3] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[4] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[5] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[6] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[7] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[8] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[9] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		map[10] = { '.', '.', '.', '.', '.', '.', '.', '.' };
		map[11] = { '.', '.', '.', '.', '.', '.', '.', '/' };
		break;
	}
}