#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	ofstream fout("stdio_image.bin",ios::app|ios::binary);
	ifstream fin("led.bin",ios::binary);

	char buffer[2048] = {};
	fin.read(buffer,1024);
	fout.write(buffer,1024);
	fout.close();
	fin.close();

	return 0;
}
