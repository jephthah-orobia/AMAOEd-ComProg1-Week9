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

void printDigits(short n){
  // only shorts from 10 to 99!
  cout << "The digits of " << n << " are: \033[32m"
    << n / 10 << " " << n % 10 << "\033[0m" << endl;
}

int main()
{
  short n;
  char todoNext;

  while(true){
    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\033[031mInvalid number. Please try again.\033[0m" << endl;
    }
    cout << "Enter a whole number from 10 to 99: ";
    cin >> noskipws >> n;
    if(!cin.fail() && n >= 10 && n <= 99){
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    } else {
      if(!cin.fail()) cin.setstate(std::ios::failbit);
    }
  }

  cout << endl << "\t";
  printDigits(n);

  cout << endl << "Enter \033[1m\033[33mr\033[0m or \033[1m\033[33mR\033[0m to restart app. Otherwise, app will exit: ";
  cin >> todoNext;

  if(todoNext == 'r' || todoNext == 'R'){
    system("clear");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return main();
  } else
    return EXIT_SUCCESS;
}
