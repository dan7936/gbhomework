#include <iostream>
#include <random>
#include <chrono>

/*
* =============================================================================================
* ---------------------------------- Conditions and variables ---------------------------------
* =============================================================================================
*/
enum VariousConditionsTask1 { Zero = 0, Double = 2, BuffErazer = 32750 };
int Number{};

/*
* =============================================================================================
* --------------------------------------- ProtoFunctions --------------------------------------
* =============================================================================================
*/
void DecToBin(int Number);
void GetNumber(int& Number);
void Task1();
long long GetNumber();
long long RecursiveExponentiation(long long  base, long long  exp);
void Task2();
long long RecursiveExponentiationWTricks(long long  base, long long exp);
void Task3();
int Routes(int x, int y);
int32_t getRandomNum(int32_t min, int32_t max);
const int SizeX{ 5 };
const int SizeY{ 5 };
int Array[SizeX][SizeY]{};
void Task4();

/*
* =============================================================================================
* ---------------------------------------- MainFunction ---------------------------------------
* =============================================================================================
*/
int main() 
{
    Task1();
    Task2();
    Task3();
    Task4();
    return 0;
}

/*
* =============================================================================================
* ----------------------------------------- Functions -----------------------------------------
* =============================================================================================
*/
void DecToBin(int Number) // recursive function for transformation decimal number in binary form
{
    if (Number < Zero)
    {
        std::cout << "-";
        DecToBin(-Number);
    }
    else if (Number < Double)
    {
        std::cout << Number;
        return;
    }
    else
    {
        DecToBin(Number / Double);
        int res = Number % Double;
        std::cout << res;
    }
}

void GetNumber(int& Number) // function for getting number from user
{
    while (true)
    {
        std::cout << "Your number is ";
        std::cin >> Number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(BuffErazer, '\n');
            std::cout << "Error! Wrong input." << std::endl;
        }
        else
        {
            break;
        }
    }
}

void Task1() // main function for task 1
{
    std::cout << "----------------------- Task 1 -----------------------" << std::endl;
    std::cout << "Enter an integer number." << std::endl;
    GetNumber(Number);
    std::cout << "Your decimal number in binary form is ";
    DecToBin(Number);
    std::cout << std::endl;
}

long long GetNumber() // function for getting number from user
{
    while (true)
    {
        long long Number{};
        std::cout << "Your number is ";
        std::cin >> Number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(BuffErazer, '\n');
            std::cout << "Error! Wrong input." << std::endl;
        }
        else
        {
            return Number;
        }
    }
}

long long RecursiveExponentiation(long long  base, long long exp) // recursive function for basic exponentiation
{
    if (exp == 1)
    {
        return base;
    }
    else if (exp > 1)
    {
        return base * RecursiveExponentiation(base, exp - 1);
    }
}

void Task2() // main function for task 2
{
    std::cout << "----------------------- Task 2 -----------------------" << std::endl;
    long long Base = GetNumber();
    long long Exp = GetNumber();
    std::cout << "Exponentiation of " << Base << "^" << Exp << " = " << RecursiveExponentiation(Base, Exp) << std::endl;
}

long long RecursiveExponentiationWTricks(long long  base, long long exp) // recursive function for exponentiation with some tricks
{
    if (exp == 1)
    {
        return base;
    }
    else if (exp % 2 == 0)
    {
        return RecursiveExponentiationWTricks(base, exp / 2) * RecursiveExponentiationWTricks(base, exp / 2);
    }
    else
    {
        return base * RecursiveExponentiationWTricks(base, exp - 1);
    }
}

void Task3() // main function for task 3
{
    std::cout << "----------------------- Task 3 -----------------------" << std::endl;
    long long Base = GetNumber();
    long long Exp = GetNumber();
    std::cout << "Exponentiation of " << Base << "^" << Exp << " = " << RecursiveExponentiationWTricks(Base, Exp) << std::endl;
}

int Routes(int x, int y) // function for finding 'king' routes on map
{
    if ((x == 0 && y == 0) || Array[x][y] == 1)
    {
        return 0;
    }
    else if (x == 0 || y == 0)
    {
        return 1;
    }
    else
    {
        return Array[x][y-1] + Array[x-1][y];
    }
}

int32_t getRandomNum(int32_t min, int32_t max) // function for geting random number
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void Task4()
{
    std::cout << "----------------------- Task 4 -----------------------" << std::endl;
    for (int x = 0; x < SizeX; x++)
    {
        for (int y = 0; y < SizeY; y++)
        {
            Array[x][y] = getRandomNum(0, 1);
        }
    }
    std::cout << "This is our field, 'king' will be strolling on this field" << std::endl;
    for (int x = 0; x < SizeX; x++)
    {
        for (int y = 0; y < SizeY; y++)
        {
            std::cout << "  " << Array[x][y] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    if (Array[0][0] == 1)
    {
        std::cout << "Where is no routes for king!" << std::endl;
    }
    else
    {
        for (int x = 0; x < SizeX; x++)
        {
            for (int y = 0; y < SizeY; y++)
            {
                Array[x][y] = Routes(x, y);
            }
        }
        for (int x = 0; x < SizeX; x++)
        {
            for (int y = 0; y < SizeY; y++)
            {
                std::cout << "  " << Array[x][y] << "  ";
            }
            std::cout << std::endl;
        }
    }
}