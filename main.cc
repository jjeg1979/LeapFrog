#include <utilities.hh>
#include <readers.hh>
#include <writers.hh>

#include <string>
#include <iostream>
#include <sstream>


int main (int argc, char ** argv)
{
  switch (utilities::preconditions(argc, argv)) {
  case 0:
    parsing::serial_reader(argv[2]);
    break;
  case 1: 
    {
      //generate outputFile
      std::stringstream ss;
      ss << std::string( argv[3] );
      unsigned int num { 0 };
      ss >> num;
    
      generating::input_files_generator( argv[2], num ); 
      break;
    }
  default:
    std::cout << "Valid options to run the program are:\n -i inputFile\n -o outPutFile numberOfLinesGenerated" 
	      << std::endl;
    break;
  }

  std::cout << *argv << " done!" << std::endl;
}
