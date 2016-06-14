// Time:  O(k * (m + n + k)) ~ O(k * (m + n + k^2))
// Space: O(m + n + k^2)

// DP + Greedy solution. (48ms)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k);
        const int m = nums1.size(), n = nums2.size();
        vector<vector<int>> max_digits1(k + 1), max_digits2(k + 1);
        getMaxDigits(nums1, max(0, k - n), min(k, m), &max_digits1);  // O(k * m) time, O(m + k^2) space.
        getMaxDigits(nums2, max(0, k - m), min(k, n), &max_digits2);  // O(k * n) time, O(n + k^2) space.
        for (int i = max(0, k - n); i <= min(k, m); ++i) {  // k * O(k) ~ k * O(k^2) time.
            int j = k - i;
            vector<int> tmp(k);
            merge(max_digits1[i], max_digits2[j], &tmp);
            if (tmp > res) {
                res = tmp;
            }
        }
        return res;
    }

private:
    void getMaxDigits(vector<int> nums, int start, int end, vector<vector<int>> *maxDigits) {
        (*maxDigits)[end] = maxDigit(nums, end);
        for (int i = end - 1; i >= start; --i) {
            (*maxDigits)[i] = deleteDigit((*maxDigits)[i + 1]);
        }
    }

    // Time:  O(n)
    // Space: O(n)
    vector<int> maxDigit(const vector<int>& nums, int k) {
        vector<int> res;
        int drop = nums.size() - k;
        for (const auto& num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                --drop;
            }
            res.emplace_back(num);
        }
        res.resize(k);
        return res;
    }

    // Time:  O(n)
    // Space: O(n)
    vector<int> deleteDigit(const vector<int>& nums) {
        vector<int> res(nums);
        for (int i = 0; i < res.size(); ++i) {
            if (i == res.size() - 1 || res[i] < res[i + 1]) {
                res.erase(res.begin() + i);
                break;
            }
        }
        return res;
    }

    // Time:  O(k) ~ O(k^2)
    // Space: O(1)
    void merge(const vector<int>& vec1, const vector<int>& vec2, vector<int> *res) {
        auto first1 = vec1.begin(), last1 = vec1.end(),
             first2 = vec2.begin(), last2 = vec2.end();
        auto result = res->begin();
        while (first1 != last1 || first2 != last2) {
            int val1 = first1 != last1 ? *first1 : numeric_limits<int>::min();
            int val2 = first2 != last2 ? *first2 : numeric_limits<int>::min();
            if (val1 > val2) {
                *result++ = *first1++;
            } else if (val1 < val2) {
                *result++ = *first2++;
            } else {
                auto pos1 = first1 + 1, pos2 = first2 + 1;
                while (pos1 != last1 || pos2 != last2) {  // O(1) ~ O(k) time.
                    int val1 = (pos1 != last1) ? *(pos1) : numeric_limits<int>::min();
                    int val2 = (pos2 != last2) ? *(pos2) : numeric_limits<int>::min();
                    if (val1 > val2) {
                        *result++ = *first1++;
                        break;
                    } else if (val1 < val2) {
                        *result++ = *first2++;
                        break;
                    }
                    ++pos1, ++pos2;
                }
                if (pos1 == last1 && pos2 == last2) {
                    *result++ = *first2++;
                }
            }
        }
    }
};
