using ll = long long;
class Solution {
public:
    int garbageCollection(vector<string>& a, vector<int>& b) {
        ll n = a.size();
        vector<ll> m(n), p(n), g(n);
        for (int i=0; i<n; i++) {
            string s = a[i];
            for (auto c : s) {
                if (c=='M') m[i]++;
                else if (c=='P') p[i]++;
                else g[i]++;
            }
        }
        
        ll ans = 0;
        int m_last, p_last, g_last;
        m_last=p_last=g_last=-1;

        for (int i=0; i<n; i++) {
            if (m[i]>0) m_last = i;
            if (p[i]>0) p_last = i;
            if (g[i]>0) g_last = i;
        }


        for (int i=0; i<=m_last; i++) {
            ans += m[i];
            if (i<n-1 && i<m_last) ans += b[i];
        }
        
        for (int i=0; i<=p_last; i++) {
            ans += p[i];
            if (i<n-1 && i<p_last) ans += b[i];
        }
        
        for (int i=0; i<=g_last; i++) {
            ans += g[i];
            if (i<n-1 && i<g_last) ans += b[i];
        }
        return ans;
    }
};