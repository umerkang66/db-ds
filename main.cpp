#include <iostream>
#include "db-engine/db-engine.hpp"

using namespace std;

int main()
{
  DbEngine evaluator;
  string input;
  cout << "Start to write your Queries. To exit, type (exit)" << endl;

  while (true)
  {
    cout << "> ";
    getline(cin, input);

    if (input == "exit")
    {
      break;
    }

    try
    {
      evaluator.evaluate(input);
    }
    catch (const exception &e)
    {
      cerr << "Error: " << e.what() << endl;
    }
  }

  return 0;
}
