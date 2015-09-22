/*
 * Source.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Xiangchen
 */

/*
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 
 Empty cells are indicated by the character '.'.
 
 You may assume that there will be only one unique solution.
 */


#include <iostream>
#include <cstdint>
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        haspos(board,0);
    }
    bool haspos(vector<vector<char>>& board,int pos){
        
        if(pos==81){
            return true;
        }
        int i = pos/9;
        int j = pos%9;
        
        if(board[i][j]=='.'){
            for (int m=1;m<10;m++){
                char t=char(m)+'0';
                if(isvalidrow(board,t,i)&&isvalidcol(board,t,j)&&isvalid(board,t,i,j)){
                    board[i][j]=t;
                    if (haspos(board,pos+1)){
                        return true;
                    }
                    board[i][j]='.';
                }
            }
        }
        else {
            if(haspos(board,pos+1)){
                return true;
            }
            
        }
        return false;
        
    }
    
    bool isvalidrow(vector<vector<char>>& board,char t ,int i){
        for (int j = 0;j<9;j++){
            if(board[i][j]!='.'){
                if (board[i][j]== t){
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalidcol(vector<vector<char>>& board,char t ,int j){
        for (int i = 0;i<9;i++){
            if(board[i][j]!='.'){
                if (board[i][j]== t){
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>& board,char t ,int i,int j){
        for(int row = 0;row<3;row++){
            for (int col = 0;col <3;col ++){
                if(board[i-i%3+row][j-j%3+col]==t){
                    return false;
                }
            }
        }
        return true;
    }
}