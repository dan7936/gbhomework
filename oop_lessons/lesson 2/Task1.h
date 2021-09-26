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

private:
	void setYearOfStudy()
	{
		std::cout << "Pls enter Student's starting year of education: ";
		m_yearOfStudy = getUserInput();
		m_studentIndex++;
		m_studentNumber = m_studentIndex;
		m_graduationCounting++;
	}
};