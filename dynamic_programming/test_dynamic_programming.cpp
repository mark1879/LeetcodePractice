#include <iostream>
#include "max_profit.hpp"
#include "max_profit2.hpp"
#include "max_profit3.hpp"
#include "max_profit5.hpp"

int main() 
{
    std::cout << "<<<<<< test_dynamic_programming..." << std::endl;

    MaxProfit::Test();
    MaxProfit2::Test();
    MaxProfit3::Test();
    MaxProfit5::Test();

    std::cout << "test done!" << std::endl << std::endl;

    return 0;
}