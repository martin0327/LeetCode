template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& qr, int k) {
        max_pq<int> pq;
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