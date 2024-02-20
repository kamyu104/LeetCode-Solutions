// Time:  precompute: O(10^MAX_N_M)
//        runtime:    O(n * m * (n + m))
// Space: O(10^MAX_N_M + n * m * (n + m))

// number theory, freq table
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

const int MAX_N_M = 6;
const auto& SPF = linear_sieve_of_eratosthenes(pow(10, MAX_N_M) - 1);
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        const auto& numbers = [&](int i, int j, int di, int dj) {
            vector<int> result;
            for (int curr = 0; 0 <= i && i < size(mat) && 0 <= j && j < size(mat[0]); i += di, j += dj) {
                curr = curr * 10 + mat[i][j];
                result.emplace_back(curr);
            }
            return result;
        };

        unordered_map<int, int> cnt;
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                for (const auto& [di, dj] : DIRECTIONS) {
                    for (const auto& x : numbers(i, j, di, dj)) {
                        if (x > 10 && SPF[x] == x) {
                            ++cnt[x];
                        }
                    }
                }
            }
        }
        pair<int, int> result = {0, -1};
        for (const auto& [k, v] : cnt) {
            result = max(result, pair(v, k));
        }
        return result.second;
    }
};


// Time:  O(n * m * (n + m) * sqrt(10^MAX_N_M))
// Space: O(n * m * (n + m))
// number theory, feq table
bool is_prime(int n) {
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i < n; i += 6) {
        if (i * i > n) {
            break;
        }
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

class Solution2 {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        const auto& numbers = [&](int i, int j, int di, int dj) {
            vector<int> result;
            for (int curr = 0; 0 <= i && i < size(mat) && 0 <= j && j < size(mat[0]); i += di, j += dj) {
                curr = curr * 10 + mat[i][j];
                result.emplace_back(curr);
            }
            return result;
        };

        unordered_map<int, int> cnt;
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                for (const auto& [di, dj] : DIRECTIONS) {
                    for (const auto& x : numbers(i, j, di, dj)) {
                        if (x > 10) {
                            ++cnt[x];
                        }
                    }
                }
            }
        }
        cout << is_prime(19) << endl;
        pair<int, int> result = {0, -1};
        for (const auto& [k, v] : cnt) {
            if (is_prime(k)) {
                result = max(result, pair(v, k));
            }
        }
        return result.second;
    }
};
