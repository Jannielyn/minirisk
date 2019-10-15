#include <iomanip>
#include <iostream>
#include <string>
#include "Date.h"
using namespace minirisk;
using namespace std;

void test1()
{
	try
	{
		Date d;
		cout << "Enter the day" << endl;

	}
	catch (int param) { cout << "int exception " << param << endl; }
	catch (char param) { cout << "char exception " << param << endl; }
	catch (...) { cout << "default exception" << endl; }
}


void test2()
{
}

void test3()
{
}

int main()
{
    test1();
    test2();
    test3();

	Date x(1900, 1, 31);


	std::cout << Date::is_leap_year(1996) << std::endl;

	unsigned i = 1826;
	std::cout << ((Date*)NULL)->get_year(i) << std::endl;
	std::cout << ((Date*)NULL)->get_month(i) << std::endl;
    return 0;
}


#if 0
DateInitializer a;
const std::array<unsigned, Date::n_years> b(static_cast<const std::array<unsigned, Date::n_years>&>(DateInitializer()));

for (auto i = a.begin(), e = a.end(); i != e; ++i) {
	cout << *i << " ";
}

std::cout << std::endl << std::endl;

for (auto i = b.begin(), e = b.end(); i != e; ++i) {
	cout << *i << " ";
}
#endif 
