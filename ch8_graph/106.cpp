#include<iostream>
#include<vector>
using namespace std;

int cal(vector<vector<int>>& graph,int n,int m){
	int res = 0;
	for(int i = 1; i <= n; i++){
		bool flag = false;
		for(int j = 1; j <= m; j++){
			if(graph[i][j] == 1){
				flag = true;
			}
			if(graph[i][j] == 0 && flag == true){
				flag = false;
				res += 2;
			}else if(j == m && flag == true){
				flag = false;
				res += 2;
			}
		}
	}
	
	for(int j = 1; j <= m; j++){
		bool flag = false;
		for(int i = 1; i <= n; i++){
			if(graph[i][j] == 1){
				flag = true;
			}
			if(graph[i][j] == 0 && flag == true){
				flag = false;
				res += 2;
			}else if( i == n && flag == true){
				flag = false;
				res += 2;
			}
		}
	}
	
	return res;
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1,vector<int>(m+1,0));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	} 
	
	cout << cal(graph,n,m);
	
	
	return 0;
} 
