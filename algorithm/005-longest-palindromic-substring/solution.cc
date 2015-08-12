class Solution {
public:
    string longestPalindrome(string s) {
      string T = translateString(s);
      int len = T.length();
      int *P = new int[len];
      int C = 0, R = 0;
      for (int i = 1; i < len - 1; ++i) {
        int i_mirror = 2 * C - i; // i_mirror = C - (i - C)
        P[i] = (C + R > i) ? min(C + R - i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
          P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
          C = i;
          R = i + P[i];
        }
      }

      // Find the maximum element in P.
      int maxLen = 0;
      int centerIndex = 0;
      for (int i = 1; i < len-1; i++) {
        if (P[i] > maxLen) {
          maxLen = P[i];
          centerIndex = i;
        }
      }
      delete[] P;

      return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
    string translateString(string s) {
      int len = s.length();
      if (len == 0) return "^$"; // start and end
      string translated = "^";
      for (int i = 0; i != len; ++i)
        translated += "#" + s.substr(i, 1);
      translated += "#$";
      return translated;
    }
};
