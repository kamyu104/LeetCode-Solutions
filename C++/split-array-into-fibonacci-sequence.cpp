// Time:  O(n^3)
// Space: O(n)

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 0, a = 0; i + 2 < S.length(); ++i) {
            a = 10 * a + S[i] - '0';
            for (int j = i + 1, b = 0; j + 1 < S.length(); ++j) {
                b = 10 * b + S[j] - '0';
                vector<int> fib = {a, b};
                int k = j + 1;
                while (k < S.length()) {
                    if (fib[fib.size() - 2] > numeric_limits<int>::max() - fib[fib.size() - 1]) {
                        break;
                    }
                    auto c = fib[fib.size() - 2] + fib[fib.size() - 1];
                    auto l = startswith(S, k, c);
                    if (l == 0) {
                        break;
                    }
                    fib.emplace_back(c);
                    k += l;
                }
                if (k == S.length()) {
                    return fib;
                }
                if (b == 0) {
                    break;
                }
            }
            if (a == 0) {
                break;
            }
        }
        return {};
    }

private:
    int startswith(const string& S, int k, int x) {
        int y = 0;
        for (int i = k; i < S.length(); ++i) {
            y = 10 * y + S[i] - '0';
            if (y == x) {
                return i - k + 1;
            } else if (y > x) {
                break;
            }
        }
        return 0;
    }
};
