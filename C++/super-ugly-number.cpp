// Time:  O(n * k)
// Space: O(n + k)

// Heap solution. (308ms)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> uglies(n), idx(primes.size()), ugly_by_last_prime(n);
        uglies[0] = 1;

        for (int i = 0; i < primes.size(); ++i) {
            heap.emplace(primes[i], i);
        }
        for (int i = 1; i < n; ++i) {
            int k;
            tie(uglies[i], k) = heap.top();
            heap.pop();
            ugly_by_last_prime[i] = k;
            while (ugly_by_last_prime[++idx[k]] > k);  // average time: O(k)
            heap.emplace(uglies[idx[k]] * primes[k], k);
        }
        return uglies[n - 1];
    }
};

// Time:  O(n * k)
// Space: O(n + k)
// DP solution. (596ms)
class Solution2 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglies(n), ugly_by_prime(primes), idx(primes.size());
        uglies[0] = 1;

        for (int i = 1; i < n; ++i) {
            int min_val = *min_element(ugly_by_prime.begin(), ugly_by_prime.end());
            uglies[i] = min_val;
            for (int k = 0; k < primes.size(); ++k) {
                if (min_val == ugly_by_prime[k]) {
                    ugly_by_prime[k] = primes[k] * uglies[++idx[k]];
                }
            }
        }
    
        return uglies[n - 1]; 
    }
};

// Time:  O(n * logk) ~ O(n * klogk)
// Space: O(k^2)
// Heap solution. (612ms)
class Solution3 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long ugly_number = 0;
        priority_queue<long long , vector<long long>, greater<long long>> heap;

        heap.emplace(1);
        for (const auto& p: primes) {
            heap.emplace(p);
        }
        for (int i = 0; i < n; ++i) {
            ugly_number = heap.top();
            heap.pop();
            int j = 0;
            for (; j < primes.size(); ++j) {
                if (ugly_number % primes[j] == 0) {
                    for (int k = 0; k <= j; ++k) {
                        // worst time:  O(klogk)
                        // worst space: O(k^2)
                        heap.emplace(ugly_number * primes[k]);
                    }
                    break;
                }
            }
        }
    
        return ugly_number; 
    }
};

// Time:  O(n * k)
// Space: O(n + k)
// Hash solution. (804ms)
class Solution4 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        unordered_set<int> ugly_set{1};
        vector<int> uglies(n), idx(primes.size());
        uglies[0] = 1;

        for (int k = 0; k < primes.size(); ++k) {
            heap.emplace(primes[k], k);
            ugly_set.emplace(primes[k]);
        }

        for (int i = 1; i < n; ++i) {
            int k;
            tie(uglies[i], k) = heap.top();
            heap.pop();
            while (ugly_set.count(primes[k] * uglies[idx[k]])) {
                ++idx[k];
            }
            heap.emplace(primes[k] * uglies[idx[k]], k);
            ugly_set.emplace(primes[k] * uglies[idx[k]]);
        }
    
        return uglies[n - 1]; 
    }
};

// Time:  O(n * logk) ~ O(n * klogk)
// Space: O(n + k)
// Heap solution. (1184ms)
class Solution5 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> uglies(n), idx(primes.size());
        uglies[0] = 1;

        for (int k = 0; k < primes.size(); ++k) {
            heap.emplace(primes[k], k);
        }

        for (int i = 1; i < n; ++i) {
            int k;
            tie(uglies[i], k) = heap.top();

            while (heap.top().first == uglies[i]) {  // worst time: O(klogk)
                tie(uglies[i], k) = heap.top();
                heap.pop();
                heap.emplace(primes[k] * uglies[++idx[k]], k);
            }
        }
    
        return uglies[n - 1]; 
    }
};
