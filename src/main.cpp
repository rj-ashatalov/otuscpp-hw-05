#include <iostream>
#include "print_ip.h"

int main(int, char const *[])
{
    //todo

    std::list testList{1, 2, 3, 4};
    std::cout<<toString(testList)<<std::endl;

    std::vector testVector{10, 20, 30, 40};
    std::cout<<toString(testVector)<<std::endl;


    //todo
    return 0;
}