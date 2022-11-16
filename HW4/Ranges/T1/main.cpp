#include <iostream>
#include <ranges>

namespace rng = std::ranges;
namespace view = rng::views;

int main() {
    const int LOWER_BOUND = 10;
    const int UPPER_BOUND = 100;
    auto range = view::iota(LOWER_BOUND, UPPER_BOUND);
    auto square = [](int i) { return i * i; };
    auto non_divisible_by_five = [](int i) { return i % 5 != 0; };
    auto to_string = [](int i) { return std::to_string(i); };
    auto result = range | view::transform(square) | view::filter(non_divisible_by_five) | view::transform(to_string);

    for (auto i : result)
    {
        std::cout << i << ' ';
    }

    return 0;
}
