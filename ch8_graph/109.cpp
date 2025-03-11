#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int N = 1010;
int f[N];
int e[N];
void init(int n){
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
}

int find(int x){
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}

void join(int s, int t){
    s = find(s);
    t = find(t);
    if(s != t){
        f[t] = s;
    }
}

void getRemoveEdge(const vector<vector<int>>& edges,int n){
    init(n);
    for(int i = 0; i < n; i++){
        if(find(edges[i][0]) == find(edges[i][1])){
            cout << edges[i][0] << " " << edges[i][1];
            return ;
        }else {
            join(edges[i][0],edges[i][1]);
        }
    }
}

bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge,int n){
    init(n);
    for(int i = 0; i < n; i++){
        if(i == deleteEdge) continue;
        if(find(edges[i][0]) == find(edges[i][1])) return false;
        join(edges[i][0],edges[i][1]);
    }
    return true;
}
int main(){
    int n;

    cin >> n;

    vector<vector<int>> edges;
    vector<int> inDegree(n+1,0);
    for(int i = 0; i < n; i++){
        int s,t;
        cin >> s >> t;
        inDegree[t]++;
        edges.push_back({s,t});
    }

    vector<int> vec;

    for(int i = n - 1; i >=0; i--){
         if(inDegree[edges[i][1]] == 2){
            vec.push_back(i);
         }
    }

    if(vec.size() > 0){
        if(isTreeAfterRemoveEdge(edges,vec[0],n)){
            cout << edges[vec[0]][0] << " " << edges[vec[0]][1];
        } else {
            cout << edges[vec[1]][0] << " " << edges[vec[1]][1];
        }

        return 0;
    }
    
    getRemoveEdge(edges,n);

    return 0;
}
