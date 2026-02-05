#include <iostream>
using namespace std;

class Student {
private:
    double grades[10];
    int size;

public:
    Student() {
        size = 10;
        cout << "Enter " << size << " student grades:\n";
        for (int i = 0; i < size; i++) {
            cin >> grades[i];
        }
    }

    void showGrades() const {
        cout << "\nStudent grades:\n";
        for (int i = 0; i < size; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }

    void retakeExam() {
        int index;
        double newGrade;
        cout << "Enter the grade number to retake (1–" << size << "): ";
        cin >> index;

        if (index < 1 || index > size) {
            cout << "Invalid number!\n";
            return;
        }

        cout << "Enter the new grade: ";
        cin >> newGrade;
        grades[index - 1] = newGrade;
        cout << "Grade successfully updated!\n";
    }

    void checkScholarship() const {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += grades[i];
        }
        double avg = sum / size;

        cout << "Average grade: " << avg << endl;

        if (avg >= 10.7)
            cout << "Scholarship granted!\n";
        else
            cout << "No scholarship.\n";
    }
};

class Menu {
private:
    Student student;

public:
    void run() {
        int choice;
        do {
            cout << "\n===== MENU =====\n";
            cout << "1. Show grades\n";
            cout << "2. Retake exam\n";
            cout << "3. Check scholarship\n";
            cout << "0. Exit\n";
            cout << "Your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                student.showGrades();
                break;
            case 2:
                student.retakeExam();
                break;
            case 3:
                student.checkScholarship();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid menu option!\n";
                break;
            }
        } while (choice != 0);
    }
};

int main() {
    Menu menu;
    menu.run();
}
