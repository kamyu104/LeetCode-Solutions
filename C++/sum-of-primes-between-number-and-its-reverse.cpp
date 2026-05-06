// Time:  precompute: O(r)
//        runtime:    O(1)
// Space: O(r)

// number theory, prefix sum
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
}

const auto& precompute = [](int n) {
    const auto& spf = linear_sieve_of_eratosthenes(n);
    vector<int> prefix(size(spf) + 1);
    for (int i = 0; i + 1 < size(prefix); ++i) {
        prefix[i + 1] = prefix[i] + (spf[i] == i ? i : 0);
    }
    return prefix;
};

const int MAX_N = 1000;
const auto& PREFIX = precompute(MAX_N);

class Solution {
public:
    int sumOfPrimesInRange(int n) {
        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        int left = n, right = reverse(n);
        if (left > right) {
            swap(left, right);
        }
        return PREFIX[right + 1] - PREFIX[left];
    }
};
