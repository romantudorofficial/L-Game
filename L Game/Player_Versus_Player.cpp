/**
    This is the implementation for the Player versus Player game mode module.
    The module is responsible with the player versus player game mode.
**/

#include "Player_Versus_Player.h"
#include "Controller.h"

#include <graphics.h>
#include <iostream>
#include <Windows.h>



/**
    Start the game in the player versus player game mode.
    Input:
        - none
    Output:
        - starts the game in the player versus player game mode
**/
void startMultiplayerGame ()
{
    GameBoard board;
    bool player = false;    // False -> The Red Player; True -> The Blue Player

    // Clear the window.
    cleardevice();

    // Draw the game board.board.cell[0][0].getPosition("ox")
    board.drawBoard(board);
    readData(board.boardData, board);

    printBoard(board.boardData);
    board.loadNewGame(board);

    // Temporary: just for testing
    delay(300);

    while (true)
    {
        switch (player)
        {
            // The red player's Turn
            case false:
                board.redMove(board);
                break;

            // The blue player's turn
            default:
            {
                // To add.
            }
        }

        // Change player.
        player = !player;
    }
}



/**
    Sets the colour of a cell.
    Input:
        - "color": the color of the cell
    Output:
        - sets the colour of the cell to its new, given value
**/
void Cell::setColor (int color)
{
    cellColor = color;
    setfillstyle(SOLID_FILL, color);
    floodfill(posX, posY, WHITE);
}



/**
    Draws a cell.
    Input:
        - "left": the left margin of the cell
        - "up": the upper margin of the cell
        - "right": the right margin of the cell
        - "bottom": the bottom margin of the cell
    Output:
        - draws the cell
**/
void Cell::drawCell (int left, int up, int right, int bottom)
{
    rectangle(left, up, right, bottom);
}



/**
    Updates the size of the cell.
    Input:
        - "newSize": the new size of the cell
    Output:
        - updates the cell size
**/
int Cell::changeCellSize (int newSize)
{
    newSize = newSize;
    return newSize;
}



/**
    ???
    Input:
        - "pX": position on ox
        - "pY": position on oy
    Output:
        - changes the private variables posx and posy
**/
void Cell::setPosition (int pX, int pY)
{
    posX = pX;
    posY = pY;
}



/**
    Gets the colour of the cell.
    Input:
        - none
    Output:
        - the colour of the cell
**/
int Cell::getColor ()
{
    return cellColor;
}



/**
    Draws a coin.
    Input:
        - none
    Output:
        - draws the coin
**/
void Coin::drawCoin (int xCoord, int yCoord)            /// We have to change this function to be more flexible-----> pls ask me wtf i meant by that
{                                                       /// WTF DID YOU MEAN???????
                                                        /// xDDD  I changed it so the coin will spawn at some coordonates saved in each cell object. Waiting for your answer!!!
                                                        /// ...
                                                        /// PUTIN E DE VIN... HEI, AUU, STATI  SFFG DATI-MI DRUMUL... SDFSD... FS.FSA.DFG DFG.....A SF......... .... ..SD GFDG...
    int height = GetSystemMetrics(SM_CYSCREEN);
    int cellSize = (height - 200) / 4;
    circle(xCoord, yCoord, getCoinSize());
    setfillstyle(SOLID_FILL, YELLOW);

    // Colour the cell.
    floodfill(xCoord, yCoord, WHITE);
}



/**
    ???
    Input:
        -
    Output:
        -
**/
int Cell::getPosition (char* axis)
{
    if (strcmp(axis, "ox") == 0)
        return posX;

    else if (strcmp(axis, "oy") == 0)
        return posY;

    return -1;
}



/**
    Draws the game board.
    Input:
        - none
    Output:
        - draws the game board
**/
void GameBoard::drawBoard (GameBoard &board)
{
    int xCoord = 0, yCoord = 0;
    int width = getmaxx();
    int height = getmaxy();
    int cellSize = (height - 200) / 4;
    int position = width / 2 - (3 * cellSize) / 2;
    cellSize = board.cell[xCoord][yCoord].changeCellSize(cellSize);///change the value in the class

    for (int i = width / 2 - 2 * cellSize; i <= width / 2 + cellSize; i += cellSize)
    {
        for (int j = height / 4 - cellSize; j <= height / 4 + 2 * cellSize; j += cellSize)
        {
            board.cell[xCoord][yCoord].drawCell(i, j,i + cellSize, j + cellSize);///draw the cell
            board.cell[xCoord][yCoord].setPosition(i + cellSize/2, j + cellSize/2);
            board.cell[xCoord][yCoord].setColor(BLACK);///set the black color to the cells
            xCoord++;
        }
        xCoord = 0;
        yCoord++;
    }
}



/**
    Load new game.
    Input:
        -
    Output:
        -
**/
void GameBoard::loadNewGame (GameBoard &board)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            if (board.boardData[i][j] == 1)
                board.cell[i][j].setColor(RED);
            else if (board.boardData[i][j] == 2)
                board.cell[i][j].setColor(BLUE);
            else if (board.boardData[i][j] == 3)
                    board.coin.drawCoin(board.cell[i][j].getPosition("ox"),board.cell[i][j].getPosition("oy"));
        }
}



/**
    ???
    Input:
        - the board of the game
    Output:
        - nuj stai sa vedem
**/
void GameBoard::redMove (GameBoard& gameBoard)
{
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (gameBoard.boardData[i][j] == 1)
                {
                    gameBoard.boardData[i][j] = 0; // deletes the positions occupied by his previous move
                    gameBoard.cell[i][j].setColor(BLACK); // sets the color of the occupied cell to BLACK to show that it's a free cell
                }
        while (1)
        {
            int playerColor = RED;
            POINT mousePos; // we'll save the cursor position in mousePos
            mousePos.x = mousex(); // get the OX coordonate
            mousePos.y = mousey(); // get the OY coordonate

        }
    }
}
