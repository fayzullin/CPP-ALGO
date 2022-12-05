#include <iostream>
#include <string>
#include <ranges>
#include <vector>

namespace rng = std::ranges;
namespace view = rng::views;

template<typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target) {
    for (auto iter = begin; iter != end; ++iter, ++target) {
        *target = *iter;
    }
}

struct Person {
public:
    std::string FirstName;
    std::string LastName;

    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};

using PersonWithAge = std::pair<Person, size_t>;

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << person.FirstName << " " << person.LastName;
    return os;
}

std::vector<PersonWithAge> generatePeople() {
    return {
            {{"Han",  "Solo"},      15},
            {{"Ben",  "Kenobi"},    14},
            {{"Luke", "Skywalker"}, 11},
            {{"Leia", "Organa"},    66}
    };
}

void printFullName(const std::vector<PersonWithAge>& peopleWithAges, size_t limit)
{
    auto extractFullName = [](const PersonWithAge &personWithAge) { return personWithAge.first; };
    auto fullNames = peopleWithAges | view::transform(extractFullName) | view::take(limit);

    std::vector<Person> people{limit};
    myCopy(fullNames.begin(), fullNames.end(), people.begin());

    for (const auto &person: people) {
        std::cout << person << "\n";
    }
}

void printLastName(const std::vector<PersonWithAge>& peopleWithAges, size_t limit)
{
    auto extractFullName = [](const PersonWithAge &personWithAge) { return personWithAge.first; };
    auto extractLastName = [](const Person& person) { return person.LastName; };
    auto lastNames = peopleWithAges | view::transform(extractFullName) | view::take(limit) | view::transform(extractLastName);

    for (const auto &lastName: lastNames) {
        std::cout << lastName << "\n";
    }
}

int main() {
    const size_t NAMES_LIMIT = 3;

    std::vector<PersonWithAge> peopleWithAges = generatePeople();

    std::cout << "FULL NAMES\n";
    printFullName(peopleWithAges, NAMES_LIMIT);
    std::cout << "\nLAST NAMES\n";
    printLastName(peopleWithAges, NAMES_LIMIT);

    return 0;
}
