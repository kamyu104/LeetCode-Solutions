// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const auto m = *min_element(cbegin(arr), cend(arr));
        const auto& d = (*max_element(cbegin(arr), cend(arr)) - m) / (arr.size() - 1);
        if (!d) {
            return true;
        }
        for (int i = 0; i < arr.size();) {
            if (arr[i] == m + i * d) {
                ++i;
            } else {
                const auto& diff = arr[i] - m;
                if (diff % d || diff / d >= arr.size() || arr[i] == arr[diff / d]) {
                    return false;
                }
                swap(arr[i], arr[diff / d]);
            }
        }
        return true;
    }
};
