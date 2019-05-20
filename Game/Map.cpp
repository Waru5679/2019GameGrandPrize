#include "Map.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"
#include "GameL/UserData.h"

//コンストラクタ
CMap::CMap(int* pSideMap,int* pVarticalMap)
{
	//マップデータコピー
	memcpy(m_SideMap, pSideMap, sizeof(int)*(SIDE_MAX_Y * SIDE_MAX_X));
	memcpy(m_VarticalMap,pVarticalMap,sizeof(int)*(VARTICAL_MAX_Y*VARTICAL_MAX_X));
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

	//生成フラグをオンにする
	m_bFirstTimeSide = true;
	m_bFirstTimeVertical = true;
	//スクロールチェンジをオフにする
	m_bScrollChangeIs = false;

	//マップの読み込み量
	((UserData*)Save::GetData())->m_iMap_x = 0;
	((UserData*)Save::GetData())->m_iMap_y = 0;

	//横マップ作製
	CreateSideFirst();
}

//更新
void CMap::Action()
{
	//スクロールの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	if (m_bScroll == SIDE)
	{
		m_fMovePos_x += SCROLL_SPEED;
	}
	else
	{
		m_fMovePos_y -= SCROLL_SPEED;
	}
}

//描画
void CMap::Draw()
{
	
}

//生成初回(横)
void CMap::CreateSideFirst()
{
	for (int x =0; x < SIDE_MAX_X; x++)
	{
		for (int y = 0; y < SIDE_MAX_Y; y++)
		{
			switch (m_SideMap[y][x])
			{
				//地面
				case MAP_PLANE:
				{
					CPlane* pPlane = new CPlane(x, y);
					Objs::InsertObj(pPlane, OBJ_PLANE, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//ブラックホール
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
 				}
				//敵
				case MAP_ENEMY:
 				{
					CEnemy* pEnemy = new CEnemy(x, y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//星
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x, y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

					break;
				}
				//アイテム(大)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

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
					m_SideMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//スクロールチェンジ
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, y, SIDE);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

					//生成場所を記憶
					((UserData*)Save::GetData())->m_iMap_x = x;
					m_bScrollChangeIs = true;
					break;
						
				}
				//ゴール
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y);
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}

			}

		}
		if (m_bScrollChangeIs == true)
		{
			//初回生成をオフにする
			m_bFirstTimeSide = false;
			break;
		}
		
	}
	
}

void CMap::CreateSideSecond()
{
	m_bScrollChangeIs = false;

	for (int x = ((UserData*)Save::GetData())->m_iMap_x; x <= SIDE_MAX_X; x++)
	{
		for (int y = 0; y < SIDE_MAX_Y; y++)
		{
			//スクロールの位置調整用数値（画面左端に移動させる）
			m_fMoveAddPos_x = ((UserData*)Save::GetData())->m_iMap_x;

			switch (m_SideMap[y][x])
			{
				//地面
				case MAP_PLANE:
				{
					CPlane* pPlane = new CPlane(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pPlane, OBJ_PLANE, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//ブラックホール
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//敵
				case MAP_ENEMY:
				{
					CEnemy* pEnemy = new CEnemy(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
				//星
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

					break;
				}
				//アイテム(大)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x - m_fMoveAddPos_x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//アイテム(小)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x - m_fMoveAddPos_x, y, m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//スクロールチェンジ
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x - m_fMoveAddPos_x, y, SIDE);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;

					//生成場所を記憶
					((UserData*)Save::GetData())->m_iMap_x = x;
					m_bScrollChangeIs = true;
					break;

				}
				//ゴール
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x - m_fMoveAddPos_x, y);
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}

			}

		}
		if (m_bScrollChangeIs == true)
		{
			//初回生成をオフにする
			m_bFirstTimeSide = false;
			break;
		}

	}
}

//生成初回(縦)
void CMap::CreateVerticalFirst()
{
	m_bScrollChangeIs = false;

	for (int y = VARTICAL_MAX_Y; y >= 0; y--)
	{
		for (int x = 0; x< VARTICAL_MAX_X; x++)
		{
			switch (m_VarticalMap[y][x])
			{
				//ブラックホール
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//敵
				case MAP_ENEMY:
				{
					CEnemy* pEnemy = new CEnemy(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//星
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					break;
				}
				//アイテム(大)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, y - VARTICAL_MAX_Y, m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//アイテム(小)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, y - VARTICAL_MAX_Y, m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//スクロールチェンジ
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, y - VARTICAL_MAX_Y,VARTICAL);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					((UserData*)Save::GetData())->m_iMap_y = y;
					m_bScrollChangeIs = true;
					break;
				}
				//上下移動敵
				case MAP_ENEMY_UPDOWN:
				{
					CEnemyUpDown* pEnemyUpDown = new CEnemyUpDown(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pEnemyUpDown, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//ゴール
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, y - VARTICAL_MAX_Y);
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
			}

		}

		if (m_bScrollChangeIs == true)
		{
			//初回生成をオフにする
			m_bFirstTimeSide = false;
			break;
		}
	}
}

//縦生成（2回目以降）
void CMap::CreateVerticalSecond()
{
	m_bScrollChangeIs = false;

	for (int y = ((UserData*)Save::GetData())->m_iMap_y - 1; y >= 0; y--)
	{
		for (int x = 0; x < VARTICAL_MAX_X; x++)
		{

			m_fMoveAddPos_y = ((UserData*)Save::GetData())->m_iMap_y;

			switch (m_VarticalMap[y][x])
			{
				//ブラックホール
				case MAP_BLACK_HOLE:
				{
					CBlackHole* pBlackHole = new CBlackHole(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y ));
					Objs::InsertObj(pBlackHole, OBJ_BLACK_HOLE, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//敵
				case MAP_ENEMY: 
				{
					CEnemy* pEnemy = new CEnemy(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pEnemy, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//星
				case MAP_STAR:
				{
					CStar* pStar = new CStar(x,((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pStar, OBJ_STAR, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					break;
				}
				//アイテム(大)
				case MAP_ITEM_BIG:
				{
					CCollectionItemBig* pCollection_big = new  CCollectionItemBig(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y), m_iMapLoop);
					Objs::InsertObj(pCollection_big, OBJ_ITEM_BIG, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_BIG;

					m_iMapLoop++;

					break;
				}
				//アイテム(小)
				case MAP_ITEM_SMALL:
				{
					CCollectionItemSmall* pCollection_small = new  CCollectionItemSmall(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y), m_iMapLoop);
					Objs::InsertObj(pCollection_small, OBJ_ITEM_SMALL, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					//マップ内のアイテムの種類識別
					m_iMapItem[m_iMapLoop] = ITEM_SMALL;

					m_iMapLoop++;

					break;
				}
				//スクロールチェンジ
				case MAP_SCROLL_CHANGE:
				{
					CScrollChange* pScrollChange = new  CScrollChange(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y), VARTICAL);
					Objs::InsertObj(pScrollChange, OBJ_SCROLL_CHANGE, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;

					((UserData*)Save::GetData())->m_iMap_y = y;
					m_bScrollChangeIs = true;
					break;
				}
				//上下移動敵
				case MAP_ENEMY_UPDOWN:
				{
					CEnemyUpDown* pEnemyUpDown = new CEnemyUpDown(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pEnemyUpDown, OBJ_ENEMY, 10);

					//生成が終われば空白に
					m_VarticalMap[y][x] = MAP_NONE;
					break;
				}
				//ゴール
				case MAP_GOAL:
				{
					CGoal* pClear = new CGoal(x, ((y - VARTICAL_MAX_Y) + m_fMoveAddPos_y));
					Objs::InsertObj(pClear, OBJ_GOAL, 10);

					//生成が終われば空白に
					m_SideMap[y][x] = MAP_NONE;
					break;
				}
			}

		}
		if (m_bScrollChangeIs == true)
		{
			//初回生成をオフにする
			m_bFirstTimeSide = false;
			break;
		}
	}
}