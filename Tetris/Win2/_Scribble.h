#pragma once
#include <windows.h>
#include <iostream>
#include "MyDefine.h"
#include "BasicData.h"
#include "BasicFunctional.h"
#include "MyPredicate.h"

class Scribble
{
	const size_t POS_1__Scribble = CHEK_AUT;
	const size_t POS_2__Scribble = CHEK_AUT + 1;
	const size_t POS_3__Scribble = CHEK_AUT * 2 + 1;



public:
	bool label = false;
	size_t POS_1()const { return POS_1__Scribble; }
	size_t POS_2()const { return POS_2__Scribble; }
	size_t POS_3()const { return POS_3__Scribble; }

	std::vector<size_t> vec_ScribbleNext{ 67, 68, 92, 93 };


	///*****Движение _-- закарючки
	//_-- закарючка стоит и двигается в право
	void MOTION_Scribble_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//_-- закарючка стоит и двигается в влево
	void MOTION_Scribble_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_1, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	//_-- закарючка лежит вправо и двигается вправо
	void MOTION_right_Scribble_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//_-- закарючка лежит вправо и двигается влево
	void MOTION_left_Scribble_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	//_-- закарючка опускается стоя
	bool MOTION_down_Scribble_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Down(basicdata, figure.Pos_2))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }

	}
	//_-- закарючка лежит вправо опускается 
	bool MOTION_down_Scribble_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Down(basicdata, figure.Pos_1) &&
			predicate.Down(basicdata, figure.Pos_3))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	//_-- закарючка лажится вправо 
	bool TURN_Scribble_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_1, 2)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 += 2;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 -= CHEK_AUT - 1;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_4, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmEmpty());
			figure.Pos_4 -= CHEK_AUT + 1;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			return true;
		}
		else { return false; }
	}

	//_-- закарючка становится прямо
	bool TURN_Scribble_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {

		if (predicate.Left(basicdata, figure.Pos_2, 1) &&
			predicate.Down(basicdata, figure.Pos_1) &&
			predicate.Down(basicdata, figure.Pos_1)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 -= 2;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 += CHEK_AUT - 1;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_4, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmEmpty());
			figure.Pos_4 += CHEK_AUT + 1;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			return true;
		}
		else { return false; }
	}
	~ Scribble() {};
};
