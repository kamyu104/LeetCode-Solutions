// Time:  O(nlogn + nlogr), r is the range of positions
// Space: O(1)

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int left = 0, right = position.back() - position.front();
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(position, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const vector<int>& position, int m, int x) {
        int count = 1, prev = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - prev >= x) {
                ++count;
                prev = position[i];
            }
        }
        return count >= m;
    }
};
