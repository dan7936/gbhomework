#include <iostream>

const int buf_erazer = 35478; //задаем константу для функции cin.ignore
const int GameField = 3; // задаем константу для массива игрового поля в крестики-нолики

int main()
{
	
    {
		std::cout << "----------Task 1----------" << std::endl;
/*
Инициализируем переменные 
указанных типов (short int, int, long long, char, bool, float, double), 
используя ввод и вывод через консоль.
*/
		
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
		
	}
	
	{
	std::cout << "----------Task 2----------" << std::endl;
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

	std::cout << "----------Task 3----------" << std::endl;

	// !!!!!! Tic_Tac_Toe Array[GameField][GameField] = { CROSS }; вот тут какая то магия происходит у меня, если инициализирую вот так, 
	// !!!!!! то при смене инициализатора на тот же ZERO, программа меняет на 1 только первую переменную в массиве
	// !!!!!! по совету использовал следующую инициализацию:
	Tic_Tac_Toe Array[GameField][GameField];
	for (int row = 0; row < GameField; ++row)
		for (int col = 0; col < GameField; ++col)
			Array[row][col] = EMPTY;

	std::cout << "Our array right now is using EMPTY ' ' inicialisation, so we will see empty space " << std::endl;
	// мне открыли глаза, что можно использовать число из одного массива, 
	// как индекс для вытягивание значения из другого массива, вух вот это магия
	std::cout << "First symbol in Array = " << Game_Chars[Array[0][0]] << " Second symbol in Array = " << Game_Chars[Array[0][1]] << std::endl; 

	// написал цикл для вывода массива на экран целиком
	
		for (int row = 0; row < GameField; ++row)
		{
			for (int col = 0; col < GameField; ++col)
				std::cout << "|" << Game_Chars[Array[row][col]] << "|   ";

			std::cout << '\n';

		}

		std::cout << "----------Task 4*----------" << std::endl;
/*
Пробую создать и инициализировать сложную структуру, 
не уверен, что вообще правильно понял задание
*/
		{
			enum MatchResult { WIN, LOOSE, DRAW, NOTDECIDED }; // задаем массив для хранения переменных победы или поражения в матче
			enum GameInProgress {PLAYING, ENDED}; // задаем массив для хранения переменных кончился матч или нет
			enum WhoseMoving {PLAYER1, PLAYER2}; // задаем массив для хранения переменных кончился чей ход
			struct MatchInfo
			{
				short int FieldSize;
				char Player1Name[30] = "JohnShepard"; // имя игрока 1, так и не смог нормально ничего записать сюда, наверное надо какую то другую переменную использовать вместо массива char
				char Player2Name[30] = "JackHarper"; // имя игрока 2, так и не смог нормально ничего записать сюда, наверное надо какую то другую переменную использовать вместо массива char
				Tic_Tac_Toe Player1Char; // чем ходит игрок 1
				Tic_Tac_Toe Player2Char; // чем ходит игрок 2
				WhoseMoving Move; // чей ход
				GameInProgress Status; // статус матча
				MatchResult Result; // результат матча
			};

			MatchInfo Game1;
			Game1.FieldSize = GameField;
			Game1.Player1Char = CROSS;
			Game1.Player2Char = ZERO;
			Game1.Move = PLAYER2;
			Game1.Status = PLAYING;
			Game1.Result = NOTDECIDED;			
		}



	}

	{
		std::cout << "----------Task 5**----------" << std::endl;
/*
Попробуем написать свою variant переменную, как это все автоматизировать я пока не знаю,
поэтому просто запишу и выведу на экран
*/
		// записываем структуру юнион где будет храниться наша трехтиповая переменная
		union VariantType
		{
			int Number;
			float FractNumber;
			char Symbol;
		};

		// Объявляем переменную Testvar типа Number входящую в структуру VariantType
		VariantType Testvar;
		Testvar.Number = 26;

		// записываем структуру битового флага 
		struct Flag
		{
			unsigned int NumberFlag : 1;
			unsigned int FractNumberFlag : 1;
			unsigned int SymbolFlag : 1;
		};

		// Ставим флаг в переменную NumberFlag
		Flag TestvarFlag;
		TestvarFlag.NumberFlag = 1;
		TestvarFlag.FractNumberFlag = 0;
		TestvarFlag.SymbolFlag = 0;
		std::cout << "Lets look where our integer(26) hide: " << std::endl;
		std::cout << "\tIts our number type slot: " << Testvar.Number << std::endl;
		std::cout << "\tIts our fractional number type slot: " << Testvar.FractNumber << std::endl;
		std::cout << "\tIts our symbol type slot: " << Testvar.Symbol << std::endl;
		std::cout << "Lets look where our flag: " << std::endl;
		std::cout << "\tIts our number type flag: " << TestvarFlag.NumberFlag << std::endl;
		std::cout << "\tIts our fractional number type flag: " << TestvarFlag.FractNumberFlag << std::endl;
		std::cout << "\tIts our symbol type flag: " << TestvarFlag.SymbolFlag << std::endl;
	}

	return 0;
}