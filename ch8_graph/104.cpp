#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
const int N = 60;
int n,m;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
void dfs(vector<vector<int>>& graph,vector<vector<bool>>& flag,int x,int y,int mark,int& cnt){
	if(graph[x][y] == 0 || flag[x][y] == true) return;
	flag[x][y] = 1;
	graph[x][y] = mark;
	for(int i = 0; i < 4; i++){
		int curx = x + dir[i][0];
		int cury = y + dir[i][1];
		if(curx <= 0 || curx > n || cury <= 0 || cury > m) continue;
		if(graph[curx][cury] != 1) continue;
		cnt++;
		dfs(graph,flag,curx,cury,mark,cnt);
	}
}


int main(){
	

	cin >> n >> m;
	vector<vector<int>> graph(n + 1,vector<int>(m + 1,0));
	vector<vector<bool>> flag(n + 1,vector<bool>(m + 1,0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j]; 
		}
	}

	unordered_map<int,int> cntMark;
    bool isALLOne = true;
	int mark = 2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
            if(graph[i][j] == 0) isALLOne = false;
			if(graph[i][j] == 1 && flag[i][j] == 0){
				int cnt = 1;
				dfs(graph,flag,i,j,mark,cnt);
				cntMark[mark] = cnt;
				mark++;
			}
		}
	}

    if(isALLOne == true){
        cout << n * m;
        return 0;
    }
	int res = 0;
	unordered_set<int> visitedGrid;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			visitedGrid.clear();
			if(graph[i][j] == 0){
				int num = 1;
				for(int k = 0; k < 4; k++){
					int curx = i + dir[k][0];
					int cury = j + dir[k][1];
					if(curx <= 0 || curx > n || cury <= 0 || cury > m) continue;
					if(graph[curx][cury] != 0){
						if(visitedGrid.count(graph[curx][cury])) continue;
						num += cntMark[graph[curx][cury]];
						visitedGrid.insert(graph[curx][cury]); 
					}
				}
				res = max(res,num);
			}
			
		}
	}
	
	cout << res;
	
}