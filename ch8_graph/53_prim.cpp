#include<iostream>
#include<vector>
using namespace std;



int main(){
	int v,e;
	int v1,v2,val;
	cin >> v >> e;
	
	vector<vector<int>> grid(v+1,vector<int>(v+1,1e4 + 10));
	vector<bool> isInTree(v+1,0);
	vector<int> minDist(v+1,1e4 + 1);
	vector<int> parent(v+1,-1);
	for(int i = 0; i < e; i++){
		cin >> v1 >> v2 >> val;
		grid[v1][v2] = val;
		grid[v2][v1] = val;
	}
	
	for(int i = 1; i < v; i++){
		int minval = 65536;
		int cur = -1;
		
		for(int j = 1; j <= v; j++){
			if(!isInTree[j] && minDist[j] < minval){
				cur = j;
				minval = minDist[j];
			}
		}
		
		isInTree[cur] = 1;
		
		for(int j = 1; j <= v; j++){
			if(!isInTree[j] && grid[cur][j] < minDist[j]){
				minDist[j] = grid[cur][j];
				parent[j] = cur;
			}
		}	
	}
	for(int i = 1; i <= v; i++){
		cout << parent[i] << "->" << i << endl;
	}
	
	int res =0;
	for(int i = 2; i <= v; i++){
		res += minDist[i];
	}
	
	cout << res;
	return 0;
}
