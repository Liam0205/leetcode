class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& vec : A) {
            std::reverse(vec.begin(), vec.end());
            for (auto& i : vec) {
                i ^= 1;
            }
        }
        return A;
    }
};
