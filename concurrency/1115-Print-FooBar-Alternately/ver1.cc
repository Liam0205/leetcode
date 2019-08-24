class FooBar {
 private:
  const int n;
  mutable bool flag = false;
  mutable std::condition_variable cv;
  mutable std::mutex cv_mtx;

 public:
  FooBar(int n_) : n(n_) {}

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; ++i) {
      std::unique_lock<std::mutex> lk(cv_mtx);
      cv.wait(lk, [this]() { return !flag; });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      flag = true;
      cv.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; ++i) {
      std::unique_lock<std::mutex> lk(cv_mtx);
      cv.wait(lk, [this]() { return flag; });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      flag = false;
      cv.notify_one();
    }
  }
};
