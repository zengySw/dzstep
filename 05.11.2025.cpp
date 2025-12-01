#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CountLinesWords(const string& filename)
{
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Файл не открыть, жизнь не удалась.\n";
        return;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;

    while (getline(fin, line)) {
        lineCount++;

        // считаем слова
        bool insideWord = false;
        for (char c : line) {
            if (!isspace(c)) {
                if (!insideWord) {
                    insideWord = true;
                    wordCount++;
                }
            }
            else {
                insideWord = false;
            }
        }
    }

    fin.close();
    cout << "Строк: " << lineCount << "\nСлов: " << wordCount << "\n";
}

void SaveArrayBinary(const string& filename, int* arr, int size)
{
    ofstream fout(filename, ios::binary);
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }

    fout.write((char*)&size, sizeof(int));
    fout.write((char*)arr, sizeof(int) * size);

    fout.close();
    cout << "Массив сохранён.\n";
}

void LoadArrayBinary(const string& filename, int*& arr, int& size)
{
    ifstream fin(filename, ios::binary);
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    fin.read((char*)&size, sizeof(int));
    arr = new int[size];
    fin.read((char*)arr, sizeof(int) * size);

    fin.close();
    cout << "Массив загружен.\n";
}

void CopyFileBinary(const string& from, const string& to)
{
    ifstream fin(from, ios::binary);
    if (!fin.is_open()) {
        cout << "Исходный файл не открыть.\n";
        return;
    }

    ofstream fout(to, ios::binary);
    if (!fout.is_open()) {
        cout << "Целевой файл не открыть.\n";
        return;
    }

    fout << fin.rdbuf(); // копирование байтов

    fin.close();
    fout.close();
    cout << "Файл скопирован.\n";
}


int main()
{
	setlocale(LC_ALL, "Russian");
    ofstream fout("data.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Ошибка открытия файла.\n";
        return 1;
    }

    cout << "Вводи строки. Пустая строка завершит ввод.\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        fout << line << endl;
    }

    fout.close();
    cout << "Записано.\n";

    CountLinesWords("data.txt");

    int arr[5] = { 1, 2, 3, 4, 5 };
    SaveArrayBinary("array.bin", arr, 5);

    int* newArr = nullptr;
    int newSize = 0;
    LoadArrayBinary("array.bin", newArr, newSize);

    for (int i = 0; i < newSize; i++)
        cout << newArr[i] << " ";
    cout << endl;

    CopyFileBinary("image.png", "copy_image.png");

    delete[] newArr;

    return 0;
}
