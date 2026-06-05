#include "../include/Electrician.h"
#include <sstream>

Object::Object() : name(""), minExperience(0), minGrade(0) {}

Object::Object(const std::string& name, int minExperience, int minGrade)
    : name(name), minExperience(minExperience), minGrade(minGrade) {}

Object::Object(const Object& other)
    : name(other.name), minExperience(other.minExperience), minGrade(other.minGrade) {}

std::string Object::to_string() const {
    std::ostringstream oss;
    oss << "[Object] " << name
        << "  мін.стаж=" << minExperience << " р."
        << "  мін.розряд=" << minGrade << "\n";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Object& o) {
    return os << o.to_string();
}

Electrician::Electrician()
    : Person(), experience(0), grade(0), currentObject(nullptr) {}

Electrician::Electrician(const std::string& fullName, int height, double weight,
                         const std::string& gender, const std::string& country,
                         const std::string& email,
                         int experience, int grade, Object* obj)
    : Person(fullName, height, weight, gender, country, email),
      experience(experience), grade(grade), currentObject(obj) {}

Electrician::Electrician(const Electrician& other)
    : Person(other),
      experience(other.experience), grade(other.grade),
      currentObject(other.currentObject) {}

bool Electrician::canWorkOnObject() const {
    if (!currentObject) return false;
    return canWorkOnObject(*currentObject);
}

bool Electrician::canWorkOnObject(const Object& obj) const {
    return experience >= obj.getMinExperience() &&
           grade      >= obj.getMinGrade();
}

bool Electrician::changeObject(Object* newObj) {
    if (newObj && !canWorkOnObject(*newObj)) return false;
    currentObject = newObj;
    return true;
}

std::string Electrician::to_string() const {
    std::ostringstream oss;
    oss << "[Electrician]\n"
        << "  ПІБ     : " << fullName   << "\n"
        << "  Зріст   : " << height     << " см\n"
        << "  Вага    : " << weight     << " кг\n"
        << "  Стать   : " << gender     << "\n"
        << "  Країна  : " << country    << "\n"
        << "  Email   : " << email      << "\n"
        << "  >200 см : " << (isTallerThan200() ? "так" : "ні") << "\n"
        << "  Україна : " << (livesInUkraine()  ? "так" : "ні") << "\n"
        << "  Стаж    : " << experience << " р.\n"
        << "  Розряд  : " << grade      << "\n"
        << "  Об'єкт  : ";
    if (currentObject)
        oss << currentObject->getName()
            << " (допуск: " << (canWorkOnObject() ? "так" : "ні") << ")";
    else
        oss << "не призначено";
    oss << "\n";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Electrician& e) {
    return os << e.to_string();
}
