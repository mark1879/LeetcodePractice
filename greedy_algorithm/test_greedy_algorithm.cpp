#include <iostream>
#include "jump.hpp"
#include "jump2.hpp"
#include "max_area.hpp"

int main()
{
    std::cout << "test_greedy_algorithm..." << std::endl;

    Jump::Test();
    Jump2::Test();
    MaxArea::Test();

    std::cout << "test done!" << std::endl << std::endl;

    return 0;
}