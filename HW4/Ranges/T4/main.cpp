#include <iostream>
#include <string>
#include <ranges>
#include <vector>
#include <algorithm>

namespace rng = std::ranges;
namespace view = rng::views;

const int STOP_NUMBER = -1;

std::vector<int> pipelineWithFor() {
    std::vector<int> numbers;
    auto input = rng::istream_view<int>(std::cin);
    auto notStopNumber = [](int i) { return i != STOP_NUMBER; };

    for (auto i: input | view::take_while(notStopNumber)) {
        numbers.push_back(i);
    }

    return numbers;
}

std::vector<int> pipelineWithoutFor() {
    std::vector<int> numbers;
    auto input = rng::istream_view<int>(std::cin);
    auto notStopNumber = [](int i) { return i != STOP_NUMBER; };
    auto pushNumber = [&numbers](int i) {numbers.push_back(i);};

    rng::for_each(input | view::take_while(notStopNumber), pushNumber);

    return numbers;
}

void printNumbers(const std::vector<int> &numbers) {
    for (auto i: numbers) {
        std::cout << i << " ";
    }
}

int main() {
    printNumbers(pipelineWithFor());
    std::cout << "\n";

    printNumbers(pipelineWithoutFor());
    std::cout << "\n";

    return 0;
}
