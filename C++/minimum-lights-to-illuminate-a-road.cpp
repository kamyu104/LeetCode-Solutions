// Time:  O(n)
// Space: O(n)

// difference array, greedy
class Solution {
public:
    int minLights(vector<int>& lights) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        vector<int> diff(size(lights) + 1);
        for (int i = 0; i < size(lights); ++i) {
            if (!lights[i]) {
                continue;
            }
            ++diff[max(i - lights[i], 0)];
            --diff[min(i + lights[i], static_cast<int>(size(lights)) - 1) + 1];
        }
        int result = 0;
        for (int i = 0, curr = 0, cnt = 0; i < size(diff); ++i) {
            curr += diff[i];
            if (i + 1 == size(diff) || curr) {
                result += ceil_divide(cnt, 3);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        return result;
    }
};
