using pii = pair<int,int>;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        int n = a.size(), m = (k+1)/2;;
        vector<double> ans;
        set<pii> s1, s2;
        for (int i=0; i<k; i++) {
            s1.insert({a[i],i});
        }
        auto f = [&] () {
            while (s1.size() > m) {
                auto it = prev(s1.end());
                s2.insert(*it);
                s1.erase(it);
            }
            while (s2.size()) {
                auto [x,i] = *prev(s1.end());
                auto [y,j] = *s2.begin();
                if (x > y) {
                    s1.erase(prev(s1.end()));
                    s2.erase(s2.begin());
                    s1.insert({y,j});
                    s2.insert({x,i});
                }
                else break;
            }
        };
        f();
        auto g = [&] () {
            if (k&1) {
                double ans =  prev(s1.end())->first;
                return ans;
            }
            else {
                double ans = prev(s1.end())->first;
                ans += s2.begin()->first;
                ans /= 2.0;
                return ans;
            }
        };
        ans.push_back(g());
        for (int i=k; i<n; i++) {
            int j = i-k;
            pii tg = {a[j],j};
            if (s1.count(tg)) {
                s1.erase(tg);
            }
            if (s2.count(tg)) {
                s2.erase(tg);
            }
            s1.insert({a[i],i});
            f();
            ans.push_back(g());
        }
        return ans;
    }
};