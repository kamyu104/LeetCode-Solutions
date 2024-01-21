// Time:  O(n)
// Space: O(1)

// math, prefix sum, difference array
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        --x, --y;
        if (x > y) {
            swap(x, y);
        }
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[0] += 1 + 1;                                                  // i -> two routes begin
            ++diff[min(abs(i - x), abs(i - y) + 1)];                           // i -> x -> y, fork one route at x to y
            ++diff[min(abs(i - y), abs(i - x) + 1)];                           // i -> y -> x, fork one route at y to x
            --diff[min(abs(i - 0), abs(i - y) + 1 + abs(x - 0))];              // i -> 0, one route ends
            --diff[min(abs(i - (n - 1)), abs(i - x) + 1 + abs(y - (n - 1)))];  // i -> n-1, one route ends
            --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 0) / 2];         // i -> x -> ((y-x)+0)//2 <- x, one route ends
            --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 1) / 2];         // i -> y -> ((y-x)+1)//2 <- y, one route ends
        }
        for (int i = 0; i + 1 < n; ++i) {
            diff[i + 1] += diff[i];
        }
        return diff;
    }
};

// Time:  O(n^2)
// Space: O(1)
// math
class Solution2 {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        --x, --y;
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const int d = min({abs(i - j), abs(i - x) + 1 + abs(y - j), abs(i - y) + 1 + abs(x - j)});
                result[d - 1] += 2;
            }
        }
        return result;
    }
};
