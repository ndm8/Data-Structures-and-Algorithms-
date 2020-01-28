//Project 4 - Data Structures
//Dr. Hwang
//
//File name: Project 4 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 7/24/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstddef>

using namespace std;

struct Record
{
    int student_id;
    string student_name;
    string student_address;
    double student_average;
    int *test_p;
};

class DynRecStack
{
    private:
        struct StackNode
        {
            Record person;
            StackNode *next;
        };

        StackNode *top;

    public:
        DynRecStack () {  top = NULL;  }

        ~DynRecStack ();

        void push (Record);
        void pop (Record &);
        bool isEmpty ();
        void displayStack ();
};

DynRecStack :: ~DynRecStack ()
{
    StackNode *nodePtr = NULL,
              *nextNode = NULL;

    nodePtr = top;

    while (nodePtr)
    {
        nextNode = nodePtr -> next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void DynRecStack :: push (Record student)
{
    StackNode *newNode = NULL;

    newNode = new StackNode;
    newNode -> person = student;

    if (isEmpty ())
    {
        top = newNode;
        newNode -> next = NULL;
    }
    else
    {
        newNode -> next = top;
        top = newNode;
    }
}

void DynRecStack :: pop (Record &student)
{
    StackNode *temp = NULL;

    if (isEmpty ())
        cout << "The stack is empty" << endl;
    else
    {
        student = top -> person;
        temp = top -> next;
        delete top;
        top = temp;
    }
}

bool DynRecStack :: isEmpty ()
{
    bool status;

    if (!top)
        status = true;
    else
        status = false;

    return status;
}

void DynRecStack :: displayStack ()
{
    if (isEmpty ())
        cout << "Stack is empty!" << endl;
    else
    {
        StackNode *p = top;
        while (p)
        {
            cout << "ID: " << (p -> person).student_id << endl;
            cout << "Name: " << (p -> person).student_name << endl;
            cout << "Address: " << (p -> person).student_address << endl;
            cout << "Average: " << (p -> person).student_average << endl;
            cout << endl;
            p = p -> next;
        }
    }
}

class StudentClass
{
    private:
        struct Student
        {
            Record person;
            Student *next;
        };
        Student *head;

    public:
        StudentClass ();
        ~StudentClass ();

        void appendNode (Record);
        void displayList ();
};

StudentClass :: StudentClass ()
{
    head = NULL;
}

StudentClass :: ~StudentClass ()
{
    Student *p;
    Student *n;

    p = head;

    while (p)
    {
        n = p -> next;
        delete p;
        p = n;
    }
}

void StudentClass :: appendNode (Record student)
{
    Student *newNode = new Student;
    newNode -> person = student;
    newNode -> next = NULL;

    if (head == NULL)
        head = newNode;

    else
    {
        Student *p = head;

        while (p->next)
        {
            p = p -> next;
        }
        p -> next = newNode;
    }
}

void StudentClass :: displayList ()
{
    Student *p = head;
    DynRecStack t;
    const int NUM_POPS = 5;

    while (p)
    {
        cout << "Student ID: " << (p -> person).student_id << endl
             << "Student Name: " << (p -> person).student_name << endl
             << "Student Address: " << (p -> person).student_address << endl
             << "Student Test Average: " << (p -> person).student_average
             << endl << endl;

        t.push (p -> person);

        p = p -> next;
    }

    Record student1;

    for (int i = 0; i < NUM_POPS; i++)
    {
        t.pop (student1);
        cout << "pop:   " << endl << endl
             << "ID: " << student1.student_id << endl
             << "Name: " << student1.student_name << endl
             << "Address: " << student1.student_address << endl
             << "Average: " << student1.student_average << endl << endl;
    }

    cout << endl << "What remains: " << endl << endl;

    t.displayStack ();

}

int main ()
{
    const int MIN_VAL = 0,
              MAX_VAL = 100,
              MIN_VAL2 = 1000,
              MAX_VAL2 = 9999,
              NUM_STUDENTS = 15,
              NUM_TESTS = 10;

    unsigned seed = time (0);

    srand (seed);

    //Data
    string name_array [NUM_STUDENTS] = {"John", "Steve", "Mariah", "Peter",
    "Nick", "Healy", "Amanda", "Sydney", "Tim", "Olivia", "Garcia", "Hank",
    "Ashley", "Matt", "William"};

    string address_array [NUM_STUDENTS] = {"12 Silk Rd.", "13 Cat Rd.",
    "14 Dog Rd.", "15 Peanut Rd.", "16 Bread Rd.", "17 Hat Rd.", "18 Chair Rd.",
    "19 Stack Rd.", "10 Class Rd.", "11 Linked List Rd.", "1 Struct Rd.",
    "2 Char Rd.", "3 Cup Rd.", "4 Pointer Rd.", "5 Computer Rd."};

    int test_scores [NUM_STUDENTS] [NUM_TESTS];

    //Populating the test scores with random scores
    for (int i = 0; i < NUM_STUDENTS; i++)
        for (int j = 0; j < NUM_TESTS; j++)
            test_scores [i] [j] = (rand () % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;

    StudentClass s;

    //Populating the Linked List with the student data
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        double sum = 0;
        Record person;
        person.student_id = (rand () % (MAX_VAL2 - MIN_VAL2 + 1)) + MIN_VAL2;
        person.student_name = name_array [i];
        person.student_address = address_array [i];
        for (int j = 0; j < NUM_TESTS; j++)
            sum += test_scores [i] [j];
        person.student_average = sum / NUM_TESTS;
        person.test_p = test_scores [i];
        s.appendNode (person);
    }

    s.displayList ();

    return 0;
}
