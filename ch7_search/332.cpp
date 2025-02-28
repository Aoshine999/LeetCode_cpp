#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<string>
using namespace std;



class Solution {
    public:
        vector<string> res;
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            vector<bool> flags(310,0);
            string prev = "";
            find(tickets,0,flags,prev);
            return res;
        }

        void find(vector<vector<string>>& tickets, int l, vector<bool>& flags,string &prev){
            if(l == tickets.size()){
                return ;
            }
            if(l == 0){
                int idx;
                vector<int> constitu;
                for(int i = 0; i < tickets.size(); i++){
                    if(tickets[i][0] == "JFK"){
                        if(prev.empty()){
                            prev = tickets[i][1];
                            idx = i;
                            res.push_back("JFK");
                            constitu.push_back(idx);
                        }else{
                            for(int j = 0; j < tickets[i][1].size(); j++){
                                int l = prev[j] - 'A';
                                int r = tickets[i][1][j] - 'A';
                                if(l == r){
                                    continue;
                                }else if(l < r){
                                    break;
                                }else{
                                    prev = tickets[i][1];
                                    idx = i;
                                    break;
                                }
                            }                            
                        }
                    }
                }
                res.push_back(prev);
                flags[idx] = 1;
                find(tickets,l + 1,flags,prev);
            }else{
                int idx;
                string prev1 = prev;
                prev = "";
                for(int i = 0; i < tickets.size(); i++){
                    if(!flags[i]){
                        if(tickets[i][0] == prev1){
                            if(prev.empty()){
                                prev = tickets[i][1];
                                idx = i;
                            }else{
                                for(int j = 0; j < tickets[i][1].size(); j++){
                                    int l = prev[j] - 'A';
                                    int r = tickets[i][1][j] - 'A';
                                    if(l == r){
                                        continue;
                                    }else if(l < r){
                                        break;
                                    }else{
                                        prev = tickets[i][1];
                                        idx = i;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                res.push_back(prev);
                flags[idx] = 1;
                find(tickets,l + 1,flags,prev);
            }

    
        }
};

class Solution1 {
private:
    unordered_map<string,map<string,int>> targets;
    bool backtracking(int ticketNum, vector<string>& result){
        if(result.size() == ticketNum + 1) return true;

        for(pair<const string, int>& target : targets[result[result.size() - 1]]){
            if(target.second > 0){
                result.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum,result)) return true;
                result.pop_back();
                target.second++; 
            }
        }

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> res;
        for(const vector<string>& vec : tickets){
            targets[vec[0]][vec[1]]++; 
        }
        res.push_back("JFK");
        backtracking(tickets.size(),res);
        return res;
    }
};