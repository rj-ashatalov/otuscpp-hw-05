#pragma once
#include <sstream>

template<class T>
std::string toString(const T& src)
{
    std::stringstream output;
    //todo
    return output.str();
}

/*
std::string toString(const IpPool& pool)
{
    std::stringstream output;
    for(const auto& ip : pool)
    {
        std::copy(ip.begin(), std::prev(ip.end()),std::ostream_iterator<int>(output, "."));
        output << ip.back() << std::endl;
    }
    return output.str();
}*/
