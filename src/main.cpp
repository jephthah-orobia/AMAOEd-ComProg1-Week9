/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: AMAOEd ITE7101 Week 9 Laboratory Exercise #8
 * @app desc: console app implementation of task from course.
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "_pause.h"

using namespace std;

void printDivision(int a, int b)
{
  cout << a << " divided by " << b << " is \033[32m" << a / b << "\033[0m";
}

int main()
{
  int n[6], i = 0;
  while (i < 6)
  {
    cout << "Enter number[" << i + 1 << "]: ";
    cin >> noskipws >> n[i];
    if (!cin.fail() && n[i] != 0)
    {
      i++;
    }
    else
    {
      cout << "\033[31mInvalid number, try again. [Hint: any integer except zero]\033[0m" << endl;
      cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cout << endl << "The results: " << endl;

  for (int i = 0; i < 3; i++)
  {
    cout << "\t";
    printDivision(n[i * 2], n[i * 2 + 1]);
    cout << endl;
  }

  cout << endl;

  _pause();
  return EXIT_SUCCESS;
}
