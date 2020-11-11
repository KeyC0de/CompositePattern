#include <iostream>
#include <memory>
#include <random>
#include "composite.h"


int main()
{
	Composite compositeBoss[5];

	// add leaves
	for ( int i = 0; i < 4; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			compositeBoss[i].add( std::make_unique<Leaf1>( i * 3 + j ) );
			compositeBoss[i].add( std::make_unique<Leaf2>( i * 3 * 2 + j + i) );
		}
	}

	std::random_device device;
	std::default_random_engine eng{ device() };
	std::uniform_int_distribution<int> distrInt( INT_MIN, INT_MAX );
	int randInt;

	// add another composite
	auto compositeSlave = std::make_unique<Composite>();
	for ( int i = 0; i < 4; ++i )
	{
		randInt = distrInt( eng );
		compositeSlave->add( std::make_unique<Leaf3>( randInt ) );
	}
	compositeBoss[4].add( std::move( compositeSlave ) );

	// operate on them
	for ( auto& elem : compositeBoss )
	{
		elem.traverse();
		std::wcout << L'\n';
	}

	return 0;
}
