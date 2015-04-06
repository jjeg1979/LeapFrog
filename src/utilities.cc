#include <utilities.hh>

#include <iostream>
#include <fstream>


namespace utilities
{
  bool file_exists(const std::string & str)
  {
    std::ifstream fs(str);
    if (!fs.is_open()) {
      std::cerr << "ERROR: File " << str << " could not be found" << std::endl;
      return false;
    }

    return true;
  }

  bool preconditions (int argc, char ** argv)
  {
    if (argc != 2) {
      std::cerr << "There should be 1 argument provided only" << std::endl;
      return false;
    }

    std::string fileName { argv[1] };
    return file_exists( fileName );
  }

  void clean_line (std::string & line)
  {
    while (line.back() == '\r') line.pop_back();
  }
}
