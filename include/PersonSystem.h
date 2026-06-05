#pragma once
#include <vector>
#include <memory>
#include "Person.h"
#include "Worker.h"
#include "Electrician.h"

class PersonSystem {
    std::vector<std::unique_ptr<Person>> people;
    std::vector<Object>                  objects;

public:
    PersonSystem() = default;

    void addPerson(const Person& p);
    void addWorker(const Worker& w);
    void addElectrician(const Electrician& e);

    bool removeByName(const std::string& fullName);
    bool removeByIndex(int idx);

    void printAll()          const;
    void printWorkers()      const;
    void printElectricians() const;

    Person*              findByName (const std::string& name) const;
    int                  findIndex  (const std::string& name) const;
    std::vector<Person*> findByType (const std::string& type) const;

    void    addObject(const Object& obj);
    Object* findObject(const std::string& name);
    void    printObjects() const;

    int  size() const { return static_cast<int>(people.size()); }
    void printElectriciansForObject(const std::string& objName) const;
};
