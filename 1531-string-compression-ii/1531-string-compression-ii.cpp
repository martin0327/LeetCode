const int inf = 1e9;

template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

class Solution {
public:
  
  int getLengthOfOptimalCompression(string s, int k) {
    
    int n = s.size();
    if (n==k) {
      return 0;
    }
    
    map<int,int> mp;
    for (auto c : s) mp[c-'a'] = 0;
    int sz = 0;
    for (auto &[k,v] : mp) v = sz++;
    vector<int> a(n);
    for (int i=0; i<n; i++) a[i] = mp[s[i] -'a'];
    vector<int> cnt(sz+1);
    for (int i=0; i<n; i++) cnt[a[i]]++;
    cnt[sz] = 1;

    vvvvi dp(n+1, vvvi(k+1, vvi(sz+1)));
    for (int i=0; i<=n; i++) {
      for (int j=0; j<=k; j++) {
        for (int l=0; l<=sz; l++) {
          dp[i][j][l] = vi(cnt[l]+1,inf);
        }
      }
    }

    dp[0][0][sz][0] = 0;

    vector<int> len(101);
    for (int i=2; i<=100; i++) {
      len[i] = to_string(i).size()+1;
    }
    len[1] = 1;

    for (int i=0; i<n; i++) {
      for (int j=0; j<=k; j++) {
        for (int l=0; l<=sz; l++) {
          for (int h=0; h<=cnt[l]; h++) {
            int x = a[i];
            if (x!=l) {
              chmin(dp[i+1][j][x][1], dp[i][j][l][h] + len[h]);
              if (j+1 <= k) chmin(dp[i+1][j+1][l][h], dp[i][j][l][h]);              
            }
            else {
              if (h+1 <= cnt[l]) chmin(dp[i+1][j][l][h+1], dp[i][j][l][h]);
              if (j+1 <= k) chmin(dp[i+1][j+1][l][h], dp[i][j][l][h]);
            }
          }
        }
      }
    }
    int ans = inf;
    for (int j=0; j<=k; j++) {
      for (int l=0; l<sz; l++) {
        for (int h=0; h<=cnt[l]; h++) {
          chmin(ans, dp[n][j][l][h] + len[h]);
        }
      }
    }
    return ans;
  }
};