#pragma once
#include <Windows.h>
#include "BasicData.h"
struct MyPredicate
{
	bool Right(class BasicData& basicdata, size_t pos, size_t shift) {
		return basicdata.getVecLogic(pos + shift) != FRAME_VER &&
			   basicdata.getVecLogic(pos + shift) != FIGURE;
	}
	bool Left(class BasicData& basicdata, size_t pos, size_t shift) {
		return basicdata.getVecLogic(pos - shift) != FRAME_VER &&
			   basicdata.getVecLogic(pos - shift) != FIGURE;
	}
	bool Down(class BasicData& basicdata, size_t pos) {
		return basicdata.getVecLogic(pos + CHEK_AUT) != FRAME_HOR &&
			   basicdata.getVecLogic(pos + CHEK_AUT) != FIGURE;
	}
	bool Up(class BasicData& basicdata, size_t pos) {
		return basicdata.getVecLogic(pos - CHEK_AUT) != FRAME_HOR &&
			   basicdata.getVecLogic(pos - CHEK_AUT) != FIGURE;
	}
};