// Time:  O(nlogn)
// Space: O(n)

// BST solution. (40ms)
class Solution {
public:
    class BSTreeNode {
    public:
        int val, count;
        BSTreeNode *left, *right;
        BSTreeNode(int val, int count) {
            this->val = val;
            this->count = count;
            this->left = this->right = nullptr;
        }
    };

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());

        BSTreeNode *root = nullptr;

        // Insert into BST and get left count.
        for (int i = nums.size() - 1; i >= 0; --i) {
            BSTreeNode *node = new BSTreeNode(nums[i], 0);
            root = insertNode(root, node);
            res[i] = query(root, nums[i]);
        }

        return res;
    }

    // Insert node into BST.
    BSTreeNode* insertNode(BSTreeNode* root, BSTreeNode* node) {
        if (root == nullptr) {
            return node;
        }
        BSTreeNode* curr = root;
        while (curr) {
            // Insert left if smaller.
            if (node->val < curr->val) {
                ++curr->count; // Increase the number of left children.
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = node;
                    break;
                }
            } else {  // Insert right if larger or equal.
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = node;
                    break;
                }
            }
        }
        return root;
    }

    // Query the smaller count of the value.
    int query(BSTreeNode* root, int val) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        BSTreeNode* curr = root;
        while (curr) {
            // Insert left.
            if (val < curr->val) {
                curr = curr->left;
            } else if (val > curr->val) {
                count += 1 + curr->count; // Count the number of the smaller nodes.
                curr = curr->right;
            } else {  // Equal.
                return count + curr->count;
            }
        }
        return 0;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// BIT solution. (56ms)
class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Get the place (position in the ascending order) of each number.
        vector<int> sorted_nums(nums), places(nums.size());
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            places[i] = 
                lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) -
                sorted_nums.begin();
        }
        // Count the smaller elements after the number.
        vector<int> bit(nums.size() + 1), ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] = query(bit, places[i]);
            add(bit, places[i] + 1, 1);
        }
        return ans;
    }

private:
    void add(vector<int>& bit, int i, int val) {
        for (; i < bit.size(); i += lower_bit(i)) {
            bit[i] += val;
        }
    }

    int query(const vector<int>& bit, int i) {
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit[i];
        }
        return sum;
    }

    int lower_bit(int i) {
        return i & -i;
    }
};
