// Time:  O(n^(1/2) * (logn + n^(1/2)))
// Space: O(logn)

class Solution {
public:
    int primePalindrome(int N) {
        if (8 <= N && N <= 11) {
            // any palindrome with even digits is multiple of 11
            return 11;
        }
        for (int i = to_string(N).length() / 2; i < 100000; ++i) {
            const string s = to_string(i), rev_s(s.rbegin(), s.rend());
            int j = stoi(s + rev_s.substr(1));
            if (j >= N && isPrime(j)) {
                return j;
            }
        }
        return -1;
    }

private:
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) {
            return num == 2;
        }
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};
