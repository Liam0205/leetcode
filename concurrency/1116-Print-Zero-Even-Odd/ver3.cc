class ZeroEvenOdd {
 private:
  const int n;
  std::queue<int> q;

  mutable std::mutex mtx;
  mutable std::condition_variable cv;

  template <typename UnaryPred>
  void print_element_in_queue(std::function<void(int)> printer,
                                             UnaryPred pred) {
    auto cond = [this, &pred]() { return q.empty() or pred(q.front()); };
    std::unique_lock<std::mutex> lk(mtx);
    while (true) {
      cv.wait(lk, cond);
      if (q.empty()) break;
      printer(q.front());
      q.pop();
      cv.notify_all();
    }
  }

 public:
  ZeroEvenOdd(int n_) : n(n_) {
    for (int i = 0; i != n; ++i) {
      q.push(0);
      q.push(i + 1);
    }
  }

  // printer(x) outputs "x", where x is an integer.
  void zero(std::function<void(int)> printer) {
    auto pred = [](int i) { return i == 0; };
    print_element_in_queue(printer, pred);
  }

  void even(std::function<void(int)> printer) {
    auto pred = [](int i) { return i != 0 and i % 2 == 0; };
    print_element_in_queue(printer, pred);
  }

  void odd(std::function<void(int)> printer) {
    auto pred = [](int i) { return i % 2 == 1; };
    print_element_in_queue(printer, pred);
  }
};
