const int inf = 1e5;
using pii = pair<int,int>;

class SummaryRanges {
public:

  set<pii> s = {{-inf,-inf}, {inf,inf}};
  
  SummaryRanges() {
    
  }

  void addNum(int x) {
    auto it2 = s.lower_bound({x,x});
    auto it1 = prev(it2);

    auto [l1,r1] = *it1;
    auto [l2,r2] = *it2;

    if ((l1<=x && x<=r1) || (l2<=x && x<=r2)) return;
    else if (x==l2-1 && x==r1+1) {
      s.erase(it1);
      s.erase(it2);
      s.insert({l1,r2});
    }
    else if (x==l2-1) {
      s.erase(it2);
      s.insert({x,r2});
    }
    else if (x==r1+1) {
      s.erase(it1);
      s.insert({l1,x});
    }
    else s.insert({x,x});
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> ret;
    for (auto [l,r] : s) {
      if (l==-inf || l==inf) continue;
      ret.push_back({l,r});
    }
    return ret;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */