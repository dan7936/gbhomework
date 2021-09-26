#pragma once

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
	void setName()
	{
		m_name = getName();
	}
	void setAge()
	{
		m_age = getAge();
	}
	void setWeight()
	{
		m_weight = getWeight();
	}
protected:
	std::string m_name{};
	int m_age{};
	int m_weight{};
private:
	std::string getName() //user input for name
	{
		std::cout << "Pls enter Person's name: ";
		std::string personName = getUserWords();
		return personName;
	}

	int getAge() //user input for age
	{
		std::cout << "Pls enter Person's age: ";
		int personAge = getUserInput();
		return personAge;
	}

	int getWeight() //user input for weight
	{
		std::cout << "Pls enter Person's weight: ";
		int personWeight = getUserInput();
		return personWeight;
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
		std::cout << "His info:" << std::endl;
		std::cout << " - name: " << m_name << std::endl;
		std::cout << " - age: " << m_age << std::endl;
		std::cout << " - weight: " << m_weight << std::endl;
		std::cout << " - year of study: " << m_yearOfStudy << std::endl;
		std::cout << " - student number: " << m_studentNumber << std::endl;
	}
	void getInfo()
	{
		setName();
		setAge();
		setWeight();
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
	int getYearOfStudy() //user input for student starting year of education
	{
		std::cout << "Pls enter Student's starting year of education: ";
		int studentStartingYear = getUserInput();
		return studentStartingYear;
	}

	void setYearOfStudy()
	{
		m_yearOfStudy = getYearOfStudy();
		m_studentIndex++;
		m_studentNumber = m_studentIndex;
		m_graduationCounting++;
	}
};