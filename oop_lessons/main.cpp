#include <iostream>
#include <math.h>
#include <cstdint>

/*
* ==================================================================================================
* --------------------------------------------Variables---------------------------------------------
* ==================================================================================================
*/
enum RgbaColors
{
	e_rgbaRed = 40, 
	e_rgbaGreen = 50, 
	e_rgbaBlue = 60, 
	e_rgbaAlpha = 70
};
double d_powerNumber{ 13 };
double d_powerExponent{ 0.354 };
uint8_t u_alphaDefault = 255;
enum StackConditions
{
	e_arrSize = 10, 
	e_null = 0
};
enum ArrayVariables
{
	e_arrOne = 3, 
	e_arrTwo = 7, 
	e_arrThree = 5
};

/*
* ==================================================================================================
* ----------------------------------------------Task 1----------------------------------------------
* ==================================================================================================
*/
class Power // this is class for task 1, here we are "raise to the POWER!"
{
public:
	void setNumb(double number)
	{
		d_number = number;
	}
	void setPow(double power)
	{
		d_power = power;
	}
	void calculateExpo()
	{
		d_result = pow(d_number, d_power);
	}
	void printExpo()
	{
		std::cout << "The result is " << d_result << std::endl;
	}
private:
	double d_number{};
	double d_power{};
	double d_result{};
};

/*
* ==================================================================================================
* ----------------------------------------------Task 2----------------------------------------------
* ==================================================================================================
*/
class RGBA // this is class for task 2, I don't really know why we used this type of variables
{
public:
	RGBA(int red, int green, int blue, int alpha) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
	void printRGBA()
	{
		std::cout << m_red << " " << m_green << " " << m_blue << " " << m_alpha << std::endl;
		std::cout << static_cast<int>(m_red) << " " << static_cast<int>(m_green) << " " << static_cast<int>(m_blue) << " " << static_cast<int>(m_alpha) << std::endl;
		std::cout << (+m_red) << " " << (+m_green) << " " << (+m_blue) << " " << (+m_alpha) << std::endl;
	}
private:
	uint8_t m_red{};
	uint8_t m_green{};
	uint8_t m_blue{};
	uint8_t m_alpha{ u_AlphaDefault };
};

/*
* ==================================================================================================
* ----------------------------------------------Task 3----------------------------------------------
* ==================================================================================================
*/
class Stack
{
public:
	void reset()
	{
		for (size_t index = e_null; index < e_arrSize; index++)
		{
			i_array[index] = e_null;
		}
		i_arrIndex = e_null;
	}
	bool push(int Input)
	{
		if (i_arrIndex == e_arrSize)
		{
			return false;
		}
		else
		{
			i_array[i_arrIndex] = Input;
			i_arrIndex++;
			return true;
		}
	}
	int pop()
	{
		if (i_arrIndex == e_null)
		{
			std::cout << "Sorry, the array is null" << std::endl;
			return e_null;
		}
		else
		{
			i_arrIndex--;
			return i_array[i_arrIndex];
		}
	}
	void print()
	{
		if (i_arrIndex == e_null)
		{
			std::cout << "[ " << " ]" << std::endl;
		}
		else
		{
			for (int index = 0; index < i_arrIndex; index++)
			{
				std::cout << "[ " << i_array[index] << " ]";
			}
			std::cout << std::endl;
		}
	}
private:
	int i_array[e_arrSize]{};
	int i_arrIndex{};
};

/*
* ==================================================================================================
* ---------------------------------------Functions prototypes---------------------------------------
* ==================================================================================================
*/
void Task1();
void Task2();
void Task3();

/*
* ==================================================================================================
* -------------------------------------------!!! MAIN !!!-------------------------------------------
* ==================================================================================================
*/
int main()
{
	Task1();
	Task2();
	Task3();
	return 0;
}

/*
* ==================================================================================================
* ---------------------------------------------Functions--------------------------------------------
* ==================================================================================================
*/
void Task1()
{
	std::cout << "------------------Task 1------------------" << std::endl;
	Power MyExpo;
	MyExpo.setNumb(d_powerNumber);
	MyExpo.setPow(d_powerExponent);
	MyExpo.calculateExpo();
	MyExpo.printExpo();
	std::cout << std::endl;
}

void Task2()
{
	std::cout << "------------------Task 2------------------" << std::endl;
	RGBA rgba(e_rgbaRed, e_rgbaGreen, e_rgbaBlue, e_rgbaAlpha);
	rgba.printRGBA();
	std::cout << std::endl;
}

void Task3()
{
	std::cout << "------------------Task 3------------------" << std::endl;
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(e_arrOne);
	stack.push(e_arrTwo);
	stack.push(e_arrThree);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
}