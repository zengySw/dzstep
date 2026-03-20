#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printNumbers() {
    for (int i = 1; i <= 100; ++i) {
        cout << i << endl;
        this_thread::sleep_for(chrono::milliseconds(200)); // у меня просто линукс, могу сделать так чтобы и на виндовс была типо Sleep(200)
    }
}

void printLetters() {
    for (char c = 'A'; c <= 'Z'; ++c) {
        cout << c << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // Sleep(500)
    }
}

int main() {
    thread t1(printNumbers);
    thread t2(printLetters);

    t1.join();
    t2.join();

    cout << "Все потоки завершены." << endl;

    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;
    }

    cout << "Сумма чисел от 1 до 100: " << sum << endl;

    return 0;
}