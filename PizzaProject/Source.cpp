#include <iostream>
#include <iomanip>
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
	float b = (float)bread * 4.99;
	string breadTotal = tostr(floor(b));
	float d = (float)drinks * 2.79;
	string drinksTotal = tostr(floor(d));
	int roomNeeded = fmax(fmax(pizzaTotal.length(), breadTotal.length()), drinksTotal.length()) + 1;
	string spaces = "";

	for (int i = 0; i < roomNeeded - pizzaTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (pizzas > 0) {

		cout << endl << fixed << setprecision(2) << pizzas << "Pizzas\t\t" << "+$" << spaces << p;

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - breadTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (bread > 0) {

		cout << endl << fixed << setprecision(2) << bread << "Sticks\t\t" << "+$" << spaces << b;

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - drinksTotal.length(); i++) {



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