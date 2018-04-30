#include "BasicData.h"



// иниц. вектора для поддержки
void BasicData::InitVecLogicAlig () {

	for (size_t i(0); i < NUMBER_STEP_HEGHT; ++i) {
		for (size_t j(0); j < NUMBER_STEP_WIDTH; ++j)
		{
			vecLogicAlig.push_back(
				(i == 0 || i == NUMBER_STEP_HEGHT - 1) ? (FRAME_HOR) :
				(j == 0 || j == WORKING_WIGHT || j == NUMBER_STEP_WIDTH - 1) ? FRAME_VER : EMPTY);
		}
	}
}
void BasicData::InitVecCoord() {
	for (size_t i(CHEK_AUT * 2 + WORKING_WIGHT + 1), j(1);
		                                       i < CHEK_AUT * 5 + WORKING_WIGHT + 4; j++) {
		if (j % 4) { ++i; }
		else {
			i += CHEK_AUT - 2;
			j = 1;
		}
		vecCoord.push_back(i);
	}
}

// иниц. вектора для рисования
void BasicData::InitVecBasicGridHWND(struct BasicFunctional& basicFunct) {
	for (size_t i(0), heght(0); i < NUMBER_STEP_HEGHT; ++i, heght += STEP) {
		for (size_t j(0), width(0); j < NUMBER_STEP_WIDTH; ++j, width += STEP)
		{
			vecBasicGridHWND.push_back(CreateWindowEx(NULL, TEXT("STATIC"), NULL,
				WS_CHILD | WS_VISIBLE | SS_BITMAP | SS_REALSIZEIMAGE,
				width, heght, STEP, STEP,
				hWnd, NULL,
				GetModuleHandle(NULL), NULL));
			if (vecLogicAlig.at(i * NUMBER_STEP_WIDTH + j) == FRAME_VER ||
				vecLogicAlig.at(i * NUMBER_STEP_WIDTH + j) == FRAME_HOR) {
				basicFunct.imageChange(vecBasicGridHWND.at(i * NUMBER_STEP_WIDTH + j), hBmFrame);
			}
			else {
				basicFunct.imageChange(vecBasicGridHWND.at(i * NUMBER_STEP_WIDTH + j), hBmEmpty);
			}
		}
	}
}


// инициализация фгуры
void BasicData::InitFigureSize(FigurePosit& figure,
	const size_t pos1,
	const size_t pos2,
	const size_t pos3) {
	figure.Pos_1 = START_POSITION;
	figure.Pos_2 = START_POSITION + pos1;
	figure.Pos_3 = START_POSITION + pos2;
	figure.Pos_4 = START_POSITION + pos3;
}
