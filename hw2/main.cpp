#include <iostream>

const int buf_erazer = 35478; //задаем константу для функции cin.ignore
const int GameField = 3;

int main()
{
	
    {
/*
Инициализируем переменные 
указанных типов (short int, int, long long, char, bool, float, double), 
используя ввод и вывод через консоль.
*/
		/*
		//воодим переменную формата 'short int'
		while (true)
		{
			std::cout << "Pls type integer (diaposon from -32'768 to 32'767): ";
			short int Short_Int;
			std::cin >> Short_Int;
			if (std::cin.fail())
			{
				std::cin.clear(); //возвращаем cin в обычный режим работы
				std::cin.ignore(buf_erazer, '\n'); //очищаем буфер
				std::cout << "\tWrong. Pls enter integer in valid diaposon." << std::endl;
			}
			else
			{
				std::cout << "\tYou typed Short_Int = " << Short_Int << std::endl;
				std::cout << "\tSize of Short_Int: " << sizeof(Short_Int) << " byte." << std::endl;
				std::cin.ignore(buf_erazer, '\n');
				break;
			}
		}
		
		//вводим переменную формата 'int'
		while (true)
		{
			std::cout << "Pls type integer (diaposon from -2'147'483'648 to 2'147'483'647): ";
			int Int;
			std::cin >> Int;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(buf_erazer, '\n');
				std::cout << "\tWrong. Pls enter integer in valid diaposon." << std::endl;
			}
			else
			{
				std::cout << "\tYou typed Int = " << Int << std::endl;
				std::cout << "\tSize of Int: " << sizeof(Int) << " byte." << std::endl;
				std::cin.ignore(buf_erazer, '\n');
				break;
			}
		}
		
		//вводим переменную формата 'long long'
		while (true)
		{
			std::cout << "Pls type integer (diaposon from -9'223'372'036'854'775'808 to 9'223'372'036'854'775'807: ";
			long long long_long;
			std::cin >> long_long;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(buf_erazer, '\n');
				std::cout << "\tWrong. Pls enter integer in valid diaposon." << std::endl;
			}
			else
			{
				std::cout << "\tYou typed long_long = " << long_long << std::endl;
				std::cout << "\tSize of long_long: " << sizeof(long_long) << " byte." << std::endl;
				std::cin.ignore(buf_erazer, '\n');
				break;
			}
		}
		
		//вводим переменную формата 'char'
		while (true)
		{
			std::cout << "Pls type one character (or symbol, or number): ";
			char Char;
			std::cin >> Char;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(buf_erazer, '\n');
				std::cout << "\tWrong. Pls enter one valid character (or symbol, or number)." << std::endl;
			}
			else
			{
				std::cout << "\tYou typed Char = " << Char << std::endl;
				std::cout << "\tSize of Char: " << sizeof(Char) << " byte." << std::endl;
				std::cin.ignore(buf_erazer, '\n');
				break;
			}
		}
		
		//вводим переменную формата 'bool'
		{
			bool Bool;
			while (true)
			{
				std::cout << "Pls type statemant true ='1' or false ='0': ";
				std::cin >> Bool;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(buf_erazer, '\n');
					std::cout << "\tWrong. Pls enter valid statement." << std::endl;
				}
				else
				{
					if (Bool == 1 || Bool == 0)
					std::cin.ignore(buf_erazer, '\n');
					break;
				}

			}
			if (Bool == 1)
				std::cout << "Your statemant is true!" << std::endl;
			else
				std::cout << "Your statemant is false!" << std::endl;
				std::cout << "\tSize of Bool: " << sizeof(Bool) << " byte." << std::endl;
		}


		//вводим переменную формата 'float'
		while (true)
		{
			std::cout << "Pls type fractional number: ";
			float Float;
			std::cin >> Float;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(buf_erazer, '\n');
				std::cout << "\tWrong. Pls enter valid fractional number." << std::endl;
			}
			else
			{
				std::cout << "\tYou typed Float = " << Float << std::endl;
				std::cout << "\tSize of Float: " << sizeof(Float) << " byte." << std::endl;
				std::cin.ignore(buf_erazer, '\n');
				break;
			}
		}

		//вводим переменную формата 'double float'
		while (true)
		{
			std::cout << "Pls type fractional number: ";
			double Double;
			std::cin >> Double;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(buf_erazer, '\n');
				std::cout << "\tWrong. Pls enter valid fractional number." << std::endl;
			}
			else
			{
				std::cout << "\tYou typed Double = " << Double << std::endl;
				std::cout << "\tSize of Double: " << sizeof(Double) << " byte." << std::endl;
				std::cin.ignore(buf_erazer, '\n');
				break;
			}
		}
		*/
	}
	
	{
/*
Создаем перечеслиние (enum), 
с возможными вариантами символов 
для игры в крестики-нолики
*/
	enum Tic_Tac_Toe {CROSS, ZERO, EMPTY};
	char Game_Chars[] = { 'X', '0', ' ' }; // задаем библиотеку символов для игры в крестики-нолики
	std::cout << "For definition of CROSS we will using: " << Game_Chars[CROSS] << std::endl;
	std::cout << "For definition of ZERO we will using: " << Game_Chars[ZERO] << std::endl;
	std::cout << "For definition of EMPTY we will using: " << Game_Chars[EMPTY] << std::endl;

	Tic_Tac_Toe Array[GameField][GameField] = { CROSS };                                               
	// мне открыли глаза, что можно использовать число из одного массива, 
	// как индекс для вытягивание значения из другого массива, вух вот это магия
	std::cout << "First symbol in Array = " << Game_Chars[Array[0][0]] << " Second symbol in Array = " << Game_Chars[Array[0][1]] << std::endl; 
	{
		for (int row = 0; row < GameField; ++row)
		{
			for (int col = 0; col < GameField; ++col)
				std::cout << Game_Chars[Array[row][col]] << "\t";

			std::cout << '\n';

		}
	}



	


	


	}
	return 0;
}