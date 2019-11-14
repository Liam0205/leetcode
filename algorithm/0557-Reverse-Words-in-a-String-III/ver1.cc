class Solution {
 public:
   std::string reverseWords(const std::string& s) {
      std::string res;
      std::string buff;
      std::istringstream iss(s);
      while (std::getline(iss, buff, ' ')) {
        std::reverse(buff.begin(), buff.end());
        res += buff + ' ';
      }
      return res.substr(0, res.size() - 1);
  }
};

