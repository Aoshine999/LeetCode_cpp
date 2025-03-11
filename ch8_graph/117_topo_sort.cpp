#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int inDegree[N] = {0};
int h[N];

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1,vector<int>(n+1,0));
	int s,t;
	for(int i = 0; i < m; i++){
		cin >> s >> t;
		graph[s][t] = 1;
		inDegree[t] += 1;
	}
	vector<int> res;
	while(true){
		int cur = -1;
		for(int i = 0; i < n; i++){
			if(inDegree[i] == 0 && h[i] == 0){
				cur = i;
				h[i] = 1;
				break;
			}
		}
		
		if(cur != -1) res.push_back(cur);
		else break;
		
		for(int i = 0; i < n; i++){
			if(graph[cur][i] == 1){
				inDegree[i] -= 1;
			}
		}
	}
	
	if(res.size() == n){
		for(int i : res){
			cout << i << " ";
		}
	}else{
		cout << -1;
	}
	return 0;
}
