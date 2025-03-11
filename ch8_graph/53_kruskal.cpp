#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e4 + 10;
int f[N];
struct Edge{
	int x;
	int y;
	int val;
};

void init(int n){
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
}
int find(int x){
	if(f[x] == x) return x;
	else return f[x] = find(f[x]);
}

void join(int x,int y){
	x = find(x);
	y = find(y);
	if(x != y) f[y] = x;
}

bool isSame(int x,int y){
	return find(x) == find(y) ? true : false;
}


bool comparator(const Edge& a, const Edge& b){
	return a.val < b.val;
} 

int main(){
	int v,e;
	cin >> v >> e;
	vector<Edge> edges;
	int x,y,val;
	for(int i = 0; i < e; i++){
		cin >> x >> y >> val;
		edges.push_back({x,y,val});
	}
	
	sort(edges.begin(),edges.end(),comparator);
	
	
	
	init(e);
	
	int res = 0;
	
	for(Edge edge : edges){
		int x = find(edge.x);
		int y = find(edge.y);
		
		if(x != y){
			res += edge.val;
		}
		join(x,y);
	}
	
	
	cout << res << endl;
	return 0;
}
