/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: AMAOEd ITE7101 Week 9 Laboratory Exercise
 * @app desc: console app implementation of task from course.
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "_pause.h"

using namespace std;

int nthFibonacci(unsigned int n)
{
  if (n < 2)
    return 1;
  else
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

void printNFibonacciNumbers(unsigned int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << nthFibonacci(i);
    if (i != n - 1)
      cout << ", ";
  }
}

int main()
{
  char todoNext;
  unsigned int n;
  cout << "\033[1m\033[34m*** Fibonacci Generator ***\033[0m" << endl;
  while (true)
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\033[031mInvalid number. Please try again. [hit: integer greater than zero]\033[0m" << endl;
    }
    cout << "Enter desired number of terms to generate: ";
    cin >> n;
    if (!cin.fail() && n > 0)
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }
    else if (!cin.fail())
    {
      cin.setstate(std::ios::failbit);
    }
  }

  cout << endl << "\033[1m\033[032m";
  printNFibonacciNumbers(n);
  cout << endl << "\033[0m";

  cout << endl
       << "Enter \033[1m\033[33mr\033[0m or \033[1m\033[33mR\033[0m to restart app. Otherwise, app will exit: ";
  cin >> todoNext;

  if (todoNext == 'r' || todoNext == 'R')
  {
    system("clear");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return main();
  }
  else
    return EXIT_SUCCESS;
}
