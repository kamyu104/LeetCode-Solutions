// Time:  O(nlogn) for total n addNums, O(logn) per addNum, O(1) per findMedian.
// Space: O(n), total space

class MedianFinder {
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
