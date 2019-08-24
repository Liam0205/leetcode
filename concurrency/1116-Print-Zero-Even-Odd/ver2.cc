class ZeroEvenOdd {
 private:
  const int n;

  mutable bool zero_flag = true;
  mutable std::mutex zero_mtx;
  mutable std::condition_variable zero_cv;

  mutable int i = 1;
  mutable std::mutex oe_mtx;
  mutable std::condition_variable oe_cv;

 public:
  ZeroEvenOdd(int n_) : n(n_) {}

  // printNumber(x) outputs "x", where x is an integer.
  void zero(std::function<void(int)> printNumber) {
    std::unique_lock<std::mutex> lk(zero_mtx);
    while (i <= n) {
      zero_cv.wait(lk, [this]() { return zero_flag; });
      if (i <= n) {
        printNumber(0);
      }
      zero_flag = false;
      oe_cv.notify_all();
    }
  }

  void even(std::function<void(int)> printNumber) {
    std::unique_lock<std::mutex> lk(oe_mtx);
    while (i <= n) {
      oe_cv.wait(lk, [this]() { return !zero_flag and (i % 2 == 0); });
      if (i <= n) {
        printNumber(i);
        zero_flag = true;
        ++i;
      }
      zero_cv.notify_one();
    }
  }

  void odd(std::function<void(int)> printNumber) {
    std::unique_lock<std::mutex> lk(oe_mtx);
    while (i <= n) {
      oe_cv.wait(lk, [this]() { return !zero_flag and (i % 2 == 1); });
      if (i <= n) {
        printNumber(i);
        zero_flag = true;
        ++i;
      }
      zero_cv.notify_one();
    }
  }
};
