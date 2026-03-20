#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex fileMutex;

class Student {
private:
    string name;
    int age;
    string university;
    double average;

public:
    Student() { cout << "please use construct with parameters, (string n, int a, string u, double avg)" << endl; }

    Student(string n, int a, string u, double avg) {
        name = n;
        age = a;
        university = u;
        average = avg;
    }

    void input() {
        cout << "Enter full name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter university: ";
        getline(cin, university);

        cout << "Enter average grade: ";
        cin >> average;
        cin.ignore();
    }

    void writeToFile(const string& filename) {
        lock_guard<mutex> lock(fileMutex);

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << name << ";" << age << ";" << university << ";" << average << endl;
        }
        file.close();
    }

    static void readFromFile(const string& filename) {
        ifstream file(filename);
        string line;

        cout << "\nFile contents:\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

void threadWrite(Student s, string filename) {
    s.writeToFile(filename);
}

int main() {

    const string filename = "students.txt";
    int n;

    cout << "How many students do you want to add: ";
    cin >> n;
    cin.ignore();

    vector<thread> threads;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "\nStudent " << i + 1 << endl;
        s.input();

        threads.push_back(thread(threadWrite, s, filename));
    }

    for (auto& t : threads) {
        t.join();
    }

    Student::readFromFile(filename);

    return 0;
}
