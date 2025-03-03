#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

const int M = 1e2*5+10;

struct edge
{
    int x;
    int y;
}edge[M];


vector<vector<int>> res;
vector<int> path;
bool flag[M];

vector<vector<int>> graph(M+1,vector<int>(M+1,0));

void dfs(int x,int y,int m){
    if(x == y){
        res.push_back(path);
        return ;
    }
    for(int i = 0; i < m; i++){
        if(edge[i].x == x && flag[x] == 0){
             flag[x] = 1;
             int x1 = edge[i].y;
             path.push_back(x1);
             dfs(x1,y,m);
             flag[x] = 0;
             path.pop_back();
        }
    }
}



int main(){

    int n,m;
    cin >> n >> m;

    int s,t;
    for(int i = 0; i < m; i++){
        cin >> edge[i].x >> edge[i].y;
    }
    path.push_back(1);
    dfs(1,n,m);

    if(res.size() == 0) cout << -1 << endl;
    for(const vector<int>& pa: res){
        for(int i = 0; i < pa.size() - 1; i++){
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1] << endl;
    }

}