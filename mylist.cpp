#include "mylist.h"

template <typename T>
void mcin(T* _x)
{
    while (true)
    {
        cin >> *_x;
        if (std::cin.good())
            break;

        cout << "invalid input" << std::endl;
        cin.clear();
        cin.ignore();
    }
}

train* myList::operator[](int idx)
{
    if (idx < 0 || idx > size)
    {
        return nullptr;
    }

    train* ptr = HEAD;

    int count = 0;
    while (count != idx)
    {
        ptr = ptr->getNextPtr();
        count++;
    }

    return ptr;
}

void myList::sort()
{
    if (size == 1)
        return;

    train* p = HEAD->getNextPtr();
    train* prev = HEAD;
    int count = 1;
    while (count != size)
    {
        int state = strcmp(p->getName().c_str(), p->getNextPtr()->getName().c_str());
        bool isToSort = (a_to_z_flag == true) ? (state > 0) : (state < 0);
        if (isToSort)
        {
            // ÔÓÏÂÌˇÚ¸ ÏÂÒÚ‡ÏË
            train* ptr0 = (*this)[count - 1];
            train* ptr1 = (*this)[count];
            train* ptr2 = (*this)[count + 1];
            train* ptr3 = (*this)[count + 2];

            ptr0->setNextPtr(ptr2);
            ptr1->setNextPtr(ptr3);
            ptr2->setNextPtr(ptr1);

            if (LAST == ptr2)
                LAST = ptr1;

            count = 1;
            p = HEAD->getNextPtr();
            prev = HEAD;
        }
        else
        {
            p = p->getNextPtr();
            prev = prev->getNextPtr();
            count++;
        }
    }
}




myList::myList()
{
    cout << "Вызван конструктор myList" << endl;
    size = 0;
    HEAD = new train;
    LAST = HEAD;
    a_to_z_flag = true;
}

void myList::flipFlag()
{
    a_to_z_flag = !a_to_z_flag;
    if (size > 0) sort();
}

void myList::seeFlag()
{
    cout << "\tsorting setting:";
    if (a_to_z_flag)
        cout << "\tA to Z" << endl;
    else
        cout << "\tA to Z" << endl;
}


void myList::add()
{
    cout << "\tadding new record" << endl;
    train* add_obj = new train;
    cin >> *add_obj;
    LAST->setNextPtr(add_obj);
    LAST = add_obj;
    size++;
    sort();
    cout << "\tadded" << endl;
}

void myList::print()
{
    if (size == 0)
        cout << endl << "\tno objects added yet" << endl;
    else
        cout << endl << "\tALL OBJECTS" << endl;
    train* p = HEAD->getNextPtr();
    while (p != nullptr)
    {
        cout << *p << endl;
        p = p->getNextPtr();
    }
}


void myList::del()
{
    cout << "\tdeleting" << endl;
    if (size == 0)
        throw 0;

    cout << "\tthere are " << size << " records, choose one to delete (index from 1 to " << size << ") : ";

    int idx;
    mcin(&idx);
    if (idx < 0 || idx > size)
        throw - 1;

    train* prev = (*this)[idx - 1];

    if (idx == size)
    {
        delete LAST;
        LAST = prev;
        LAST->setNextPtr(nullptr);
        size--;
        return;
    }

    train* curr = (*this)[idx];
    train* next = (*this)[idx + 1];

    delete curr;
    prev->setNextPtr(next);

    cout << "\tdeleted" << endl;
    size--;
    sort();
}

void myList::edit()
{
    cout << "\tediting" << endl;
    if (size == 0)
        throw 0;

    cout << "\tthere are " << size << " records, choose one to delete (index from 1 to " << size << ") : ";

    int idx;
    mcin(&idx);
    if (idx < 0 || idx > size)
        throw - 1;


    train* curr = (*this)[idx];
    cout << "\tenter new values for this object" << endl;
    cin >> *curr;

    cout << "\tedited" << endl;
    sort();
}

void myList::findType()
{
    cout << "\tsearch " << endl;
    if (size == 0)
        throw 0;

    string searchValue;

    cout << "\tПоиск поезда по пункту назначения: ";
    cin.clear();
    cin.ignore();
    getline(cin, searchValue);

    train* p = HEAD->getNextPtr();
    while (p != nullptr)
    {
        if (p->getName() == searchValue)
        {
            cout << "Номер: " << p->getNumber() << " Пункт назначения: " << p->getName() << " Время: " << p->getType() << endl;
        }

        p = p->getNextPtr();
    }
    cout << "\tsearch finished" << endl;
}
