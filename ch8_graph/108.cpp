#include<iostream>
#include<vector>
using namespace std;
const int N = 1010;
int f[N];
int e[N];
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
    int n;

    cin >> n;
    init(n);
    int s,t;
    int flag = 0;
    for(int i = 1; i <= n; i++){
        cin >> s >> t;
        if(find(s) == find(t)){
            cout << s << t;
            break;
        } 
        else join(s,t);

    }
    
    return 0;
}
