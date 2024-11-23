#include <iostream>

using namespace std;

// InputBuffer struct to manage input
struct InputBuffer
{
  string buffer;
};

// Function to create a new InputBuffer
InputBuffer *new_input_buffer() { return new InputBuffer(); }

// Function to print the prompt
void print_prompt() { cout << "db > "; }

// Function to read input into the InputBuffer
void read_input(InputBuffer &input_buffer)
{
  string input_line;
  if (!getline(cin, input_line))
  {
    cerr << "Error reading input" << endl;
    exit(1);
  }
  input_buffer.buffer = input_line;
}

// Main function
int main()
{
  InputBuffer *input_buffer = new_input_buffer();

  while (true)
  {
    print_prompt();
    read_input(*input_buffer);

    if (input_buffer->buffer == ".exit")
    {
      cout << "Exiting..." << endl;
      break;
    }
    else
      cout << "Unrecognized command '" << input_buffer->buffer << "'." << endl;
  }

  return 0;
}
