class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        std::vector<std::string> res;
        std::unordered_multiset<std::string> recA, recB;
        recordWords(A, &recA);
        recordWords(B, &recB);
        for (auto word : recA) {
            if (recA.count(word) == 1 and recB.count(word) == 0) {
                res.push_back(word);
            }
        }
        for (auto word : recB) {
            if (recB.count(word) == 1 and recA.count(word) == 0) {
                res.push_back(word);
            }
        }
        return res;
    }

private:
    void recordWords(const string& A, std::unordered_multiset<std::string>* record) {
        istringstream isstr(A);
        std::string buff;
        while (std::getline(isstr, buff, ' ')) {
            record->insert(buff);
        }
    }
};
