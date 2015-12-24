// Time:  O(k * n^2)
// Space: O(k * n)

// DP + Greedy solution. (48ms)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k);
        const int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> dp1(k + 1), dp2(k + 1);
        getDp(nums1, max(0, k - size2), min(k, size1), dp1);  // O(k * n) time
        getDp(nums2, max(0, k - size1), min(k, size2), dp2);  // O(k * n) time
        for (int i = max(0, k - size2); i <= min(k, size1); ++i) {  // O(k * n^2) time
            int j = k - i;
            vector<int> tmp(k);
            merge(dp1[i].begin(), dp1[i].end(), dp2[j].begin(), dp2[j].end(), tmp.begin());
            if (compareVector(tmp, res)) {
                res = tmp;
            }
        }
        return res;
    }

    void getDp(vector<int> nums, int start, int end, vector<vector<int>> &dp) {
        dp[end] = maxDigit(nums, end);
        for (int i = end - 1; i >= start; --i) {
            dp[i] = deleteDigit(dp[i + 1]);
        }
    }

    // Time:  O(n)
    // Space: O(n)
    vector<int> maxDigit(const vector<int>& nums, int k) {
        vector<int> res;
        int delete_cnt = nums.size() - k;
        for (const auto& num : nums) {
            while (delete_cnt > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                --delete_cnt;
            }
            res.emplace_back(num);
        }
        while (delete_cnt > 0) {
            res.pop_back();
            --delete_cnt;
        }
        return res;
    }

    // Time:  O(n)
    // Space: O(n)
    vector<int> deleteDigit(const vector<int>& nums) {
        vector<int> res(nums);
        for (int j = 0; j < res.size(); ++j) {
            if (j == res.size() - 1 || res[j] < res[j + 1]) {
                res.erase(res.begin() + j);
                break;
            }
        }
        return res;
    }

    // Time:  O(n)
    // Space: O(1)
    template <class T>
    bool compareVector(T vec1, T vec2) {
        auto first1 = vec1.begin(), last1 = vec1.end(), first2 = vec2.begin(), last2 = vec2.end();
        for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
            if (*first1 > *first2) {
                return true;
            } else if (*first1 < *first2) {
                return false;
            }
        }
        if (first1 == last1) {
            return false;
        } else {
            return true;
        }
    }

    // Time:  O(n^2)
    // Space: O(1)
    template <class T>
    T merge(T first1, T last1, T first2, T last2, T result) {
        while (true) {
            if (first1 == last1) {
                return std::copy(first2,last2,result);
            }
            if (first2 == last2) {
                return std::copy(first1,last1,result);
            }
            if (*first2 > *first1) {
                *result++ = *first2++;
            } else if (*first2 < *first1) {
                *result++ = *first1++;
            } else {
                auto pos1 = first1, pos2 = first2;
                while (true) {  // Worst case O(n^2) time.
                    int v1 = (++pos1 != last1) ? *(pos1) : numeric_limits<int>::min();
                    int v2 = (++pos2 != last2) ? *(pos2) : numeric_limits<int>::min();
                    if (v1 > v2) {
                        *result++ = *first1++;
                        break;
                    } else if (v1 < v2) {
                        *result++ = *first2++;
                        break;
                    }
                }
            }
        }
    }
};
