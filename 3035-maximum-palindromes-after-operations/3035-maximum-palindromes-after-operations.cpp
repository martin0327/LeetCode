using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& a) {
        vi cnt(26);
        vi sz;
        for (auto s : a) {
            sz.push_back(s.size());
            for (auto c : s) {
                cnt[c-'a']++;
            }
        }
        int even = 0;
        int odd = 0;
        for (auto x : cnt) {
            even += x / 2;
            odd += x % 2;
        }
        sort(sz.begin(), sz.end());
        int ans = 0;
        for (auto x : sz) {
            int q = x / 2;
            int r = x % 2;
            if (even >= q && odd >= r) {
                even -= q;
                odd -= r;
                ans++;
            }
            else if (even >= q) {
                if (even >= q+1) {
                    even -= q+1;
                    odd++;
                    ans++;
                }
            }
        }
        return ans;        
    }
};