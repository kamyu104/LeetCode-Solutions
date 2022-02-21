// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        return (num % 3 == 0) ? vector<long long>({num / 3 - 1, num / 3, num / 3 + 1}) : vector<long long>();
    }
};
