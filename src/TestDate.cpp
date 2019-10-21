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
	for (unsigned y = 1900; y < 2200; ++y) {
		for (unsigned m = 1; m <= 12; ++m) {
			unsigned dmax = ((Date::is_leap_year(y)) ? days_in_month_leap[m - 1] : days_in_month[m - 1]);
			for (unsigned d = 1; d <= dmax; ++d) {
				
				Date ds(y, m, d);	//date stored serial format
				std::string ds_str = ds.to_string(); //convert the serial date back to string in calander format (e.g. 1-1-1900)
				std::string cal = std::to_string(d) + '-' + std::to_string(m) + '-' + std::to_string(y);

				if (cal.compare(ds_str) != 0) {
					failures++;
				}
			}
		}
	}
	std::cout << "Test2 completed " << ((failures == 0) ? "successfully" : "unsuccessfully") << " with " << failures << " exceptions found!" << std::endl;
}


void test3()
{
	int failures = 0;
	const std::array<unsigned, 12> days_in_month = { {31,28,31,30,31,30,31,31,30,31,30,31} };
	const std::array<unsigned, 12> days_in_month_leap = { {31,29,31,30,31,30,31,31,30,31,30,31} };
	for (unsigned y = 1900; y < 2200; ++y) {
		for (unsigned m = 1; m <= 12; ++m) {
			unsigned dmax = ((Date::is_leap_year(y)) ? days_in_month_leap[m - 1] : days_in_month[m - 1]);
			for (unsigned d = 1; d <= dmax; ++d) {

				//end the test when loop till 31-Dec-2199
				if (y == 2199 && m == 12 && d == 31) 
				{
					std::cout << "Test3 completed " << ((failures == 0) ? "successfully" : "unsuccessfully") << " with " << failures << " exceptions found!" << std::endl;
				}
				else 
				{
					Date d1(y, m, d);
					//move on to the next day:
					unsigned y_n, m_n, d_n;
					(d == dmax) ? (d_n = 1, (m == 12) ? (m_n = 1, y_n = y + 1) : (m_n = m + 1, y_n = y)) : (d_n = d + 1, m_n = m, y_n = y);
					Date d2(y_n, m_n, d_n);

					if (d2 - d1 != 1) failures++;
					
				}

			}
		}
	}
}

int main()
{
    test1();
    test2();
    test3();

	
    return 0;
}

