#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            dfs(board);
        }

        bool isValid(int row, int col, char val, vector<vector<char>>& board){
           for(int i = 0; i < 9; i++){
                if(board[row][i] == val)
                    return false;
           }
           for(int i = 0; i < 9; i++){
                if(board[i][col] == val)
                    return false;
           }

           int row1 = (row / 3) * 3;
           int col1 = (col / 3) * 3;
           for(int i = row1; i < row1 + 3; i++){
                for(int j = col1; j < col1 + 3; j++){
                    if(board[i][j] == val){
                        return false;
                    }
                }
           }

            return true;
        }

        bool dfs(vector<vector<char>>& board){
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    if(board[i][j] == '.'){
                        for(char k = '1'; k <= '9'; k++){
                            if(isValid(i,j,k,board)){
                                board[i][j] = k;
                                if(dfs(board)) return true;
                                board[i][j] = '.';
                            }
                        }

                        return false;
                    }
                }
            }

            return true;
        }
};