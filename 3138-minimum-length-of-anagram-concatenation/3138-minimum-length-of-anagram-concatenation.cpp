class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size(), ans = n;
        for (int i=1; i*i<=n; i++) {
            if (n % i == 0) {
                int m1 = i, m2 = n / i;
                auto f = [&] (int m) {
                    string u;
                    for (int j=0; j<n; j+=m) {
                        auto t = s.substr(j,m);
                        sort(t.begin(), t.end());
                        if (u.empty()) u = t;
                        else if (u != t) return false;
                    }
                    return true;
                };
                if (f(m1)) ans = min(ans, m1);
                if (f(m2)) ans = min(ans, m2);
            }
        }
        return ans;
    }
}; 