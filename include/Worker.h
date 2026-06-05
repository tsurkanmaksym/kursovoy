#pragma once
#include "Person.h"

class Worker : public Person {
protected:
    std::string factory;
    std::string position;
    double      salary;

public:
    Worker();
    Worker(const std::string& fullName, int height, double weight,
           const std::string& gender, const std::string& country,
           const std::string& email,
           const std::string& factory, const std::string& position,
           double salary);
    Worker(const Worker& other);
    virtual ~Worker() = default;

    std::string getFactory()  const { return factory;  }
    std::string getPosition() const { return position; }
    double      getSalary()   const { return salary;   }

    void setFactory (const std::string& v) { factory  = v; }
    void setPosition(const std::string& v) { position = v; }
    void setSalary  (double v)             { salary   = v; }

    void increaseSalary();
    void changePosition(const std::string& newPosition) { position = newPosition; }

    std::string to_string() const override;
    void        print()     const override { std::cout << to_string(); }
    std::string type()      const override { return "Worker"; }

    friend std::ostream& operator<<(std::ostream& os, const Worker& w);
};
