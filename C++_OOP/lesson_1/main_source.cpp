#include <iostream>
#include <math.h>
#include <cstdint>

/*
* ==================================================================================================
* --------------------------------------------Variables---------------------------------------------
* ==================================================================================================
*/
enum RgbaColors{e_RgbaRed = 40, e_RgbaGreen = 50, e_RgbaBlue = 60, e_RgbaAlpha = 70};
double d_PowerNumber{ 13 };
double d_PowerExponent{ 0.354 };
uint8_t u_AlphaDefault = 255;
enum StackConditions{e_ArrSize = 10, e_Null = 0};
enum ArrayVariables{e_ArrOne = 3, e_ArrTwo = 7, e_ArrThree = 5};

/*
* ==================================================================================================
* ----------------------------------------------Task 1----------------------------------------------
* ==================================================================================================
*/
class Power // this is class for task 1, here we are "raise to the POWER!"
{
public:
	void setExpo(double Number, double Power)
	{
		d_Number = Number;
		d_Power = Power;
	}
	void calculateExpo()
	{
		d_Result = pow(d_Number, d_Power);
	}
	void printExpo()
	{
		std::cout << "The result is " << d_Result << std::endl;
	}
private:
	double d_Number{};
	double d_Power{};
	double d_Result{};
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
		for (size_t Index = e_Null; Index < e_ArrSize; Index++)
		{
			i_Array[Index] = e_Null;
		}
		i_ArrIndex = 0;
	}
	bool push(int Input)
	{
		if (i_ArrIndex == e_ArrSize)
		{
			return false;
		}
		else
		{
			i_Array[i_ArrIndex] = Input;
			i_ArrIndex++;
			return true;
		}
	}
	int pop()
	{
		if (i_ArrIndex == e_Null)
		{
			std::cout << "Sorry, the array is null" << std::endl;
			return e_Null;
		}
		else
		{
			i_ArrIndex--;
			return i_Array[i_ArrIndex];
		}
	}
	void print()
	{
		if (i_ArrIndex == e_Null)
		{
			std::cout << "[ " << " ]" << std::endl;
		}
		else
		{
			for (int Index = 0; Index < i_ArrIndex; Index++)
			{
				std::cout << "[ " << i_Array[Index] << " ]";
			}
			std::cout << std::endl;
		}
	}
private:
	int i_Array[e_ArrSize]{};
	int i_ArrIndex{};
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
	MyExpo.setExpo(d_PowerNumber, d_PowerExponent);
	MyExpo.calculateExpo();
	MyExpo.printExpo();
	std::cout << std::endl;
}

void Task2()
{
	std::cout << "------------------Task 2------------------" << std::endl;
	RGBA rgba(e_RgbaRed, e_RgbaGreen, e_RgbaBlue, e_RgbaAlpha);
	rgba.printRGBA();
	std::cout << std::endl;
}

void Task3()
{
	std::cout << "------------------Task 3------------------" << std::endl;
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(e_ArrOne);
	stack.push(e_ArrTwo);
	stack.push(e_ArrThree);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
}