// Used for testing, do not use it as an example
#include <iostream>
#include "qpp.h"
#include "experimental/experimental.h"

using namespace qpp;

int main()
{
    std::cout << "Testing...\n";
    PRINTLN("Testing debug messages");
    ERRORLN("Testing debug error messages");

    std::cout << disp(st.plus(1)) << "\n\n";
    std::cout << disp(st.zero(1)) << "\n\n";
}
