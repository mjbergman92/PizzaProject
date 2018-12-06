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
	cout << "# of Medium Pizzas:\t";
	cin >> medium;
	cout << "# of Small Pizzas:\t";
	cin >> small;
	cout << "# of Breadsticks:\t";
	cin >> bread;
	cout << "# of Drinks:\t\t";
	cin >> drinks;
	cout << "Coupon? (Y or N)\t";
	cin >> coupon;

	cout << endl << "| ---------------------- |";

	int pizzas = large + medium + small;
	float p = (float)large * 10.00f + (float)medium * 8.00f + (float)small * 6.00f;
	string pizzaTotal = to_string(floor(p));
	float b = (float)bread * 4.99f;
	string breadTotal = to_string(floor(b));
	float d = (float)drinks * 2.79;
	string drinksTotal = to_string(floor(d));
	int roomNeeded = fmax(fmax(pizzaTotal.length(), breadTotal.length()), drinksTotal.length()) + 1;
	string spaces = "";

	for (int i = 0; i < roomNeeded - pizzaTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (pizzas > 0) {

		cout << endl << fixed << setprecision(2) << "| " << pizzas << " Pizzas:\t" << "+$" << spaces << p << " |";

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - breadTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (bread > 0) {

		cout << endl << fixed << setprecision(2) << "| " << bread << " Sticks:\t" << "+$" << spaces << b << " |";

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - drinksTotal.length(); i++) {

		spaces = spaces + " ";

	}

	if (drinks > 0) {

		cout << endl << fixed << setprecision(2) << "| " << drinks << " Drinks:\t" << "+$" << spaces << d << " |";

	}

	cout << endl << "| ---------------------- |";

	float subTotal = p + b + d;
	string subTotalString = to_string(floor(subTotal));

	spaces = "";

	for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

		spaces = spaces + " ";

	}

	cout << endl << fixed << setprecision(2) << "| " << "Subtotal:\t" << " $" << spaces << subTotal << " |";

	if (coupon == 'y' || coupon == 'Y' || pizzas > 4) {

		if (coupon == 'y' || coupon == 'Y') {

			subTotal -= 2.00;

			spaces = "";

			for (int i = 0; i < roomNeeded - to_string(floor(2.00)).length(); i++) {

				spaces = spaces + " ";

			}

			cout << endl << fixed << setprecision(2) << "| " << "Coupon:\t" << "-$" << spaces << 2.00 << " |";

		}

		if (pizzas > 4) {

			float discount = subTotal * .1f;
			string discountString = to_string(floor(discount));
			subTotal *= .9f;

			spaces = "";

			for (int i = 0; i < roomNeeded - discountString.length(); i++) {

				spaces = spaces + " ";

			}

			cout << endl << fixed << setprecision(2) << "| " << "10% Discount:\t" << "-$" << spaces << discount << " |";

		}

		cout << endl << "| ---------------------- |";

		subTotalString = to_string(floor(subTotal));

		spaces = "";

		for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

			spaces = spaces + " ";

		}

		cout << endl << fixed << setprecision(2) << "| " << "Subtotal:\t" << " $" << spaces << subTotal << " |";

	}

	float tax = subTotal * .06;

	string taxString = to_string(floor(tax));

	spaces = "";

	for (int i = 0; i < roomNeeded - taxString.length(); i++) {

		spaces = spaces + " ";

	}

	cout << endl << fixed << setprecision(2) << "| " << "6% Tax:\t" << "+$" << spaces << tax << " |";

	subTotal *= 1.06;

	cout << endl << "| ---------------------- |";

	subTotalString = to_string(floor(subTotal));

	spaces = "";

	for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

		spaces = spaces + " ";

	}

	cout << endl << fixed << setprecision(2) << "| " << "Total:\t" << " $" << spaces << subTotal << " |" << endl << endl;

	system("pause");

	return 0;

}