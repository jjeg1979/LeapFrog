#include <readers.hh>

#include <utilities.hh>
#include <file_parser.hh>

#include <iostream>
#include <fstream>
#include <chrono>


namespace parsing
{
  void serial_reader(const std::string & fileName)
  {
    // get initial time
    auto t0 = std::chrono::high_resolution_clock::now();
  
    // process file
    std::ifstream fs( fileName );
    parsing::FileParser fp;
    for(std::string line; std::getline( fs, line );) {
      // clean the line
      utilities::clean_line( line );
      // process line
      fp.process_line( line );
    }
    // get final time
    auto t1 =  std::chrono::high_resolution_clock::now();
  
    // print elapsed time
    std::cout << std::chrono::duration_cast< std::chrono::microseconds >(t1-t0).count() / 1000.0
	      << " milliseconds passed" << std::endl;
  }
}
