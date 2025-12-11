#include <iostream>
#include <cstring>
using namespace std;


template <class T>
struct Element
{
	T data;
	Element* next;
};

template<class T>
class List
{
	Element<T>* head;
	Element<T>* tail;
	int count;

public:
	List();
	~List();

	void add(T data);
	void paste(T data, int id);
	void del_head();
	void del(int id);
	void del_all();
	void print();
	int get_count();
	int get_id(T data);
	T* get_item(int id);
};

template <class T>
List<T>::List()
{
	head = tail = NULL;
	count = 0;
}

template <class T>
List<T>::~List()
{
	del_all();
}

template <class T>
int List<T>::get_count()
{
	return count;
}

template<class T>
int List<T>::get_id(T data)
{
	Element<T>* temp = new Element<T>;
	for (size_t i = 0; i < this->count; i++)
	{
		if (temp->data == data) return i;
	}
	return -1;
}

template<class T>
T* List<T>::get_item(int id)
{
	Element<T>* temp = new Element<T>;
	for (size_t i = 0; i < id; i++)
	{
		temp->next = temp->next->next;
	}
	return temp->next;
}

template <class T>
void List<T>::add(T data)
{
	Element<T>* temp = new Element<T>;

	temp->data = data;
	temp->next = NULL;
	if (head != NULL) {
		tail->next = temp;
		tail = temp;
	}
	else {
		head = tail = temp;
	}
	this->count++;
}

template<class T>
void List<T>::paste(T data, int id)
{
	Element<T>* temp = new Element<T>;
	temp->data = data;
	if (head != NULL) {
		if (tail != get_item(id - 1)) temp->next = get_item(id + 1);
		else {
			temp->next = NULL;
			tail = temp;
		}
		get_item(id - 1)->next = temp;
	}
	else {
		head = tail = temp;
	}
	this->count++;
}

template <class T>
void List<T>::del_head()
{
	Element<T>* temp = head;
	head = head->next;
	delete temp;
}

template<class T>
void List<T>::del(int id)
{
	if (id < 0 || id >= this->count) throw "err";
	Element<T>* temp = get_item(id);
	if (this->count == 1) this->head = this->tail = nullptr;
	else if (id == 0) this->head = temp->next;
	else if (id == this->count - 1)
	{
		Element<T>* prev = get_item(id - 1);
		prev->next = nullptr;
		this->tail = prev;
	}
	else get_item(id - 1)->next = temp->next;
	delete temp;
	this->count--;
}

template <class T>
void List<T>::del_all()
{
	while (head != 0)
		del_head();
	this->count = 0;
}

template <class T>
void List<T>::print()
{
	Element<T>* temp = head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n\n";
}

int main()
{
	List<char> lst;

	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.add(s[i]);
	lst.print();
	lst.del_head();
	lst.del_head();
	lst.del_head();
	lst.print();
}