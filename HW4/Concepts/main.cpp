#include <iostream>
#include <concepts>

template <typename T>
concept IntegralOrFloating = std::is_integral_v<T> || std::is_floating_point_v<T>;

template<IntegralOrFloating T, IntegralOrFloating U>
std::string concat(const T& t1, const U& t2)
{
    return std::to_string(t1) + std::to_string(t2);
}
