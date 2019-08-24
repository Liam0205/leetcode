class FooBar {
 private:
  const int n;
  mutable bool flag = false;
  mutable std::condition_variable cv;
  mutable std::mutex cv_mtx;

  template <typename UnaryPred>
  void generic_printer(std::function<void()> printer, UnaryPred pred) {
    auto cond = [this, &pred]() { return pred(flag); };
    std::unique_lock<std::mutex> lk(cv_mtx);
    for (int i = 0; i < n; ++i) {
      cv.wait(lk, cond);
      printer();
      flag = !flag;
      cv.notify_one();
    }
  }
 public:
  FooBar(int n_) : n(n_) {}

  void foo(std::function<void()> printFoo) {
    auto pred = [](bool flag) { return !flag; };
    generic_printer(printFoo, pred);
  }

  void bar(std::function<void()> printBar) {
    auto pred = [](bool flag) { return flag; };
    generic_printer(printBar, pred);
  }
};
