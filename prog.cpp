#include "std_lib_facilities.h"

int main( int argc, char ** argv )
{
	// Number of output arguments
	cout << "Number of input arguments: " << argc << '\n';
	// Read name of program and arguments
	for( int i = 0; i < argc; i++ )
	{
		cout << "Value of argv[ " << i << " ]: " << argv[ i ] << '\n';
		cout << "With pointers arithmetics: \n";
		
		int j = 0;
		
		while ( *( argv[ i ] + j * sizeof( char ) ) != '\0' )
		{
			cout << *( argv[ i ] + j * sizeof( char ) );
			j++;
		}
		cout << '\n';
		
					
	}
}
