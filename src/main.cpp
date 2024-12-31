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

void printNFibonacciNumbers(short n, unsigned int i, unsigned long long prev0, unsigned long long prev1)
{
  if(i < n){
    cout << prev1;
    if (i != n - 1)
      cout << ", ";
    return printNFibonacciNumbers(n, i+1, prev1, prev0 + prev1);
  }
}

int main()
{
  char todoNext;
  short n;
  cout << "\033[1m\033[34m*** Fibonacci Generator ***\033[0m" << endl;
  while (true)
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\033[031mInvalid number or exceeds limitation. Please try again." << endl;
      cout << "[hit: integer greater than zero but less than 94. ";
      cout << "Due to computing limit, accuracy falters after the 93rd term]\033[0m"<< endl;
    }
    cout << "Enter desired number of terms to generate: ";
    cin >> n;
    if (!cin.fail() && n > 0 && n < 94)
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
  printNFibonacciNumbers(n, 0, 0, 1);
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
