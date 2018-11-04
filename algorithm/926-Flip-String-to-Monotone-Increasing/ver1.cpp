#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
      int len = S.length();
      vector<int> 
        l(len + 1),  // 表示將當前位置及之前的元素全部變為 0 需要的操作數;
        r(len + 1);  // ................之後.............. 1 ............;
      l[0] = S[0] - '0';
      r[len - 1] = '1' - S[len - 1];
      for (int i=1; i!=len; ++i) {
        l[i] = l[i - 1] + S[i] - '0';
      }

      for (int i=len - 2; i>=0; --i) {
        r[i] = r[i + 1] + '1' - S[i];
      }

      int ans = r[0];
      for (int i=0; i<=len; ++i) {
        // 尋找最優方案的過程是尋找一個點使得將它之前元素全部變為 0 , 
        // 之後元素全部變為 1 所執行的操作總數最小
        ans = min(ans, l[i -1 ] + r[i]); 
      }
      
      return ans;
    }
};
