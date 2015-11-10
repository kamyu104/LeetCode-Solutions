// Time:  ctor: O(n),
//        lookup: O(1)
// Space: O(n)

class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.emplace_back(0);
        for (const auto& num : nums) {
            accu.emplace_back(accu.back() + num);
        }
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }

private:
    vector<int> accu;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
