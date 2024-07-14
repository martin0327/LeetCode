using ll = long long;
class Solution {
public:
    string countOfAtoms(string s) {
        ll n = s.size();
        map<ll,ll> match;
        stack<ll> st;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                auto j = st.top();
                match[j] = i;
                st.pop();
            }
        }

        function<bool(char)> is_digit = [&] (char c) {
            int x = c - '0';
            return 0 <= x && x <= 9;
        };

        function<ll(ll)> d2n = [&] (ll i) {
            int ret = 1;
            string t;
            for (int j=i; j<n; j++) {
                if (is_digit(s[j])) t += s[j];
                else break;
            }
            if (!t.empty()) ret *= stoll(t);
            return ret;
        };

        function<map<string,int>(int,int)> f = [&] (int l, int r) {
            map<string,int> ret;
            if (l > r) return ret;
            if (is_digit(s[l])) return f(l+1,r);

            if (s[l] == '(') {
                int j = match[l];
                auto t1 = f(l+1,j);
                int mul = 1;
                if (j+1 < n) mul *= d2n(j+1);
                auto t2 = f(j+1,r);
                for (auto &[k,v] : t1) ret[k] += mul * v;
                for (auto &[k,v] : t2) ret[k] += v;
            }
            else if (isupper(s[l])) {
                string t(1,s[l]);
                int nxt = l+1;
                for (int i=l+1; i<r; i++) {
                    if (islower(s[i])) {
                        t += s[i];
                        nxt = i + 1;
                    }
                    else break;
                }
                
                int mul = 1;
                if (nxt < n) mul *= d2n(nxt);
                ret[t] += mul;
                for (auto &[k,v] : f(nxt,r)) {
                    ret[k] += v;
                }
            }
            return ret;
        };
        auto mp = f(0,n-1);
        string ans;
        for (auto [k,v] : mp) {
            ans += k;
            if (v > 1) ans += to_string(v);
        }
        return ans;
    }
};