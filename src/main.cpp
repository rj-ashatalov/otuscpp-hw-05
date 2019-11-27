#include <iostream>
#include "print_ip.h"

int main(int, char const *[])
{
    //todo
    char charIP = -1;
    std::cout<<toString(charIP)<<std::endl;

    int intIP = 1234;
    std::cout<<toString(intIP)<<std::endl;

    std::cout<<toString(std::string{"192.168.1.1"})<<std::endl;

    std::list testList{1, 2, 3, 4};
    std::cout<<toString(testList)<<std::endl;

    std::vector testVector{10, 20, 30, 40};
    std::cout<<toString(testVector)<<std::endl;


    //todo
    return 0;
}