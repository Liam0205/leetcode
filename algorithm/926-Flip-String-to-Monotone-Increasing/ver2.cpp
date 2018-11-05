class Solution {
public:
    int minFlipsMonoIncr(string S) {
      int cnt = 0;
      for (auto i : S) {
        cnt += i - '0'; // counting `1's in s;`
      }

      int l = 0, r = S.length() - cnt;
      int ans = min(cnt, static_cast<int>(S.length() - cnt));
      for (auto ch : S) {
        if ('0' == ch) {
          --r;
        } else {
          ++l;
        }
        ans = min(ans, r + l);
      }
      
      return ans;
    }
};
