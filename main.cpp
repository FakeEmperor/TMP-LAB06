/**
* @file main.cpp
* @author FakeEmperor <fake_empire@mail.ru>
* @version 1.0
* <http://github.com/fakeemperor/TMP-LAB06/>
*
* @section LICENSE
*
* GNU GPL LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details at
* http://www.gnu.org/copyleft/gpl.html
*
* @section DESCRIPTION
*
* This is test code to get basic understanding of Factory classes.
*
* User writes a letter, that is a name of a class.
* Program creates selected class with <B>Factory</B> class and then calls <I>show()</I> method on that class
*
*/


#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>

/**
*	@brief Basic class for all other three classes.
*/
class A{
public:
	static const char Name;
	static const std::string HelloString;
	virtual void show(){
		std::cout << A::HelloString << A::Name << std::endl;
	};

};

/**
*	@brief Class B derived from the class A.
*/
class B :public A{
public:
	static const char Name;
	void show() override final{
		std::cout << B::HelloString << B::Name << std::endl;
	};
};

/**
*	@brief Class C derived from the class A.
*/
class C :public A{
public:
	static const char Name;
	void show() override final{
		std::cout << C::HelloString << C::Name << std::endl;
	};
};

/**
*	@brief Class D derived from the class A.
*/
class D :public A{
public:
	static const char Name;
	void show() override final{
		std::cout << D::HelloString << D::Name << std::endl;
	};
};

/**
*	@brief Standard message template for the <I>show()</I> method on all 4 classes.
*/
const std::string A::HelloString = "Hello, i'm ";

const char A::Name = 'A';
const char B::Name = 'B';
const char C::Name = 'C';
const char D::Name = 'D';

/**
*	@brief Factory class, that is used to make all 4 classes.
*	Contains static methods, wich are responsible for the creation.
*	NOTE: Classes are being created in the heap.
*	So it is necessary to delete these classes manually to avoid memory leaks
*/
class Factory{
public:
	static A* makeA(){
		return new A();
	};
	static B* makeB(){
		return new B();
	};
	static C* makeC(){
		return new C();
	};
	static D* makeD(){
		return new D();
	};
};
/**
*	@brief Function that returns the numerical index of the class that user demands.
*	@param[in] ch Name of a class, that user has provided.
*	@return Returns an integer value in the range <B>0-4</B>, if the name does exist.*
*	This value is an index of a demanded class. In case of error, a value <B>-1</B> is provided.  
*/
int typeof(const char ch){
	char sch = tolower(ch);
	if		( sch == tolower(A::Name) )
		return 0;
	else if ( sch == tolower(B::Name) )
		return 1;
	else if ( sch == tolower(C::Name) )
		return 2;
	else if ( sch == tolower(D::Name) )
		return 3;
	return -1;
}

int main(){
	bool good = true;
	char ch;
	A *ptr = nullptr;
	std::cout << "Hello, this is LAB-TMP06: \'Factory Classes\'." << std::endl
		<< "To test it, press keys \'A\', \'B\', \'C\' or \'D\'. " << std::endl
		<< "In the console you should see a message from appropriate class." << std::endl
		<< "To close the application, press any other key." << std::endl;


	while (good){
		delete ptr;
		ptr = nullptr;

		ch = getch();

		switch (typeof(ch)){
		case 0:	ptr = Factory::makeA();	break;
		case 1: ptr = Factory::makeB();	break;
		case 2:	ptr = Factory::makeC();	break;
		case 3:	ptr = Factory::makeD(); break;
		default: good = false;			break;
		}
		if (ptr)
			ptr->show();
		
	}
	std::cout << "Test ended." << std::endl
			  << "To continue, press any key...";
	getch();

	return 0;
};