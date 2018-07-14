// Time:  O(nlogk)
// Space: O(k)

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) :
        k_(k) {
        for (const auto& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        min_heap_.emplace(val);
        if (min_heap_.size() > k_) {
            min_heap_.pop();
        }
        return min_heap_.top();
    }

private:
    const int k_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
 
