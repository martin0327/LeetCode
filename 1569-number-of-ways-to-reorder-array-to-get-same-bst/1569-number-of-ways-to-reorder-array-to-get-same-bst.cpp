struct node {
    int val;
    node* left = nullptr;
    node* right = nullptr;
    node(int val) {
        this->val = val;
    }
};

using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;
const pii inf = {mod,mod};

class Solution {
public:
    int numOfWays(vector<int>& a) {
        int n = a.size();
        node* root = new node(a[0]);
        
        function<void(node*,int)> f = [&](node* u, int x) {
            int y = u->val;
            if (x < y) {
                if (u->left) f(u->left,x);
                else u->left = new node(x);
            }
            else {
                if (u->right) f(u->right,x);
                else u->right = new node(x);
            }
        };
        
        for (int i=1; i<n; i++) {
            f(root,a[i]);
        }

        vvi dp(n+1, vi(n+1));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=i; j++) {
                if (j <= i-1) dp[i][j] += dp[i-1][j];
                if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            }
        }

        function<pii(node*)> g = [&](node* u) {
            pii l = inf, r = inf;
            if (u->left) l = g(u->left);
            if (u->right) r = g(u->right);
            if (l==inf && r==inf) return make_pair(1ll,1ll); 
            if (l==inf) return make_pair(r.first, r.second+1);
            if (r==inf) return make_pair(l.first, l.second+1);
            
            auto [comb1, cnt1] = l;
            auto [comb2, cnt2] = r;
            ll comb = (comb1 * comb2) % mod;
            comb *= dp[cnt1+cnt2][cnt1];
            return make_pair(comb%mod,cnt1+cnt2+1);
        };

        auto [ans,cnt] = g(root);
        return ans-1;
    }
}; 