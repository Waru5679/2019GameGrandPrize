#include "SceneRanking.h"
#include "Ranking.h"

//初期化
void CSceneRanking::InitScene()
{
	//ランキングObj作成
	CRanking* pRanking = new CRanking();
	Objs::InsertObj(pRanking, OBJ_RANKING, 0);
}