#include <iostream>
#include <bitset>
using namespace std;

int main() {

	const unsigned int red_mask = 0xFF0000;
	const unsigned int grean_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(grean_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;


	unsigned int pixel_color = 0xDAA520;

	cout << bitset<32>(pixel_color) << endl;

	unsigned char blue = pixel_color & blue_mask;
	unsigned char grean = (pixel_color & grean_mask) >> 8;
	unsigned char red = (pixel_color & red_mask) >> 16;


	cout << "blue" << bitset<8>(blue) << " " << int(blue) << endl;
	cout << "grean" << bitset<8>(grean) << " " << int(grean) << endl;
	cout << "red" << bitset<8>(red) << " " << int(red) << endl;


}
