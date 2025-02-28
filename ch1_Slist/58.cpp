#include<iostream>
#include<vector>
using namespace std;
const int N  = 100010;
int main(){
    int n;
    int a[N],b[N];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }
    int i,j;
    while(cin >> i >> j){
        cout << b[j+1] - b[i] << endl;
    }
    return 0;
}