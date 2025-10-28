// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    long long maxCaloriesBurnt(vector<int>& heights) {
        ranges::sort(heights);
        int left = 0, right = size(heights) - 1;
        int64_t result = static_cast<int64_t>(0 - heights[right]) * (0 - heights[right]);
        while (left != right) {
            result += static_cast<int64_t>(heights[right] - heights[left]) * (heights[right] - heights[left]);
            --right;
            if (left == right) {
                break;
            }
            result += static_cast<int64_t>(heights[left] - heights[right]) * (heights[left] - heights[right]);
            ++left;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, greedy
class Solution2 {
public:
    long long maxCaloriesBurnt(vector<int>& heights) {
        ranges::sort(heights);
        int left = 0, right = size(heights) - 1;
        int64_t result = static_cast<int64_t>(0 - heights[right]) * (0 - heights[right]);
        for (int8_t d = 0; left != right;) {
            result += static_cast<int64_t>(heights[right] - heights[left]) * (heights[right] - heights[left]);
            left += d;
            d ^= 1;
            right -= d;
        }
        return result;
    }
};
