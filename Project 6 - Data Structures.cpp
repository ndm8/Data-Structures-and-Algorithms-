//Project 6 - Data Structures
//Dr. Hwang
//
//File name: Project 6 - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 7/31/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


const char FROM_PEG = 'A',
           TO_PEG = 'C',
           TEMP_PEG = 'B';

void moveDiscs (int NUM_DISC, int num, char fromPeg, char toPeg, char tempPeg,
                vector <char> &my_array)
{
    if (num > 0)
    {
        moveDiscs(NUM_DISC, num - 1, fromPeg, tempPeg, toPeg, my_array);
        cout << "Move disc" << num << " from peg " << fromPeg
             << " to peg " << toPeg << endl;
        my_array [num - 1] = toPeg;
        cout << "Positioning: ";
        for (int i = 0; i < NUM_DISC; i++)
            cout << my_array [i] << " ";
        cout << endl;

        moveDiscs(NUM_DISC, num - 1, tempPeg, toPeg, fromPeg, my_array);
    }
}

int main ()
{
    bool ans;
    do
    {
        int n;
        char x;
        vector <char> my_array;

        cout << "Enter how many discs (n) to use: ";
        cin >> n;

        for (int i = 0; i < n; i++)
            my_array.push_back('A');
        cout << endl << "Starting with: ";
        for (int i = 0; i < n; i++)
            cout << my_array [i] << " ";
        cout << endl;

        //Play the game.
        moveDiscs(n, n, FROM_PEG, TO_PEG, TEMP_PEG, my_array);
        cout << "All the pegs are moved!" << endl << endl;
        cout << "Would you like to play again? (Y or N)" << endl;
        cin >> x;
        cout << endl;

        if (x == 'Y')
            ans = true;
        else
            ans = false;
    } while (ans);

    return 0;
}
