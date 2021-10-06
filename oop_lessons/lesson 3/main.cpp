#include <iostream>

/*
* ====================================================================
* --------------------------Func prototypes---------------------------
* ====================================================================
*/
void Task1();
void Task2();
void Task3();

/*
* ====================================================================
* ---------------------------Task 1 classes---------------------------
* ====================================================================
*/
class Figure
{
public:
	Figure() = default;
	virtual void area() = 0;
protected:

};

class Parallelogram : public Figure
{
public:
	Parallelogram() = default;
	Parallelogram(int a, int h) : m_a(a), m_h(h) {}
	void area() override
	{
		std::cout << "Area of parallelogram is: " << m_a << "*" << m_h << "=" << m_a * m_h << std::endl;
	}
protected:
	int m_a{};
	int m_h{};
};

class Circle : public Figure
{
public:
	Circle(double r) : m_r(r) {}
	void area() override
	{
		std::cout << "Area of circle is: " << m_pi << "*(" << m_r << "*" << m_r << ")=" << m_pi * (m_r * m_r) << std::endl;
	}
private:
	const double m_pi{3.14};
	double m_r{};
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int a, int b) : Parallelogram(a, 0), m_b(b) {}
	void area() override
	{
		std::cout << "Area of rectangle is: " << m_a << "*" << m_b << "=" << m_a * m_b << std::endl;
	}
private:
	int m_b{};
};

class Square : public Parallelogram
{
public:
	Square(int a) : Parallelogram(a, 0) {}
	void area() override
	{
		std::cout << "Area of square is: " << m_a << "*" << m_a << "=" << m_a * m_a << std::endl;
	}
private:

};

class Rhombus : public Parallelogram
{
public:
	Rhombus(int a, int h) : Parallelogram(a, h) {}
	void area() override
	{
		std::cout << "Area of rhombus is: " << m_a << "*" << m_h << "=" << m_a * m_h << std::endl;
	}
private:

};

/*
* ====================================================================
* ---------------------------Task 2 classes---------------------------
* ====================================================================
*/
class Car
{
public:
	Car() = default;
	Car(std::string const company, std::string const model) : m_company(company), m_model(model) 
	{
		std::cout << "(GranParent construct) This car's name is " << model << " and it was made by - " << company << std::endl;
	}
protected:
	std::string m_company{};
	std::string m_model{};
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar() = default;
	PassengerCar(std::string const company, std::string const model) : Car(company, model) 
	{
		std::cout << "(Father construct) This Passenger car's name is " << model << " and it was made by - " << company << std::endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus() = default;
	Bus(std::string const company, std::string const model) : Car(company, model) 
	{
		std::cout << "(Mother construct) This Bus's name is " << model << " and it was made by - " << company << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string const company, std::string const model) : Car(company, model) 
	{
		std::cout << "(Child construct) This Minivan's name is " << model << " and it was made by - " << company << std::endl;
	}
};

/*
* ====================================================================
* ---------------------------Task 3 classes---------------------------числитель и знаменатель
* ====================================================================
*/
class Fraction
{
public:
	Fraction(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			std::cout << "Error denominator is zero!" << std::endl;
		}
		else
		{
			m_numerator = numerator;
			m_denominator = denominator;
		}
	}
	friend Fraction operator+ (const Fraction& num1, const Fraction& num2);
	friend Fraction operator- (const Fraction& num1, const Fraction& num2);
	friend Fraction operator* (const Fraction& num1, const Fraction& num2);
	friend Fraction operator/ (const Fraction& num1, const Fraction& num2);
	Fraction operator- ()
	{
		return Fraction(-m_numerator, m_denominator);
	}
	friend bool operator< (const Fraction& num1, const Fraction& num2);
	friend bool operator> (const Fraction& num1, const Fraction& num2);
	friend bool operator!= (const Fraction& num1, const Fraction& num2);
	friend bool operator== (const Fraction& num1, const Fraction& num2);
	friend bool operator<= (const Fraction& num1, const Fraction& num2);
	friend bool operator>= (const Fraction& num1, const Fraction& num2);
	int getResultNum()
	{
		return m_numerator;
	}
	int getResultDem()
	{
		return m_denominator;
	}
	void printResult()
	{
		std::cout << getResultNum() << "/" << getResultDem();
	}
private:
	int m_numerator{};
	int m_denominator{};
};

Fraction operator+ (const Fraction &num1, const Fraction &num2)
{
	return Fraction(num1.m_numerator * num2.m_denominator + num2.m_numerator*num1.m_denominator, num1.m_denominator*num2.m_denominator); 
}

Fraction operator- (const Fraction& num1, const Fraction& num2)
{
	return Fraction(num1.m_numerator * num2.m_denominator - num2.m_numerator * num1.m_denominator, num1.m_denominator * num2.m_denominator);
}

Fraction operator* (const Fraction& num1, const Fraction& num2)
{
	return Fraction(num1.m_numerator * num2.m_numerator, num1.m_denominator * num2.m_denominator);
}

Fraction operator/ (const Fraction& num1, const Fraction& num2)
{
	return Fraction(num1.m_numerator * num2.m_denominator, num1.m_denominator * num2.m_numerator);
}

bool operator< (const Fraction& num1, const Fraction& num2)
{
	return (num1.m_numerator * num2.m_denominator < num2.m_numerator * num1.m_denominator);
}

bool operator> (const Fraction& num1, const Fraction& num2)
{
	return (num1.m_numerator * num2.m_denominator > num2.m_numerator * num1.m_denominator);
}

bool operator== (const Fraction& num1, const Fraction& num2)
{
	return (num1.m_numerator * num2.m_denominator == num2.m_numerator * num1.m_denominator);
}

bool operator!= (const Fraction& num1, const Fraction& num2)
{
	return !(num1 == num2);
}

bool operator<= (const Fraction& num1, const Fraction& num2)
{
	return (num1 == num2 || num1 < num2);
}

bool operator>= (const Fraction& num1, const Fraction& num2)
{
	return (num1 == num2 || num1 > num2);
}

/*
* ====================================================================
* ---------------------------Task 4 classes---------------------------
* ====================================================================
*/
class Card
{
public:
	void flip()
	{
		if (!m_face_up)
		{
			m_face_up = true;
		}
		else
		{
			m_face_up = false;
		}
	}
	int getValue()
	{
		return m_value;
	}
protected:
	bool m_face_up{};
	enum CardParam
	{
		m_suit,
		m_value
	};
};

/*
* ====================================================================
* -----------------------------!!!MAIN!!!-----------------------------
* ====================================================================
*/
int main()
{
	//Task1();
	//Task2();
	Task3();
	return 0;
}

/*
* ====================================================================
* ------------------------------Functions-----------------------------
* ====================================================================
*/
void Task1()
{
	std::cout << "---------------------------Task 1---------------------------" << std::endl;
	Parallelogram paralelogram(10, 20);
	Circle circle(10);
	Rectangle rectangle(20, 40);
	Square square(20);
	Rhombus rhombus(14, 24);
	Figure* figure = &paralelogram;
	figure->area();
	figure = &circle;
	figure->area();
	figure = &rectangle;
	figure->area();
	figure = &square;
	figure->area();
	figure = &rhombus;
	figure->area();
	std::cout << std::endl;
}

void Task2()
{
	std::cout << "---------------------------Task 2---------------------------" << std::endl;
	Car car("KAMAZ", "kamaz-2120");
	PassengerCar passengercar("toyota", "corolla");
	Bus bus("PAZ", "trolley");
	Minivan minivan("subaru", "empreza");
	std::cout << std::endl;
}

void Task3()
{
	std::cout << "---------------------------Task 3---------------------------" << std::endl;
	Fraction number1(4, 6);
	Fraction number2(8, 9);
	Fraction sum = number1 + number2;
	std::cout << "Sum of two fraction numbers is "; 
	sum.printResult();
	std::cout << std::endl;
	Fraction dif = number1 - number2;
	std::cout << "Difference of two fraction numbers is ";
	dif.printResult();
	std::cout << std::endl;
	Fraction mul = number1 * number2;
	std::cout << "Multiply of two fraction numbers is ";
	mul.printResult();
	std::cout << std::endl;
	Fraction quo = number1 / number2;
	std::cout << "Quotient of two fraction numbers is ";
	quo.printResult();
	std::cout << std::endl;
	std::cout << "Reverse sign of number is " << -number2.getResultNum() << "/" << number2.getResultDem() << std::endl;
	if (number1 == number2)
	{
		std::cout << "equal" << std::endl;
	}
	else
	{
		std::cout << "not equal" << std::endl;
	}
	if (number1 != number2)
	{
		std::cout << "not equal" << std::endl;
	}
	else
	{
		std::cout << "equal" << std::endl;
	}
	if (number1 > number2)
	{
		std::cout << "more" << std::endl;
	}
	else
	{
		std::cout << "not more" << std::endl;
	}
	if (number1 < number2)
	{
		std::cout << "less" << std::endl;
	}
	else
	{
		std::cout << "not less" << std::endl;
	}
	if (number1 <= number2)
	{
		std::cout << "less or equal" << std::endl;
	}
	else
	{
		std::cout << "not" << std::endl;
	}
	if (number1 >= number2)
	{
		std::cout << "more or equal" << std::endl;
	}
	else
	{
		std::cout << "not" << std::endl;
	}
}