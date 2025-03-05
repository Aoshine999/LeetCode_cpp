#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& graph,vector<bool>& flag,int numV,int s){
	for(int i = 1; i <= numV; i++){
		if(graph[s][i] == 1 && flag[i] == 0){
			flag[i] = 1;
			dfs(graph,flag,numV,i);
		}
	}
}

int main(){
	int numV,numE;
	cin >> numV >> numE;
	int s,t;
	vector<bool> flag(numV + 1 , false);
	vector<vector<int>> graph(numV + 1,vector<int>(numV + 1, 0));
	for(int i = 0; i < numE; i++){
		cin >> s >> t;
		graph[s][t] = 1;
	}
	
	dfs(graph,flag,numV,1);
	
	flag[1] = true;
	
	bool out = true;
	for(int i = 1; i <= numV; i++){
		if(flag[i] == false){
			out = false;
		}
	}
	int res = out==true ? 1 : -1;
	cout << res;
	return 0;
}


