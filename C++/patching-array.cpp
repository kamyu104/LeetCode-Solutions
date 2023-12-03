// Time:  O(s + logn), s is the number of elements in the array
// Space: O(1)

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0, reachable = 0;
        for (const auto& x : nums) {
            if (x > n) {
                break;
            }
            while (!(reachable >= x - 1)) {
                ++result;
                reachable += reachable + 1;
            }
            if (reachable >= n - x) {
                return result;
            }
            reachable += x;
        }
        ++result;
        for (; !(reachable >= n - (reachable + 1)); reachable += reachable + 1) {
            ++result;
        }
        return result;
    }
};

// Time:  O(s + logn), s is the number of elements in the array
// Space: O(1)
class Solution2 {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0, reachable = 0;
        for (const auto& x : nums) {
            while (!(reachable >= x - 1)) {
                ++result;
                if (reachable >= n - (reachable + 1)) {
                    return result;
                }
                reachable += reachable + 1;
            }
            if (reachable >= n - x) {
                return result;
            }
            reachable += x;
        }
        ++result;
        for (; !(reachable >= n - (reachable + 1)); reachable += reachable + 1) {
            ++result;
        }
        return result;
    }
};

// Time:  O(s + logn), s is the number of elements in the array
// Space: O(1)
class Solution3 {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        for (uint64_t miss = 1, i = 0; miss <= n;) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;  // miss may overflow, thus prefer to use uint64_t.
                ++patch;
            }
        }
        return patch;
    }
};
