#include <file_generator.hh>

#include <iostream>


namespace generating
{
  FileGenerator::FileGenerator( const std::string & outputFile, unsigned int numberOfLines, const std::string & templateFile):
    numberOfLinesToGenerate {numberOfLines}, outputFilePath {outputFile}, templateFilePath {templateFile}
  {}

  bool FileGenerator::create_file ()
  {
    bool res = false;
    // read the header => returns the header and the number of columns per row

    // write the header in the file

    // for every row
    //    generate the row with the number of columns => returns the string
    //    write the line

    std::cerr << "Creating the file with parameters: " << outputFilePath << ", " << numberOfLinesToGenerate << templateFilePath <<std::endl;

    /* MOCK CREATION */
    std::cerr << "[FileGenerator::create_file] method NOT implemented yet." << std::endl;

    return res;
  }
}
