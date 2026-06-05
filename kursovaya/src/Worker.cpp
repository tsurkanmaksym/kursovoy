#include "../include/Worker.h"

Worker::Worker()
    : Person(), factory(""), position(""), salary(0.0) {}

Worker::Worker(const std::string& fullName, int height, double weight,
               const std::string& gender, const std::string& country,
               const std::string& email,
               const std::string& factory, const std::string& position,
               double salary)
    : Person(fullName, height, weight, gender, country, email),
      factory(factory), position(position), salary(salary) {}

Worker::Worker(const Worker& other)
    : Person(other),
      factory(other.factory), position(other.position), salary(other.salary) {}

void Worker::increaseSalary() {
    if      (position == "директор"    || position == "Director")    salary *= 1.30;
    else if (position == "менеджер"    || position == "Manager")     salary *= 1.20;
    else if (position == "інженер"     || position == "Engineer")    salary *= 1.15;
    else if (position == "технік"      || position == "Technician")  salary *= 1.10;
    else                                                              salary *= 1.05;
}

std::string Worker::to_string() const {
    std::ostringstream oss;
    oss << "[Worker]\n"
        << "  ПІБ     : " << fullName << "\n"
        << "  Зріст   : " << height   << " см\n"
        << "  Вага    : " << weight   << " кг\n"
        << "  Стать   : " << gender   << "\n"
        << "  Країна  : " << country  << "\n"
        << "  Email   : " << email    << "\n"
        << "  >200 см : " << (isTallerThan200() ? "так" : "ні") << "\n"
        << "  Україна : " << (livesInUkraine()  ? "так" : "ні") << "\n"
        << "  Завод   : " << factory  << "\n"
        << "  Посада  : " << position << "\n"
        << "  Оклад   : " << salary   << " грн\n";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Worker& w) {
    return os << w.to_string();
}
