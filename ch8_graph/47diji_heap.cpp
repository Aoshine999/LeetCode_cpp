#include<iostream>
#include<vector>
#include<queue>
#include<list> 
#include<climits>
using namespace std;
struct Edge{
	int to; //邻接结点
	int val; //边的值 
	Edge(int to,int val): to(to), val(val) {} 
};
class mycmp{
public:
	bool operator()(const pair<int,int>& a,const pair<int,int>& b){
		return a.second > b.second;
	}
};


int main(){
	int v,e;
	cin >> v >> e;
	vector<list<Edge>> grid(v+1);
	
	int x,y,val;
	for(int i = 1; i <= e; i++){
		cin >> x >> y >> val;
		grid[x].push_back(Edge(y,val));
	}
	
	int st = 1;
	int ed = v;
	
	vector<int> minDist(v + 1, 65535);
	
	vector<bool> visit(v + 1, false);
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;
	
	pq.push(pair<int,int>(st,0));
	
	minDist[st] = 0;
	
	while(!pq.empty()){
		// 第一步，找出源点到哪个结点未访问过
		pair<int,int> cur = pq.top();
		pq.pop();
		
		if(visit[cur.first]) continue;
		
		// 第二步，将最近结点设置为以访问 
		visit[cur.first] = true;
		
		for(Edge edge : grid[cur.first]){
			if(!visit[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]){
				minDist[edge.to] = minDist[cur.first] + edge.val;
				pq.push(pair<int,int>(edge.to,minDist[edge.to]));
			}
		}
	}
	
	if(minDist[ed] == 65535) cout << -1;
	else cout << minDist[ed]; 
	
	
}

