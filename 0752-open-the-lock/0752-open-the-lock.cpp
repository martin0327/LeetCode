class Solution {
public:
    const int inf = 1e9;
    using vi = vector<int>;
    
    int openLock(vector<string>& de, string tg) {
        set<string> blk(de.begin(), de.end());
        map<string,int> vis;
        
        string src = "0000";
        if (blk.count(src)) return -1;
        queue<string> q;
        q.push(src);
        vis[src] = 0;
        auto f = [&] (string s) {
            vector<string> ret;
            for (int i=0; i<4; i++) {
                int x = s[i] - '0';
                {
                    int y = (x+1) % 10;
                    string t = s;
                    t[i] = '0' + y;
                    ret.push_back(t);
                }
                {
                    int y = (x+9) % 10;
                    string t = s;
                    t[i] = '0' + y;
                    ret.push_back(t);
                }
            }
            return ret;
        };
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (auto v : f(u)) {
                if (!vis.count(v) && !blk.count(v)) {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
        int ans = vis.count(tg) ? vis[tg] : -1;
        return ans;
        
    }
};