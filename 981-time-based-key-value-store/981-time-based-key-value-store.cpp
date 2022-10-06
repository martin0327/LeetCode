class TimeMap {
public:
  map<string,set<pair<int,string>>> mp;
  TimeMap() {
  }

  void set(string key, string v, int t) {
    mp[key].insert({t,v});
  }

  string get(string key, int t) {
    pair<int, string> x = {t,"{}"};
    auto it = mp[key].upper_bound(x);
    if (it == mp[key].begin()) return "";
    else return (*prev(it)).second;
  }
  
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */