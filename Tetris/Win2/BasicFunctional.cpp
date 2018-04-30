#include "BasicFunctional.h"

void BasicFunctional::imageChange(HWND hBitmap, HBITMAP hBit) {
	SendMessage(hBitmap, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBit);
}
void BasicFunctional::MATION(class BasicData& basicData, struct FigurePosit& figure,
	int shift) {
	basicData.setVecLogic(figure.Pos_1, EMPTY);
	basicData.setVecLogic(figure.Pos_2, EMPTY);
	basicData.setVecLogic(figure.Pos_3, EMPTY);
	basicData.setVecLogic(figure.Pos_4, EMPTY);
	imageChange(basicData.getVecBasic(figure.Pos_1),
		basicData.gethBmEmpty());
	imageChange(basicData.getVecBasic(figure.Pos_2),
		basicData.gethBmEmpty());
	imageChange(basicData.getVecBasic(figure.Pos_3),
		basicData.gethBmEmpty());
    imageChange(basicData.getVecBasic(figure.Pos_4),
		basicData.gethBmEmpty());
	figure.Pos_1 += shift; basicData.setVecLogic(figure.Pos_1, FIGURE);
	figure.Pos_2 += shift; basicData.setVecLogic(figure.Pos_2, FIGURE);
	figure.Pos_3 += shift; basicData.setVecLogic(figure.Pos_3, FIGURE);
	figure.Pos_4 += shift; basicData.setVecLogic(figure.Pos_4, FIGURE);
	imageChange(basicData.getVecBasic(figure.Pos_1),
		basicData.gethBmFigure());
	imageChange(basicData.getVecBasic(figure.Pos_2),
		basicData.gethBmFigure());
	imageChange(basicData.getVecBasic(figure.Pos_3),
		basicData.gethBmFigure());
	imageChange(basicData.getVecBasic(figure.Pos_4),
		basicData.gethBmFigure());
}
void BasicFunctional::mation_RIGHT(class BasicData& basicData, struct FigurePosit& figure) {
	MATION(basicData, figure, 1);
}
// движение фигуры влево
void BasicFunctional::mation_LEFT(class BasicData& basicData, struct FigurePosit& figure) {
	MATION(basicData, figure, -1);
}
// движение фигуры вниз
void BasicFunctional::mation_DOWN(class BasicData& basicData, struct FigurePosit& figure) {
	MATION(basicData, figure, CHEK_AUT);
}

// первый выбор
void BasicFunctional::FirstChoiceFigure(BasicData& basicData) {
	srand(time(NULL));
	basicData.setnumberFigure(rand() % QUANTITY_FIGURE);
	basicData.setnumberNextFigure(rand() % QUANTITY_FIGURE);
}
//  выбор фигуры
void BasicFunctional::RandomChoiceFigure(BasicData& basicData) {
	int f = basicData.getnextNumberFigure();
	basicData.setnumberFigure(basicData.getnextNumberFigure());
	basicData.setnumberNextFigure(rand() % QUANTITY_FIGURE);
	}


// УДАЛЯЕТ ЗАПОЛНЕННЫЙ РЯД
void BasicFunctional::SweepingSupport(BasicData& basicData, size_t i, size_t j) {
for (size_t clean = i - j, Mobil = clean + 16; clean < Mobil; clean++) {
	imageChange(basicData.getVecBasic(clean), basicData.gethBmEmpty());
			basicData.setVecLogic(clean, ' ');
	if (clean + 1 == Mobil)
		for (size_t _len = Mobil - 1; _len >= i - j; _len--) // проход вверх
			for (size_t h = _len; h > 170; h -= CHEK_AUT) {
				basicData.setVecLogic(h, basicData.getVecLogic(h - CHEK_AUT));
				if (basicData.getVecLogic(h) == ' ') {
					imageChange(basicData.getVecBasic(h),
								basicData.gethBmEmpty());
					}
				else {
					imageChange(basicData.getVecBasic(h),
								basicData.gethBmFigure());
					}
				}
		}
}

// УДАЛЯЕТ ЗАПОЛНЕННЫЙ РЯД
void BasicFunctional::Sweeping(BasicData& basicData) {// стерание полного ряда
	for (size_t i = 688; i >= CHEK_AUT * 2; i -= CHEK_AUT) {
		size_t Counter = 0;
		for (size_t j = 0; j <= 16; j++) {// проверка идет справа налево
			wchar_t d = basicData.getVecLogic(688);
			if (basicData.getVecLogic(i - j) == '@') {
				Counter++;
				if (Counter == 16) { // слева направо
					SweepingSupport(basicData, i, j);
				}
			}
		}
	}
	
}



// стирает маленькое окно(там где показывает следующую фигуру)
//  рисует следующую фигуру в  окне
void BasicFunctional::SweepAndPrintNextFigure(class BasicData& basicdata,
	struct BasicFunctional& basicFunct, const std::vector<size_t>& vec, size_t SIZE, bool flag) {
	for (size_t i(0); i < SIZE; i++) {
		if (flag) {
			basicdata.setVecLogic(vec.at(i), EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(vec.at(i)),
				basicdata.gethBmEmpty());
		}
		else {
			basicdata.setVecLogic(vec.at(i), FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(vec.at(i)),
				basicdata.gethBmFigure());
		}
	}
}
void BasicFunctional::RANDOM(class BasicData& basicdata,
	struct BasicFunctional& basicFunct, const  std::vector<size_t>& vec) {
		SweepAndPrintNextFigure(basicdata, basicFunct, basicdata.getVecCoord(),
		                                       basicdata.getVecCoord_Size(), true); 
		SweepAndPrintNextFigure(basicdata, basicFunct, vec,	vec.size(), false);
}