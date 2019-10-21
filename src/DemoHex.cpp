#include <iostream>
#include <iomanip>
#include <cstdint>
#include "Streamer.h"

//using namespace std;
using namespace minirisk;

//void out_char_as_hex(int c)
//{
//    cout << hex << setw(2) << setfill('0') << c;
//}

int main()
{
    union { double d; uint64_t u; } tmp;
    double x = -0.15625;
    tmp.d = x;
    std::cout << std::hex << tmp.u << std::endl;


	string main_path = __FILE__;
	string cd = main_path.substr(0, main_path.rfind("DemoHex.cpp"));   //get cd of this working file
	std::cout << cd << std::endl;
	{
		double y = -0.15625;
		my_ofstream outfile(cd + "DemoHex.txt");
		outfile << y;
		outfile.endl();
		outfile.close();

		my_ifstream infile(cd + "DemoHex.txt");
		double i;
		infile.read_line();
		infile >> i;
		std::cout << i << std::endl;
	}
	
	//my_ifstream infile(double c);

    return 0;
}
