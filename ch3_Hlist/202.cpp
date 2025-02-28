#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> res;
        while(1){
            int sum = getSum(n);
            if(sum==1){
                return true;
            }
            if(res.find(sum)!=res.end()){
                return false;
            }else{
                res.insert(sum);
            }
            n = sum;
        }
    }
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n/=10;
        }
        return sum;
    }
};

