#include <iostream>
#include <string>
#include <ranges>
#include <vector>

namespace rng = std::ranges;
namespace view = rng::views;

template <typename InputIter>
auto sum(InputIter begin, InputIter end)
{
    auto sum{ *begin };
    for (auto iter = ++begin; iter != end; ++iter)
    {
        sum += *iter;
    }
    return sum;
}

struct Person
{
public:
    std::string FirstName;
    std::string LastName;
};

std::vector<std::pair<Person, size_t>> generatePeople()
{
    std::vector<std::pair<Person, size_t>> result = {
            { {"Han", "Solo"}, 15},
            { {"Ben", "Kenobi"}, 14},
            { {"Luke", "Skywalker"}, 11},
            { {"Leia", "Organa"}, 66}
    };
    return result;
}

int main() {
    const size_t LOWER_AGE_BOUND = 12;
    const size_t UPPER_AGE_BOUND = 65;

    std::vector<std::pair<Person, size_t>> peopleWithAges = generatePeople();

    auto extractAges = [](const std::pair<Person, size_t>& personWithAge) { return personWithAge.second; };
    auto boundAges = [](size_t age) { return LOWER_AGE_BOUND <= age && age <= UPPER_AGE_BOUND; };
    auto boundedAges = peopleWithAges | view::transform(extractAges) | view::filter(boundAges);

    std::cout << static_cast<double>(sum(boundedAges.begin(), boundedAges.end())) / rng::distance(boundedAges);

    return 0;
}
