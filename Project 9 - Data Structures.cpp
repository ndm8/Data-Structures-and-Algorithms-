//Project 9 - Data Structures
//Dr. Hwang
//
//File name: Project 9 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 8/9/2017

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int m = 23,
          MIN_VAL = 100000,
          MAX_VAL = 999999,
          MIN_VAL1 = 10,
          MAX_VAL1 = 40,
          NUM_STUDENTS = 20;

struct Record
{
    int id;
    string name;
    double gpa;
    string address;
};

int h (int k)
{
    int m = 23;
    return k % m;

}

bool isEmpty (int x)
{
    return x == -1;
}

void add (Record person, Record hash_table [])
{
    int x = person.id;
    int y = h (x);

    if (isEmpty (hash_table [y].id))
        hash_table [y] = person;
    else
    {
        int temp = h (x);
        int i = h (x);

        do
        {
            i++;
        } while (!isEmpty (hash_table [h(i)].id) && h (i) != temp);

        if (h (i) == temp)
            cout << "ERROR: The list is full" << endl;
        else
            hash_table [h (i)] = person;
    }
}

int searchData (int entry, Record hash_table [])
{
    if (hash_table [h (entry)].id == entry)
        return h (entry);
    else
    {
        int temp = h (entry);
        int i = h (entry);

        do
        {
            i++;
        } while (hash_table [h(i)].id != entry && !isEmpty(hash_table [h(i)].id)
                 && h (i) != temp);

        if (h (i) == temp || isEmpty (hash_table [h(i)].id))
            return -1;
        else
            return h (i);
    }
}

void displayRecords (Record student_vector [], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "ID: " << student_vector [i].id << endl;
        cout << "Name: " << student_vector [i].name << endl;
        cout << "GPA: " << student_vector [i].gpa << endl;
        cout << "Address: " << student_vector [i].address << endl << endl;
    }
}

int main ()
{
    unsigned seed = time (0);
    srand (seed);

    Record student_array [NUM_STUDENTS];

    //Data
    string name_array [NUM_STUDENTS] = {"John", "Steve", "Mariah", "Peter",
    "Nick", "Healy", "Amanda", "Sydney", "Tim", "Olivia", "Garcia", "Hank",
    "Ashley", "Matt", "Courtney", "Emily", "Stacey", "Liza", "Dani", "William"};

    string address_array [NUM_STUDENTS] = {"12 Silk Rd.", "13 Cat Rd.",
    "14 Dog Rd.", "15 Peanut Rd.", "16 Bread Rd.", "17 Hat Rd.", "18 Chair Rd.",
    "19 Stack Rd.", "10 Class Rd.", "11 Linked List Rd.", "1 Struct Rd.",
    "2 Char Rd.", "3 Cup Rd.", "4 Pointer Rd.", "5 Computer Rd.", "14 CPU Ln.",
    "12 Array St.", "21 Int Ln.", "39 Mouse Rd.", "90 Last Rd."};

    //Populating the Array with the student data
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        Record person;
        person.id = (rand () % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
        person.name = name_array [i];
        person.gpa = ((rand () % (MAX_VAL1 - MIN_VAL1 + 1)) + MIN_VAL1)/10.0;
        person.address = address_array [i];
        student_array [i] = person;
    }

    cout << "The Hash Table: " << endl << endl;

    Record hash_table [m];

    for (int i = 0; i < m; i++)
        hash_table [i].id = -1;

    for (int i = 0; i < NUM_STUDENTS; i++)
        add (student_array [i], hash_table);

    displayRecords (hash_table, m);

    bool ans;
    do
    {
        int search;
        cout << "Enter a student id to search: ";
        cin >> search;

        int n = searchData(search, hash_table);
        if (n == -1)
            cout << endl << "ERROR: value not found" << endl;
        else
        {
            cout << endl << "Student Record Found: " << endl;
            cout << "ID: " << hash_table [n].id << endl;
            cout << "Name: " << hash_table [n].name << endl;
            cout << "GPA: " << hash_table [n].gpa << endl;
            cout << "Address: " << hash_table [n].address << endl;
        }

        char input;
        cout << endl << "Would you like to make another search? (Y or N): ";
        cin >> input;
        if (input == 'Y')
            ans = true;
        else
            ans = false;
    } while (ans);

    return 0;
}
