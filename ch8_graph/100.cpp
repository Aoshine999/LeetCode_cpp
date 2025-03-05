#include<iostream>
#include<vector>
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
const int N = 60;

void dfs(std::vector<std::vector<int>>& graph,int x,int y,int n,int m,int& cnt){
	for(int i = 0; i < 4; i++){
		int curx = x + dir[i][0];
		int cury = y + dir[i][1];
		if(curx <= 0 || curx > n || cury <=0 || cury > m || graph[curx][cury] == 0) continue;
		cnt++;
		graph[curx][cury] = 0;
		dfs(graph,curx,cury,n,m,cnt); 
	}
}

int main(){
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> graph(N,std::vector<int>(N,0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			std::cin >> graph[i][j]; 
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(graph[i][j] == 1){
				int cnt = 1;
				graph[i][j] = 0;
				dfs(graph,i,j,n,m,cnt);
				res = std::max(res,cnt);
			}
		}
	}
	
	std::cout << res;
	
	return 0;
}
