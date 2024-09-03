class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& qr, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        for (auto v : qr) {
            int d = abs(v[0])+abs(v[1]);
            pq.push(d);
            while (pq.size() > k) pq.pop();
            ans.push_back(pq.size()==k?pq.top():-1);
        }
        return ans;
    }
};