#include "SceneRanking.h"
#include "Ranking.h"

//‰Šú‰»
void CSceneRanking::InitScene()
{
	//ƒ‰ƒ“ƒLƒ“ƒOObjì¬
	CRanking* pRanking = new CRanking();
	Objs::InsertObj(pRanking, OBJ_RANKING, 0);
}