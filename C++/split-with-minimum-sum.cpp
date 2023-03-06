// Time:  O(mlogm), m = O(logn)
// Space: O(m)

// sort, greedy
class Solution {
public:
    int splitNum(int num) {
        vector<int> sorted_num;
        for (; num; num /= 10)  {
            sorted_num.emplace_back(num % 10);
        }
        sort(begin(sorted_num), end(sorted_num));
        int result = 0;
        for (int i = 0; i < size(sorted_num); ++i) {
            if (i % 2 == size(sorted_num) % 2) {
                result *= 10;
            }
            result += sorted_num[i];
        }
        return result;
    }
};
