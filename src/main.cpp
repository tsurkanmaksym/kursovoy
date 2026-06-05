#include <iostream>
#include <string>
#include <limits>
#include "../include/PersonSystem.h"

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static int readInt(const std::string& prompt) {
    int v;
    std::cout << prompt;
    std::cin >> v;
    clearInput();
    return v;
}

static double readDouble(const std::string& prompt) {
    double v;
    std::cout << prompt;
    std::cin >> v;
    clearInput();
    return v;
}

static std::string readLine(const std::string& prompt) {
    std::string v;
    std::cout << prompt;
    std::getline(std::cin, v);
    return v;
}

static Person inputPerson() {
    std::string fn = readLine("  ПІБ: ");
    int         h  = readInt   ("  Зріст (см): ");
    double      w  = readDouble("  Вага (кг): ");
    std::string g  = readLine("  Стать: ");
    std::string c  = readLine("  Країна: ");
    std::string em = readLine("  Email: ");
    return Person(fn, h, w, g, c, em);
}

static Worker inputWorker() {
    Person      base     = inputPerson();
    std::string factory  = readLine("  Завод: ");
    std::string position = readLine("  Посада: ");
    double      salary   = readDouble("  Оклад: ");
    return Worker(base.getFullName(), base.getHeight(), base.getWeight(),
                  base.getGender(), base.getCountry(), base.getEmail(),
                  factory, position, salary);
}

static Electrician inputElectrician(PersonSystem& sys) {
    Person base  = inputPerson();
    int    exp   = readInt("  Стаж (роки): ");
    int    grade = readInt("  Розряд: ");

    Object*     obj    = nullptr;
    std::string choice = readLine("  Призначити об'єкт? (так/ні): ");
    if (choice == "так" || choice == "yes") {
        std::string objName = readLine("  Назва об'єкта: ");
        obj = sys.findObject(objName);
        if (!obj) std::cout << "  Об'єкт не знайдено, буде призначено nullptr.\n";
    }
    return Electrician(base.getFullName(), base.getHeight(), base.getWeight(),
                       base.getGender(), base.getCountry(), base.getEmail(),
                       exp, grade, obj);
}

static Object inputObject() {
    std::string name     = readLine("  Назва об'єкта: ");
    int         minExp   = readInt("  Мін. стаж: ");
    int         minGrade = readInt("  Мін. розряд: ");
    return Object(name, minExp, minGrade);
}

void showMenu() {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║       СИСТЕМА УПРАВЛІННЯ ПЕРСОНАЛОМ  ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  1. Додати Person                    ║\n";
    std::cout << "║  2. Додати  Робітник                 ║\n";
    std::cout << "║  3. Додати  Електрик                 ║\n";
    std::cout << "║  4. Видалити за ім'ям                ║\n";
    std::cout << "║  5. Видалити за індексом             ║\n";
    std::cout << "║  6. Вивести всіх                     ║\n";
    std::cout << "║  7. Вивести лише Робітники           ║\n";
    std::cout << "║  8. Вивести лише Електрики           ║\n";
    std::cout << "║  9. Пошук за ім'ям                   ║\n";
    std::cout << "║ 10. Збільшити оклад робітника        ║\n";
    std::cout << "║ 11. Змінити посаду робітника         ║\n";
    std::cout << "║ 12. Перевірити допуск електрика      ║\n";
    std::cout << "║ 13. Змінити об'єкт електрика         ║\n";
    std::cout << "║ 14. Додати об'єкт (довідник)         ║\n";
    std::cout << "║ 15. Вивести об'єкти                  ║\n";
    std::cout << "║ 16. Електрики для об'єкта            ║\n";
    std::cout << "║  0. Вихід                            ║\n";
    std::cout << "╚══════════════════════════════════════╝\n";
    std::cout << "Оберіть дію: ";
}

int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    PersonSystem sys;

    sys.addObject(Object("Підстанція A", 3, 4));
    sys.addObject(Object("Підстанція B", 5, 5));

    sys.addPerson(Person("Коваль Іван Петрович", 185, 80.0, "чол", "Україна", "koval@mail.ua"));
    sys.addWorker(Worker("Мельник Олег Сергійович", 175, 75.0, "чол", "Україна", "melnyk@mail.ua",
                         "Завод №1", "інженер", 25000.0));
    sys.addWorker(Worker("Шевченко Ганна Василівна", 165, 60.0, "жін", "Польща", "shevch@mail.ua",
                         "Завод №2", "менеджер", 30000.0));

    Object* objA = sys.findObject("Підстанція A");
    sys.addElectrician(Electrician("Бондар Микола Олексійович", 178, 82.0, "чол", "Україна", "bondar@mail.ua",
                                   4, 5, objA));
    sys.addElectrician(Electrician("Литвин Степан Іванович", 170, 77.0, "чол", "Україна", "lytvyn@mail.ua",
                                   2, 3, nullptr));

    int choice = -1;
    while (choice != 0) {
        showMenu();
        std::cin >> choice;
        clearInput();

        switch (choice) {
        case 1: {
            Person p = inputPerson();
            sys.addPerson(p);
            std::cout << "  Додано.\n";
            break;
        }
        case 2: {
            Worker w = inputWorker();
            sys.addWorker(w);
            std::cout << "  Додано.\n";
            break;
        }
        case 3: {
            Electrician e = inputElectrician(sys);
            sys.addElectrician(e);
            std::cout << "  Додано.\n";
            break;
        }
        case 4: {
            std::string name = readLine("  Введіть ПІБ: ");
            std::cout << (sys.removeByName(name) ? "  Видалено.\n" : "  Не знайдено.\n");
            break;
        }
        case 5: {
            int idx = readInt("  Введіть індекс (0-based): ");
            std::cout << (sys.removeByIndex(idx) ? "  Видалено.\n" : "  Невірний індекс.\n");
            break;
        }
        case 6:
            sys.printAll();
            break;
        case 7:
            sys.printWorkers();
            break;
        case 8:
            sys.printElectricians();
            break;
        case 9: {
            std::string name = readLine("  Введіть ПІБ: ");
            Person* p = sys.findByName(name);
            if (p) p->print(); else std::cout << "  Не знайдено.\n";
            break;
        }
        case 10: {
            std::string name    = readLine("  ПІБ робітника: ");
            auto        workers = sys.findByType("Worker");
            bool        found   = false;
            for (auto* p : workers)
                if (p->getFullName() == name) {
                    Worker* w   = static_cast<Worker*>(p);
                    double  old = w->getSalary();
                    w->increaseSalary();
                    std::cout << "  Оклад: " << old << " → " << w->getSalary() << " грн\n";
                    found = true;
                    break;
                }
            if (!found) std::cout << "  Робітника не знайдено.\n";
            break;
        }
        case 11: {
            std::string name    = readLine("  ПІБ робітника: ");
            auto        workers = sys.findByType("Worker");
            bool        found   = false;
            for (auto* p : workers)
                if (p->getFullName() == name) {
                    Worker*     w      = static_cast<Worker*>(p);
                    std::string newPos = readLine("  Нова посада: ");
                    w->changePosition(newPos);
                    std::cout << "  Посаду змінено на \"" << newPos << "\".\n";
                    found = true;
                    break;
                }
            if (!found) std::cout << "  Робітника не знайдено.\n";
            break;
        }
        case 12: {
            std::string name  = readLine("  ПІБ електрика: ");
            auto        elecs = sys.findByType("Electrician");
            bool        found = false;
            for (auto* p : elecs)
                if (p->getFullName() == name) {
                    Electrician* e = static_cast<Electrician*>(p);
                    std::cout << (e->canWorkOnObject() ? "  Допущено.\n" : "  Не допущено.\n");
                    found = true;
                    break;
                }
            if (!found) std::cout << "  Електрика не знайдено.\n";
            break;
        }
        case 13: {
            std::string name  = readLine("  ПІБ електрика: ");
            auto        elecs = sys.findByType("Electrician");
            bool        found = false;
            for (auto* p : elecs)
                if (p->getFullName() == name) {
                    Electrician* e       = static_cast<Electrician*>(p);
                    std::string  objName = readLine("  Нова назва об'єкта (або Enter для скидання): ");
                    Object*      obj     = objName.empty() ? nullptr : sys.findObject(objName);
                    if (e->changeObject(obj))
                        std::cout << "  Об'єкт змінено.\n";
                    else
                        std::cout << "  Електрик не відповідає вимогам об'єкта.\n";
                    found = true;
                    break;
                }
            if (!found) std::cout << "  Електрика не знайдено.\n";
            break;
        }
        case 14: {
            Object o = inputObject();
            sys.addObject(o);
            std::cout << "  Об'єкт додано.\n";
            break;
        }
        case 15:
            sys.printObjects();
            break;
        case 16: {
            std::string objName = readLine("  Назва об'єкта: ");
            sys.printElectriciansForObject(objName);
            break;
        }
        case 0:
            std::cout << "  До побачення!\n";
            break;
        default:
            std::cout << "  Невірний вибір.\n";
        }
    }
    return 0;
}
