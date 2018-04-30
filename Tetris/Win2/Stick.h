#pragma once
#include <windows.h>
#include <iostream>
#include "MyDefine.h"
#include "BasicData.h"
#include "BasicFunctional.h"
#include "MyPredicate.h"

class Stick
{
	const size_t POS_1_Squre = CHEK_AUT;
	const size_t POS_2_Squre = CHEK_AUT * 2;
	const size_t POS_3_Squre = CHEK_AUT * 3;

	
public:
	bool label = false;
	size_t POS_1()const { return POS_1_Squre; }
	size_t POS_2()const { return POS_2_Squre; }
	size_t POS_3()const { return POS_3_Squre; }
	
	// для координат фигуры в малом окне
	std::vector<size_t> vecStickNext{ 68, 92, 116, 140 };
	

		//палка стоит и двигается вправо
		void mation_RIGHT_Stick(class BasicData& basicdata, struct MyPredicate& predicate,
			struct BasicFunctional& basicFunct, struct FigurePosit& figure){
			if (predicate.Right(basicdata, figure.Pos_1, 1) &&
				predicate.Right(basicdata, figure.Pos_2, 1) &&
				predicate.Right(basicdata, figure.Pos_3, 1) &&
				predicate.Right(basicdata, figure.Pos_4, 1))
			{
				basicFunct.mation_RIGHT(basicdata, figure);
			}
		}
		//палка стоит и двигается ввлево
		void mation_LEFT_Stick(class BasicData& basicdata, struct MyPredicate& predicate,
			struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
			if (predicate.Left(basicdata, figure.Pos_1, 1) &&
				predicate.Left(basicdata, figure.Pos_2, 1) &&
				predicate.Left(basicdata, figure.Pos_3, 1) &&
				predicate.Left(basicdata, figure.Pos_4, 1))
			{
				basicFunct.mation_LEFT(basicdata, figure);
			}
		}
	
	// палка лeжит и двигается вправо
	void mation_RIGHT_Stick_Lie(class BasicData& basicdata, struct MyPredicate& predicate,
			struct BasicFunctional& basicFunct, struct FigurePosit& figure){
			if (predicate.Right(basicdata, figure.Pos_1, 1))
			{
				basicFunct.mation_RIGHT(basicdata, figure);
			}
		}
	// палка лежит и двигается влево 
	void mation_LEFT_Stick_Lie(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_4, 1))
		{
			basicFunct.mation_LEFT(basicdata, figure);
		}
	}
	// палка опускается стоя
	bool mation_DOWN_Stick_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_4))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else {
			return false;
		}
	}

	// палка опускается  лежа
	bool mation_DOWN_Stick_Lie(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Down(basicdata, figure.Pos_1) &&
			predicate.Down(basicdata, figure.Pos_2) &&
			predicate.Down(basicdata, figure.Pos_3) &&
			predicate.Down(basicdata, figure.Pos_4))
		{
			basicFunct.mation_DOWN(basicdata, figure);
			return true;
		}
		else {
			return false;
		}
	}

	// палка ложится
	bool TURN_Stick_Lie(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Right(basicdata, figure.Pos_1, 1) &&
			predicate.Right(basicdata, figure.Pos_2, 1) &&
			predicate.Right(basicdata, figure.Pos_3, 1) &&
			predicate.Right(basicdata, figure.Pos_4, 1) &&
			predicate.Right(basicdata, figure.Pos_1, 2) &&
			predicate.Right(basicdata, figure.Pos_2, 2) &&
			predicate.Right(basicdata, figure.Pos_3, 2) &&
			predicate.Right(basicdata, figure.Pos_4, 2) && 
			predicate.Right(basicdata, figure.Pos_1, 3) &&
			predicate.Right(basicdata, figure.Pos_2, 3) &&
			predicate.Right(basicdata, figure.Pos_3, 3) &&
			predicate.Right(basicdata, figure.Pos_4, 3)) 
			
		{
			
		
		basicdata.setVecLogic(figure.Pos_1, EMPTY); 
		basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
			basicdata.gethBmEmpty());
		figure.Pos_1 += 75;
		basicdata.setVecLogic(figure.Pos_1, FIGURE);
		basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
			basicdata.gethBmFigure());
				
		basicdata.setVecLogic(figure.Pos_2, EMPTY);
		basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
			basicdata.gethBmEmpty());
		figure.Pos_2 += 50;
		basicdata.setVecLogic(figure.Pos_2, FIGURE);
		basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
			basicdata.gethBmFigure());

		basicdata.setVecLogic(figure.Pos_3, EMPTY);
		basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_3),
			basicdata.gethBmEmpty());
		figure.Pos_3 += 25;
		basicdata.setVecLogic(figure.Pos_3, FIGURE);
		basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_3),
			basicdata.gethBmFigure());
		return true;
		}
		else {
			return false;
		}
	}

	// палка становится
	bool TURN_Stick_Standing(class BasicData& basicdata, struct MyPredicate& predicate,
		struct BasicFunctional& basicFunct, struct FigurePosit& figure) {
		if (predicate.Left(basicdata, figure.Pos_1, CHEK_AUT) &&
			predicate.Left(basicdata, figure.Pos_2, CHEK_AUT) &&
			predicate.Left(basicdata, figure.Pos_3, CHEK_AUT) &&
			predicate.Left(basicdata, figure.Pos_4, CHEK_AUT) &&
			predicate.Left(basicdata, figure.Pos_1, CHEK_AUT * 2) &&
			predicate.Left(basicdata, figure.Pos_2, CHEK_AUT * 2) &&
			predicate.Left(basicdata, figure.Pos_3, CHEK_AUT * 2) &&
			predicate.Left(basicdata, figure.Pos_4, CHEK_AUT * 2) &&
			predicate.Left(basicdata, figure.Pos_1, CHEK_AUT * 3) &&
			predicate.Left(basicdata, figure.Pos_2, CHEK_AUT * 3) &&
			predicate.Left(basicdata, figure.Pos_3, CHEK_AUT * 3) &&
			predicate.Left(basicdata, figure.Pos_4, CHEK_AUT * 3))
			
		{
			basicdata.setVecLogic(figure.Pos_1, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmEmpty());
			figure.Pos_1 -= 75;
			basicdata.setVecLogic(figure.Pos_1, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_1),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_2, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmEmpty());
			figure.Pos_2 -= 50;
			basicdata.setVecLogic(figure.Pos_2, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_2),
				basicdata.gethBmFigure());

			basicdata.setVecLogic(figure.Pos_3, EMPTY);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_3),
				basicdata.gethBmEmpty());
			figure.Pos_3 -= 25;
			basicdata.setVecLogic(figure.Pos_3, FIGURE);
			basicFunct.imageChange(basicdata.getVecBasic(figure.Pos_3),
				basicdata.gethBmFigure());
			
			return true;
		}
		else {
			return false;
		}
	}
	
	~Stick() {};
};

