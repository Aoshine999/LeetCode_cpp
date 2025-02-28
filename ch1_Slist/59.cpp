#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));

        int startx = 0, starty = 0;  //定义起始位置

        int loop = n / 2;  //定义每圈循环次数

        int mid = n / 2;  //矩阵中间的位置

        int offset = 1;  // 控制每一条边遍历的长度，每次循环右边界收缩一位

        int i,j;

        int count = 1;

        while (loop --)
        {
            i = startx;
            j = starty;

            for(j; j < n - offset; j++) res[i][j] = count++;

            for(i; i < n - offset; i++) res[i][j] = count++;

            for(; j > starty; j--) res[i][j] = count++;

            for(; i > startx; i--) res[i][j] = count++;

            startx++;
            starty++;

            offset += 1;
        }
        
        if(n % 2){
            res[mid][mid] = count;
        }
    }
};