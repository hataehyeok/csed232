#include "menu.h"
int main()
{
    WhiteBoard board;
    AShapeList shape_list;
    Menu menu(&board, &shape_list);
    while (menu.getRunning())
    {
        //WhiteBoard Display
        board.reset();
        shape_list.drawAll(&board);
        board.display();
        //Menu Display & Get Input
        menu.display();
        menu.getUserInput();
    }
    return 0;
}