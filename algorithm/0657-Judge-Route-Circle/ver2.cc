static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool judgeCircle(const std::string& moves) {
    size_t lcnt = 0, rcnt = 0, ucnt = 0, dcnt = 0;
    int lr = 0, ud = 0;
    for (const auto& c : moves) {
      switch (c) {
        case 'L':
            ++lr;
            break;
        case 'R':
            --lr;
            break;
        case 'U':
            ++ud;
            break;
        case 'D':
            --ud;
            break;
        default:
            break;
      }
    }
    return lr == 0 and ud == 0;
  }
};

