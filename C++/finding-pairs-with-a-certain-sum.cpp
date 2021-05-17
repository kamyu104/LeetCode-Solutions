// Time:  ctor:  O(n1 + n2)
//        add:   O(1)
//        count: O(n1)
// Space: O(n1 + n2)

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
     : nums2_(nums2) {
        for (const auto& x : nums1) {
            ++count1_[x];
        }
        for (const auto& x : nums2) {
            ++count2_[x];
        }
    }
    
    void add(int index, int val) {
        --count2_[nums2_[index]];
        nums2_[index] += val;
        ++count2_[nums2_[index]];
    }
    
    int count(int tot) {
        int result = 0;
        for (const auto& [x, cnt] : count1_) {
            if (count2_.count(tot - x)) {
                result += cnt * count2_[tot - x];
            }
        }
        return result;
    }

private:
    vector<int> nums2_;
    unordered_map<int, int> count1_, count2_;
};
