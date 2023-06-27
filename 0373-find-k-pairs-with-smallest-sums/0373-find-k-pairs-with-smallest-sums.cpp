class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<tuple<int,int,int>> pq;
        for (auto x : a) {
            for (auto y : b) {
                if (pq.size() < k) pq.emplace(x+y,x,y);
                else {
                    auto [w,xx,yy] = pq.top();
                    if (w <= x+y) break;
                    else {
                        pq.emplace(x+y,x,y);
                        pq.pop();
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while (pq.size()) {
            auto [w,x,y] = pq.top(); pq.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};

