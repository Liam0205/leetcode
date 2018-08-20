class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        recursive_search(n, n, "", &res);
        return res;
    }

private:
    void recursive_search(int left, int right, std::string generated, std::vector<std::string>* res) {
        if (left == 0 and right == 0) {
            res->push_back(generated);
        } else {
            if (right > 0 and left < right) {
                recursive_search(left, right - 1, generated + ")", res);
            }
            if (left > 0) {
                recursive_search(left - 1, right, generated + "(", res);
            }
        }
    }
};
