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
PlayLevel::PlayLevel() 
{

}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	mapLevel();
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

	helper maphelper;

	//버블 배열

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
}


int PlayLevel::check_x(int _x,int _y)
{
	if (_x > 0) 
	{
		if (y % 2 == 1)
		{	
			_x = (collideLocate.X - 237) / 32 + 1;
		}
		else
		{
		_x = (collideLocate.X - 221) / 32 + 1;
		}
	}
	else
	return _x;
}

std::map<int, std::vector<char>> PlayLevel::getmap()
{
	return map;
}
void PlayLevel::set_map_vector()
{
	y = (collideLocate.Y - 65) / 16;
	x = (collideLocate.X - 205) / 16;
	if (y > 0)
	{
		y = (collideLocate.Y - 81) / 32 + 1;
		x = check_x(x,y);
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
				}

			}
		}
	}
	int a = 0;
}
void PlayLevel::remove_not_visited_bubbles()
{
	std::pair<int, int> p;

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
				}
					nowbobble.erase({ row,col });
			}
		}
	}
	int a = 0;
}



void PlayLevel::remove_hanging_bubbles()
{
	visited.clear();
	for (int row = 0; row < 7; row++)
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

void up(int* _levelptr)
{
	// 내가 가리키는 번지의 값에 접근하겠다.
	*_levelptr = *_levelptr + 1;
	// 그려면
}

void PlayLevel:: nextLevel()
{
	std::string str;
	str = "Level";
	str = str + std::to_string(Level);
	GEngine->DestroyLevel(str);
	helper::Level++;
	str = "Level";
	str = str + std::to_string(Level);
	GEngine->CreateLevel<PlayLevel>(str);
	GEngine->ChangeLevel(str);
}
void PlayLevel::Tick(float _DeltaTime) {

	if (nowbobble.size() <= 0)
	{
		nextLevel();
	}

	ULevel::Tick(_DeltaTime);
	if (cur_bobble == true && true == UEngineInput::IsDown(VK_SPACE))
	{
		firebobble->setfireAng(Arrow->getangle());
		cur_bobble = false;
		firing = true;
	}
	if (UEngineInput::IsDown('R'))
	{
		nextLevel();
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
				NewB->SetActorLocation({ 221 + (32 * (x-1)), 65 + (32 * y) }); 
				NewB->setmap(getmap(),x,y);
				map[y][x] = now;
				nowbobble[{ x, y}].push_back(NewB);
			}
			else {
				if (y % 2 == 1)
				{
					Bobble* NewB = SpawnActor<Bobble>();
					NewB->get_bubble(now);
					NewB->SetActorLocation({ 221 + (32 * x), 65 + (32 * y) });
					NewB->setmap(getmap(),x,y);
					map[y][x] = now;
					nowbobble[{x, y}].push_back(NewB);
				} 
				else
				{
					Bobble* NewB = SpawnActor<Bobble>();
					NewB->get_bubble(now);
					NewB->SetActorLocation({ 205 + (32 * x), 65 + (32 * y) });
					NewB->setmap(getmap(),x,y);
					map[y][x] = now;
					nowbobble[{x, y}].push_back(NewB);
				}
			}
 			remove_bobble(x, y, now);
			nowmap = getmap();
			CellCount++ ;
			firing = false;
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
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 9:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 10:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 11:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 12:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 13:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 14:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 15:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 16:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 17:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 18:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 19:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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
	case 20:
		map[0] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', 'G' };
		map[1] = { 'R', 'R', 'Y', 'Y', 'B', 'B', 'G', '/' };
		map[2] = { 'B', 'B', 'G', 'G', 'R', 'R', 'Y', 'Y' };
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

	default:
		break;
	}
}