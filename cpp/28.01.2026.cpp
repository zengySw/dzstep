#include <iostream>
#include <mutex>
#include <thread>
#include <fstream>
#include <string>
using namespace std;

mutex mtx;

// vars for files

void logPrint(string fileName, string message, int thread)
{
	lock_guard<mutex> lock(mtx);
	ofstream logFile(fileName, ios::app);
	if (logFile.is_open()) {
		logFile << thread << " " << message << endl;
		logFile.close();
	}
}

void logRestricted(string logFile, string RestrictedFile, string line, int lineNum)
{
	ifstream RestrictedList(RestrictedFile);
	string RestrictedChar;
	while (getline(RestrictedList, RestrictedChar))
	{
		size_t pos = 0;
		while ((pos = line.find(RestrictedChar, pos)) != string::npos) {
			lock_guard<mutex> lock(mtx);
			ofstream log(logFile, ios::app);
			if (log.is_open()) {
				log << RestrictedChar << " (" << lineNum << " | " << pos + 1 << ")" << endl;
			}
			pos++;
		}
	}
}

int main() {
	ofstream logFile("log.txt");
	logFile.close();
	const int thCount = 5;
	thread threads[thCount];
	cin.ignore();
	for (int i = 0; i < thCount; i++) {
		string log;
		cout << "Enter log message: ";
		getline(cin, log);
		threads[i] = thread(logPrint, "log.txt", log, i + 1);
	}
	for (int i = 0; i < thCount; i++) {
		threads[i].join();
	}
	ifstream readFile("log.txt");
	if (readFile.is_open()) {
		string line;
		while (getline(readFile, line)) {
			cout << line << endl;
		}
		readFile.close();
	}

	
}
