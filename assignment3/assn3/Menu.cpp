#include "Menu.h"

using namespace std;

Menu::Menu(WhiteBoard* board, AShapeList* shape_list)
	:is_running(true)
{
	this->board = board;
	this->shape_list = shape_list;
}


Menu::~Menu()
{
}

void Menu::display() const
{
	cout << "[=========]" << endl << "[Select Menu]" << endl << "[=========]" << endl;
	cout << "1. add new shape" << endl << "2. delete existing shape" << endl << "3. exit" << endl << ">>";
}

bool Menu::getRunning() const
{
	if (is_running == true)
		return is_running;
	cout << "Exit Program" << endl;
	return is_running;
}

void Menu::getUserInput()
{
	int u_in;		//user_input, it must be 1 or 2 or 3
	cin >> u_in;

	while (u_in != 1 && u_in != 2 && u_in != 3)		//When input value has other case, repeat this section
	{
		cout << "Invalid input. Type again" << endl;
		board->display();
		display();
		cin >> u_in;
	}

	if (u_in == 1)
	{
		is_running = true;
		addAShape();
	}
	else if (u_in == 2)
	{
		is_running = true;
		deleteAShape();
	}
	else
		is_running = false;		//record for program terminate
}

void Menu::addAShape() const
{
	char alph;		//input value, alphabet
	int xi, xf, yi, yf;		//input value, coordinates

	cout << "[Add New AShape]" << endl;
	cout << "Enter Alphabet >>";
	cin >> alph;
	cout << "Enter x_start >>";
	cin >> xi;
	cout << "Enter x_end >>";
	cin >> xf;
	cout << "Enter y_start >>";
	cin >> yi;
	cout << "Enter y_end >>";
	cin >> yf;
	
	//Consider error case
	if (xi > xf)
	{
		cout << "Error: x_start exceed x_end" << endl;
		return;
	}
	if (yi > yf)
	{
		cout << "Error: y_start exceed y_end" << endl;
		return;
	}
	if (xi < 0 || xf < 0 || yi < 0 || yf < 0)
	{
		cout << "Error: coordinate cannot be negative value" << endl;
		return;
	}
	if (xi > 14 || xf > 14 || yi > 14 || yf > 14)
	{
		cout << "Error: your input exceed whiteboard size" << endl;
		return;
	}

	AShape* s;		//Shape object

	if (xi == xf && yi == yf)
	{
		s = new APoint(xi, yi, alph);
		cout << "New APoint added with size: 1" << endl;
	}	
	else if (xi == xf)
	{
		s = new AVerticalLine(xi, yi, yf, alph);
		cout << "New AVerticalLine added with size: " << s->size() << endl;
	}
		
	else if (yi == yf)
	{
		s = new AHorizontalLine(yi, xi, xf, alph);
		cout << "New AHorizontalLine added with size: " << s->size() << endl;
	}
	else
	{
		s = new ARectangle(xi, xf, yi, yf, alph);
		cout << "New ARectangle added with size: " << s->size() << endl;
	}

	shape_list->addNewAShape(s);
}

void Menu::deleteAShape() const
{
	int size = shape_list->getSize();
	if (size == 0)
	{
		cout << "AShapeList is empty." << endl;
		return;
	}

	int idx;		//user_input, index of delete node

	cout << "Choose index of AShape that you want to remove" << endl << "[========List of AShape========]" << endl;
	cout << "Current Size: " << size << endl;
	shape_list->displayAShapeList();
	cout << ">>";
	cin >> idx;

	if (idx < 0 || idx >= size)		//consider error case
	{
		cout << "Error: Index exceed size of AShapeList" << endl;
		return;
	}

	shape_list->popNodeByIdx(idx);
}