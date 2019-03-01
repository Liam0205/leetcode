class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::unordered_set<std::string> set;
        for (auto word : words) {
            std::string out;
            for (auto c : word) {
                out += morse_[c - 'a'];
            }
            set.insert(out);
        }
        return set.size();
    }

 private:
    const std::vector<std::string> morse_ = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};
