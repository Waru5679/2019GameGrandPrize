#pragma once

#include "GameL\DrawTexture.h"
using namespace GameL;

#include "Vector.h"
#include "main.h"

//Rect_f�̃����o�[���Z�b�g����֐�
void RectSet(RECT_F* rect,float top,float left,float Size_x,float Size_y);

//�F���Z�b�g����֐�
void ColorSet(float r, float g, float b, float a, float color[4]);

//��ʓ����̃`�F�b�N
bool WindowInCheck(Vector vPos,Vector vSize);

//�����ƕ��Ŋp�x�����߂�
float GetAtan2Angle(float w, float h);

//�x�N�g���̐��K�����s���֐�
bool UnitVec(float* vx, float* vy);