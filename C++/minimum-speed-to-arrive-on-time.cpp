// Time:  O(nlogr), r is the range of speed
// Space: O(1)

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        static const double MAX_SPEED = 1e7;
        if (!check(dist, hour, MAX_SPEED)) {
            return -1;
        }
        int left = 1, right = MAX_SPEED;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(dist, hour, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int ceil(int a, int b) {
        return (a + b - 1) / b;
    }
    
    double total_time(const vector<int>& dist, int x) {
        return accumulate(cbegin(dist), prev(cend(dist)), 0,
                          [this, &x](int total, int i) {
                              return total + ceil(i, x);
                          }) +
               double(dist.back()) / x;
    }
    
    bool check(const vector<int>& dist, double hour, int x) {
        return total_time(dist, x) <= hour;
    }
};
