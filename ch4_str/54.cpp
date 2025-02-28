#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    string s;
    cin >> s;
        /* code */
    int len = s.size() - 1;
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            count++;
        }
    }

    s.resize(s.size() + 5*count);
    int newInd = s.size() - 1;
    while(len >= 0){
        if(s[len] >= '0' && s[len] <= '9'){
            s[newInd--] = 'r';
            s[newInd--] = 'e';
            s[newInd--] = 'b';
            s[newInd--] = 'm';
            s[newInd--] = 'u';
            s[newInd--] = 'n';
        }else{
            s[newInd--] = s[len];
        }
        len--;
    }

    cout << s;
}