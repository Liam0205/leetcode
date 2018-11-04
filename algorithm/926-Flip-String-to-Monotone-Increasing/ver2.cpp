#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
      int cnt = 0;
      for (auto i : S) {
        cnt += '1' - i; // counting `0's in s;`
      }

      int l = S.length() - cnt, r = cnt;
      int ans = min(cnt, cnt - S.length());
      for (auto ch : S) {
        if ('0' == ch) {
          --r;
        } else {
          ++l;
        }
        ans = min(ans, r + l);
      }
    }
};
