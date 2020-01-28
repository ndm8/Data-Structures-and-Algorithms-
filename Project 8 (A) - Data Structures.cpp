//Project 8 (A) - Data Structures
//Dr. Hwang
//
//File name: Project 8 (A) - Data Structures.cpp
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

class charStack
{
private:
    char *stackArray;
    int stackSize;
    int top;
public:
    charStack (int);

    charStack (const charStack &);

    ~charStack ();

    void push (char);
    void pop (char &);
    bool isFull () const;
    bool isEmpty () const;
    char nextChar ();
};

charStack :: charStack (int size)
{
    stackArray = new char [size];
    stackSize = size;
    top = -1;
}

charStack :: charStack (const charStack &obj)
{
    if (obj.stackSize > 0)
        stackArray = new char [obj.stackSize];
    else
        stackArray = NULL;
    stackSize = obj.stackSize;
    for (int count = 0; count < stackSize; count++)
        stackArray [count] = obj.stackArray [count];
    top = obj.top;
}

charStack :: ~charStack ()
{
    delete [] stackArray;
}

void charStack :: push (char x)
{
    if (isFull ())
        cout << "The stack is full." << endl;
    else
    {
        top++;
        stackArray [top] = x;
    }
}

void charStack :: pop (char &x)
{
    if (isEmpty ())
        cout << "The stack is empty" << endl;
    else
    {
        x = stackArray [top];
        top--;
    }
}

bool charStack :: isFull () const
{
    return top == stackSize - 1;
}

bool charStack :: isEmpty () const
{
    return top == -1;
}

char charStack :: nextChar ()
{
    return stackArray [top];
}

bool isoperation (char x)
{
    if (x == '+' || x == '*'|| x == '/' || x == '-')
        return true;
    else
        return false;
}

bool lowerPrecedence (char x, char y)
{
    if ((x == '+' || x == '-') && (y == '+' || y == '-'))
        return true;
    else if ((x == '+' || x == '-') && (y == '*' || y == '/'))
        return true;
    else if ((x == '*' || x == '/') && (y == '*' || y == '/'))
        return true;
    else
        return false;
}


int main ()
{
    charStack my_stack (100);

    bool ans;
    do
    {
        char x;
        cout << "Input your infix expression: ";

        string infix_exp;
        cin >> infix_exp;
        for (int i = 0; i < infix_exp.size (); i++)
        {
            x = infix_exp [i];
            if (x == '(')
                my_stack.push (x);
            else if (isdigit(x) || isalpha(x))
                cout << x << " ";
            else if (isoperation(x))
            {

                while (!my_stack.isEmpty () && my_stack.nextChar () != '(' &&
                        lowerPrecedence (x, my_stack.nextChar ()))
                {
                    char y;
                    my_stack.pop (y);
                    cout << y << " ";
                }
                my_stack.push (x);
            }
            else
            {
                char s;
                while (my_stack.nextChar () != '(')
                {
                    my_stack.pop (s);
                    cout << s << " ";
                }
                my_stack.pop (s);
            }
        }

        char s;
        while (!my_stack.isEmpty ())
        {
            my_stack.pop (s);
            cout << s;
        }

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
