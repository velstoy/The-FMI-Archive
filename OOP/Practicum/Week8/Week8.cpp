#include <iostream>
#include <string>
#include <print>
#include "Optional.hpp"

int main()
{
    Optional<int> bobby(12);

    std::string test = "A";

    bobby.apply([](int& a) {a++;});

    std::println("{}", bobby.getOrDefault(0));

    return 0;
}
