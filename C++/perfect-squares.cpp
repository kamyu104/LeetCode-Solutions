// Time:  O(n * sqrt(n))
// Space: O(n)

class Solution {
public:
    int numSquares(int n) {
        static vector<int> num{0};
        while (num.size() <= n) {
            int squares = numeric_limits<int>::max();
            for (int i = 1; i * i <= num.size(); ++i) {
                squares = min(squares, num[num.size() - i * i] + 1);
            }
            num.emplace_back(squares);
        }
        return num[n];
    }
};

// Time:  O(n * sqrt(n))
// Space: O(n)
class Solution2 {
public:
    int numSquares(int n) {
        vector<int> num(n + 1, numeric_limits<int>::max());
        num[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = i - 1, k = 1; j >= 0; ++k, j = i - k * k) {
                num[i] = min(num[i], num[j] + 1);
            }
        }
        return num[n];
    }
};
