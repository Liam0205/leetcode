class Foo {
 private:
  mutable std::mutex cv_mtx;
  mutable std::condition_variable cv;
  mutable uint32_t condition = 0;

 public:
  void first(function<void()> printFirst) {
    std::unique_lock<std::mutex> lk(cv_mtx);
    cv.wait(lk, [this]() { return condition == 0; });
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    ++condition;
    lk.unlock();
    cv.notify_all();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(cv_mtx);
    cv.wait(lk, [this]() { return condition == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    ++condition;
    lk.unlock();
    cv.notify_all();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lk(cv_mtx);
    cv.wait(lk, [this]() { return condition == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    ++condition;
    lk.unlock();
    cv.notify_all();
  }
};
