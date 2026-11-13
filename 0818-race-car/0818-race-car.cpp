using pii = pair<int,int>;
class Solution {
public:
    int racecar(int tg) {
        pii src = {0,1};
        map<pii,int> dp;
        dp[src] = 0;
        queue<pii> q;
        q.push(src);
        while (q.size()) {
            auto [u,v] = q.front();
            auto d = dp[{u,v}];
            q.pop();
            {
                int nu = u + v;
                int nv = 2 * v;
                if (nu == tg) return d+1;
                if (abs(nu) <= 2*tg) {
                    pii nxt = {nu,nv};
                    if (!dp.count(nxt)) {
                        dp[nxt] = d + 1;
                        q.push(nxt);
                    }
                } 
            }
            {
                int nu = u;
                int nv = (v > 0) ? -1 : 1;
                pii nxt = {nu,nv};
                if (!dp.count(nxt)) {
                    dp[nxt] = d + 1;
                    q.push(nxt);
                }
            }
        }
        return -1;
    }
};
