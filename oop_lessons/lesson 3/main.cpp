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
	Circle(double pi, double r) : m_pi(pi), m_r(r) {}
	void area() override
	{
		std::cout << "Area of circle is: " << m_pi << "*(" << m_r << "*" << m_r << ")=" << m_pi * (m_r * m_r) << std::endl;
	}
private:
	const double m_pi{};
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
	int getResultNum()
	{
		return m_numerator;
	}
	int getResultDem()
	{
		return m_denominator;
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
		if (m_position == true)
		{
			m_position = false;
		}
		else
		{
			m_position = true;
		}
	}
	int getValue()
	{
		return m_value;
	}
protected:
	bool m_position{};
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
	Task1();
	Task2();
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
	paralelogram.area();
	Circle circle(3.14, 10);
	circle.area();
	Rectangle rectangle(20, 40);
	rectangle.area();
	Square square(20);
	square.area();
	Rhombus rhombus(14, 24);
	rhombus.area();
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
	std::cout << "Sum of two fraction numbers is " << sum.getResultNum() << "/" << sum.getResultDem() << std::endl;
	Fraction dif = number1 - number2;
	std::cout << "Difference of two fraction numbers is " << dif.getResultNum() << "/" << dif.getResultDem() << std::endl;
	Fraction mul = number1 * number2;
	std::cout << "Multiply of two fraction numbers is " << mul.getResultNum() << "/" << mul.getResultDem() << std::endl;
	Fraction quo = number1 / number2;
	std::cout << "Quotient of two fraction numbers is " << quo.getResultNum() << "/" << quo.getResultDem() << std::endl;
	std::cout << "Reverse sign of number is " << -number2.getResultNum() << "/" << number2.getResultDem() << std::endl;
}