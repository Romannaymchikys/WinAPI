
#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
#include "resource.h"
#include "MyDefine.h"
#include "BasicFunctional.h"





// структура с расположением элементов фигуры
struct FigurePosit {
	size_t Pos_1;
	size_t Pos_2;
	size_t Pos_3;
	size_t Pos_4;
};

class BasicData
{
	// вектор для дискрипторов ячеек
	std::vector<HWND> vecBasicGridHWND;
	// вектор для логической растоновки
	std::vector<wchar_t> vecLogicAlig;
	// дискрипторы основных битмапов
	HBITMAP hBmFigure, hBmFrame, hBmEmpty;
	// дискрипторы кнопок
	HWND hWnd, hLeft, hRight, hdown, hSpace;
	// вектор для хронения координат стирание фигур в малом окне(каторые идут следующие)
	std::vector<size_t> vecCoord;

	size_t numberFigure, numberNextFigure;
	
public:
	BasicData(HWND newHwnd) : hWnd(newHwnd),
		          hBmFigure(LoadBitmap(GetModuleHandle(NULL),
		                       MAKEINTRESOURCE(Id_BITMAP1))),
		           hBmFrame(LoadBitmap(GetModuleHandle(NULL),
					           MAKEINTRESOURCE(Id_BITMAP2))),
		           hBmEmpty(LoadBitmap(GetModuleHandle(NULL), 
					           MAKEINTRESOURCE(Id_BITMAP3))){
		hLeft  = GetDlgItem(newHwnd, VK_LEFT);
		hRight = GetDlgItem(newHwnd, VK_RIGHT);
		hdown  = GetDlgItem(newHwnd, VK_DOWN);
		hSpace = GetDlgItem(newHwnd, VK_SPACE);
	};
	HWND getVecBasic(const size_t index) const {
		return vecBasicGridHWND.at(index);
     }
	wchar_t getVecLogic(const size_t index) const {
		return vecLogicAlig.at(index);
	}
	std::vector<size_t> getVecCoord() const {
		return vecCoord;
	}
	size_t getVecCoord_Size() const {
		return vecCoord.size();
	}
	
	HBITMAP gethBmFigure()const { return hBmFigure; }
	HBITMAP gethBmFrame()const  { return hBmFrame; }
	HBITMAP gethBmEmpty()const  { return hBmEmpty; }
	HWND getHWnd()const { return hWnd; }
	HWND getHLeft()const { return hLeft; }
	HWND getHRight()const { return hRight; }
	HWND getHDown()const { return hdown; }
	HWND getHSpace()const { return hSpace; }
	size_t getnumberFigure()const { return numberFigure; }
	size_t getnextNumberFigure()const { return numberNextFigure; }
	void setVecBasic(const size_t index, const HWND hbitmap) {
		vecBasicGridHWND.at(index) = hbitmap;
	}
	void setVecLogic( size_t index, const wchar_t symbol) {
		vecLogicAlig.at(index) = symbol;
	}
	void setnumberFigure(const size_t newNumberFigure) {
		numberFigure = newNumberFigure;
	}
	void setnumberNextFigure(const size_t newNumberNextFigure){
		numberNextFigure = newNumberNextFigure;
	}
	void InitVecLogicAlig();
	void InitVecCoord();
	void InitVecBasicGridHWND(struct BasicFunctional&);
	void InitFigureSize(class FigurePosit&, const size_t, const size_t, const size_t);

	~BasicData() {};
};