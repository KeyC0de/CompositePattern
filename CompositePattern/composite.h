#pragma once

#include <vector>

// a common interface for all the leaves as well as the Composite
class IComponent
{
public:
	virtual void traverse() = 0;
};


class Leaf1
	: public IComponent
{
	int m_value;
public:
	Leaf1( int value )
		:
		m_value( value )
	{}

	void traverse() override
	{
		std::wcout << L"Leaf1:"
			<< m_value << L' ';
	}
};

class Leaf2
	: public IComponent
{
	int m_value;
public:
	Leaf2( int value )
		:
		m_value( value )
	{}

	void traverse() override
	{
		std::wcout << L"Leaf2:"
			<< m_value << L' ';
	}
};

class Leaf3
	: public IComponent
{
	int m_value;
public:
	Leaf3( int value )
		:
		m_value( value )
	{}

	void traverse() override
	{
		std::wcout << L"Leaf3:"
			<< m_value << L' ';
	}
};


class Composite
	: public IComponent
{
	std::vector<std::unique_ptr<IComponent>> m_children;
public:
	Composite() = default;
	Composite( const Composite& rhs ) = default;
	Composite& operator=( const Composite& rhs ) = delete;
	Composite( Composite&& rhs ) noexcept;
	Composite& operator=( Composite&& rhs ) noexcept;
	// supply unique_ptr s of IComponents here
	void add( std::unique_ptr<IComponent> element );
	void traverse() override;
};

Composite::Composite( Composite&& rhs ) noexcept
	:
	m_children{ std::move( rhs.m_children ) }
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