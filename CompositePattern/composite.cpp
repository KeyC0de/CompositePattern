#include <iostream>
#include "composite.h"


// a common interface for all the leaves as well as the Composite
Leaf1::Leaf1( int value )
	:
	m_value( value )
{}

void Leaf1::traverse()
{
	std::cout << L"Leaf1:"
		<< m_value << ' ';
}

Leaf2::Leaf2( int value )
	:
	m_value( value )
{}

void Leaf2::traverse()
{
	std::cout << "Leaf2:"
		<< m_value << ' ';
}

Leaf3::Leaf3( int value )
	:
	m_value( value )
{}

void Leaf3::traverse()
{
	std::cout << "Leaf3:"
		<< m_value << ' ';
}


Composite::Composite( Composite&& rhs ) noexcept
	:
	m_children{std::move( rhs.m_children )}
{}

Composite& Composite::operator=( Composite&& rhs ) noexcept
{
	if ( this != &rhs )
	{
		Composite temp( std::move( rhs ) );
		std::swap( this->m_children, temp.m_children );
	}
	return *this;
}

void Composite::add( std::unique_ptr<IComponent> element )
{
	m_children.emplace_back( std::move( element ) );
}

void Composite::traverse()
{
	for ( auto& i : m_children )
	{
		// Use polymorphism to delegate to children
		i->traverse();
	}
}