using ll = long long;
using tdii = tuple<double,int,int>;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& a, int ex) {
        priority_queue<tdii,vector<tdii>, greater<tdii>> pq;
        auto f = [&] (ll x, ll y) {
            double w = (y+1)*x - y*(x+1);
            w /= (y+1)*y;
            return w;            
        };
        for (auto &pt : a) {
            int x = pt[0], y = pt[1];
            pq.push({f(x,y),x,y});
        }
        while (ex--) {
            auto [w,x,y] = pq.top();
            pq.pop();
            pq.push({f(x+1,y+1),x+1,y+1});
        }
        double ans = 0;
        while (pq.size()) {
            auto [w,x,y] = pq.top();
            pq.pop();
            double t = x;
            t /= y;
            ans += t;
        }
        ans /= a.size();
        return ans;
    }
};