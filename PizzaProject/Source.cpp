#include <iostream>
#include <string>

using namespace std;
int main() {

	int large = 0;
	int medium = 0;
	int small = 0;
	int bread = 0;
	int drinks = 0;

	cout << "# of Large Pizzas: ";
	cin >> large;
	cout << endl << "# of Medium Pizzas: ";
	cin >> medium;
	cout << endl << "# of Small Pizzas: ";
	cin >> small;
	cout << endl << "# of Breadsticks: ";
	cin >> bread;
	cout << endl << "# of Drinks: ";
	cin >> drinks;

	makeLine();

	int pizzas = large + medium + small;
	float p = (float)large * 10.00 + (float)medium * 8.00 + (float)small * 6.00;
	string pizzaTotal = tostr(floor(p));
	string spaces = "hello" + "hello";

	if (pizzas > 0) {

		cout << pizzas << "Pizzas\t\t" << "+$" << 

	}


	system("pause");

	return 0;

}

void makeLine() {

	cout << "-------------------------------";

}

template <typename T> string tostr(const T& t) {
	ostringstream os;
	os << t;
	return os.str();
}