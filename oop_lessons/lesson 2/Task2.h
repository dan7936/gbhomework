#pragma once

/*
* =================================================================
* ------------------------Class for Task 2-------------------------
* =================================================================
*/
class Fruit // Parent class for TASK 2
{
public:
	Fruit() = default;
	Fruit(std::string const name, std::string const color) : m_name(name), m_color(color) {}
	const std::string getName()
	{
		return m_name;
	}
	const std::string getColor()
	{
		return m_color;
	}
protected:
	std::string m_name{};
	std::string m_color{};
};

class Apple : public Fruit // heritage class for TASK 2
{
public:
	Apple(const std::string color) : Fruit("apple", color) {}
protected:

};

class Banana : public Fruit // heritage class for TASK 2
{
public:
	Banana() : Fruit("banana", "yellow") {}
protected:

};

class GrannySmith : public Apple // heritage^2 class for TASK 2
{
public:
	GrannySmith() : Apple("green") {}
protected:

};