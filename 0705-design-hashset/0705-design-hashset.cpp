class MyHashSet {
public:
    vector<int> a;
    MyHashSet() {
        a.resize(1e6+1);
    }
    
    void add(int key) {
        a[key] = 1;
    }
    
    void remove(int key) {
        a[key] = 0;
    }
    
    bool contains(int key) {
        return a[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */