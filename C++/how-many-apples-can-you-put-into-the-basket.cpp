// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        static int LIMIT = 5000;
        sort(arr.begin(), arr.end());
        int result = 0, total = 0;
        for (const auto& x : arr) {
            if (total + x > LIMIT) {
                break;
            }
            total += x;
            ++result;
        }
        return result;
    }
};
