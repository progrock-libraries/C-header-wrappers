# C header wrappers for C++

Wraps C++ 17's 26 pairs of `<cFOO>` and `<FOO.h>` headers via a single `<c/FOO.hpp>` header for each pair.

---
This documentation refers to e.g. `<c/math.hpp>` for readability.

You *can* install the library so that you get that simple path, and I (the author) prefer that for my own code. But the full path with a simple direct copying of the library sources to your include directory, is `<progrock/c/math.hpp>`. The full `progrock` path avoids a possible conflict with a more practical future standard library, however infinitesimal that risk is.

Exceptions from full pair inclusion:

* `<c/setjmp.hpp>` and `<c/signal.hpp>`<br/>
… bring in C functionality that generally Does Not Work Correctly&trade; in C++. One would generally not even want a third party header that includes these, to compile successfully by default. These wrappers therefore yield full stop compile errors on inclusion unless respectively `REALLY_WANT_SETJMP` and `REALLY_WANT_SIGNAL` are defined.
* `<c/stdalign.hpp>`<br/>
… includes `<cstdalign>` but not `<stdalign.h>`. Including `<stdalign.h>` wouldn’t do anything anyway since this is a header that just defines two macros. And at the time of coding up this library `<stdalign.h>` was not provided by Visual C++.
* `<c/tgmath>`<br/>
… includes `<ctgmath>` but not `<tgmath.h>`. As with the previous header `<tgmath.h>` was not provided by Visual C++ at the time of coding this library. And `<tgmath.h>` is anyway just C11 type-generic macros, a C kind of macro magic function overloading that can’t be used in C++.

--- 

Added functionality:

* By default `<c/math.hpp>` provides [»the Posix `<math.h>` constants `M_PI` etc.«](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html)
* For historical reasons `<c/math.hpp>` includes the `<c/stdlib.hpp>` headers. With C++14 and earlier that provided the `<c/stdlib.hpp>` integer argument overloads of `abs` and `div` along with the floating point overloads from `<cmath>`.

You can define `NO_MATH_CONSTANTS_PLEASE` in a build to avoid getting `M_PI` etc. defined.

For example, with C++20 and later you can use [»`std::numbers::pi`«](https://en.cppreference.com/w/cpp/numeric/constants) instead of `M_PI`.

