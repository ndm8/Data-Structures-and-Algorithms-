//Project 7 - Data Structures
//Dr. Hwang
//
//File name: Project 7 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 8/3/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MIN_VAL = 0,
          MAX_VAL = 100,
          MIN_VAL2 = 1000,
          MAX_VAL2 = 9999,
          MIN_VAL3 = 10,
          MAX_VAL3 = 40,
          NUM_STUDENTS = 20,
          NUM_TESTS = 10;

struct Record
{
    int id;
    string name;
    double gpa;
    string address;
    int *test_p;
};

int partitionArray (vector <Record> &my_array, int p, int r)
{
    int x = my_array [r].id;
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (my_array [j].id <= x)
        {
            i = i + 1;
            swap (my_array [i], my_array [j]);
        }
    }
    swap (my_array [i + 1], my_array [r]);
    return i + 1;
}

void quickSort (vector <Record> &my_array, int p, int r)
{
    if (p < r)
    {
        int q = partitionArray (my_array, p, r);
        quickSort (my_array, p, q - 1);
        quickSort (my_array, q + 1, r);
    }
}

void displayRecords (vector <Record> student_vector,
                     int test_scores [NUM_STUDENTS] [NUM_TESTS])
{
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "ID: " << student_vector [i].id << endl;
        cout << "Name: " << student_vector [i].name << endl;
        cout << "GPA: " << student_vector [i].gpa << endl;
        cout << "Address: " << student_vector [i].address << endl;
        cout << "Test Scores: ";
        for (int j = 0; j < NUM_TESTS; j++)
        {
          cout << test_scores [i] [j] << " ";
        }
        cout << endl << endl;
    }
}

int main ()
{
    unsigned seed = time (0);
    srand (seed);

    vector <Record> student_vector;

    //Data
    string name_array [NUM_STUDENTS] = {"John", "Steve", "Mariah", "Peter",
    "Nick", "Healy", "Amanda", "Sydney", "Tim", "Olivia", "Garcia", "Hank",
    "Ashley", "Matt", "Courtney", "Emily", "Stacey", "Liza", "Dani", "William"};

    string address_array [NUM_STUDENTS] = {"12 Silk Rd.", "13 Cat Rd.",
    "14 Dog Rd.", "15 Peanut Rd.", "16 Bread Rd.", "17 Hat Rd.", "18 Chair Rd.",
    "19 Stack Rd.", "10 Class Rd.", "11 Linked List Rd.", "1 Struct Rd.",
    "2 Char Rd.", "3 Cup Rd.", "4 Pointer Rd.", "5 Computer Rd.", "14 CPU Ln.",
    "12 Array St.", "21 Int Ln.", "39 Mouse Rd.", "90 Last Rd."};

    int test_scores [NUM_STUDENTS] [NUM_TESTS];
    //Populating the test scores with random scores
    for (int i = 0; i < NUM_STUDENTS; i++)
        for (int j = 0; j < NUM_TESTS; j++)
            test_scores [i] [j] = (rand () % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;

    //Populating the Linked List with the student data
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        Record person;
        person.id = (rand () % (MAX_VAL2 - MIN_VAL2 + 1)) + MIN_VAL2;
        person.name = name_array [i];
        person.gpa = ((rand () % (MAX_VAL3 - MIN_VAL3 + 1)) + MIN_VAL3)/10.0;
        person.address = address_array [i];
        person.test_p = test_scores [i];
        student_vector.push_back (person);
    }

    cout << "Records before quick sort: " << endl;
    displayRecords(student_vector, test_scores);

    quickSort (student_vector, 0, student_vector.size () - 1);

    cout << endl << endl << "Records after quick sort: " << endl;
    displayRecords (student_vector, test_scores);

    return 0;
}
