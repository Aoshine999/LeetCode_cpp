#include<iostream>
#include<vector>
using namespace std;
//prim 算法


int main(){
    int v,e;

    int x,y,k;

    cin >> v >> e;   //输入节点数v,边数e

    vector<vector<int>> grid(v+1,vector<int>(v+1,INT32_MAX));

    for(int i = 0; i < e; i++){
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;

    }

    vector<int> minDist(v+1, 1e4 + 1);  //设置最小生成树中每个节点的最短距离


    vector<bool> isInTree(v+1,false);

    //循环n-1次，建立n-1条边
    for(int i = 1; i < v; i++){
        // 第一步 选距离生成树最近节点
        int cur = -1;
        int minVal = INT32_MAX;
        for(int j = 1; j <= v; j++){
            // 选择节点条件：
            // 1.不在最小生成树中
            // 2.距离最小生成树最近的节点
            if(!isInTree[j] && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }

        // 第二步 将节点加入生成树
        isInTree[cur] = true;

        // 第三步 更新非生成树节点到生成树的距离
        for(int j = 1; j <= v; j++){
            // 更新条件
            // 1.节点是非生成树中的节点
            // 2.与cur 相连的某节点的权值进行更新
            if(!isInTree[j] && grid[cur][j] < minDist[j]){
                minDist[j] = grid[cur][j];
            }
        }

    }  
    int res = 0;
    for(int i = 2; i <= v; i++){
        res+= minDist[i];
    }

    cout << res << endl;
    return 0;
}