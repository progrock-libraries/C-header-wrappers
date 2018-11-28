# C header wrappers for C++

Wraps C++ 17's 26 pairs of `<cFOO>` and `<FOO.h>` headers via a single `<c/FOO.hpp>` header for each pair.

--- 

Added functionality:

* By default `<c/math.hpp>` provides the Posix `<math.h>` constants [`M_PI` etc.](http://pubs.opengroup.org/onlinepubs/7908799/xsh/math.h.html)
* `<c/math.hpp>` as-if includes `<c/stdlib.hpp>` to provide that headers' overloads of `abs` and `div` along with those from `<cmath>`.

You can define `NO_MATH_CONSTANTS_PLEASE` in a build to avoid getting `M_PI` etc.

---

Exceptions from full pair inclusion:

* `<c/setjmp.hpp>` and `<c/signal.hpp>`<br/>
give `#error` on inclusion unless respectively `REALLY_WANT_SETJMP` and `REALLY_WANT_SIGNAL` is defined.<br/>
Reason: They bring in C functionality that generally Does Not Work Correctly&trade; in C++. One would generally not even want a third party header that includes these, to compile successfully by default.
* `<c/stdalign.hpp>`<br/>
includes `<cstdalign>` but not `<stdalign.h>`.<br/>
Reason: `<stdalign.h>` isn't provided by Visual C++ 2017, and including it wouldn't do anything anyway since this is a header that just defines two macros.
* `<c/tgmath>`<br/>
includes `<ctgmath>` but not `<tgmath.h>`.<br/>
Reason: `<tgmath.h>` isn't provided by Visual C++ 2017, and this is anyway just C11 type-generic macros, a C kind of macro magic function overloading that can't be used in C++. C++ has real function overloading.
