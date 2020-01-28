//Project 3 - Data Structures
//Dr. Hwang
//
//File name: Project 3 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 7/20/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

struct Record
{
    int student_id;
    string student_name;
    string student_address;
    double average;
    int *test_p;
};

class StudentStack
{
    private:
        static const int STACK_SIZE = 100;
        Record stackArray [STACK_SIZE];
        int top;
    public:
        StudentStack () { top = -1; }

        void push (Record);
        Record pop ();
        bool isFull () const;
        bool isEmpty () const;
        void displayStack ();
};

bool StudentStack :: isFull () const
{
    return (top == STACK_SIZE - 1);
}

bool StudentStack :: isEmpty () const
{
    return (top == -1);
}

void StudentStack :: push (Record student)
{
    assert (!isFull());

    top++;
    stackArray [top] = student;
}

Record StudentStack :: pop ()
{
    assert (!isEmpty ());

    Record student = stackArray [top];
    top--;
    return student;
}

void StudentStack :: displayStack ()
{
    if (isEmpty())
        cout << "Stack is empty." << endl;
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stackArray [i].student_id << endl;
            cout << stackArray [i].student_name << endl;
            cout << stackArray [i].student_address << endl;
            cout << stackArray [i].average << endl << endl;
        }
    }
}

int main ()
{
    const int MIN_VAL = 0,
              MAX_VAL = 100,
              MIN_VAL2 = 1000,
              MAX_VAL2 = 9999,
              NUM_STUDENTS = 15,
              NUM_TESTS = 10,
              NUM_POPS = 5;

    unsigned seed = time (0);

    srand (seed);

    Record student_array [NUM_STUDENTS]; //For student array

    //Data
    string name_array [NUM_STUDENTS] = {"John", "Steve", "Mariah", "Peter", "Nick",
    "Healy", "Amanda", "Sydney", "Tim", "Olivia", "Garcia", "Hank", "Ashley",
    "Matt", "William"};

    string address_array [NUM_STUDENTS] = {"12 Silk Rd.", "13 Cat Rd.", "14 Dog Rd.",
    "15 Peanut Rd.", "16 Bread Rd.", "17 Hat Rd.", "18 Chair Rd.",
    "19 Stack Rd.", "10 Class Rd.", "11 Linked List Rd.", "1 Struct Rd.",
    "2 Char Rd.", "3 Cup Rd.", "4 Pointer Rd.", "5 Computer Rd."};

    int test_scores [NUM_STUDENTS] [NUM_TESTS];

    //Populating the test scores with random scores
    for (int i = 0; i < NUM_STUDENTS; i++)
        for (int j = 0; j < NUM_TESTS; j++)
            test_scores [i] [j] = (rand () % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;

    //Populating the student array with the student data
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        double sum = 0;
        Record person;
        person.student_id = (rand () % (MAX_VAL2 - MIN_VAL2 + 1)) + MIN_VAL2;
        person.student_name = name_array [i];
        person.student_address = address_array [i];
        for (int j = 0; j < NUM_TESTS; j++)
            sum += test_scores [i] [j];
        person.average = sum / NUM_TESTS;
        person.test_p = test_scores [i];
        student_array [i] = person;
    }

    cout << "The student records are: " << endl << endl;
    for (int i = 0; i < NUM_STUDENTS; i ++)
    {
        cout << student_array [i].student_id << endl;
        cout << student_array [i].student_name << endl;
        cout << student_array [i].student_address << endl;
        cout << student_array [i].average << endl << endl;
    }

    StudentStack s; //For the static stack

    for (int i = 0; i < NUM_STUDENTS; i++) //push all student records
        s.push(student_array [i]);

    for (int i = 0; i < NUM_POPS; i++) //pops 5 student records
    {
        Record x = s.pop ();
        cout << "pop: " << x.student_name << endl;
    }

    cout << endl << "Remaining student records: " << endl << endl;
    s.displayStack();

    return 0;
}
