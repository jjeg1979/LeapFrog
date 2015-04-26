#include <writers.hh>

#include <file_generator.hh>

#include <iostream>
#include <chrono>


namespace generating
{
  void input_files_generator(const std::string & outputFile, unsigned int numberOfLines,
			     const std::string & templateFile)
  {
    // get initial time
    auto t0 = std::chrono::high_resolution_clock::now();
  
    // generate file
    FileGenerator fg (outputFile, numberOfLines, templateFile);
    auto res = fg.create_file();
    
    std::cout << "Output file " << outputFile << " generated " << ((res) ? "" : "UN") << "succesfully with " <<
      numberOfLines << " random line" << ((numberOfLines > 1) ? "s" : "") << std::endl;

    // get final time
    auto t1 =  std::chrono::high_resolution_clock::now();
  
    // print elapsed time
    std::cerr << "[input_files_generator] " << std::chrono::duration_cast< std::chrono::microseconds >(t1-t0).count() / 1000.0
	      << " milliseconds passed" << std::endl;
  }
}
