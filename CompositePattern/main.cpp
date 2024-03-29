#include <iostream>
#include <random>
#include "composite.h"
#if defined _DEBUG && !defined NDEBUG
#	pragma comment( lib, "C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld.lib" )
#	include <C:/Program Files (x86)/Visual Leak Detector/include/vld.h>
#endif


int main()
{
	std::random_device device;
	std::default_random_engine rneng{device()};
	std::uniform_int_distribution<int> distrInt( INT_MIN, INT_MAX );
	int randInt;

	Composite composites[5];

	// add leaves
	for ( int i = 0; i < 4; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			composites[i].add( std::make_unique<Leaf1>( i * 3 + j ) );
			composites[i].add( std::make_unique<Leaf2>( i * 3 * 2 + j + i) );
		}
	}
	
	// create another composite and add leaves to it
	auto compositeChild = std::make_unique<Composite>();
	for ( int i = 0; i < 4; ++i )
	{
		randInt = distrInt( rneng );
		compositeChild->add( std::make_unique<Leaf3>( randInt ) );
	}
	// make the composite a child of composite[4]
	composites[4].add( std::move( compositeChild ) );

	// traverse the hierarchy
	for ( auto& elem : composites )
	{
		elem.traverse();
		std::cout << '\n';
	}

#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}