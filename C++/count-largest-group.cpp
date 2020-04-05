// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> count;
        for (int i = 1; i <= n; ++i) {
            int total = 0;
            for (int j = i; j; j /= 10) {
                total += j % 10;
            } 
            ++count[total];
        }
        const auto& max_count = max_element(cbegin(count), cend(count),
                                            [](const auto& a, const auto& b) {
                                                return a.second < b.second;
                                            })->second;
        int result = 0;
        for (const auto& [_, v]: count) {
            if (v == max_count) {
                ++result;
            }
        }
        return result;
    }
};
