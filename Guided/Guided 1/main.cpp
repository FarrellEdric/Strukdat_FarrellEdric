#include <iostream>
using namespace std;

//main program

int main ()
{
    char op;
float num1, num2;
// It allows user to enter operator i.e. +, -, *, /
cout << "Masukan Operator: ";
cin >> op;
// It allow user to enter the operands
cout << "Masukan angka pertama: ";
cin >> num1;
cout << "Masukan  angka kedua: "; 
cin >> num2;
// Switch statement begins
switch (op)
{
// If user enter +
case '+':
cout << num1 + num2;
break;
// If user enter -
case '-':
cout << num1 - num2;
break;
// If user enter *
case '*':
cout << num1 * num2;
break;
// If user enter /
case '/':
cout << num1 / num2;
break;
// If the operator is other than +, -, * or /,
// error message will display
default:
cout << "Error! operator is not correct";
} // switch statement ends
return 0;
}
