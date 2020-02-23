// Time:  O(sqrt(n))
// Space: O(1)

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<vector<int>> results = {divisors(num + 1), divisors(num + 2)};
        return *min_element(cbegin(results), cend(results),
                            [](const auto& a, const auto& b) {
                                return a[1] - a[0] < b[1] - b[0];
                            });
    }

private:
    vector<int> divisors(int n) {
        for (int d = sqrt(n); d >= 1; --d) {
            if (n % d == 0) {
                return {d, n / d};
            }
        }
        return {1, n};
    }
};

// Time:  O(sqrt(n))
// Space: O(1)
class Solution2 {
public:
    vector<int> closestDivisors(int num) {
        vector<int> result = {1, num};
        for (int d = 1; d * d <= num + 2; ++d) {
            if ((num + 2) % d == 0) {
                result = {d, (num + 2) / d};
            }
            if ((num + 1) % d == 0) {
                result = {d, (num + 1) / d};
            }
        }
        return result;
    }
};
