#ifndef WRITERS_H
#define WRITERS_H

#include <string>

namespace generating
{
  void input_files_generator(const std::string & outputFile, unsigned int numberOfLines = 1,
			     const std::string & templateFile = "");
}

#endif
