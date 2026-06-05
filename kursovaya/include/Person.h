#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Person {
protected:
    std::string fullName;
    int         height;
    double      weight;
    std::string gender;
    std::string country;
    std::string email;

public:
    Person();
    Person(const std::string& fullName, int height, double weight,
           const std::string& gender, const std::string& country,
           const std::string& email);
    Person(const Person& other);
    virtual ~Person() = default;

    std::string getFullName() const { return fullName; }
    int         getHeight()   const { return height;   }
    double      getWeight()   const { return weight;   }
    std::string getGender()   const { return gender;   }
    std::string getCountry()  const { return country;  }
    std::string getEmail()    const { return email;    }

    void setFullName(const std::string& v) { fullName = v; }
    void setHeight  (int v)                { height   = v; }
    void setWeight  (double v)             { weight   = v; }
    void setGender  (const std::string& v) { gender   = v; }
    void setCountry (const std::string& v) { country  = v; }
    void setEmail   (const std::string& v) { email    = v; }

    bool isTallerThan200() const { return height > 200; }
    bool livesInUkraine()  const { return country == "Україна" || country == "Ukraine"; }

    virtual std::string to_string() const;
    virtual void        print()     const { std::cout << to_string(); }
    virtual std::string type()      const { return "Person"; }

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    Person& operator=(const Person& other);
    bool    operator==(const Person& other) const;
};
