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
    for (const auto& email : emails) {
      std::string temp;
      size_t i, sz = email.size();
      bool valid = true;
      for (i = 0; i != sz and email[i] != '@'; ++i) {
        if (valid) {
          const char c = email[i];
          if (c == '.') {
            // ignored
          } else if (c == '+') {
            valid = false;
            i = email.find_first_of('@', i);
            break;
          } else {
            temp += c;
          }
        }
      }
      uniq_emails.insert(temp + email.substr(i));
    }
    return uniq_emails.size();
  }
};

