// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// recursion.cpp
void cpp_A();
extern "C" SEXP _testcpp11unwind_cpp_A() {
  BEGIN_CPP11
    cpp_A();
    return R_NilValue;
  END_CPP11
}
// recursion.cpp
void cpp_B();
extern "C" SEXP _testcpp11unwind_cpp_B() {
  BEGIN_CPP11
    cpp_B();
    return R_NilValue;
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_testcpp11unwind_cpp_A", (DL_FUNC) &_testcpp11unwind_cpp_A, 0},
    {"_testcpp11unwind_cpp_B", (DL_FUNC) &_testcpp11unwind_cpp_B, 0},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_testcpp11unwind(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
