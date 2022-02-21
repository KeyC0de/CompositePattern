#include <iostream>
#include "composite.h"


Leaf1::Leaf1( int value )
	:
	m_value(value)
{

}

void Leaf1::traverse()
{
	std::cout << "Leaf1:"
		<< m_value
		<< ' ';
}

Leaf2::Leaf2( int value )
	:
	m_value(value)
{

}

void Leaf2::traverse()
{
	std::cout << "Leaf2:"
		<< m_value
		<< ' ';
}

Leaf3::Leaf3( int value )
	:
	m_value(value)
{

}

void Leaf3::traverse()
{
	std::cout << "Leaf3:"
		<< m_value
		<< ' ';
}


Composite::Composite( Composite&& rhs ) noexcept
	:
	m_pChildren{std::move( rhs.m_pChildren )}
{

}

Composite& Composite::operator=( Composite&& rhs ) noexcept
{
	std::swap( this->m_pChildren, rhs.m_pChildren );
	return *this;
}

void Composite::add( std::unique_ptr<IComponent> element )
{
	m_pChildren.emplace_back( std::move( element ) );
}

void Composite::traverse()
{
	std::cout << "{\n";
	for ( auto& i : m_pChildren )
	{
		i->traverse();
	}
	std::cout << "\n}";
}