class Solution {
public:
    vector<vector<string>> findLadders(string s, string t, vector<string>& a) {
      using vi = vector<int>;
      using vvi = vector<vi>;
      const int inf = 1e9;
      
      map<string,int> mp1;
      map<int,string> mp2;
      int idx = 0;
      for (auto x : a) mp1[x] = 0;
      vector<vector<string>> ret;
      if (!mp1.count(t)) return ret;
      mp1[s] = 0;
      int sz = 0;
      for (auto &[k,v] : mp1) {
        v = sz++;
        mp2[v] = k;
      }
      int start = mp1[s];
      int goal = mp1[t];
      vvi adj(sz); 
      for (int i=0; i<sz; i++) {
        for (int j=i+1; j<sz; j++) {
          string u = mp2[i];
          string v = mp2[j];
          int cnt = 0;
          for (int k=0; k<u.size(); k++) 
            cnt += u[k] != v[k];
          if (cnt==1) {
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
    
      vi dist(sz,inf);
      queue<int> q;
      dist[start] = 0;
      q.push(start);
      while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
          if (dist[v] < inf) continue;
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
      int d = dist[goal];
      if (d == inf) return ret;
      
      vvi b = {{goal}};
      for (int i=d-1; i>=0; i--) {
        vvi temp;
        for (auto c : b) {
          int u = c.back();
          for (auto v : adj[u]) {
            if (dist[v] == i) {
              vi d = c;
              d.push_back(v);
              temp.push_back(d);
            }
          }
        }
        b = temp;
      }
      for (auto &c : b) {
        reverse(c.begin(), c.end());
        vector<string> d;
        for (auto &u : c) {
          d.push_back(mp2[u]);
        }
        ret.push_back(d);
      }
      return ret;
        
    }
};