// Time:  O(nlogn)
// Space: O(n)

// https://blog.csdn.net/john123741/article/details/76576925
// FWT solution
class Solution {
public:
    int countTriplets(vector<int>& A) {
        static const int k = 3;

        vector<int> B(1 << 16); 
        for (const auto& x : A) {
            ++B[x];
        }

        FWT(&B);
        for(auto& x : B) {
            x = pow(x, k);
        }
        UFWT(&B);

        return B[0];
    }
    
private:
    void FWT(vector<int> *A) {
        for (int d = 1; d < A->size(); d <<= 1) {
            for (int m = d << 1, i = 0; i < A->size(); i += m) {
                for (int j = 0; j < d ; ++j) {  
                    (*A)[i + j] = (*A)[i + j] + (*A)[i + j + d];
                }
            }  
        }
    }
    
    void UFWT(vector<int> *A) {
        for (int d = 1; d < A->size(); d <<= 1) {
            for (int m = d << 1, i = 0; i < A->size(); i += m) {
                for (int j = 0; j < d ; ++j) {  
                    (*A)[i + j] = (*A)[i + j] - (*A)[i + j + d];
                }
            }  
        }
    }
};

// Time:  O(n^3)
// Space: O(n^2)
class Solution2 {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> count;
        for (int i = 0 ;i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                ++count[A[i] & A[j]];
            }
        }
        int result = 0;
        for (int k = 0; k < A.size(); ++k) {
            for (const auto& kvp : count) {
                if ((A[k] & kvp.first) == 0) {
                    result += kvp.second;
                }
            }
        }
        return result;
    }
};
