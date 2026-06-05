#include "../include/Person.h"

Person::Person()
    : fullName(""), height(0), weight(0.0),
      gender(""), country(""), email("") {}

Person::Person(const std::string& fullName, int height, double weight,
               const std::string& gender, const std::string& country,
               const std::string& email)
    : fullName(fullName), height(height), weight(weight),
      gender(gender), country(country), email(email) {}

Person::Person(const Person& other)
    : fullName(other.fullName), height(other.height), weight(other.weight),
      gender(other.gender), country(other.country), email(other.email) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        fullName = other.fullName;
        height   = other.height;
        weight   = other.weight;
        gender   = other.gender;
        country  = other.country;
        email    = other.email;
    }
    return *this;
}

bool Person::operator==(const Person& other) const {
    return fullName == other.fullName &&
           email    == other.email;
}

std::string Person::to_string() const {
    std::ostringstream oss;
    oss << "[Person]\n"
        << "  ПІБ     : " << fullName << "\n"
        << "  Зріст   : " << height   << " см\n"
        << "  Вага    : " << weight   << " кг\n"
        << "  Стать   : " << gender   << "\n"
        << "  Країна  : " << country  << "\n"
        << "  Email   : " << email    << "\n"
        << "  >200 см : " << (isTallerThan200() ? "так" : "ні") << "\n"
        << "  Україна : " << (livesInUkraine()  ? "так" : "ні") << "\n";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    return os << p.to_string();
}
