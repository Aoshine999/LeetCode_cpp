#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
	int v,e;
	cin >> v >> e;
	vector<vector<int>> grid(v + 1, vector<int>(v + 1, 65535));
	int x,y,val;
	for(int i = 1; i <= e; i++){
		cin >> x >> y >> val;
		grid[x][y] = val; 
	} 
	
	int st = 1;
	int ed = v;
	
	vector<int> minDist(v + 1,65535);
	vector<bool> visit(v + 1, 0);
	
	minDist[st] = 0;
	
	for(int i = 1; i <= v; i++){
		int minval = 65535;
		int cur = 1;
		
		for(int j = 1; j <= v; j++){
			if(!visit[j] && minDist[j] < minval){
				cur = j;
				minval = minDist[j];
			}
		}
		
		visit[cur] = 1;
		
		for(int j = 1; j <= v; j++){
			if(!visit[j] && grid[cur][j] != 65535 && minDist[cur] + grid[cur][j] < minDist[j]){
				minDist[j] = minDist[cur] + grid[cur][j];
			}
		}
		
	}
	
	if(minDist[ed] == 65535) cout << -1;
	else cout << minDist[ed];
	return 0;
}
