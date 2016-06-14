// Time:  O(k * (m + n + k)) ~ O(k * (m + n + k^2))
// Space: O(m + n + k^2)

// DP + Greedy solution.
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int m = nums1.size(), n = nums2.size();
        vector<vector<int>> max_numbers1(k + 1), max_numbers2(k + 1);
        maxNumberDP(nums1, max(0, k - n), min(k, m), &max_numbers1);  // O(k * m) time, O(m + k^2) space.
        maxNumberDP(nums2, max(0, k - m), min(k, n), &max_numbers2);  // O(k * n) time, O(n + k^2) space.

        vector<int> res(k);
        for (int i = max(0, k - n); i <= min(k, m); ++i) {  // k * O(k) ~ k * O(k^2) time
            vector<int> tmp(k);
            merge(max_numbers1[i], max_numbers2[k - i], &tmp);
            if (tmp > res) {
                res = move(tmp);
            }
        }
        return res;
    }
private:
    void maxNumberDP(vector<int> nums, int start, int end, vector<vector<int>> *max_numbers) {
        (*max_numbers)[end] = maxNumber(nums, end);
        for (int i = end - 1; i >= start; --i) {
            (*max_numbers)[i] = deleteNumber((*max_numbers)[i + 1]);
        }
    }

    // Time:  O(n)
    // Space: O(n)
    vector<int> maxNumber(const vector<int>& nums, int k) {
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
    vector<int> deleteNumber(const vector<int>& nums) {
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
            if (greater(first1, last1, first2, last2)) {
                *result++ = *first1++;
            } else {
                *result++ = *first2++;
            }
        }
    }

    template<typename IT>
    bool greater(IT first1, IT last1, IT first2, IT last2) {
        while (first1 != last1 && first2 != last2 && *first1 == *first2) {
            ++first1;
            ++first2;
        }
        return (first2 == last2) || (first1 != last1 && *first1 > *first2);
    }
};
