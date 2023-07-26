
<!-- README.md is generated from README.Rmd. Please edit that file -->

# testcpp11unwind

``` r
# Destructor is run
testcpp11unwind:::call_A()
#> Error: oh no!
#> hello from the destructor!

# Destructor is NOT run
testcpp11unwind:::call_B()
#> Error: oh no!
```

Note that `cpp_A()` and `cpp_B()` on their own are seemingly innocuous
code that a developer is likely to write without thinking twice about
it.

The destructor of `a` doesn’t run in the `cpp_B()` case because:

- `call_B()` sets up a try/catch through the entry macros
- `fn()` calls `unwind_protect()` and sets
  `should_unwind_protect = FALSE`
- `R_UnwindProtect()` is used to call `call_A()`, and a `setjmp()` is
  used to be able to recover from `longjmp()`s
- `call_A()` sets up a try/catch through the entry macros
- `cpp_A()` is called
- `a` is created
- `stop()` calls `unwind_protect()`, but `should_unwind_protect = FALSE`
  so it does NOT use `R_UnwindProtect()` or `setjmp()`
- `stop()` ends up calling `Rf_error()`, causing a `longjmp()`
- Because `should_unwind_protect = FALSE`, the `longjmp()` is not caught
  in `stop()`. Instead we jump alllll the way back to where `fn()`
  called `unwind_protect()` and `R_UnwindProtect()`. This skips over the
  `cpp_A()` frame where `a` should have been destructed on the way out.
  VERY BAD!
