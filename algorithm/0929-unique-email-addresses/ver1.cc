static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int numUniqueEmails(const std::vector<std::string>& emails) {
    std::unordered_set<std::string> uniq_emails;
    std::vector<std::string> components, cache;
    for (const auto& email : emails) {
      split(email, components, "@");
      split(components[0], cache, "+");
      cache[0].erase(std::remove(cache[0].begin(), cache[0].end(), '.'), cache[0].end());
      uniq_emails.insert(cache[0] + "@" + components[1]);
    }
    return uniq_emails.size();
  }

 private:
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

