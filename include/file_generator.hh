#ifndef FILE_GENERATOR_H
#define FILE_GENERATOR_H

#include <string>

namespace generating
{
  class FileGenerator
  {
  public:
    FileGenerator (const std::string & outputFile, unsigned int numberOfLines = 1, const std::string & templateFile = "");
    bool create_file ();

  private:
    unsigned int numberOfLinesToGenerate;
    const std::string & outputFilePath;
    const std::string & templateFilePath;
  };
}

#endif
