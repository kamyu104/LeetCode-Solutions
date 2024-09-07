// Time:  ctor: O(n)
//        pick: O(1)
// Space: O(n)

class Solution {
public:
    Solution(vector<int> nums) : gen_(random_device()()) {
        for (int i = 0; i < size(nums); ++i) {
            lookup_[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        uniform_int_distribution<int> dist(0, size(lookup_[target]) - 1);
        return lookup_[target][dist(gen_)];
    }

private:
    unordered_map<int, vector<int>> lookup_;
    default_random_engine gen_;
};

// Time:  ctor: O(1)
//        pick: O(n)
// Space: O(1)
class Solution_TLE {
public:
    Solution_TLE(vector<int> nums) : nums_(nums), gen_(random_device()()) {
        
    }
    
    int pick(int target) {
        auto reservoir = -1;
        auto n = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] != target) {
                continue;
            }
            uniform_int_distribution<int> dist(0, n++);
            if (dist(gen_) == 0) {
                reservoir = i;
            }
        }
        return reservoir;
    }

private:
    const vector<int> nums_;
    default_random_engine gen_;
};
