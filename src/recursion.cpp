#include <cpp11.hpp>

class A {
public:
  ~A();
};

A::~A() {
  // We expect that when A is destructed, a message is printed
  Rprintf("hello from the destructor!");
}

[[cpp11::register]]
void cpp_A() {
  // If you just call `call_A()`, which calls `cpp_A()`, then the destructor
  // runs as expected.
  A a{};
  cpp11::stop("oh no!");
}

[[cpp11::register]]
void cpp_B() {
  // If you call `call_B()`, which calls `cpp_B()` here, then the destructor
  // for `a` does NOT run.
  auto fn = cpp11::package("testcpp11unwind")["call_A"];
  fn();
}

