class PQ {
    constructor(comparator = (a, b) => a - b) {
        this.heap = [];
        this.comparator = comparator;
    }

    push(val) {
        this.heap.push(val);
        this._heapifyUp();
    }

    pop() {
        if (this.size() === 1) {
            return this.heap.pop();
        }
        const top = this.heap[0];
        this.heap[0] = this.heap.pop();
        this._heapifyDown();
        return top;
    }

    top() {
        return this.heap[0];
    }

    size() {
        return this.heap.length;
    }

    _heapifyUp() {
        let index = this.heap.length - 1;
        while (index > 0) {
            let parentIndex = Math.floor((index - 1) / 2);
            if (this.comparator(this.heap[index], this.heap[parentIndex]) >= 0) break;
            [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
            index = parentIndex;
        }
    }

    _heapifyDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[0];

        while (true) {
            let leftChildIndex = 2 * index + 1;
            let rightChildIndex = 2 * index + 2;
            let leftChild, rightChild;
            let swap = null;

            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                if (this.comparator(leftChild, element) < 0) {
                    swap = leftChildIndex;
                }
            }

            if (rightChildIndex < length) {
                rightChild = this.heap[rightChildIndex];
                if (
                    (swap === null && this.comparator(rightChild, element) < 0) ||
                    (swap !== null && this.comparator(rightChild, leftChild) < 0)
                ) {
                    swap = rightChildIndex;
                }
            }

            if (swap === null) break;
            [this.heap[index], this.heap[swap]] = [this.heap[swap], this.heap[index]];
            index = swap;
        }
    }
}

/**
 * @param {number[][]} queries
 * @param {number} k
 * @return {number[]}
 */
var resultsArray = function(qr, k) {
    // const pq = new PQ((a, b) => a - b); // Min-heap
    const pq = new PQ((a, b) => b - a); // Max-heap

    const ans = [];

    for (const v of qr) {
        const d = Math.abs(v[0]) + Math.abs(v[1]);
        pq.push(d);
        while (pq.size() > k) pq.pop();
        ans.push(pq.size() === k ? pq.top() : -1);
    }

    return ans;
};

