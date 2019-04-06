#pragma once

#include "GameL\DrawTexture.h"
using namespace GameL;

#include "Vector.h"
#include "main.h"

//Rect_fのメンバーをセットする関数
void RectSet(RECT_F* rect,float top,float left,float Size_x,float Size_y);

//色をセットする関数
void ColorSet(float r, float g, float b, float a, float color[4]);

//画面内かのチェック
bool WindowInCheck(Vector vPos,Vector vSize);

//高さと幅で角度を求める
float GetAtan2Angle(float w, float h);

//ベクトルの正規化を行う関数
bool UnitVec(float* vx, float* vy);