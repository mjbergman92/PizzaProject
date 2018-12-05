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
	char coupon = ' ';

	cout << "# of Large Pizzas:\t";
	cin >> large;
	cout << endl << "# of Medium Pizzas:\t";
	cin >> medium;
	cout << endl << "# of Small Pizzas:\t";
	cin >> small;
	cout << endl << "# of Breadsticks:\t";
	cin >> bread;
	cout << endl << "# of Drinks:\t\t";
	cin >> drinks;
	cout << endl << "Coupon? (Y or N)\t";
	cin >> coupon;

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

		cout << endl << fixed << setprecision(2) << pizzas << "Pizzas:\t\t" << "+$" << spaces << p;

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - breadTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (bread > 0) {

		cout << endl << fixed << setprecision(2) << bread << "Sticks:\t\t" << "+$" << spaces << b;

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - drinksTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (drinks > 0) {

		cout << endl << fixed << setprecision(2) << drinks << "Drinks:\t\t" << "+$" << spaces << d;

	}

	makeLine();

	float subTotal = l + b + d;
	string subTotalString = tostr(floor(subTotal));

	if (coupon == 'y' || coupon == 'Y' || pizzas > 4) {

		if (coupon == 'y' || coupon == 'Y') {

			subTotal -= 2.00;

			spaces = "";

			for (int i = 0; i < roomNeeded - 1; i++) {

				spaces = spaces + " ";

			}

			cout << endl << fixed << setprecision(2) << "Coupon:\t\t" << "-$" << spaces << 2.00;

		}

		if (pizzas > 4) {

			float discount = subTotal * .1;
			string discountString = tostr(floor(discount));
			subTotal *= .9;

			spaces = "";

			for (int i = 0; i < roomNeeded - discountString.length(); i++) {

				spaces = spaces + " ";

			}

			cout << endl << fixed << setprecision(2) << "10% Discount:\t\t" << 

		}

		makeLine();

		subTotalString = tostr(floor(subTotal));

		spaces = "";

		for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

			spaces = spaces + " ";

		}

		cout << endl << fixed << setprecision(2) << "Subtotal:\t\t" << " $" << spaces << subTotal;

	}




	system("pause");

	return 0;

}

void makeLine() {

	cout << endl << "-------------------------------";

}

template <typename T> string tostr(const T& t) {
	ostringstream os;
	os << t;
	return os.str();
}