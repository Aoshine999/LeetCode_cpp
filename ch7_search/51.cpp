#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;




class Solution {
    public:
        bool rowf[10];
        bool colf[10];
        bool diag[30];
        bool diag1[30];
        vector<vector<string>> res;
        vector<int> place;
        
        vector<vector<string>> solveNQueens(int n) {
            solveNQueens1(0,n);
            return res;
        }

        void solveNQueens1(int lev, int n){
            if(lev == n){
                vector<string> path;
                for(int i = 0; i < place.size(); i++){
                    int s = place[i];
                    string rowplace = "";
                  
                    for(int i = 1; i <= place.size(); i++){
                        if(i == s){
                            rowplace.push_back('Q');
                        }else{
                            rowplace.push_back('.');
                        }
                    }
                    path.push_back(rowplace);
                }
                res.push_back(path);
            }
            for(int i = 1; i <= n; i++){
                if(!rowf[lev] && !colf[i] && !diag[lev + i] && !diag1[lev - i + 10]){
                    rowf[lev] = 1;
                    colf[i] = 1;
                    diag[i + lev] = 1;
                    diag1[lev - i + 1] = 1;
                    place.push_back(i);
                    solveNQueens1(lev + 1, n);
                    rowf[lev] = 0;
                    colf[i] = 0;
                    diag[i + lev] = 0;
                    diag1[lev - i + 1] = 0;
                    place.pop_back();
                }
            }
        }
    };