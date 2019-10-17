#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "Date.h"
using namespace minirisk;

bool isValidDate(unsigned y, unsigned m, unsigned d)
{
	if (y > Date::last_year || y < Date::first_year) return false;
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > 31) return false;

	// Handle February month with leap year 
	if (m == 2) {
		if (Date::is_leap_year(y))
			return (d <= 29);
		else
			return (d <= 28);
	}
	// 30 day in Apr, Jun, Sep and Nov 
	if (m == 4 || m == 6 ||	m == 9 || m == 11)
		return (d <= 30);

	return true;
}

void test1()
{
	int counter = 0;
	int flag = 0;
	int failures = 0;
	srand(time(NULL));
	unsigned seed; 
	while (counter < 1000) {
		//std::cout << counter << std::endl;
		seed = rand();
		srand(seed);

		unsigned y = rand() % 500 + 1800;	//rand year between (1800, 2299)
		unsigned m = rand() % 20;			//rand month between (0, 19)
		unsigned d = rand() % 40;			//rand day between (0, 39)
		
		// Logic: given a randomly generated invalid date, 
		if (!isValidDate(y,m,d)){ 
			counter++; 
			//Try to put into the constructor, if the error got caught which it supposed to be, set flag=1. 
			try {
				Date(y, m, d);
			}
			catch (const std::invalid_argument& x) {
				flag = 1; 
			}
			// if flag still = 0 at this moment, means invalid date is not caught, so we print out seed. 
			if (flag == 0) {
				std::cout << "Invalid date " << d << "-" << m << "-" << y << " is not captured. Seed: " << seed << std::endl;
				failures++;
			}
		}
		else {
			continue;
		}

		flag = 0;
	}
	
	std::cout << "Test1 completed " << ((failures == 0) ? "successfully" : "unsuccessfully") << " with " << failures << " exceptions found!" << std::endl;
}


void test2()
{	
	int failures = 0;
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
					failures++;
				}
			}
		}
	}
	std::cout << "Test2 completed " << ((failures == 0) ? "successfully" : "unsuccessfully") << " with " << failures << " exceptions found!" << std::endl;
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
