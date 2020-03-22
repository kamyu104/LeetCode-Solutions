// Time:  O(n * sqrt(n))
// Space: O(1)

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (const auto& num : nums) {
            vector<int> facs;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i) {
                    continue;
                }
                facs.emplace_back(i);
                if (i != num / i) {
                    facs.emplace_back(num / i);
                    if (facs.size() > 4) {
                        break;
                    }
                }
            }
            if (facs.size() == 4) {
                result += accumulate(cbegin(facs), cend(facs), 0);
            } 
        }
        return result;
    }
};

// Time:  O(n * sqrt(n))
// Space: O(sqrt(n))
class Solution2 {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (const auto& num : nums) {
            const auto& facs = factorize(num);
            if (facs.size() == 1 && facs[0].second == 3) {
                const auto& p = facs[0].first;
                result += int(pow(p, 4) - 1) / (p - 1);  // p^0 + p^1 +p^2 +p^3
            } else if (facs.size() == 2 &&
                       facs[0].second == 1 &&
                       facs[1].second == 1) {
                const auto& [p, q] = pair(facs[0].first, facs[1].first);
                result += (1 + p) * (1 + q);
            }
        }
        return result;
    }

private:
    vector<pair<int, int>> factorize(int x) {
        vector<pair<int, int>> result;
        for (int d = 2; d * d <= x; d += (d == 2) ? 1: 2) {
            int e = 0;
            for (; x % d == 0; ++e) {
                x /= d;
            }
            if (e) {
                result.emplace_back(d, e);
            }
        }
        if (x > 1) {
            result.emplace_back(x, 1);
        }
        return result;
    }
};
