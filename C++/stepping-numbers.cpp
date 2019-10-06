// Time:  O(logk + r), r is the size of result
// Space: O(k), k is the size of stepping numbers in [0, high]

constexpr auto result = []() {
    const int MAX_HIGH = 2e9;
    array<int, 3504> result{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1, l = 10; result[l - 1] < MAX_HIGH; ++i) {
        int d1 = result[i] % 10 - 1, d2 = result[i] % 10 + 1;
        if (d1 >= 0) {
            result[l++] = result[i] * 10 + d1;
        }
        if (d2 <= 9) {
            result[l++] = result[i] * 10 + d2;
        }
    }
    result.back() = numeric_limits<int>::max();
    return result;
}();

class Solution {
public:
	vector<int> countSteppingNumbers(int low, int high) {
		const auto lit = lower_bound(result.cbegin(), result.cend(), low);
		const auto rit = upper_bound(result.cbegin(), result.cend(), high);
		return vector<int>(lit, rit);
	}
};

// Time:  O(k + r), r is the size of result
// Space: O(k), k is the size of stepping numbers in [0, high]
class Solution2 {
public:
	vector<int> countSteppingNumbers(int low, int high) {
        vector<int> result{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 1; result.back() < high; ++i) {
            int d1 = result[i] % 10 - 1;
            if (d1 >= 0) {
                result.emplace_back(result[i] * 10 + d1);
            }
            int d2 = result[i] % 10 + 1;
            if (d2 <= 9) {
                result.emplace_back(result[i] * 10 + d2);
            }
        }
        result.emplace_back(numeric_limits<int>::max());

		const auto lit = lower_bound(result.cbegin(), result.cend(), low);
		const auto rit = upper_bound(result.cbegin(), result.cend(), high);
		return vector<int>(lit, rit);
	}
};
