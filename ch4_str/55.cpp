#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;
void right_reverse(string &s,int k){
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin() + k);
    reverse(s.begin() + k, s.end());
}

int main(){
    string s;
    int k;
    cin >> k;
    cin >> s;
    
    right_reverse(s,k);
    cout << s;
    return 0;
}