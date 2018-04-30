#pragma once
#include <Windows.h>
#include "BasicData.h"
#include <stdlib.h>
#include <time.h>

struct BasicFunctional
{
	void imageChange(HWND, HBITMAP);

	void MATION(class BasicData&, struct FigurePosit&, int);
	void mation_RIGHT(class BasicData&, struct FigurePosit&);
	void mation_LEFT(class BasicData&, struct FigurePosit&);
	void mation_DOWN(class BasicData&, struct  FigurePosit&);
	
	void FirstChoiceFigure(class BasicData&);
	void RandomChoiceFigure(class BasicData&);
	void Sweeping(class BasicData&);
	void SweepingSupport(BasicData&, size_t, size_t);
	void RANDOM(class BasicData&, struct BasicFunctional&, const std::vector<size_t>&);
	void SweepAndPrintNextFigure(class BasicData&, struct BasicFunctional&,
		const std::vector<size_t>&, size_t, bool);
};