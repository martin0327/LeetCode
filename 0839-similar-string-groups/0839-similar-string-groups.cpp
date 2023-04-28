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

class Solution {
public:
    int numSimilarGroups(vector<string>& a) {
        int n = a.size();
        int m = a[0].size();

        dsu d(n);
        vi cnt(26);
        for (auto c : a[0]) {
            cnt[c-'a']++;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                string s = a[i];
                string t = a[j];
                vi diff;
                for (int k=0; k<m; k++) {
                    if (s[k] != t[k]) diff.push_back(k);
                }
                if (diff.size()==0) d.merge(i,j);
                if (diff.size()==2) {
                    int ii = diff[0];
                    int jj = diff[1];
                    vi b = {s[ii],s[jj]};
                    vi c = {t[jj],t[ii]};
                    if (b==c) d.merge(i,j);
                }
            }
        }
        int ans = d.groups().size();
        return ans;      
    }
};