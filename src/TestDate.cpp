#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "Date.h"
using namespace minirisk;

void test1()
{
	Date a(1899, 2, 28);
	Date b(2200, 2, 28);
	Date c(2000, 0, 28);
	Date d(2000, 13, 28);
	Date e(2000, 1, 0);
	Date f(2000, 1, 32);
	Date g(2000, 4, 31);
	Date h(2000, 2, 30);
	Date i(1999, 2, 29);
	Date j(1900, 2, 29);
	Date x(2000, 2, 29);
	std::cout << i.get_serial() << std::endl;
	std::cout << x.get_serial() << std::endl;

	int counter = 0;
	srand(time(NULL));
	unsigned seed; 
	while (counter < 1000) {
		seed = rand();
		srand(seed);
		//generate a random number between 10000000 and 30000000 to imitate YYYYMMDD format
		int randDate = (rand() %(300000000 - 100000000 + 1)) + 100000000; 
		
		unsigned d = randDate % 100; 
		unsigned m = ((randDate - d) / 100) % 100;
		unsigned y = (randDate - d - 100 * m) / 10000;
	}

}


void test2()
{	
	int error = 0;
	const std::array<unsigned, 12> days_in_month = { {31,28,31,30,31,30,31,31,30,31,30,31} };
	const std::array<unsigned, 12> days_in_month_leap = { {31,29,31,30,31,30,31,31,30,31,30,31} };
	for (int y = 1900; y < 1901; ++y) {
		for (int m = 1; m <= 1; ++m) {
			int dmax = ((Date::is_leap_year(y)) ? days_in_month_leap[m - 1] : days_in_month[m - 1]);
			for (int d = 1; d <= dmax; ++d) {
				
				Date someDay(y, m, d);	//date stored serial format
				std::string someDay_str = someDay.to_string(); //convert the serial date back to string in calander format (e.g. 1-1-1900)

				//get the day, month, year out of the string respectively 
				int someDay_str_day = std::stoi(someDay_str.substr(0, someDay_str.find('-')));
				int someDay_str_month = std::stoi(someDay_str.substr(someDay_str.find('-') + 1, someDay_str.rfind('-') - someDay_str.find('-') - 1));
				int someDay_str_year = std::stoi(someDay_str.substr(someDay_str.rfind('-') + 1));

				if (someDay_str_day != d || someDay_str_month != m || someDay_str_year != y) {
					error++; 
				}
			}
		}
	}
	std::cout << "Test2 completed " << ((error == 0) ? "successfully" : "unsuccessfully") << " with " << error << " error found!" << std::endl;
}

void test3()
{
}

int main()
{
    test1();
    test2();
    test3();

	 
	std::cout << Date::is_leap_year(1996) << std::endl;

	Date y(2019, 3, 1);
	std::cout << y.to_string() << std::endl;
	std::cout << y.to_string(false) << std::endl;

	//unsigned i = 109572;
	//::cout << ((Date*)NULL)->get_year(i) << std::endl;
	//std::cout << ((Date*)NULL)->get_month(i) << std::endl;
	//std::cout << ((Date*)NULL)->get_day(i) << std::endl;

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
