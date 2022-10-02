#include <iostream>
using namespace std;


struct Element
{

    char data;
    Element* Next;

};

class List
{
    Element* Head;
    Element* Tail;
    int Count;

public:

    List();
    ~List();
    void Add(char data);
    void Del();
    void DelAll();
    void Print();
    int GetCount();
    int GetPos(char c);
    void DelChoice(int pos);
    void InsertChoice(int pos);
    void AddTail(int n);
    void AddHead(int n);
};

int List::GetPos(char c) {
    Element* temp = Head;
    int i = 1;
    bool ifFound = false;
    while (temp != Tail) {
        temp = temp->Next;
        i++;
        if (temp->data == c) {
            ifFound = true;
            break;
        }
    }
    if (ifFound == true) {
        return i;
    }
    else {
        return 0;
    }
}

List::List()
{

    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{

    DelAll();
}

int List::GetCount()
{

    return Count;
}

void List::Add(char data)
{

    Element* temp = new Element;
    temp->data = data;
    temp->Next = NULL;
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    else {
        Head = Tail = temp;
    }
    Count++;
}
void List::InsertChoice(int pos)
{

    if (pos < 1 || pos > Count + 1)
    {
        cout << "Incorrect position\n";
        return;
    }


    if (pos == Count + 1)
    {
        int data;
        cout << "Input new char: ";
        cin >> data;
        AddTail(data);
        return;
    }
    else if (pos == 1)
    {
        int data;
        cout << "Input new char: ";
        cin >> data;
        AddHead(data);
        return;
    }
    int i = 1;
    Element* Ins = Head;

    while (i < pos)
    {

        Ins = Ins->Next;
        i++;
    }
    Element* temp = new Element;
    cout << "Input new char: ";
    cin >> temp->data;

    Element* temp2 = nullptr;
    temp2 = Head;
    while (i < pos - 1)
    {
        temp2 = temp2->Next;
        i++;
    }
    if (Count != 1)
        temp2->Next = temp;

    temp->Next = Ins;

    Count++;
}

void List::AddHead(int n)
{
    Element* temp = new Element;

    temp->data = n;
    temp->Next = Head;
    if (Count == 0)
        Head = Tail = temp;
    else
        Head = temp;

    Count++;
}

void List::AddTail(int n)
{
    Element* temp = new Element;
    temp->Next = 0;
    temp->data = n;


    if (Tail != 0)
        Tail->Next = temp;

    if (Count == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    Count++;
}

void List::DelChoice(int pos)
{
    if (pos < 1 || pos > Count)
    {
        cout << "Incorrect position\n";
        return;
    }
    Element* Del = nullptr;
    int i = 1;
    Del = Head;

    while (i < pos)
    {
        Del = Del->Next;
        i++;
    }
    Element* temp = nullptr;
    temp = Head;
    while (i < pos - 1)
    {
        temp = temp->Next;
        i++;
    }
    Element* AfterDel = Del->Next;
    if (Count != 1)
        temp->Next = AfterDel;
    if (pos == 1) {
        Head = AfterDel;
    }
    if (pos == Count) {
        Tail = temp;
    }
    delete Del;

    Count--;
}

void List::Del()
{

    Element* temp = Head;
    Head = Head->Next;
    delete temp;
}

void List::DelAll()
{
    while (Head != 0)
        Del();
}

void List::Print()
{
    Element* temp = Head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }

    cout << "\n\n";
}

int main()
{

    List lst;
    char s[] = "Hello, World !!!\n";
    cout << s << "\n\n";
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);
    lst.Print();
    lst.Del();
    lst.Del();
    lst.Del();
    lst.Print();
    lst.DelChoice(2);
    lst.Print();
    lst.InsertChoice(2);
    lst.Print();
    cout << "GetPos: ";
    cout << lst.GetPos('7');
    cout << endl;
}