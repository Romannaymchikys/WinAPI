#include <windows.h>
#include <vector>
#include <tchar.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "resource.h"
#include "MyDefine.h"
#include "BasicData.h"
#include "BasicFunctional.h"
#include "MyPredicate.h"
#include "Square.h"
#include "Stick.h"
#include "Latter_G.h"
#include "_Scribble.h"
#include "Thing.h"


struct AllFigures {
	Stick stick;
	Square square;
	Latter_G letter_G;
	Scribble scribble;
	Thing thing;
};

void InitSelecNextFigures(struct AllFigures& , struct FigurePosit& ,
	                      class BasicData& ,class BasicFunctional& , bool&);
void MationLEFTFigures(struct AllFigures&, struct FigurePosit&,
	class BasicData&, class BasicFunctional&, struct MyPredicate&);
void MationRIGHTFigures(struct AllFigures&, struct FigurePosit&,
	class BasicData&, class BasicFunctional&, struct MyPredicate&);
void MationDOWNFigures(struct AllFigures&, struct FigurePosit&,
	class BasicData&, class BasicFunctional&, struct MyPredicate&, bool&);
void ChangeSositionFigures(struct AllFigures&, struct FigurePosit&,
	class BasicData&, class BasicFunctional&, struct MyPredicate&);


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage,
	                                WPARAM wParam, LPARAM lParam)
{
	static FigurePosit figure;
	static BasicData basicData(hWnd);
	static MyPredicate predicate;
	static BasicFunctional basicFunct;
	static AllFigures allFigures;
	
	static bool FLAG_LEFT, FLAG_RIGHT, FLAG_DOWN, FLAG_G;
	static bool selector;
	
	switch (uMessage)
	{
	case WM_CREATE:
		basicData.InitVecLogicAlig();
		basicData.InitVecCoord();
		basicData.InitVecBasicGridHWND(basicFunct);
		// первый выбор фигуры
		basicFunct.FirstChoiceFigure(basicData);
		InitSelecNextFigures(allFigures, figure,basicData, basicFunct, selector);
		SetTimer(hWnd, 1, 100, NULL);
		SetTimer(hWnd, 2, 10, NULL);
		break;

	case WM_CHAR:
		if (wParam == VK_DOWN_1 || wParam == VK_DOWN_2) {
 			FLAG_DOWN = true;
			SendMessage(hWnd, WM_TIMER, 0, 0);
			break;
		}
		if (wParam == VK_G_1 || wParam == VK_G_2) {
			FLAG_G = true;
			SendMessage(hWnd, WM_TIMER, 0, 0);
			break;
		}
		if (wParam == VK_LEFT_1 || wParam == VK_LEFT_2) {
			FLAG_LEFT = true;
			SendMessage(hWnd, WM_TIMER, 0, 0);
			break;
		}
		if (wParam == VK_RIGHT_1 || wParam == VK_RIGHT_2) {
     		FLAG_RIGHT = true;
			SendMessage(hWnd, WM_TIMER, 0, 0);
			break;
		}
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case (1):
			if (!FLAG_DOWN) {
				//______________________________________________________________________________________________
			//движение влево
				if (FLAG_LEFT) {
					MationLEFTFigures(allFigures, figure, basicData, basicFunct, predicate);
					FLAG_LEFT = false;
				}
				//______________________________________________________________________________________________
			   //движение вправо
				if (FLAG_RIGHT) {
					MationRIGHTFigures(allFigures, figure, basicData, basicFunct, predicate);
					FLAG_RIGHT = false;
				}
				//______________________________________________________________________________________________	
			   // фигура меняет позицию
				if (FLAG_G) {
					ChangeSositionFigures(allFigures, figure, basicData, basicFunct, predicate);

					FLAG_G = false;
				}
				//______________________________________________________________________________________________	
			   // движение вниз
				MationDOWNFigures(allFigures, figure, basicData, basicFunct, predicate, selector);
			}
			//______________________________________________________________________________________________	
		   // ускорение
		case (2):
			if (FLAG_DOWN) {
				MationDOWNFigures(allFigures, figure, basicData, basicFunct, predicate, selector);
				FLAG_DOWN = false;
			}
			//______________________________________________________________________________________________
		   //рисование новой фигуры
			if (selector) {
				basicFunct.RandomChoiceFigure(basicData);
				InitSelecNextFigures(allFigures, figure, basicData, basicFunct, selector);

			}
		}
		break;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
 }

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, 
	                 LPSTR lpszCmdLine, int nCmdShow)
{
	
	WNDCLASSEX wnd;

	wnd.cbSize = sizeof(wnd);
	wnd.lpszClassName = TEXT("Window");
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	wnd.hCursor =LoadCursor(NULL, IDC_ARROW);
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hbrBackground = (HBRUSH)GetStockObject(BLACK_PEN);//фон
	wnd.lpszMenuName = NULL;
	wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, TEXT("Sorry :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}
	// дискриптор окна
	HWND hWnd = CreateWindowEx(WS_EX_WINDOWEDGE,
		TEXT("Window"),
		TEXT("Window "),
		WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX,
		250,
		0,
		NUMBER_STEP_WIDTH * STEP + 15,
		NUMBER_STEP_HEGHT * STEP + 36,
		NULL, 
		NULL,
		hInstance,
		NULL);

	if (!hWnd) {
		MessageBox(NULL, TEXT("Sorry... :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);
	

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);// воспринемает код из клавиатуры
		DispatchMessage(&msg); // непосредственно отправляет сообщение
	}
	return msg.wParam;
}

void InitSelecNextFigures(struct AllFigures& allFigures,
	                      struct FigurePosit& figure,
	                      class BasicData& basicData,
	                      class BasicFunctional& basicFunct, bool& selector) {
	allFigures.stick.label = true;
	allFigures.scribble.label = true;
	allFigures.letter_G.label = 0;
	allFigures.thing.label = 0;
	selector = false;

	switch (basicData.getnumberFigure())
	{
	case (0): basicData.InitFigureSize(figure, allFigures.square.POS_1(),
		allFigures.square.POS_2(), allFigures.square.POS_3());
		break;
	case (1): basicData.InitFigureSize(figure, allFigures.stick.POS_1(),
		allFigures.stick.POS_2(), allFigures.stick.POS_3());
		break;
	case (2): basicData.InitFigureSize(figure, allFigures.letter_G.POS_1(),
		allFigures.letter_G.POS_2(), allFigures.letter_G.POS_3());
		break;
	case (3): basicData.InitFigureSize(figure, allFigures.scribble.POS_1(),
		allFigures.scribble.POS_2(), allFigures.scribble.POS_3());
		break;
	case (4): basicData.InitFigureSize(figure, allFigures.thing.POS_1(),
		allFigures.thing.POS_2(), allFigures.thing.POS_3());
		break;
	}
	switch (basicData.getnextNumberFigure())
	{
	case (0):basicFunct.RANDOM(basicData, basicFunct, allFigures.square.vecSquareNext);
		break;
	case (1):basicFunct.RANDOM(basicData, basicFunct, allFigures.stick.vecStickNext);
		break;
	case (2):basicFunct.RANDOM(basicData, basicFunct, allFigures.letter_G.vecLetter_GNext);
		break;
	case (3):basicFunct.RANDOM(basicData, basicFunct, allFigures.scribble.vec_ScribbleNext);
		break;
	case (4):basicFunct.RANDOM(basicData, basicFunct, allFigures.thing.vecThingNext);
		break;
	}
}



void MationLEFTFigures(struct AllFigures& allFigures,
	                   struct FigurePosit& figure,
	                   class BasicData& basicData,
	                   class BasicFunctional& basicFunct, 
	                   struct MyPredicate& predicate) {
	switch (basicData.getnumberFigure()) {

	case(0):  allFigures.square.mation_LEFT_Square(basicData, predicate, 
		                                           basicFunct, figure);
		break;


	case(1): if (allFigures.stick.label) { 
		      allFigures.stick.mation_LEFT_Stick(basicData, predicate, 
				                                 basicFunct, figure); 
	            }
			 else {
				 allFigures.stick.mation_LEFT_Stick_Lie(basicData, predicate,
				                                        basicFunct, figure); 
			 }
			 break;


	case(2):switch (allFigures.letter_G.label){

	       case(0):allFigures.letter_G.MOTION_left_letter_G(basicData, predicate,
		                                             basicFunct, figure);
		            break;
	       case(1):allFigures.letter_G.MOTION_left_letter_G_Lie_right(basicData, predicate,
			                                                          basicFunct, figure);
		            break;
	       case(2):allFigures.letter_G.MOTION_left_letter_G_Headsup(basicData, predicate,
		                                                            basicFunct, figure);
		            break;
	       case(3):allFigures.letter_G.MOTION_left_letter_G_Lie_left(basicData, predicate,
			                                                        basicFunct, figure);
		           break;
	       }
			break;


	case(3): if (allFigures.scribble.label) { 
		           allFigures.scribble.MOTION_Scribble_left(basicData, predicate,
					                                        basicFunct, figure);
	          }
			 else {
				 allFigures.scribble.MOTION_left_Scribble_Lie_left(basicData, predicate,
					                                               basicFunct, figure); }
			 break;


	case(4):switch (allFigures.thing.label)
	       {
	        case(0):allFigures.thing.MOTION_left_thing(basicData, predicate,
				                                       basicFunct, figure);
		          break;
	        case(1):allFigures.thing.MOTION_left_thing_Lie_left(basicData, predicate,
				                                                basicFunct, figure);
		          break;
	        case(2):allFigures.thing.MOTION_left_thing_Headsup(basicData, predicate,
				                                               basicFunct, figure);
		          break;
	        case(3):allFigures.thing.MOTION_left_thing_Lie_right(basicData, predicate, 
				                                                 basicFunct, figure);
		         break;
	       }
	}

}


void MationRIGHTFigures(struct AllFigures& allFigures,
	                    struct FigurePosit& figure,
	                    class BasicData& basicData,
	                    class BasicFunctional& basicFunct,
	                    struct MyPredicate& predicate) {
	switch (basicData.getnumberFigure()) {

	case(0): allFigures.square.mation_RIGHT_Square(basicData, predicate,
		                                           basicFunct, figure);
		   break;


	case(1):if (allFigures.stick.label) { 
		allFigures.stick.mation_RIGHT_Stick(basicData, predicate,
			                                basicFunct, figure);
	              }
			else { 
				allFigures.stick.mation_RIGHT_Stick_Lie(basicData, predicate,
					                                    basicFunct, figure);
			}
			break;


	case(2):switch (allFigures.letter_G.label){

	       case(0):allFigures.letter_G.MOTION_right_letter_G(basicData, predicate,
			                                                 basicFunct, figure);
		          break;
	      case(1):allFigures.letter_G.MOTION_right_letter_G_Lie_right(basicData, predicate, 
			                                                          basicFunct, figure);
		          break;
	      case(2):allFigures.letter_G.MOTION_right_letter_G_Headsup(basicData, predicate,
			                                                        basicFunct, figure);
		          break;
	      case(3):allFigures.letter_G.MOTION_right_letter_G_Lie_left(basicData, predicate,
			                                                         basicFunct, figure);
		          break;
	}
			break;


	case(3): if (allFigures.scribble.label) {
		        allFigures.scribble.MOTION_Scribble_right(basicData, predicate,
					                                      basicFunct, figure); 
	         }
			 else {
				 allFigures.scribble.MOTION_right_Scribble_Lie_right(basicData, predicate,
					                                                 basicFunct, figure); 
			 }
			 break;


	case(4):switch (allFigures.thing.label)
	        {
	        case(0):allFigures.thing.MOTION_right_thing(basicData, predicate,
				                                        basicFunct, figure);
		           break;
	        case(1):allFigures.thing.MOTION_right_thing_Lie_right(basicData, predicate, 
				                                                  basicFunct, figure);
		           break;
	        case(2):allFigures.thing.MOTION_right_thing_Headsup(basicData, predicate,
				                                                basicFunct, figure);
	               break;
	       case(3):allFigures.thing.MOTION_right_thing_Lie_left(basicData, predicate, basicFunct, figure);
		          break;
	      }
	}
}

void MationDOWNFigures(struct AllFigures& allFigures,
	                   struct FigurePosit& figure,
	                    class BasicData& basicData,
	                    class BasicFunctional& basicFunct,
	                   struct MyPredicate& predicate, bool& selector) {
	switch (basicData.getnumberFigure()) {
	case (0): if (!(allFigures.square.mation_DAWN_Square(basicData, predicate, 
		                                                basicFunct, figure))) {
		basicFunct.Sweeping(basicData);
		selector = true;
	}
			  break;


	case (1):if (allFigures.stick.label) {
		if (!(allFigures.stick.mation_DOWN_Stick_Standing(basicData, predicate, 
			                                              basicFunct, figure))) {
			basicFunct.Sweeping(basicData);
			selector = true;
		}
	}
			 else {
				 if (!(allFigures.stick.mation_DOWN_Stick_Lie(basicData, predicate,
					                                          basicFunct, figure))) {
					 basicFunct.Sweeping(basicData);
					 selector = true;
				 }
			 }
			 break;


	case(2):switch (allFigures.letter_G.label)
	        {
	         case(0):if (!(allFigures.letter_G.MOTION_dawn_letter_G_Standing(basicData, predicate, 
		                                                                     basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	        }
			 break;
	         case(1):if (!(allFigures.letter_G.MOTION_dawn_letter_G_Lie_right(basicData, predicate, 
				                                                              basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	        }
			 break;
	         case(2):if (!(allFigures.letter_G.MOTION_dawn_letter_G_Lie_Headsup(basicData, predicate,
				                                                                basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	                }
			        break;
	         case(3):if (!(allFigures.letter_G.MOTION_dawn_letter_G_Lie_left(basicData, predicate,
				                                                             basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	                }
			        break;
	        }
			break;


	case (3):	if (allFigures.scribble.label) {
		if (!(allFigures.scribble.MOTION_down_Scribble_Standing(basicData, predicate, 
			                                                    basicFunct, figure))) {
			basicFunct.Sweeping(basicData);
			selector = true;
		}
	  }
				else {
					if (!(allFigures.scribble.MOTION_down_Scribble_Lie_right(basicData, predicate, 
						                                                     basicFunct, figure))) {
						basicFunct.Sweeping(basicData);
						selector = true;
					}
				}
				break;


	case(4):switch (allFigures.thing.label)
	        {
	         case(0):if (!(allFigures.thing.MOTION_dawn_thing_Standing(basicData, predicate,
				                                                       basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	                }
			         break;
	         case(1):if (!(allFigures.thing.MOTION_dawn_thing_Lie_right(basicData, predicate,
				                                                        basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	                }
			         break;
	         case(2):if (!(allFigures.thing.MOTION_dawn_thing_Lie_Headsup(basicData, predicate,
				                                                          basicFunct, figure))) {
		             basicFunct.Sweeping(basicData);
		             selector = true;
	                }
			         break;
	         case(3):if (!(allFigures.thing.MOTION_dawn_thing_Lie_left(basicData, predicate,
				                                                       basicFunct, figure))) {
	 	             basicFunct.Sweeping(basicData);
		             selector = true;
	                }
			         break;
	       }
	}
}


void ChangeSositionFigures(struct AllFigures& allFigures,
	                       struct FigurePosit& figure,
	                        class BasicData& basicData,
	                        class BasicFunctional& basicFunct,
	                       struct MyPredicate& predicate) {

	switch (basicData.getnumberFigure())
	{
	case (1): if (allFigures.stick.label) {
		if (allFigures.stick.TURN_Stick_Lie(basicData, predicate,
			                               basicFunct, figure)) {
			allFigures.stick.label = false;
		}
	}
			  else {
				  if (allFigures.stick.TURN_Stick_Standing(basicData, predicate,
					                                       basicFunct, figure)) {
					  allFigures.stick.label = true;
				  }
			  }
			  break;


	case (2):
		if (allFigures.letter_G.label < 3) {
			allFigures.letter_G.label++;
		}
		else { allFigures.letter_G.label = 0; }
		switch (allFigures.letter_G.label)
		      {
		       case(0):allFigures.letter_G.TURN_letter_G_Standing(basicData, predicate,
				                                                  basicFunct, figure);
			   break;
		       case(1):allFigures.letter_G.TURN_letter_G_Lie_right(basicData, predicate,
				                                                   basicFunct, figure);
			   break;
		       case(2):allFigures.letter_G.TURN_letter_G_Headsup(basicData, predicate, 
				                                                 basicFunct, figure);
			   break;
		       case(3):allFigures.letter_G.TURN_letter_G_Lie_left(basicData, predicate, 
				                                                  basicFunct, figure);
			   break;
		}
		break;


	case (3): if (allFigures.scribble.label) {
		if (allFigures.scribble.TURN_Scribble_Lie_right(basicData, predicate, 
			                                            basicFunct, figure)) {
			allFigures.scribble.label = false;
		}
	}
			  else {
				  if (allFigures.scribble.TURN_Scribble_Standing(basicData, predicate, 
					                                             basicFunct, figure)) {
					  allFigures.scribble.label = true;
				  }
			  }
			  break;


	case (4):
		if (allFigures.thing.label < 3) {
			allFigures.thing.label++;
		}
		else { allFigures.thing.label = 0; }
		switch (allFigures.thing.label)
		      {
		       case(0):allFigures.thing.TURN_thing_Standing(basicData, predicate, 
			                                                basicFunct, figure);
			   break;
		       case(1):allFigures.thing.TURN_thing_Lie_right(basicData, predicate,
				                                             basicFunct, figure);
			   break;
		       case(2):allFigures.thing.TURN_thing_Headsup(basicData, predicate,
			   basicFunct, figure);
			   break;
		       case(3):allFigures.thing.TURN_thing_Lie_left(basicData, predicate, 
				                                            basicFunct, figure);
			   break;
		}
	}
}