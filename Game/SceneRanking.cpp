#include "SceneRanking.h"
#include "Ranking.h"

//������
void CSceneRanking::InitScene()
{
	//�����L���OObj�쐬
	CRanking* pRanking = new CRanking();
	Objs::InsertObj(pRanking, OBJ_RANKING, 0);
}