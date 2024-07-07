// Time:  O(nlogr), r = max(nums)
// Space: O(logr)

// freq table, two pointers, sliding window, lc1521
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        BitCount count(bit_length(ranges::max(nums)));
        int result = numeric_limits<int>::max();
        for (int left = 0, right = 0; right < size(nums); ++right) {
            count += nums[right];
            while (left <= right) {
                const auto& f = count.bitOr();
                result = min(result, abs(f - k));
                if (f <= k) {
                    break;
                }
                count -= nums[left++];
            }
        }
        return result;
    }

private:
    int bit_length(int x) {
        return (x ? std::__lg(x) : -1) + 1;
    }

    class BitCount {
    public:
        BitCount(int n)
          : l_(0)
          , n_(n)
          , count_(n) {
            
        }

        int bitOr() const {
            int num = 0;
            for (int i = 0; i < n_; ++i) {
                if (count_[i]) {
                    num |= 1 << i;
                }
            }
            return num;
        }

        void operator+=(int num) {
            ++l_;
            for (int i = 0; i < n_; ++i) {
                if (num & (1 << i)) {
                    ++count_[i];
                }
            }
        }
        
        void operator-=(int num) {
            --l_;
            for (int i = 0; i < n_; ++i) {
                if (num & (1 << i)) {
                    --count_[i];
                }
            }
        }

    private:
        int l_;
        int n_;
        vector<int> count_;
    };
};

// Time:  O(nlogr), r = max(nums)
// Space: O(logr)
// freq table, two pointers, lc1521
class Solution2 {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int result = numeric_limits<int>::max();
        unordered_set<int> dp;  // at most O(logr) dp states
        for (const auto& x : nums) {
            unordered_set<int> new_dp = {x};
            for (const auto& f: dp) {
                new_dp.emplace(f | x);
            }
            for (const auto& f : new_dp) {
                result = min(result, abs(f - k));
            }
            dp = move(new_dp);
        }
        return result;
    }
};
