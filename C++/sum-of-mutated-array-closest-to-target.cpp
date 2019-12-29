// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end(), greater<int>());
        const auto max_arr = arr[0];
        while (!arr.empty() && arr.back() * arr.size() <= target) {
            target -= arr.back(); arr.pop_back();
        }
        // let x = ceil(t/n)-1
        // (1) (t/n-1/2) <= x:
        //    return x, which is equal to ceil(t/n)-1 = ceil(t/n-1/2) = (2t+n-1)//2n
        // (2) (t/n-1/2) > x:
        //    return x+1, which is equal to ceil(t/n) = ceil(t/n-1/2) = (2t+n-1)//2n
        // (1) + (2) => both return (2t+n-1)//2n
        return arr.empty() ? max_arr : (2 * target + arr.size() - 1) / (2 * arr.size());
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end(), greater<int>());
        const auto max_arr = arr[0];
        while (!arr.empty() && arr.back() * arr.size() <= target) {
            target -= arr.back(); arr.pop_back();
        }
        if (arr.empty()) {
            return max_arr;
        }
        const auto& x = (target - 1) / arr.size();
        return target - x * arr.size() <= (x + 1) * arr.size() - target ? x : x + 1;
    }
};

// Time:  O(nlogm), m is the max of arr, which may be larger than n
// Space: O(1)
class Solution3 {
public:
    int findBestValue(vector<int>& arr, int target) {
        int left = 1, right = *max_element(arr.cbegin(), arr.cend());
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(arr, mid, target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return target - total(arr, left - 1) <= total(arr, left) - target ? left - 1 : left;
    }

private:
    int total(const vector<int>& arr, int v) {
        return accumulate(arr.cbegin(), arr.cend(), 0,
                          [&v](const auto& x, const auto& y) {
                              return x + min(v, y);
                          });
    }

    bool check(const vector<int>& arr, int v, int target) {
        return total(arr, v) >= target;
    }
};
