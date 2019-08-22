#include <iostream>
#include <vector>

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
} ();

class Solution {
 public:
  double findMedianSortedArrays(const std::vector<int>& A, const std::vector<int>& B) {
    if (A.empty()) {
      return findMedianInSortedArray(B);
    } else if (B.empty()) {
      return findMedianInSortedArray(A);
    } else {
      return bsearchWrapper(A, B);
    }
  }

 private:
  inline double findMedianInSortedArray(const std::vector<int>& v) {
    size_t len = v.size();
    if (len % 2 == 0) {
      return static_cast<double>(v[len / 2] + v[len / 2 - 1]) / 2.0;
    } else {
      return v[len / 2];
    }
  }

  inline double bsearchWrapper(const std::vector<int>& A, const std::vector<int>& B) {
    const size_t m = A.size(), n = B.size();
    if (m <= n) {
      return bsearchHelper(A, B);
    } else {
      return bsearchHelper(B, A);
    }
  }

  inline double bsearchHelper(const std::vector<int>& A, const std::vector<int>& B) {
    const size_t m = A.size(), n = B.size();
    size_t left = 0, right = m + 1;
    size_t i, j;
    while (left < right) {
      i = left + (right - left) / 2;
      j = (m + n) / 2 - i;
      if (not(i == m or B[j - 1] < A[i])) {
        left = i + 1;
      } else if (not(i == 0 or A[i - 1] < B[j])) {
        right = i;
      } else {
        break;
      }
    }
    if ((m + n) % 2 == 0) {
      double mx = (i == m) ? B[j] : ((j == n) ? A[i] : std::min(A[i], B[j]));
      double mn = (i == 0) ? B[j - 1] : ((j == 0) ? A[i - 1] : std::max(A[i - 1], B[j - 1]));
      return (mn + mx) / 2.0;
    } else {
      return (i == m) ? B[j] : ((j == n) ? A[i] : std::min(A[i], B[j]));
    }
  }
};

template <typename T>
std::ostream& print_vector(const std::vector<T>& vec, std::ostream& os) {
  for (const T& e : vec) {
    os << e << ' ';
  }
  os << '\n';
  return os;
}

int main() {
  std::vector<int> A = {1, 2, 3, 4, 5};
  std::vector<int> B = {2, 3, 4, 10, 11, 12, 13, 14, 15};
  print_vector(A, std::cout);
  print_vector(B, std::cout);

  std::cout << Solution().findMedianSortedArrays(A, B) << std::endl;

  return 0;
}

