#include<iostream>
#include<vector>
using namespace std;
const int N = 11S0;

int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
void dfs(vector<vector<int>>& graph,vector<vector<bool>>& flag,int n,int m,int x,int y){
	if(flag[x][y]) return;
	flag[x][y] = true;
	
	for(int i = 0; i < 4; i++){
		int curx = x + dir[i][0];
		int cury = y + dir[i][1];
		if(curx <= 0 || curx > n || cury <=0 || cury > m) continue;
		if(graph[x][y] > graph[curx][cury]) continue;
		dfs(graph,flag,n,m,curx,cury);
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
	vector<vector<bool>> left(n+1,vector<bool>(m+1,false));
	vector<vector<bool>> right(n+1,vector<bool>(m+1,false));
	for(int i = 1; i <= n; i++){
		dfs(graph,left,n,m,i,1);
		dfs(graph,right,n,m,i,m);
	}
	
	for(int i = 1; i <= m; i++){
		dfs(graph,left,n,m,1,i);
		dfs(graph,right,n,m,n,i);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(left[i][j] && right[i][j]) cout << i - 1 << " " << j - 1 << endl;
		}
	}
	
	return 0;
}
