// Time:  O(n)
// Space: O(k)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        Window window1, window2;
        int result = 0, left1 = 0, left2 = 0;
        for (const auto& i : A) {
            window1.add(i);
            while (window1.size() > K) {
                window1.remove(A[left1]);
                ++left1;
            }
            window2.add(i);
            while (window2.size() >= K) {
                window2.remove(A[left2]);
                ++left2;
            }
            result += left2 - left1;
        }
        return result;
    }

private:
    class Window {
    public:
        void add(int x) {
            ++count_[x];
        }
        
        void remove(int x) {
            --count_[x];
            if (count_[x] == 0) {
                count_.erase(x);
            }
        }
        
        size_t size() const {
            return count_.size();
        }
    
    private:
        unordered_map<int, int> count_;
    };
};
