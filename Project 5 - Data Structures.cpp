//Project 5 - Data Structures
//Dr. Hwang
//
//File name: Project 5 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 7/31/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Record
{
    int id;
    string name;
    double gpa;
    string address;
    int *test_p;
};

int binarySearch (vector <Record> array, int first, int last, int value)
{
    int middle;

    if (first > last)
        return -1;
    middle = (first + last) / 2;
    if (array [middle].id == value)
        return middle;
    if (array [middle].id < value)
        return binarySearch(array, middle + 1, last, value);
    else
        return binarySearch(array, first, middle - 1, value);
}

int main ()
{
    const int MIN_VAL = 0,
              MAX_VAL = 100,
              MIN_VAL2 = 1000,
              MAX_VAL2 = 9999,
              MIN_VAL3 = 10,
              MAX_VAL3 = 40,
              NUM_STUDENTS = 20,
              NUM_TESTS = 10;

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

    //Sort:
    for (int i = 0; i < NUM_STUDENTS - 1; i++)
    {
        Record min = student_vector [i];
        int min_index = i;
        for (int j = i; j < NUM_STUDENTS; j++)
            if (student_vector [j].id < min.id)
            {
                min = student_vector [j];
                min_index = j;
            }
        student_vector [min_index] = student_vector [i];
        student_vector [i] = min;
    }

    //Output:
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

    bool ans;
    do
    {
        char s;

        //Binary Search:
        int value;
        cout << "Enter a Student ID to search: ";
        cin >> value;
        int x = binarySearch(student_vector, 0, student_vector.size(),value);

        cout << endl << "You entered: " << value << endl;
        cout << "The result for the search is: " << endl << endl;

        if (x == -1)
            cout << endl << "**ERROR: ID not found**" << endl << endl;
        else
        {
            cout << "ID: " << student_vector [x].id << endl;
            cout << "Name: " << student_vector [x].name << endl;
            cout << "GPA: " << student_vector [x].gpa << endl;
            cout << "Address: " << student_vector [x].address << endl;
            cout << "Test Scores: ";
            for (int j = 0; j < NUM_TESTS; j++)
            {
              cout << test_scores [x] [j] << " ";
            }
            cout << endl << endl;
        }
        cout << "Would you like to make another search? (Y or N)" << endl;
        cin >> s;
        if (s == 'Y')
            ans = true;
        else
            ans = false;
    } while (ans);

    return 0;
}
