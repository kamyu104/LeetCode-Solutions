// Time:  precompute: O(r), r = max(nums)
//        runtime:    O(n)
// Space: O(r)

// number theory, mono deque, two pointers, sliding window
vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
    vector<int> spf(n + 1, -1);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == -1) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const auto& p : primes) {
            if (i * p > n || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
    return spf;
};

const int MAX_NUMS = 5 * 1e4;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_NUMS);
class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        deque<int> idxs, max_dq, min_dq;
        int result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (SPF[nums[right]] == nums[right]) {
                idxs.emplace_back(right);
                while (!empty(max_dq) && nums[max_dq.back()] <= nums[right]) {
                    max_dq.pop_back();
                }
                max_dq.emplace_back(right);
                while (!empty(min_dq) && nums[min_dq.back()] >= nums[right]) {
                    min_dq.pop_back();
                }
                min_dq.emplace_back(right);
                for (; nums[max_dq[0]] - nums[min_dq[0]] > k; ++left) {
                    if (max_dq[0] == left) {
                        max_dq.pop_front();
                    }
                    if (min_dq[0] == left) {
                        min_dq.pop_front();
                    }
                    if (idxs[0] == left) {
                        idxs.pop_front();
                    }
                }
            }
            if (size(idxs) >= 2) {
                result += (idxs[size(idxs) - 2]) - left + 1;
            }
        }
        return result;
    }
};
