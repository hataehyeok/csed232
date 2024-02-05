#pragma once
#include "AShape.h"
#include "WhiteBoard.h"
#include <iostream>

struct AShapeNode
{
	AShape* shape;
	AShapeNode* next;
};

class AShapeList
{
private:
	AShapeNode* head;
	AShapeNode* tail;
	int size;

public:
	AShapeList();
	~AShapeList();
	void addNewAShape(AShape* new_shape);
	void popNodeByIdx(int idx);		//modify this mothod from original method
	const AShapeNode* getNodeByIdx(int idx) const;
	void displayAShapeList() const;
	void drawAll(WhiteBoard* board) const;
	int getSize() const;
};