static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
   std::string complexNumberMultiply(const std::string& a, const string& b) {
    std::istringstream isstr_a(a), isstr_b(b);
    int real_a, real_b, image_a, image_b;
    char buff;
    isstr_a >> real_a >> buff >> image_a;
    isstr_b >> real_b >> buff >> image_b;
    std::ostringstream osstr;
    osstr << real_a * real_b - image_a * image_b << '+' << real_a * image_b + image_a * real_b << 'i';
    return osstr.str();
  }
};

