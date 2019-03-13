static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

struct Solution {
  struct cell {
    alignas(1) uint8_t value = 0;
    alignas(1) uint8_t psblt = 0;
    std::bitset<10> constraints;
  };
  using status_t = std::array<std::array<cell, 9>, 9>;

  status_t status;

 private:
  inline bool update_constraints(const uint8_t i, const uint8_t j, const uint8_t value) {
    cell& c = status[i][j];
    if (c.constraints[value]) {
      return true;
    } else if (value == c.value) {
      return false;
    } else {
      c.constraints.set(value);
      --(c.psblt);
      if (c.psblt == 1) {
        return implicit_set_value(i, j);
      } else {
        return true;
      }
    }
  }
  inline bool implicit_set_value(const uint8_t i, const uint8_t j) {
    cell& c = status[i][j];
    for (uint8_t v = 1; v < 10; ++v) {
      if (not (c.constraints[v])) {
        return explicit_set_value(i, j, v);
      } else /* lbi */;
    }
    return false;
  }
  inline bool explicit_set_value(const uint8_t i, const uint8_t j, const uint8_t value) {
    cell& c = status[i][j];
    if (value == c.value) {
      return true;
    } else if (c.constraints[value]) {
      return false;
    } else {
      c.value = value;
      c.psblt = 1;
      c.constraints.set();
      c.constraints.reset(value);
      return propagating_constraints(i, j, value);
    }
  }
  inline bool propagating_constraints(const uint8_t i, const uint8_t j, const uint8_t value) {
    for (uint8_t k = 0; k != 9; ++k) {
      if (i != k and !update_constraints(k, j, v)) {
        return false;
      }
      if (j != k and !update_constraints(i, k, v)) {
        return false;
      }
      uint8_t ix = (i / 3) * 3 + k / 3;
      uint8_t jx = (j / 3) * 3 + k % 3;
      if (ix != i and jx != j and !update_constraints(ix, jx, v)) {
        return false;
      }
    }
    return true;
  }
};

