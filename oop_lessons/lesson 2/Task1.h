#pragma once

bool getUserInputWom();
char userChoosing();
std::string getUserWords();
int getUserInput();
/*
* =================================================================
* ------------------------Class for Task 1-------------------------
* =================================================================
*/
class Person // Parent class for TASK 1
{
public:
	Person() = default;
	~Person() = default;
protected:
	std::string m_name{};
	int m_age{};
	int m_weight{};
	bool m_isWoman{};
	void setName() //user input for name
	{
		std::cout << "Pls enter Person's name: ";
		m_name = getUserWords();
	}

	void setAge() //user input for age
	{
		std::cout << "Pls enter Person's age: ";
		m_age = getUserInput();
	}

	void setPersonSex()
	{
		std::cout << "Pls enter Person's sex 1 is man 0 is woman: ";
		m_isWoman = getUserInputWom();
	}

	void setWeight() //user input for weight
	{
		std::cout << "Pls enter Person's weight: ";
		m_weight = getUserInput();
	}
};

class Student : public Person // Heritage class for TASK 1
{
public:
	Student() = default;
	~Student() = default;
	void setYearOfStudy()
	{
		std::cout << "Pls enter Student's starting year of education: ";
		m_yearOfStudy = getUserInput();
		m_studentIndex++;
		m_studentNumber = m_studentIndex;
		m_graduationCounting++;
	}
	void incrYearOfStudy()
	{
		m_graduationCounting++;
		if (m_graduationCounting > e_yearsOfStudy)
		{
			std::cout << "Congratulations this student graduated our university at last!" << std::endl;
		}
		else
		{
			m_yearOfStudy++;
			m_age++;
		}
	}
	void printStudentInfo()
	{
		std::cout << "This student's number is " << m_studentNumber << std::endl;
		std::cout << "Information:" << std::endl;
		std::cout << " - name: " << m_name << std::endl;
		std::cout << " - age: " << m_age << std::endl;
		std::cout << " - weight: " << m_weight << std::endl;
		std::cout << " - sex: " << (m_isWoman ? "man" : "woman") << std::endl;
		std::cout << " - year of study: " << m_yearOfStudy << std::endl;
		std::cout << " - student number: " << m_studentNumber << std::endl;
	}
	void getInfo()
	{
		setName();
		setAge();
		setWeight();
		setPersonSex();
		setYearOfStudy();
	}
protected:
	int m_studentIndex{};
	int m_yearOfStudy{};
	int m_studentNumber{};
	int m_graduationCounting{};
	enum EducationMatters // mark of education's length
	{
		e_yearsOfStudy = 4
	};
};

class StudentDataBase
{
public:
	StudentDataBase() = default;
	~StudentDataBase() = default;
	void databaseWork()
	{
		sizeOfDatabase = setSizeOfDatabase();
		Student* p_studentDatabase = new Student[sizeOfDatabase];
		while (!databaseClosing)
		{
			std::cout << "Do you want to input a new student in database? y/n: ";
			c_userChoise = userChoosing();
			if (databaseIndex > sizeOfDatabase)
			{
				std::cout << "Sorry the database is full!" << std::endl;
			}
			else if (c_userChoise == 'y')
			{
				p_studentDatabase[databaseIndex].getInfo();
				databaseIndex++;
			}
			else
			{
				std::cout << "Do you want to increment existing student's year of study? y/n: ";
				c_userChoise = userChoosing();
				if (c_userChoise == 'y')
				{
					std::cout << "Pls choose a student's number who's year of study you want to increment: ";
					dataBaseNavigationYear(p_studentDatabase, databaseIndex);
				}
				else
				{
					std::cout << "Right now we have a " << databaseIndex << " students in our database!" << std::endl;
					std::cout << "Do you want to see info about your students? y/n: ";
					c_userChoise = userChoosing();
					if (c_userChoise == 'y')
					{
						std::cout << "Pls choose a student's number who's info you want to read: ";
						dataBaseNavigationPrint(p_studentDatabase, databaseIndex);
					}
					else
					{
						std::cout << "Do you want to stop working with database? y/n: ";
						c_userChoise = userChoosing();
						if (c_userChoise == 'y')
						{
							databaseClosing = true;
						}
						else
						{
							databaseClosing = false;
						}
					}
				}
			}
		}
		delete[] p_studentDatabase;
	}
private:
	char c_userChoise{};
	int databaseIndex{};
	bool databaseClosing{};
	int sizeOfDatabase{};
	int setSizeOfDatabase() // function for seting size of database in TASK 1
	{
		std::cout << "Let's create our student database." << std::endl;
		std::cout << "Pls, enter the size of our database: ";
		int sizeOfDatabase = getUserInput();
		return sizeOfDatabase;
	}
	char userChoosing() // function for geting user input on continue or not
	{
		char c_choise{};
		bool cinFlag{};
		while (!cinFlag)
		{
			cinFlag = true;
			std::cin >> c_choise;
			if (std::cin.fail() || c_choise != 'y' && c_choise != 'n')
			{
				cinFlag = false;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error! Pls try again." << std::endl;
			}
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return c_choise;
	}
	void dataBaseNavigationYear(Student student[], int databaseIndex) // function for database naviagation and years increment
	{
		int databaseNavig = getUserInput();
		if (databaseNavig > databaseIndex)
		{
			std::cout << "Sorry, we don't have so much students in our database!" << std::endl;
		}
		else
		{
			databaseNavig--;
			student[databaseNavig].incrYearOfStudy();
		}
	}
	void dataBaseNavigationPrint(Student student[], int databaseIndex) // function for database naviagation and printing student's info
	{
		int databaseNavig = getUserInput();
		if (databaseNavig > databaseIndex)
		{
			std::cout << "Sorry, we don't have so much students in our database!" << std::endl;
		}
		else
		{
			databaseNavig--;
			student[databaseNavig].printStudentInfo();
		}
	}
};