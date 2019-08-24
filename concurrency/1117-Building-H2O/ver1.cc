class H2O {
 private:
  mutable std::mutex mtx;
  mutable std::condition_variable cv;
  mutable size_t counter = 0;

  template <typename UnaryPred>
  void release_one_atom(std::function<void()> releaser, UnaryPred pred) {
    auto cond = [this, &pred]() { return pred(counter); };
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, cond);
    releaser();
    ++counter;
    if (!cond()) { cv.notify_all(); }
  }

 public:
  H2O() {}

  void hydrogen(std::function<void()> releaser) {
    static auto pred = [](size_t c) { return c % 3 != 0; };
    release_one_atom(releaser, pred);
  }

  void oxygen(std::function<void()> releaser) {
    static auto pred = [](size_t c) { return c % 3 == 0; };
    release_one_atom(releaser, pred);
  }
};
