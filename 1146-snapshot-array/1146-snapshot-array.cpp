using ll = long long;
using vi = vector<ll>;
using vp = vector<pair<ll,ll>>;

class SnapshotArray {
public:
    vector<map<ll,ll>> mp;
    ll idx = 0;
    vi a;
    int n;
    queue<pair<ll,ll>> q;
    SnapshotArray(int length) {
        n = length;
        a.resize(n);
        mp.resize(n);
    }
    
    void set(int idx, int val) {
        a[idx] = val;
        q.push({idx,val});
    }
    
    int snap() {
        if (idx==0) {
            for (int i=0; i<n; i++) {
                mp[i][idx] = a[i];
            }
        }
        else {
            while (q.size()) {
                auto [i,val] = q.front();
                q.pop();
                mp[i][idx] = val;
            }
        }
        
        return idx++;
    }
    
    int get(int i, int snap_id) {
        auto it = mp[i].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */