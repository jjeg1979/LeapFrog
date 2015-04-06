#include <utilities.hh>
#include <readers.hh>

#include <string>
#include <iostream>


int main (int argc, char ** argv)
{
  if (utilities::preconditions(argc, argv))
    {
      parsing::serial_reader(argv[1]);
    }

  std::cout << *argv << " done!" << std::endl;
}
