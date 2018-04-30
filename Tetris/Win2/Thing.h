#pragma once
#include <windows.h>
#include <iostream>
#include "MyDefine.h"
#include "BasicData.h"
#include "BasicFunctional.h"
#include "MyPredicate.h"

class Thing
{
	const size_t POS_1_Thing = CHEK_AUT - 1;
	const size_t POS_2_Thing = CHEK_AUT;
	const size_t POS_3_Thing = CHEK_AUT + 1;

public:
	size_t label = 0;
	size_t POS_1()const { return POS_1_Thing; }
	size_t POS_2()const { return POS_2_Thing; }
	size_t POS_3()const { return POS_3_Thing; }

	std::vector<size_t> vecThingNext{ 68, 91, 92, 93 };

	//_|_ штука стоит и двигается в право
	void MOTION_right_thing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//_|_ штука стоит и двигается в влево
	void MOTION_left_thing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_1, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	//_|_ штука лежит вправо и двигается вправо
	void MOTION_right_thing_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//_|_ штука вправо и двигается влево
	void MOTION_left_thing_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1) &&
			predicate.Left(basicdata, figure.Pos_3, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	//_|_ штука стоит вверхголовой и двигается вправо
	void MOTION_right_thing_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//_|_ штука стоит вверхголовой и двигается влево
	void MOTION_left_thing_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_1, 1) &&
			predicate.Left(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	//_|_ штука лежит влево и двигается вправо
	void MOTION_right_thing_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_RIGHT(basicdata, figure);
		}
	}
	//_|_ штука лежит влево и двигается влево
	void MOTION_left_thing_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1) &&
			predicate.Left(basicdata, figure.Pos_1, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	//_|_ штука опускается стоя
	bool MOTION_dawn_thing_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_2) &&
			predicate.Down(basicdata, figure.Pos_4))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }

	}
	//_|_ штука лежит вправо опускается 
	bool MOTION_dawn_thing_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_1) &&
			predicate.Down(basicdata, figure.Pos_4))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	//_|_ штука лежит вверхголовой опускается 
	bool MOTION_dawn_thing_Lie_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_1) &&
			predicate.Down(basicdata, figure.Pos_2) &&
			predicate.Down(basicdata, figure.Pos_4))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	//_|_ штука лежит влево опускается
	bool MOTION_dawn_thing_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_1) &&
			predicate.Down(basicdata, figure.Pos_2))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else { return false; }
	}
	//_|_ штука лажится вправо 
	bool TURN_thing_Lie_right(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_4) &&
			predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Up(basicdata, figure.Pos_2)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 += CHEK_AUT + 1;
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
			figure.Pos_4 += CHEK_AUT - 1;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			return true;
		}
		else { return false; }
	}
	//_|_ штука  лажится вверх головой
	bool TURN_thing_Headsup(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_4, 1) &&
			predicate.Left(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 += CHEK_AUT - 1;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 += CHEK_AUT + 1;
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
	//_|_ штука лажится влево 
	bool TURN_thing_Lie_left(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_2) &&
			predicate.Up(basicdata, figure.Pos_3) &&
			predicate.Up(basicdata, figure.Pos_4)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 -= CHEK_AUT + 1;
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
			figure.Pos_4 -= CHEK_AUT - 1;
			basicdata.setVecLogic(figure.Pos_4, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_4),
				basicdata.gethBmFigure());
			return true;
		}
		else { return false; };
	}
	//_|_ штука становится прямо
	bool TURN_thing_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Left(basicdata, figure.Pos_2, 1)) {

			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 -= CHEK_AUT - 1;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 -= CHEK_AUT + 1;
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
	~Thing() {};
};