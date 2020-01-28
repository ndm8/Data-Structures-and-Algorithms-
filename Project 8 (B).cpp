//Project 8 (B) - Data Structures
//Dr. Hwang
//
//File name: Project 8 (B) - Data Structures.cpp
//
//Author: Nick Montana
//
//Due Date: 8/7/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <ctype.h>

using namespace std;

class doubStack
{
private:
    double *stackArray;
    int stackSize;
    int top;
public:
    doubStack (int);

    doubStack (const doubStack &);

    ~doubStack ();

    void push (double);
    void pop (double &);
    bool isFull () const;
    bool isEmpty () const;
    char nextChar ();
};

doubStack :: doubStack (int size)
{
    stackArray = new double [size];
    stackSize = size;
    top = -1;
}

doubStack :: doubStack (const doubStack &obj)
{
    if (obj.stackSize > 0)
        stackArray = new double [obj.stackSize];
    else
        stackArray = NULL;
    stackSize = obj.stackSize;
    for (int count = 0; count < stackSize; count++)
        stackArray [count] = obj.stackArray [count];
    top = obj.top;
}

doubStack :: ~doubStack ()
{
    delete [] stackArray;
}

void doubStack :: push (double x)
{
    if (isFull ())
        cout << "The stack is full." << endl;
    else
    {
        top++;
        stackArray [top] = x;
    }
}

void doubStack :: pop (double &x)
{
    if (isEmpty ())
        cout << "The stack is empty" << endl;
    else
    {
        x = stackArray [top];
        top--;
    }
}

bool doubStack :: isFull () const
{
    return top == stackSize - 1;
}

bool doubStack :: isEmpty () const
{
    return top == -1;
}

bool isoperation (char x)
{
    if (x == '+' || x == '*'|| x == '/' || x == '-')
        return true;
    else
        return false;
}

double evaluate (double num1, double num2, char x)
{
    if (x == '+')
        return num2 + num1;
    else if (x == '-')
        return num2 - num1;
    else if (x == '*')
        return num2 * num1;
    else if (x == '/')
        return num2 / num1;
}

int main ()
{
    doubStack my_stack (100);


    bool ans;
    do
    {
        string expression;
        cout << "Please enter a postfix expression: ";
        cin >> expression;

        char x;
        for (int i = 0; i < expression.size (); i++)
        {
            x = expression [i];
            if (isdigit(x))
            {
                int n = static_cast <int> (x) - 48;
                my_stack.push (n);
            }
            else if (isoperation(x))
            {
                double a, b, y;
                my_stack.pop (a);
                my_stack.pop (b);
                y = evaluate (a, b, x);
                my_stack.push (y);
            }
            else
            {
                cout << "Error - encountered unrecognized character: "
                     << x << endl;
                return -1;
            }
        }

        double s;
        my_stack.pop (s);
        cout << "This evaluates to: " << s << endl;

        char input;
        cout << endl<< "Would you like to enter another expression? (Y or N): ";
        cin >> input;
        if (input == 'Y')
            ans = true;
        else
            ans = false;
    } while (ans);

    return 0;
}
