static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::unordered_set<std::string> set;
        for (const auto& word : words) {
            std::string out;
            for (const auto& c : word) {
                out += morse_[c - 'a'];
            }
            set.insert(out);
        }
        return set.size();
    }

 private:
    const std::vector<std::string> morse_ = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
      "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
      "..-", "...-", ".--", "-..-", "-.--", "--.."};
};

