#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>


namespace utilities
{
  bool file_exists(const std::string & str);
  bool preconditions (int argc, char ** argv);
  // cleans the line of end of line return carriages
  void clean_line(std::string & line); 
}

#endif
