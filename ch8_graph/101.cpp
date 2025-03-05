#include<iostream>
#include<vector>
using namespace std;

int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
const int N = 60;


void dfs(std::vector<std::vector<int>>& graph,int x,int y,int n,int m){
	graph[x][y] = 2;
	for(int i = 0; i < 4; i++){
		int curx = x + dir[i][0];
		int cury = y + dir[i][1];
		if(curx <= 0 || curx > n || cury <=0 || cury > m || graph[curx][cury] == 0 || graph[curx][cury] == 2) continue;
		dfs(graph,curx,cury,n,m);
	}
} 

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> graph(N,vector<int>(N,0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j]; 
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(graph[i][1] == 1) dfs(graph,i,1,n,m);
		if(graph[i][m] == 1) dfs(graph,i,m,n,m);
	}
	
	for(int j = 1; j <= m; j++){
		if(graph[1][j] == 1) dfs(graph,1,j,n,m);
		if(graph[n][j] == 1) dfs(graph,n,j,n,m);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(graph[i][j] == 1){
				cnt++;
			}
		}
	}
	
	cout << cnt;
	return 0;
}
