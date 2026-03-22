#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <fstream>
#include <semaphore>

using namespace std;

// ===================== 1 =====================

class Parking {
private:
    int freePlaces;
    mutex mtx;
    condition_variable cv;

public:
    Parking(int places) : freePlaces(places) {}

    void parkCar(const string& carName, const string& plate) {
        {
            unique_lock<mutex> lock(mtx);
            cout << carName << " (" << plate << ") подъехала\n";

            while (freePlaces == 0) {
                cout << carName << " ждет...\n";
                cv.wait(lock);
            }

            freePlaces--;
            cout << carName << " припарковалась. Свободно: " << freePlaces << "\n";
        }

        this_thread::sleep_for(chrono::seconds(1));

        {
            unique_lock<mutex> lock(mtx);
            freePlaces++;
            cout << carName << " уехала. Свободно: " << freePlaces << "\n";
        }

        cv.notify_one();
    }
};

void task1() {
    Parking parking(3);
    vector<thread> cars;

    vector<pair<string, string>> carData = {
        {"BMW", "AA1111BB"},
        {"Audi", "BB2222CC"},
        {"Toyota", "CC3333DD"},
        {"Mercedes", "DD4444EE"},
        {"Honda", "EE5555FF"},
        {"Ford", "FF6666GG"}
    };

    for (auto& car : carData) {
        cars.emplace_back([&parking, car]() {
            parking.parkCar(car.first, car.second);
            });
    }

    for (auto& t : cars) t.join();
}

// ===================== 2 =====================

counting_semaphore<2> fileSemaphore(2);
mutex fileMutex;

void writeToFile(int id) {
    cout << "Поток " << id << " старт\n";

    fileSemaphore.acquire();

    {
        lock_guard<mutex> lock(fileMutex);
        ofstream file("log.txt", ios::app);
        file << "Поток " << id << " записал данные\n";
    }

    this_thread::sleep_for(chrono::milliseconds(300));

    fileSemaphore.release();
}

void task2() {
    ofstream clear("log.txt", ios::trunc);
    clear.close();

    vector<thread> threads;

    for (int i = 1; i <= 6; i++) {
        threads.emplace_back(writeToFile, i);
    }

    for (auto& t : threads) t.join();

    cout << "Готово, смотрите log.txt\n";
}

// ===================== 3 =====================

int dataArr[20] = { 0 };
counting_semaphore<2> dataSemaphore(2);
mutex dataMutex;

bool isFull() {
    for (int i = 0; i < 20; i++)
        if (dataArr[i] == 0) return false;
    return true;
}

void fillArray(int id) {
    while (true) {
        dataSemaphore.acquire();

        {
            lock_guard<mutex> lock(dataMutex);

            if (isFull()) {
                dataSemaphore.release();
                return;
            }

            for (int i = 0; i < 20; i++) {
                if (dataArr[i] == 0) {
                    dataArr[i] = id;
                    cout << "Поток " << id << " -> индекс " << i << "\n";
                    break;
                }
            }
        }

        dataSemaphore.release();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void task3() {
    vector<thread> threads;

    for (int i = 1; i <= 5; i++) {
        threads.emplace_back(fillArray, i);
    }

    for (auto& t : threads) t.join();

    cout << "\nМассив:\n";
    for (int i = 0; i < 20; i++) {
        cout << dataArr[i] << " ";
    }
    cout << "\n";
}

// ==========================================

int main() {
    setlocale(LC_ALL, "ru");

    int choice;

    cout << "Выберите задание:\n";
    cout << "1 - Парковка\n";
    cout << "2 - Запись в файл\n";
    cout << "3 - Массив\n";
    cout << ">> ";

    cin >> choice;

    switch (choice) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        cout << "неправильно\n";
    }

    return 0;
}