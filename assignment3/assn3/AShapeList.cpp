#include "AShapeList.h"
#include <iostream>

using namespace std;

AShapeList::AShapeList()
	:head(NULL), tail(NULL), size(0)
{
}

AShapeList::~AShapeList()
{
	for (; head != NULL; )
	{
		popNodeByIdx(0);
	}
}

void AShapeList::addNewAShape(AShape* new_shape)
{
	AShapeNode* nNode = new AShapeNode;		//new node to be added

	nNode->shape = new_shape;
	nNode->next = NULL;
	size++;

	if (head == NULL)
		head = nNode;
	else
		tail->next = nNode;
	tail = nNode;
}

void AShapeList::popNodeByIdx(int idx)		//delete index node form linked list and deallocate momory
{
	AShapeNode* tNode = head;		//target node, index node
	AShapeNode* fNode = head;		//front of target node, index - 1 node

	for (int i = 0; i < idx; i++)
		tNode = tNode->next;

	if (idx == 0)
	{
		if (size == 1)
			tail = tail->next;
		head = head->next;
	}
 	else
	{
		for (int i = 0; i < idx-1; i++)
			fNode = fNode->next;
		fNode->next = tNode->next;
	}

	size--;

	delete tNode->shape;
	delete tNode;
}

const AShapeNode* AShapeList::getNodeByIdx(int idx) const
{
	AShapeNode* idx_n = head;		//index node of linked list

	for (int i = 0; i < idx; i++)
		idx_n = idx_n->next;

	return idx_n;
}


void AShapeList::displayAShapeList() const
{
	AShapeNode* pNode = head;		//print node

	for (int i = 0; i < size; i++)
	{
		cout << i << ") ";
		pNode->shape->print();
		pNode = pNode->next;
	}
}

void AShapeList::drawAll(WhiteBoard* board) const
{
	AShapeNode* dNode = head;		//draw node

	for (int i = 0; i < size; i++)
	{
		dNode->shape->draw(board);
		dNode = dNode->next;
	}
}

int AShapeList::getSize() const
{
	return size;
}