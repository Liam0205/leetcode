#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string toGoatLatin(const std::string& S) {
    std::vector<std::string> tokens;
    split(S, tokens);
    const size_t sz = tokens.size();
    for (size_t i = 0; i != sz; ++i) {
      std::string word = tokens[i];
      if (vowels.find(word[0]) != vowels.end()) {
        tokens[i] = word + "ma" + std::string(i + 1, 'a');
      } else {
        tokens[i] = word.substr(1) + word[0] + "ma" + std::string(i + 1, 'a');
      }
    }
    return std::accumulate(tokens.begin(), tokens.end(), std::string(),
        [](const std::string& sub, const std::string& cur) {
            return sub.empty() ? cur : sub + " " + cur;
        });
  }

 private:
  const std::set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  void split(const std::string& s, std::vector<std::string>& sv, const char* delim = " ") {
    sv.clear();
    char* buffer = new char[s.size() + 1];
    buffer[s.size()] = '\0';
    std::copy(s.begin(), s.end(), buffer);
    char* p = std::strtok(buffer, delim);
    do {
      sv.push_back(p);
    } while ((p = std::strtok(NULL, delim)));
    delete[] buffer;
    return;
  }
};

