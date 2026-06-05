#pragma once
#include <string>
#include <iostream>

class Object {
    std::string name;
    int         minExperience;
    int         minGrade;

public:
    Object();
    Object(const std::string& name, int minExperience, int minGrade);
    Object(const Object& other);

    std::string getName()          const { return name;          }
    int         getMinExperience() const { return minExperience; }
    int         getMinGrade()      const { return minGrade;      }

    void setName         (const std::string& v) { name          = v; }
    void setMinExperience(int v)                 { minExperience = v; }
    void setMinGrade     (int v)                 { minGrade      = v; }

    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& os, const Object& o);
};

#include "Person.h"

class Electrician : public Person {
    int     experience;
    int     grade;
    Object* currentObject;

public:
    Electrician();
    Electrician(const std::string& fullName, int height, double weight,
                const std::string& gender, const std::string& country,
                const std::string& email,
                int experience, int grade, Object* obj = nullptr);
    Electrician(const Electrician& other);
    ~Electrician() override = default;

    int     getExperience()    const { return experience;    }
    int     getGrade()         const { return grade;         }
    Object* getCurrentObject() const { return currentObject; }

    void setExperience   (int v)      { experience     = v; }
    void setGrade        (int v)      { grade          = v; }
    void setCurrentObject(Object* o)  { currentObject  = o; }

    bool canWorkOnObject() const;
    bool canWorkOnObject(const Object& obj) const;
    bool changeObject(Object* newObj);

    std::string to_string() const override;
    void        print()     const override { std::cout << to_string(); }
    std::string type()      const override { return "Electrician"; }

    friend std::ostream& operator<<(std::ostream& os, const Electrician& e);
};
