class Solution {
private:
    vector<int> path;
    unordered_map<int, int> in, out;
    unordered_map<int, vector<int>> graph;
    
    void make_path(int u) {
        while(out[u] > 0) {
            int v = graph[u].back();
            graph[u].pop_back();
            out[u] -= 1;
            make_path(v);
        }
        path.push_back(u);
    }
    
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto &it: pairs) {
            graph[it[0]].push_back(it[1]);
            out[it[0]] += 1;
            in[it[1]] += 1;
        }
        
        // find the start node
        // start always exists
        int start = -1;
        for(auto &it: pairs) {
            int u = it[0];
            int v = it[1];
            if(out[u] - in[u] == 1) {
                start = u;
                break;
            } else if(out[v] - in[v] == 1) {
                start = v;
                break;
            }
        }
        
        if(start == -1) 
            start = pairs[0][0];
                
        make_path(start);
        
        vector<vector<int>> ans;
        for(int i = path.size()-1; i > 0; i--) {
            ans.push_back({path[i], path[i-1]});
        }
        
        return ans;
    }
};
