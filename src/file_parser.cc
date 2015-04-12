#include <file_parser.hh>

#include <cctype>
#include <cstdlib>
#include <type_traits>
#include <typeinfo>

namespace parsing
{
  FileParser::FileParser () :   state {InnerState::version}, currentLine {0}, 
    lineInCurrentState {0}, lastLine {}
  {}

  template< typename T >
  std::vector< T > FileParser::get_values_from_line( const std::string & line )
  {
    std::vector< T > ret;
    std::string number {};
    T val {};
    bool isTypeDouble = typeid(T) == typeid(double);
    bool isTypeULong = typeid(T) == typeid(unsigned long);
    
    for(auto c : line) {
      switch(c) {
      default:
	if (std::isdigit(c) || (c == '-'))
	  number += c;
	else if (!number.empty()) {
	  // number found
	  if ( isTypeDouble ) 
	    val = std::stod( number );
	  if ( isTypeULong )
	    val = std::stoul( number );
	  // process it
	  ret.push_back( val );
	  // reset and next one
	  number.clear();
	  T aux{};
	  val = aux;
	}
	break;
      case ',':
	number += ".";
	break;
      }
    }
    return ret;
  }

  void FileParser::process_line (const std::string & line)
  {
    ++currentLine;
    ++lineInCurrentState;

    if( line.empty() && !lastLine.empty()) {
      // state++
      switch(state) {
      case InnerState::version:
	state = InnerState::initialization;
	break;
      case InnerState::initialization:
	state = InnerState::headers_definition;
	break;
      case InnerState::headers_definition:
	state = InnerState::headers_used;
	break;
      case InnerState::headers_used:
	state = InnerState::data;
	break;
      case InnerState::data:
	state = InnerState::version;
	break;
      }

      lineInCurrentState = 0;
    }

    if( state == InnerState::headers_definition && std::isdigit(line.front()) ) {
      state = InnerState::headers_used;
      lineInCurrentState = 1;
    }
    if (state == InnerState::headers_used) {
      switch (lineInCurrentState) { // MAGIC NUMBERS
      case 3:
	state = InnerState::data;
	lineInCurrentState = 0;
	break;
      case 1:
	// reading the IDs (numbers) is enough because the possible columns have already been populated with that info
	auto depthInfoElementsUsed = get_values_from_line< unsigned long >( line );
	/*for (auto cols : depthInfoElementsUsed)
	  std::cout << cols << " $ ";
	  std::cout << std::endl;
	*/break;
      }
    }
    else if (state == InnerState::data) {
      auto values = get_values_from_line< double >( line );
      //for (auto val : values)
      //	  std::cout << val << " $ ";
      //std::cout << std::endl;
    }
    
    lastLine = line;
  }

} //namespace

