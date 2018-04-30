#pragma once
#include <windows.h>
#include <iostream>
#include "MyDefine.h"
#include "BasicData.h"
#include "BasicFunctional.h"
#include "MyPredicate.h"


class Square
{
	const size_t POS_1_Squre = 1;
	const size_t POS_2_Squre = CHEK_AUT;
	const size_t POS_3_Squre = CHEK_AUT + 1;
	
	
public:
	size_t POS_1()const { return POS_1_Squre; }
	size_t POS_2()const { return POS_2_Squre; }
	size_t POS_3()const { return POS_3_Squre; }

	// для координат фигуры в малом окне
	std::vector<size_t> vecSquareNext{ 67, 68, 91, 92 };


	// движение квадрата вправо
	void mation_RIGHT_Square(class BasicData& basicdata,struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1)) {
			basicFunct.mation_RIGHT(basicdata, figure);
			
		}
		
	}
	// движение квадрата влево

	void mation_LEFT_Square(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_3, 1) &&
			predicate.Left(basicdata, figure.Pos_1, 1)) {
			basicFunct.mation_LEFT(basicdata, figure);
			
		}
		
	}
	// движение квадрата вниз
	bool mation_DAWN_Square(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_4)) {
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else {	
			return false; }
	}
	~Square() {};
};


