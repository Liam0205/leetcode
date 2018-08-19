class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::vector<std::string> res;
        res.reserve(words.size());
        for (const auto word : words) {
            auto c = std::tolower(word[0]);
            for (const auto& row : rows) {
                if (row.find(c) != row.end()) {
                    bool flag = true;
                    for (auto c : word) {
                        c = std::tolower(c);
                        if (row.find(c) == row.end()) {
                            flag = false;
                        }
                    }
                    if (flag) {
                        res.push_back(word);
                    }
                    break;
                }
            }
        }
        return res;
    }

private:
    const std::vector<std::unordered_set<char>> rows = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}, {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}, {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};
};
