#include <utilities.hh>

#include <iostream>
#include <fstream>


namespace utilities
{
  bool file_exists(const std::string & str)
  {
    std::ifstream fs(str);
    if (!fs.is_open()) {
      //std::cerr << "[file_exists] File " << str << " could not be found" << std::endl;
      return false;
    }

    return true;
  }

  int preconditions (int argc, char ** argv)
  {
    int retVal = -1;
    if ((argc != 3) && (argc != 4)) {
      std::cerr << "Incorrect amount of arguments provided" << std::endl;
      return retVal;
    }

    std::string option { argv[1] };
    std::cerr << "option: "<< option << std::endl;
    if (option == std::string( "-i" )) {
      std::string fileName { argv[2] };
      if (file_exists( fileName )) 
	retVal = 0;
    }
    else if (option == std::string( "-o" )) {
      std::string fileName { argv[2] };
      if (file_exists( fileName )) 
	std::cerr << "File " << fileName << " will be overwriten" << std::endl;
      retVal = 1;
    }
    else
      std::cerr << "ERROR: Unknown option" << std::endl;

    return retVal;
  }

  void clean_line (std::string & line)
  {
    while (line.back() == '\r') line.pop_back();
  }
}
