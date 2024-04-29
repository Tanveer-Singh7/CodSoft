#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return (a + b);
}
int subtraction(int a, int b)
{
    return (a - b);
}
int division(int a, int b)
{
    return (a / b);
}
int multiplication(int a, int b)
{
    return (a * b);
}

int main()
{
    char option = 'y';
    while (option == 'y')
    {
        cout << "\t\t Welcome! This is an simple calculator. \t\t\nKindly select your option" << endl;
        cout << "\t\t1. Addition " << endl;
        cout << "\t\t2. Subtraction" << endl;
        cout << "\t\t3. Division" << endl;
        cout << "\t\t4. Multiplication" << endl;

        int operation;
        cout << "\n\n\t\t";
        cin >> operation;

        int num1, num2;
        cout << "\t\tEnter two numbers respectively " << endl;
        cout << "\n\n\t\t";
        cin >> num1 >> num2;

        switch (operation)
        {
        case 1:
            cout << "\t\t" << num1 << " + " << num2 << " = " << sum(num1, num2) << endl;
            break;

        case 2:
            cout << "\t\t" << num1 << " - " << num2 << " = " << subtraction(num1, num2) << endl;
            break;
        case 3:
            cout << "\t\t" << num1 << " / " << num2 << " = " << division(num1, num2) << endl;
            break;
        case 4:
            cout << "\t\t" << num1 << " * " << num2 << " = " << multiplication(num1, num2) << endl;
            break;

        default:
            cout << "\t\t"
                 << "Sorry! wrong Input " << endl;
            break;
        }

        cout << "\t\t"
             << "Do you want to continue (y/n)?" << endl;
        cout << "\t\t";
        cin >> option;
    }
    if (option == 'n')
    {
        cout << "\n\t\t"
             << "Thank You!" << endl;
    }
    return 0;
}