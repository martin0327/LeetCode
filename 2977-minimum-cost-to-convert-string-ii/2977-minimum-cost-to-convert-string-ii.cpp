using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

const int N = 300;
const ll inf = 2e18;

ll dist[N][N];


class Solution {
public:
    long long minimumCost(string src, string tg, vector<string>& org, vector<string>& chg, vector<int>& cost) {
        
        map<string,int> mp;
        for (auto x : org) mp[x];
        for (auto x : chg) mp[x];
        
        ll sz = 0;
        for (auto &[k,v] : mp) v = sz++;

        
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                dist[i][j] = inf;
            }
            dist[i][i] = 0;
        }
        
        for (int i=0; i<org.size(); i++) {
            int u = mp[org[i]];
            int v = mp[chg[i]];
            dist[u][v] = min(dist[u][v], (ll) cost[i]);
        }

        for (int k=0; k<sz; k++) {
            for (int i=0; i<sz; i++) {
                for (int j=0; j<sz; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        ll n = src.size();
        vi dp(n+1, inf);
        dp[0] = 0;
        src.insert(src.begin(), ' ');
        tg.insert(tg.begin(), ' ');

        vi len;
        for (auto x : org) {
            len.push_back(x.size());
        }
        len = get_unique(len);

        for (int r=1; r<=n; r++) {
            if (src[r] == tg[r]) {
                dp[r] = min(dp[r], dp[r-1]);
            }
            for (auto d : len) {
                if (r-d+1 < 1) break;
                ll l = r-d+1;
                string s = src.substr(l,d);
                auto it1 = mp.find(s);
                if (it1 != mp.end()) {
                    string t = tg.substr(l,d);
                    auto it2 = mp.find(t);
                    if (it2 != mp.end()) {
                        dp[r] = min(dp[r], dp[l-1] + dist[it1->second][it2->second]);
                    }
                }
            }        
        }
        ll ans = dp[n];
        if (ans == inf) ans = -1;
        
        return ans;
    }
}; 