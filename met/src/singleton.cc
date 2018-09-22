#include <iostream>
#include <memory>
#include <mutex>

template <typename DerivedT>
class Singleton {
 public:
    static DerivedT* GetPointer() {
        std::call_once(_s_once_flag_, [](){ _s_pointer_.reset(new DerivedT); });
        return _s_pointer_.get();
    }
    static DerivedT& GetInstance() {
        return *GetPointer();
    }

 protected:
    Singleton() = default;
    virtual ~Singleton() = default;

 private:
    static std::unique_ptr<DerivedT> _s_pointer_;
    static std::once_flag            _s_once_flag_;
};

template <typename DerivedT>
std::unique_ptr<DerivedT>  Singleton<DerivedT>::_s_pointer_;
template <typename DerivedT>
std::once_flag             Singleton<DerivedT>::_s_once_flag_;

struct Derived : public Singleton<Derived> {
    Derived() = default;
    int i = 0;
};

int main() {
    std::cout << Singleton<Derived>::GetInstance().i << std::endl;
    Singleton<Derived>::GetPointer()->i = 100;
    std::cout << Singleton<Derived>::GetInstance().i << std::endl;
    return 0;
}
