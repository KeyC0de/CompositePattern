#pragma once

#include <vector>


// a common interface for all the leaves as well as the Composite(s)
class IComponent
{
public:
	virtual void traverse() = 0;
	virtual ~IComponent() = default;
};


class Leaf1
	: public IComponent
{
	int m_value;
public:
	Leaf1( int value );

	void traverse() override;
};

class Leaf2
	: public IComponent
{
	int m_value;
public:
	Leaf2( int value );

	void traverse() override;
};

class Leaf3
	: public IComponent
{
	int m_value;
public:
	Leaf3( int value );

	void traverse() override;
};


class Composite
	: public IComponent
{
	std::vector<std::unique_ptr<IComponent>> m_pChildren;
public:
	Composite() = default;
	virtual ~Composite() = default;
	Composite( const Composite& rhs ) = default;
	Composite& operator=( const Composite& rhs ) = delete;
	Composite( Composite&& rhs ) noexcept;
	Composite& operator=( Composite&& rhs ) noexcept;

	void add( std::unique_ptr<IComponent> element );
	void traverse() override;
};