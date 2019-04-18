#include "Map.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"

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

	//マップ配列探索用変数初期化
	m_iMapItem[MAX_ITEM];
	m_iMapLoop = 0;

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
	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			switch (m_Map[y][x])
			{
				//地面
				case MAP_PLANE:
				{
					CPlane* pPlane = new CPlane(x, y);
					Objs::InsertObj(pPlane, OBJ_PLANE, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}
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
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = 1;

					m_iMapLoop++;

					break;
				}
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y,m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = 2;

					m_iMapLoop++;

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