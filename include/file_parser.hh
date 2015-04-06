#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <vector>

namespace parsing
{
  class FileParser
  {
  public:
    FileParser();

    void process_line (const std::string & line);

  private:
    enum class InnerState { version, initialization, headers_definition, headers_used, data };
    InnerState state;// = InnerState::version;
    unsigned int currentLine;// {0};
    unsigned int lineInCurrentState;// {0};
    std::string lastLine;// {};

    template< typename T >
    std::vector< T > get_values_from_line( const std::string & line );
  };
}


#endif
