//Project 2 - Data Structures
//Dr. Hwang
//
//File name: Project 2 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 7/17/2017

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Record
{
    int student_id;
    string student_name;
    string student_address;
    double student_gpa;
};

class StudentClass
{
    private:
        struct Student
        {
            int ID;
            string name;
            string address;
            double GPA;
            Student *next;
        };
        Student *head;

    public:
        StudentClass ();
        ~StudentClass ();

        void appendNode (Record);
        void insertNode (Record);
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
    newNode -> ID = student.student_id;
    newNode -> name = student.student_name;
    newNode -> address = student.student_address;
    newNode -> GPA = student.student_gpa;
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

void StudentClass :: insertNode (Record student)
{
    Student *newNode;
    Student *p;
    Student *n;

    newNode = new Student;
    newNode -> ID = student.student_id;
    newNode -> name = student.student_name;
    newNode -> address = student.student_address;
    newNode -> GPA = student.student_gpa;

    p = head;
    while (p && p -> name < student.student_name)
    {
        n = p;
        p = p -> next;
    }

    if (p == head)
    {
        head = newNode;
        newNode -> next = p;
    }
    else
    {
        n -> next = newNode;
        newNode -> next = p;
    }
}

void StudentClass :: displayList ()
{
    Student *p = head;

    cout << endl;

    while (p)
    {
        cout << "Student ID: " << p -> ID << endl
             << "Student Name: " << p -> name << endl
             << "Student Address: " << p -> address << endl
             << "Student GPA: " << p -> GPA << endl;

        p = p -> next;
        cout << endl;
    }
}

int main ()
{
    //Code for random number
    const int MIN_VAL = 1000;
    const int MAX_VAL = 9999;

    unsigned seed = time (0);

    srand (seed);

    const int SIZE = 15; //Number of students

    Record student_array [SIZE]; //For student array

    //Data
    string name_array [SIZE] = {"John", "Steve", "Mariah", "Peter", "Nick",
    "Healy", "Amanda", "Sydney", "Tim", "Olivia", "Garcia", "Hank", "Ashley",
    "Matt", "William"};

    string address_array [SIZE] = {"12 Silk Rd.", "13 Cat Rd.", "14 Dog Rd.",
    "15 Peanut Rd.", "16 Bread Rd.", "17 Hat Rd.", "18 Chair Rd.",
    "19 Stack Rd.", "10 Class Rd.", "11 Linked List Rd.", "1 Struct Rd.",
    "2 Char Rd.", "3 Cup Rd.", "4 Pointer Rd.", "5 Computer Rd."};

    double GPA_array [SIZE] = {3.14, 2.5, 2.71, 1.41, 4.0, 3.75, 3.68, 2.13,
    1.11, 2.22, 3.33, 2.0, 3.0, 1.14, 2.75};

    //Populating the student array with the student data
    for (int i = 0; i < SIZE; i++)
    {
        Record person;
        person.student_id = (rand () % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
        person.student_name = name_array [i];
        person.student_address = address_array [i];
        person.student_gpa = GPA_array [i];
        student_array [i] = person;
    }

    StudentClass s; //Creates a StudentClass Object

    //Creates the student Linked List form the student array (NOT sorted)
    for (int i = 0; i < 10; i++)
    {
        s.appendNode (student_array [i]);
    }

    cout << "Unsorted Linked List:" << endl;

    s.displayList (); //Displays the unsorted Linked List

    //Sorted Linked List:
    StudentClass t; //Creates the second Linked List

    for (int i = 0; i < SIZE; i++)
    {
        t.insertNode (student_array [i]);
    }

    cout << endl << "Sorted Linked List:" << endl;

    t.displayList (); //Displays the sorted Linked List

    t.~StudentClass();

    return 0;
}
