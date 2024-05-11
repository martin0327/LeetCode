class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n = q.size();
        vector<pair<double,int>> a(n);
        for (int i=0; i<n; i++) {
            a[i] = {(double) w[i] / (double) q[i], q[i]};
        }
        sort(a.begin(), a.end());
        int s = 0;
        priority_queue<int> pq;
        double ans = 2e18;
        for (auto [r,x] : a) {
            s += x;
            pq.push(x);
            if (pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) ans = min(ans, r * s);
        }
        return ans;        
    }
};