#pragma once
#include "AShapeList.h"
#include "WhiteBoard.h"
#include "AShape.h"
#include "APoint.h"
#include "AVerticalLine.h"
#include "AHorizontalLine.h"
#include "ARectangle.h"
#include <iostream>

class Menu
{
private:
	bool is_running;
	AShapeList* shape_list;
	WhiteBoard* board;
public:
	Menu(WhiteBoard* board, AShapeList* shape_list);
	~Menu();
	void display() const;
	bool getRunning() const;
	void getUserInput();
	void addAShape() const;
	void deleteAShape() const;
};