#pragma once
#include <windows.h>
#include <iostream>
#include "MyDefine.h"
#include "BasicData.h"
#include "BasicFunctional.h"
#include "MyPredicate.h"

class Latter_G
{
	const size_t POS_1_Squre = 1;
	const size_t POS_2_Squre = CHEK_AUT ;
	const size_t POS_3_Squre = CHEK_AUT * 2;

	

public:
	size_t label = 0;
	size_t POS_1()const { return POS_1_Squre; }
	size_t POS_2()const { return POS_2_Squre; }
	size_t POS_3()const { return POS_3_Squre; }

	std::vector<size_t> vecLetter_GNext{ 67, 68, 91, 115 };

	//буква Г стоит и двигается в право
	void MOTION_right_letter_G(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_2, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	
	//буква Г стоит и двигается в влево
	void MOTION_left_letter_G(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_3, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Left(basicdata, figure.Pos_1, 1)) {
			basicFunct.mation_LEFT(basicdata, figure);

		}
	}
	//буква Г лежит вправо и двигается вправо
	void MOTION_right_letter_G_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//буква Г лежит вправо и двигается влево
	void MOTION_left_letter_G_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_2, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1)) {
			basicFunct.mation_LEFT(basicdata, figure);

		}
	}
	//буква Г стоит вверхголовой и двигается вправо
	void MOTION_right_letter_G_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//буква Г стоит вверхголовой и двигается влево
	void MOTION_left_letter_G_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_3, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1)) {
			basicFunct.mation_LEFT(basicdata, figure);

		}
	}
	//буква Г лежит влево и двигается вправо
	void MOTION_right_letter_G_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
		
	}
	//буква Г лежит влево и двигается влево
	void MOTION_left_letter_G_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_2, 1) &&
			predicate.Left(basicdata, figure.Pos_1, 1)) {
			basicFunct.mation_LEFT(basicdata, figure);

		}
	}
	// буква Г опускается стоя
	bool MOTION_dawn_letter_G_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_2) &&
			predicate.Down(basicdata, figure.Pos_4)) {
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	// буква Г лежит вправо опускается 
	bool MOTION_dawn_letter_G_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Down(basicdata, figure.Pos_2)) {
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	
	// буква Г лежит вверхголовой опускается 
	bool MOTION_dawn_letter_G_Lie_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_2) &&
			predicate.Down(basicdata, figure.Pos_1)) {
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	// буква Г лежит влево опускается 
	bool MOTION_dawn_letter_G_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Down(basicdata, figure.Pos_1)) {
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }

	}
	// буква Г лажится вправо 
	bool TURN_letter_G_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_3, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1)) {
		
			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 += 25;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 += 48;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_4, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmEmpty());
			figure.Pos_4 -= 25;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			// стоит или лежит
			return true;
		}
		else {	return false;}	
	}
	// буква Г  лажится вверх головой
	bool TURN_letter_G_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Up(basicdata, figure.Pos_3) &&
			predicate.Up(basicdata, figure.Pos_4)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 += 23;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 -= 2;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_4, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmEmpty());
			figure.Pos_4 -= 23;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			// стоит или лежит
			return true;
		}
		else { return false; }
	}
	// буква Г лажится влево 
	bool TURN_letter_G_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_3, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 -= 25;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 -= 48;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_4, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmEmpty());
			figure.Pos_4 += 25;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			// стоит или лежит
			return true;
		}
		else { return false; }
	}
	// буква Г становится прямо
	bool TURN_letter_G_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Up(basicdata, figure.Pos_3) &&
			predicate.Up(basicdata, figure.Pos_4)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 -= 23;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 += 2;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_4, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmEmpty());
			figure.Pos_4 += 23;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			// стоит или лежит
			return true;
		}
		else { return false; }
	}
	~Latter_G() {};
};

