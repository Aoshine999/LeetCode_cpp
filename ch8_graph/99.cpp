#include<iostream>
#include<queue>
#include<vector>
using namespace std;


const int N = 60;

int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};


void dfs(vector<vector<int>> graph,int x, int y, int n, int m){
    graph[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int curx = x + dir[i][0];
        int cury = y + dir[i][1];
        if(curx <= 0 || curx > n || cury <=0 || cury > m || graph[curx][cury] == 0) continue;
        dfs(graph,curx,cury,n,m);
    }
}

void bfs(vector<vector<int>>& graph, int x, int y, int n, int m){
    queue<pair<int,int>> que;
    graph[x][y] = 0;
    que.push({x,y});
    while(!que.empty()){
        pair<int,int> cur = que.front();
        
        que.pop();
        for(int i = 0; i < 4; i++){
            int curx = cur.first + dir[i][0];
            int cury = cur.second + dir[i][1];
            if(curx <= 0 || curx > n || cury <=0 || cury > m || graph[curx][cury] == 0) continue;
            que.push({curx,cury});
            graph[curx][cury] = 0;
        }
    }
}


int cnt(vector<vector<int>>& graph, int n, int m){
    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(graph[i][j] == 1){
                dfs(graph,i,j,n,m);
                count++;
            }
        }
    }

    return count;
}


int main(){
    vector<vector<int>> graph(N+1,vector<int>(N+1,0));
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }

    cout << cnt(graph,n,m);


    return 0;
}

