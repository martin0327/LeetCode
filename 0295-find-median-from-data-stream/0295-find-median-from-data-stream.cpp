template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class MedianFinder {
public:
    max_pq<int> pq1;
    min_pq<int> pq2;
    
    MedianFinder() {
    
    }
    
    void addNum(int x) {
        pq1.push(x);
        if (pq1.size() > pq2.size()) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        while (pq1.top() > pq2.top()) {
            pq2.push(pq1.top()); pq1.pop();
            pq1.push(pq2.top()); pq2.pop();
        }
    }
    
    double findMedian() {
        if (pq1.size() == pq2.size()) {
            double ret = pq1.top() + pq2.top();
            return ret / 2.0;
        }
        else return pq2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */