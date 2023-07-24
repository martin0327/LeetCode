struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    
        
    bool gcdSort(vector<int>& a) {
        int n = a.size(), m = 1e5;
        vi spf(m+1);
        spf[1] = 1;
        for (int i=2; i<=m; i++) spf[i] = i;
        for (int i=4; i<=m; i+=2) spf[i] = 2;
        for (int i=3; i*i<=m; i++) {
            if (spf[i] == i) {
                for (int j=i*i; j<=m; j+=i) {
                    if (spf[j]==j) spf[j] = i;
                }
            }
        }
        auto f = [&](int x) {
            vi ret;
            while (x != 1) {
                ret.push_back(spf[x]);
                x = x / spf[x];
            }
            return ret;
        };
        // vvi pfactors;
        // pfactors.resize(m+1);
        // for (int i=2; i<=m; i++) {
        //     if (pfactors[i].empty()) {
        //         for (int j=i; j<=m; j+=i) {
        //             pfactors[j].push_back(i);
        //         }
        //     }
        // }
        dsu d(m+1);
        for (auto x : a) {
            auto pfac = f(x);
            for (auto p : pfac) {
                d.merge(p,pfac.front());
            }
        }
        vi grp(n);
        for (int i=0; i<n; i++) {
            grp[i] = d.leader(spf[a[i]]);
        }
        map<int,vi> mp;
        for (int i=0; i<n; i++) {
            mp[grp[i]].push_back(a[i]);
        }
        for (auto &[k,v] : mp) {
            sort(v.rbegin(), v.rend());
        }
        for (int i=0; i<n; i++) {
            a[i] = mp[grp[i]].back();
            mp[grp[i]].pop_back();
        }
        vi b = a;
        sort(b.begin(), b.end());
        return a==b;
        
    }
};