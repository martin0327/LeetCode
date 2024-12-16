using pii = pair<int,int>;
class Solution {
public:
    vector<int> getFinalState(vector<int>& a, int k, int m) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n = a.size();
        for (int i=0; i<n; i++) pq.push({a[i],i});
        while (k--) {
            auto [x,i] = pq.top();
            pq.pop();
            pq.push({m*x,i});
        }
        while (pq.size()) {
            auto [x,i] = pq.top();
            pq.pop();
            a[i] = x;
        }
        return a;
    }
};