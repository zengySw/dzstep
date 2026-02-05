#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int choice;
    while (true) {
        cout << "1 - Задание 1\n";
        cout << "2 - Задание 2\n";
        cout << "3 - Задание 3\n";
        cout << "4 - Задание 4\n";
        cout << "0 - Выход\n";
        cin >> choice;

        if (choice == 0) {
            cout << "Выход\n";
            break;
        }

        if (choice == 1) {
            int arr[10];
            for (int i = 0; i < 10; i++) {
                arr[i] = 10 + rand() % 10;
            }
            int a1[5], a2[5];
            for (int i = 0; i < 5; i++) {
                a1[i] = arr[i];
                a2[i] = arr[i + 5];
            }
            cout << "a1: ";
            for (int i = 0; i < 5; i++) cout << a1[i] << " ";
            cout << "\na2: ";
            for (int i = 0; i < 5; i++) cout << a2[i] << " ";
            cout << "\n";
        }

        if (choice == 2) {
            int x[10], y[10], z[10];
            for (int i = 0; i < 10; i++) {
                x[i] = 10 + rand() % 10;
                y[i] = 10 + rand() % 10;
                z[i] = x[i] + y[i];
                cout << x[i] << " + " << y[i] << " = " << z[i] << "\n";
            }
        }

        if (choice == 3) {
            double arr[7];
            double sum = 0;
            for (int i = 0; i < 7; i++) {
                cout << "Введите расход за день " << i+1 << ": ";
                cin >> arr[i];
                sum += arr[i];
            }
            double avg = sum / 7;
            cout << "Сумма: " << sum << "\n";
            cout << "Среднее: " << avg << "\n";
            cout << "Дни с расходом > 100:\n";
            int cnt = 0;
            for (int i = 0; i < 7; i++) {
                if (arr[i] > 100) {
                    cout << "День " << i+1 << " : " << arr[i] << "\n";
                    cnt++;
                }
            }
            cout << "Кол-во: " << cnt << "\n";
        }

        if (choice == 4) {
            double deposit;
            cout << "Введите депозит (EUR): ";
            cin >> deposit;
            double rate[12], percent[12];
            for (int i = 0; i < 12; i++) {
                cout << "Курс (EUR->USD) месяц " << i+1 << ": ";
                cin >> rate[i];
                cout << "Процент месяц " << i+1 << ": ";
                cin >> percent[i];
            }
            int m;
            cout << "Введите номер месяца: ";
            cin >> m;
            m--;
            double interest = deposit * (percent[m] / 100.0);
            double totalEUR = deposit + interest;
            double totalUSD = totalEUR * rate[m];
            cout << "Общая сумма в USD: " << totalUSD << "\n";
            if (totalUSD >= 500) {
                cout << "Можно снять: " << totalUSD * 0.5 << "\n";
            } else {
                cout << "Сумма меньше 500, снимать нельзя\n";
            }
        }
    }
    return 0;
}
