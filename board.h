#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
using namespace std;

class board{

public:
	//CONSTURCTOR
	board(){

		board = {
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{2,0,2,0,2,0,2,0},
			{0,2,0,2,0,2,0,2},
			{2,0,2,0,2,0,2,0}
		};
	}
	
    void remove(int x, int y){board[x][y] = 0;}

    void moveRightDown(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";}
	    if((x+1)>7||(y+1)>7) {cout<< "Invalid Move!";}
	   
	    if(isEmpty(x+1, y+1) == false) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x+1][y+1] = 1;
    }
	
    void moveLeftDown(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";}
	    if((x+1)>7||(y-1)<0) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x+1][y-1] == 1) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x+1][y-1] = 1;
    }
	
    void moveRightUp(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";}
	    if((x-1)<0||(y+1)>7) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x-1][y+1] = 2;
    }
	
    void moveLeftUp(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";}
	    if((x-1)<0||(y-1)<0) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x-1][y-1] = 2;
    }
	
    void jumpRightDown(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";} 
	    if((x+2)>7||(y+2)>7) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x+1][y+1] == 1) {cout<< "Invalid Move!"; return;}  
	   
	    remove(x,y);
	    int newX = x+2;
	    int newY = y+2;
	    boardArray[newX][newY] = 1;
	    remove(x+1,y+1);
	    if(isLeftDown2 == true){
	    	jumLeftDown(newX, newY);
	    }
	    if(isRightDown2 == true){
	    	jumpRightDown(newX, newY);
	    }
    }

    void jumpLeftDown(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";} 
	    if((x+2)>7||(y-2)<0) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x+2][y-2] == 1) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x+2][y-2] = 1;
	    remove(x+1,y-1);
    }
	
    void jumpRightUp(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";} 
	    if((x-2)<0||(y+2)>7) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x-2][y+2] = 2;
	    remove(x-1,y+1);
    }
	
    void jumpLeftUp(int x, int y){
	    if(isVaild(x,y) == false) {cout<< "Invalid Move!";} 
	    if((x-2)<0||(y-2)<0) {cout<< "Invalid Move!"; return;}
	   
	    if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!"; return;}
	   
	    remove(x,y);
	    boardArray[x-2][y-2] = 2;
	    remove(x-1,y-1);
    }

    bool isValid(int x, int y){return (x+y)%2 != 0;}
    bool isEmpty(int x, int y){return board[x][y] == 0;}
    bool is1(int x, int y){return board[x][y] == 1;}
    bool is2(int x, int y){return board[x][y] == 2;}
    bool isLeftUp1(int x, int y){return board[x-1][y-1] == 1;}
    bool isRightUp1(int x, int y){return board[x-1][y+1] == 1;}
    bool isLeftDown2(int x, int y){return board[x+1][y-1] == 2;}
    bool isLeftUp2(int x, int y){return board[x+1][y+1] == 2;}
   
private:
	static int boardArray[8][8];

};

#endif
