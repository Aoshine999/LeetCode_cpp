#include<iostream>
#include<vector>
using namespace std;
const int N = 110;
int f[N];
void init(int n){
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
}

int find(int x){
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}

void join(int s, int t){
    s = find(s);
    t = find(t);
    if(s != t){
        f[t] = s;
    }
}



int main(){
    int n,m;
    cin >> n >> m;
    init(n);
    for(int i = 1; i <= m; i++){
        int s,t;
        cin >> s >> t;
        join(s,t);
    }

    int s,t;
    cin >> s >> t;
    if(find(s) == find(t)) cout << "1";
    else cout << "0";

    return 0;
}