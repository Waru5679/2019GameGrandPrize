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

	//スクロール移動
	m_fScroll = SCROLL_SPEED;

}

//更新
void CMap::Action()
{
	//スクロールの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//縦
	if (m_bScroll == SIDE)
	{
		//オブジェクト生成(横)
		CreateSide();
	}
	else
	{
		//オブジェクト生成(縦)
		CreateVertical();
	}
}

//描画
void CMap::Draw()
{
	
}

//生成(横)
void CMap::CreateSide()
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
				//ブラックホール
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

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
				//アイテム(大)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//アイテム(小)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

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
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y);
					Objs::InsertObj(pClear, OBJ_GAME_CLEAR, 10);

					//生成が終われば空白に
					m_Map[y][x] = MAP_NONE;
					break;
				}

			}

		}
	}
}

//生成(縦)
void CMap::CreateVertical()
{
	for (int y = MAX_Y; y > 0; y--)
	{
		for (int x = MAX_X; x > 0; x--)
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
			//ブラックホール
			case MAP_BLACK_HOLE:
			{
				CBlackHole* pBlackHole = new CBlackHole(x, y);
				Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

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
			//アイテム(大)
			case MAP_ITEM_BIG:
			{
				CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
				Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

				//生成が終われば空白に
				m_Map[y][x] = MAP_NONE;

				//マップ内のアイテムの種類識別
				m_iMapItem[m_iMapLoop] = ITEM_BIG;

				m_iMapLoop++;

				break;
			}
			//アイテム(小)
			case MAP_ITEM_SMALL:
			{
				CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y, m_iMapLoop);
				Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

				//生成が終われば空白に
				m_Map[y][x] = MAP_NONE;

				//マップ内のアイテムの種類識別
				m_iMapItem[m_iMapLoop] = ITEM_SMALL;

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