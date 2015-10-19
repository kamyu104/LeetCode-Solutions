// Time:  O(nlogn) for total n addNums, O(logn) per addNum, O(1) per findMedian.
// Space: O(n), total space

// Heap solution.
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        // Balance smaller half and larger half.
        if (max_heap_.empty() || num > max_heap_.top()) {
            min_heap_.emplace(num);
            if (min_heap_.size() > max_heap_.size() + 1) {
                max_heap_.emplace(min_heap_.top());
                min_heap_.pop();
            }
        } else {
            max_heap_.emplace(num);
            if (max_heap_.size() > min_heap_.size()) {
                min_heap_.emplace(max_heap_.top());
                max_heap_.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return min_heap_.size() == max_heap_.size() ?
                   (max_heap_.top() + min_heap_.top()) / 2.0 :
                   min_heap_.top();

    }

private:
    // min_heap_ stores the larger half seen so far.
    priority_queue<int, vector<int>, greater<int>> min_heap_;
    // max_heap_ stores the smaller half seen so far.
    priority_queue<int, vector<int>, less<int>> max_heap_;
};

// BST solution.
class MedianFinder2 {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        // Balance smaller half and larger half.
        if (max_bst_.empty() || num > *max_bst_.cbegin()) {
            min_bst_.insert(num);
            if (min_bst_.size() > max_bst_.size() + 1) {
                max_bst_.insert(*min_bst_.cbegin());
                min_bst_.erase(min_bst_.cbegin());
            }
        } else {
            max_bst_.insert(num);
            if (max_bst_.size() > min_bst_.size()) {
                min_bst_.insert(*max_bst_.cbegin());
                max_bst_.erase(max_bst_.cbegin());
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return min_bst_.size() == max_bst_.size() ?
                   (*max_bst_.cbegin() + *min_bst_.cbegin()) / 2.0 :
                   *min_bst_.cbegin();

    }

private:
   // min_bst_ stores the larger half seen so far.
    multiset<int, less<int>> min_bst_;
    // max_bst_ stores the smaller half seen so far.
    multiset<int, greater<int>> max_bst_;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
