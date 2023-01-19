class DataStream {
public:
  int cnt = 0;
  int v, k;
  DataStream(int value, int _k) {
    v = value;
    k = _k;
  }

  bool consec(int num) {
    if (num == v) cnt++;
    else cnt = 0;
    cnt = min(cnt, k);
    if (cnt==k) return true;
    else return false;
  }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */