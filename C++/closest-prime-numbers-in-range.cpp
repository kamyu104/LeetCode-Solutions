// Time:  precompute:  O(MAX_N * log(MAX_N))
//        runtime:     O(log(MAX_N))
// Space: O(MAX_N)

// Template:
// https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/booking-concert-tickets-in-groups.cpp
template <typename T>
class SegmentTree {
    public:
    explicit SegmentTree(
        int N,
        const function<T(const int&)>& build_fn,
        const function<T(const T&, const T&)>& query_fn)
        : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
        base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
        build_fn_(build_fn),
        query_fn_(query_fn) {

        for (int i = base; i < base + N; ++i) {
            tree[i] = build_fn_(i - base);
        }
        for (int i = base - 1; i >= 1; --i) {
            tree[i] = query_fn_(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(int L, int R) const {
        L += base;
        R += base;
        T left, right;
        for (; L <= R; L /= 2, R /= 2) {
            if (L & 1) {
                left = query_fn_(left, tree[L]);
                ++L;
            }
            if ((R & 1) == 0) {
                right = query_fn_(tree[R], right);
                --R;
            }
        }
        return query_fn_(left, right);
    }

    vector<T> tree;
    int base;

private:
    const function<T(const int&)> build_fn_;
    const function<T(const T&, const T&)> query_fn_;
};

// number theory, segment tree
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
    return primes;  // len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n
}

const int MAX_N = 1e6;
const auto& PRIMES = linear_sieve_of_eratosthenes(MAX_N);
const auto& build_fn = [](int i) {
    return vector<int>{PRIMES[i + 1] - PRIMES[i], PRIMES[i], PRIMES[i + 1]};
};
const auto& query_fn = [](const vector<int>& x, const vector<int>& y) {
    if (empty(x)) {
        return y;
    }
    if (empty(y)) {
        return x;
    }
    return min(x, y);
};

const auto& ST = SegmentTree<vector<int>>(size(PRIMES) - 1, build_fn, query_fn);
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int i = distance(cbegin(PRIMES), lower_bound(cbegin(PRIMES), cend(PRIMES), left));
        int j = distance(cbegin(PRIMES), upper_bound(cbegin(PRIMES), cend(PRIMES), right)) - 1;
        if (i > j - 1) {
            return {-1, -1};
        }
        const auto& result = ST.query(i, j - 1);
        return {result[1], result[2]};
    }
};

