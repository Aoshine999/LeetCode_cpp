#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

int n;


int main(){
	cin >> n;
	string str;
	string fm,end;
	cin >> fm >> end;
	unordered_set<string> allstr;
	for(int i = 0; i < n; i++){
		cin >> str;
		allstr.insert(str);
	}
	
	unordered_map<string,int> findMap;
	
	queue<string> que;
	que.push(fm);
	findMap.insert(pair<string,int>(fm,1));
	
	while(!que.empty()){
		string s = que.front();
		que.pop();
		int path = findMap[s];
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < 26; j++){
				string s1 = s;
				s1[i] = 'a' + j;
				if(s1 == end){
					cout << path + 1;
					return 0;	
				} 
				
				if(findMap.find(s1) == findMap.end() && allstr.find(s1) != allstr.end()){
					findMap.insert(pair<string,int>(s1,path + 1));
					que.push(s1); 
				}
				
			}
		}
	}
	
	cout << 0;
	return 0;
}
