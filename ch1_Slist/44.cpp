#include<iostream>
using namespace std;
const int N = 1010;
int main(){
    int n,m;

    cin >> n >> m;

    int a[N][N],b[N][N];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> b[i][j];
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
        }
    }
    int ans = INT32_MAX;
    for(int i = 1; i < n; i++){
        int x = abs(a[n][m] - a[i][m] * 2);
        ans = min(ans,x);
    }

    for(int j = 1; j < m; j++){
        int x = abs(a[n][m] - a[n][j] * 2);
        ans = min(ans,x);
    }

    cout << ans;
    return 0;
}