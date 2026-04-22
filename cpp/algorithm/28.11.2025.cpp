#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Student {
private:
    std::string name;
    int age;

public:
    Student(std::string n, int a) : name(n), age(a) {}

    std::string getName() const {
        return name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "Name: " << s.name << ", Age: " << s.age;
        return os;
    }
};

void findByName(const std::list<Student>& students, const std::string& name) {
    for (const auto& s : students) {
        if (s.getName() == name) {
            std::cout << "Found: " << s << std::endl;
            return;
        }
    }
    std::cout << "Student not found." << std::endl;
}

int main() {
    std::list<Student> students;

    students.push_back(Student("John", 20));
    students.push_back(Student("Alice", 22));
    students.push_back(Student("Bob", 19));
    students.push_back(Student("Eve", 21));
    students.push_back(Student("Charlie", 20));

    for (const auto& s : students) {
        std::cout << s << std::endl;
    }

    findByName(students, "Alice");

    std::string toRemove = "Bob";
    students.remove_if([&toRemove](const Student& s) {
        return s.getName() == toRemove;
    });

    for (const auto& s : students) {
        std::cout << s << std::endl;
    }

    return 0;
}