#include "User.h"

int User::count = 0;

User::User(string name, int* library_ids, const int size, int frequency)
{
    this->id = count++;
    if (size < 0) throw "Size can't be < 0";
    if (size > 3) throw "1 User can't owned more than 3 books";
    this->lib_size = size;

    if (library_ids != nullptr)
    {
        this->library_ids = new int[this->lib_size];
        for (size_t i = 0; i < this->lib_size; i++)
        {
            if (library_ids[i] < 0) throw "library_id can't be < 0";
            this->library_ids[i] = library_ids[i];
        }
    }
    else this->library_ids = nullptr;

    this->name = name;

    if (frequency <= 0) throw "frequency can't be <= 0";
    this->frequency = frequency;
}

User::User(string name, int book_id, int frequency)
{
    this->id = count++;
    this->lib_size = 1;

    if (book_id > -1)
    {
        this->library_ids = new int[1];
        this->library_ids[0] = book_id;
    }
    else
    {
        this->library_ids = nullptr;
        throw "book_id can't be < 0";
    }

    this->name = name;

    if (frequency <= 0) throw "frequency can't be <= 0";
    this->frequency = frequency;
}

User::User(string name, Book* library, const int size, int frequency)
{
    this->id = count++;
    if (size < 0) throw "Size can't be < 0";
    if (size > 3) throw "1 User can't owned more than 3 books";

    this->lib_size = size;

    if (library != nullptr)
    {
        this->library_ids = new int[this->lib_size];
        for (size_t i = 0; i < this->lib_size; i++)
        {
            if (library[i].GetId() < 0) throw "library_id can't be < 0";
            this->library_ids[i] = library[i].GetId();
        }
    }
    else this->library_ids = nullptr;

    this->name = name;

    if (frequency <= 0) throw "frequency can't be <= 0";
    this->frequency = frequency;
}

User::User(string name, Book& book, int frequency)
{
    this->id = count++;
    this->lib_size = 1;

    this->library_ids = new int[1];
    if (book.GetId() < 0) throw "book id can't be < 0";
    this->library_ids[0] = book.GetId();

    this->name = name;

    if (frequency <= 0) throw "frequency can't be <= 0";
    this->frequency = frequency;
}

User::User(const User& obj)
{
    this->id = obj.id;
    this->name = obj.name;
    this->lib_size = obj.lib_size;
    this->frequency = obj.frequency;

    if (obj.library_ids != nullptr && obj.lib_size > 0)
    {
        this->library_ids = new int[obj.lib_size];
        for (int i = 0; i < obj.lib_size; i++)
            this->library_ids[i] = obj.library_ids[i];
    }
    else this->library_ids = nullptr;
}

void User::AddBook(int id)
{
    if (id < 0) throw "book id can't be < 0";
    if (this->lib_size + 1 > 3) throw "1 User can't owned more than 3 books";

    int* temp = new int[this->lib_size + 1];

    for (size_t i = 0; i < this->lib_size; i++)
        temp[i] = this->library_ids[i];

    delete[] this->library_ids;

    temp[this->lib_size] = id;
    this->lib_size++;

    this->library_ids = temp;
}

void User::RemoveBook(int id)
{
    if (id < 0) throw "book id can't be < 0";

    if (this->lib_size <= 1 && this->library_ids != nullptr)
    {
        delete[] this->library_ids;
        this->library_ids = nullptr;
        this->lib_size--;
        return;
    }

    int* temp = new int[this->lib_size - 1];
    int j = 0;

    // логика та же, просто цикл исправлен
    for (size_t i = 0; i < this->lib_size; i++)
    {
        if (this->library_ids[i] != id)
            temp[j++] = this->library_ids[i];
    }

    delete[] this->library_ids;

    this->library_ids = temp;
    this->lib_size--;
}

User& User::operator=(const User& obj)
{
    if (this == &obj) return *this;

    delete[] this->library_ids;

    this->id = obj.id;
    this->name = obj.name;
    this->lib_size = obj.lib_size;
    this->frequency = obj.frequency;

    if (obj.library_ids != nullptr && obj.lib_size > 0)
    {
        this->library_ids = new int[obj.lib_size];
        for (int i = 0; i < obj.lib_size; i++)
            this->library_ids[i] = obj.library_ids[i];
    }
    else this->library_ids = nullptr;

    return *this;
}

User::~User()
{
    delete[] library_ids;
}
