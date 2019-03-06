#include "Map.h"
#include "Function.h"
#include "main.h"


//コンストラクタ
CMap::CMap(int map[MAX_Y][MAX_X])
{
	//マップデータコピー
	memcpy(m_Map, map, sizeof(int)*(MAX_Y * MAX_X));
}

//初期化
void CMap::Init()
{
	//描画色設定
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CMap::Action()
{
	//オブジェクト生成
	Create();
}

//描画
void CMap::Draw()
{
	
}

//生成
void CMap::Create()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			switch (m_Map[y][x])
			{
				//穴
				case MAP_HOLE:
				{
					CHole* pHole = new CHole(y, x);
					Objs::InsertObj(pHole, OBJ_HOLE, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;

				}
			}
		}
	}
}