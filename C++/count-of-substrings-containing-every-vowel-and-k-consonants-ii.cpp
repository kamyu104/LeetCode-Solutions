// Time:  O(n)
// Space: O(1)

// two pointers, sliding window, freq table
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        vector<int> cnt1(26), cnt2(26);
        int curr1 = 0, curr2 = 0;
        const auto& update = [&](int i, int d) {
            if (!VOWELS.count(word[i])) {
                curr2 += d;
                return;
            }
            const auto x = word[i] - 'a';
            if (cnt1[x] == 0) {
                ++curr1;
            }
            cnt1[x] += d;
            if (cnt1[x] == 0) {
                --curr1;
            }
        };

        int64_t result = 0;
        for (int right = 0, left = 0, mid = 0; right < size(word); ++right) {
            update(right, +1);
            while (curr2 > k) {
                update(left, -1);
                if (left < mid) {
                    --cnt2[word[left] - 'a'];
                }
                mid = max(mid, ++left);
            }
            if (!(curr1 == size(VOWELS) && curr2 == k)) {
                continue;
            }
            for (; VOWELS.count(word[mid]) && cnt1[word[mid] - 'a'] - (cnt2[word[mid] - 'a'] + 1) >= 1; ++mid) {
                ++cnt2[word[mid] - 'a'];
            }
            result += mid - left + 1;                
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// two pointers, sliding window, freq table
class Solution2 {
public:
    long long countOfSubstrings(string word, int k) {
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        const auto& count = [&](int k) {
            vector<int> cnt(26);
            int curr1 = 0, curr2 = 0;
            const auto& update = [&](int i, int d) {
                if (!VOWELS.count(word[i])) {
                    curr2 += d;
                    return;
                }
                const auto x = word[i] - 'a';
                if (cnt[x] == 0) {
                    ++curr1;
                }
                cnt[x] += d;
                if (cnt[x] == 0) {
                    --curr1;
                }
            };
    
            int64_t result = 0;
            for (int right = 0, left = 0; right < size(word); ++right) {
                update(right, +1);
                for (; curr1 >= size(VOWELS) && curr2 >= k; ++left) {
                    result += size(word) - right;
                    update(left, -1);
                }
            }
            return result;
        };

        return count(k) - count(k + 1);
    }
};
