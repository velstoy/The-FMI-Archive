#include <iostream>
#include <string>
#include "Pair.hpp"

int main()
{
    Pair<char, int> person('A', 89);

    std::cout << person << std::endl;

    Pair<std::string, int> person2;

    std::cin >> person2;
    std::cout << person2;

    return 0;
}
