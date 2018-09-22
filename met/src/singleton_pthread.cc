#include <pthread.h>
#include <iostream>

template <typename DerivedT>
class Singleton {
 public:
    static DerivedT* GetPointer() {
        pthread_once(&_s_once_flag_, [](){ _s_pointer_ = new DerivedT; });
        return _s_pointer_;
    }
    static DerivedT& GetInstance() {
        return *GetPointer();
    }

 protected:
    Singleton() = default;
    virtual ~Singleton() = default;

 private:
    static DerivedT*      _s_pointer_;
    static pthread_once_t _s_once_flag_;
};

template <typename DerivedT>
DerivedT*      Singleton<DerivedT>::_s_pointer_   = nullptr;
template <typename DerivedT>
pthread_once_t Singleton<DerivedT>::_s_once_flag_ = PTHREAD_ONCE_INIT;

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
