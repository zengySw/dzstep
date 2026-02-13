#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
using namespace std;

mutex mx;

void Read(string file)
{
	mx.lock();
	ifstream read(file);
	if (read.is_open() && !file.empty())
	{
		string str;
		while (read >> str) {
			cout << str;
		}
	}
	read.close();
	mx.unlock();
}

void Write(string file, string str)
{
	mx.lock();
	ofstream write(file);
	if (write.is_open() && str != "")
	{
		write << str << '\n';
	}
	write.close();
	mx.unlock();
}

int main()
{
	thread th1(Write, string("FileName.txt"), "hello");
	thread th2(Read, string("FileName.txt"));
	th1.join();
	th2.join();
}
