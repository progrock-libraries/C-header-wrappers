#include <c/float.hpp>          // DBL_DIG
#include <c/math.hpp>           // abs, M_PI
#include <iostream>
#include <iomanip>              // std::setprecision    

using C_str = const char*;

auto type_name( int ) -> C_str      { return "int"; }
auto type_name( double ) -> C_str   { return "double"; }

auto main() -> int
{
    using std::cout, std::endl, std::fixed, std::setprecision;
    
    cout << fixed << setprecision( DBL_DIG )
        << "`M_PI` is a " << type_name( M_PI ) << " of value ~= " << abs( -M_PI )
        << ", and `abs(42)` is an " << type_name( abs( 42 ) ) << "."
        << endl;
}
