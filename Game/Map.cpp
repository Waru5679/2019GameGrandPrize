#include "Map.h"
#include "Function.h"
#include "main.h"


//コンストラクタ
CMap::CMap(int* pMap)
{
	//マップデータコピー
	memcpy(m_Map, pMap, sizeof(int)*(MAX_Y * MAX_X));
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
					CHole* pHole = new CHole(x, y);
					Objs::InsertObj(pHole, OBJ_HOLE, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//敵
				case MAP_ENEMY:
				{
					CEnemy* pEnemy = new CEnemy(x, y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//星
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x, y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//アイテム
				case MAP_ITEM:
				{
					CCollectionItem* pCollection = new  CCollectionItem(x, y);
					Objs::InsertObj(pCollection, OBJ_ITEM, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}
				//スクロールチェンジ
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, y);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}
			}
		}
	}
}