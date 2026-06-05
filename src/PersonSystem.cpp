#include "../include/PersonSystem.h"
#include <iostream>
#include <algorithm>

void PersonSystem::addPerson(const Person& p) {
    people.push_back(std::make_unique<Person>(p));
}

void PersonSystem::addWorker(const Worker& w) {
    people.push_back(std::make_unique<Worker>(w));
}

void PersonSystem::addElectrician(const Electrician& e) {
    people.push_back(std::make_unique<Electrician>(e));
}

bool PersonSystem::removeByName(const std::string& fullName) {
    for (auto it = people.begin(); it != people.end(); ++it) {
        if ((*it)->getFullName() == fullName) {
            people.erase(it);
            return true;
        }
    }
    return false;
}

bool PersonSystem::removeByIndex(int idx) {
    if (idx < 0 || idx >= static_cast<int>(people.size())) return false;
    people.erase(people.begin() + idx);
    return true;
}

void PersonSystem::printAll() const {
    if (people.empty()) { std::cout << "  (список порожній)\n"; return; }
    for (const auto& p : people) p->print();
}

void PersonSystem::printWorkers() const {
    bool found = false;
    for (const auto& p : people)
        if (p->type() == "Worker") { p->print(); found = true; }
    if (!found) std::cout << "  (робітників немає)\n";
}

void PersonSystem::printElectricians() const {
    bool found = false;
    for (const auto& p : people)
        if (p->type() == "Electrician") { p->print(); found = true; }
    if (!found) std::cout << "  (електриків немає)\n";
}

Person* PersonSystem::findByName(const std::string& name) const {
    for (const auto& p : people)
        if (p->getFullName() == name) return p.get();
    return nullptr;
}

int PersonSystem::findIndex(const std::string& name) const {
    for (int i = 0; i < static_cast<int>(people.size()); ++i)
        if (people[i]->getFullName() == name) return i;
    return -1;
}

std::vector<Person*> PersonSystem::findByType(const std::string& type) const {
    std::vector<Person*> result;
    for (const auto& p : people)
        if (p->type() == type) result.push_back(p.get());
    return result;
}

void PersonSystem::addObject(const Object& obj) {
    objects.push_back(obj);
}

Object* PersonSystem::findObject(const std::string& name) {
    for (auto& o : objects)
        if (o.getName() == name) return &o;
    return nullptr;
}

void PersonSystem::printObjects() const {
    if (objects.empty()) { std::cout << "  (об'єктів немає)\n"; return; }
    for (const auto& o : objects) std::cout << o;
}

void PersonSystem::printElectriciansForObject(const std::string& objName) const {
    const Object* target = nullptr;
    for (const auto& o : objects)
        if (o.getName() == objName) { target = &o; break; }

    if (!target) { std::cout << "  Об'єкт \"" << objName << "\" не знайдено.\n"; return; }

    std::cout << "Електрики, що можуть працювати на об'єкті \"" << objName << "\":\n";
    bool found = false;
    for (const auto& p : people) {
        if (p->type() == "Electrician") {
            const Electrician* e = static_cast<const Electrician*>(p.get());
            if (e->canWorkOnObject(*target)) {
                std::cout << "  - " << e->getFullName()
                          << " (стаж=" << e->getExperience()
                          << ", розряд=" << e->getGrade() << ")\n";
                found = true;
            }
        }
    }
    if (!found) std::cout << "  (нікого)\n";
}
