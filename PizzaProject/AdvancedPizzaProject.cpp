#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main() {

	//number of each item
	int large = 0;
	int medium = 0;
	int small = 0;
	int bread = 0;
	int drinks = 0;
	char coupon = ' ';

	//get inputs from user
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

	//start the receipt
	cout << endl << "| ---------------------- |";

	//calculate the amount of each section of items: pizza, breadsticks, and drinks
	//also figure out the number in string form for display purposes
	int pizzas = large + medium + small;
	float p = (float)large * 10.00f + (float)medium * 8.00f + (float)small * 6.00f;
	string pizzaTotal = to_string(floor(p));
	float b = (float)bread * 4.99f;
	string breadTotal = to_string(floor(b));
	float d = (float)drinks * 2.79;
	string drinksTotal = to_string(floor(d));
	int roomNeeded = fmax(fmax(pizzaTotal.length(), breadTotal.length()), drinksTotal.length()) + 1;
	string spaces = "";

	/* whenever a for loop is used in the rest of the program,
	 * it means that we are trying to figure out how many spaces
	 * are needed to display the receipt for that line correctly
	 * for alignment purposes.
	 */
	for (int i = 0; i < roomNeeded - pizzaTotal.length(); i++) {

		spaces = spaces + " ";

	}

	//if the customer wants pizza, display it
	//otherwise, just skip displaying pizzas on the receipt
	if (pizzas > 0) {

		cout << endl << fixed << setprecision(2) << "| " << pizzas << " Pizzas:\t" << "+$" << spaces << p << " |";

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - breadTotal.length(); i++) {

		spaces = spaces + " ";

	}

	//if the customer wants breadsticks, display it
	//otherwise, just skip displaying breadsticks on the receipt
	if (bread > 0) {

		cout << endl << fixed << setprecision(2) << "| " << bread << " Sticks:\t" << "+$" << spaces << b << " |";

	}

	spaces = "";

	for (int i = 0; i < roomNeeded - drinksTotal.length(); i++) {

		spaces = spaces + " ";

	}

	//if the customer wants drinks, display it
	//otherwise, just skip displaying drinks on the receipt
	if (drinks > 0) {

		cout << endl << fixed << setprecision(2) << "| " << drinks << " Drinks:\t" << "+$" << spaces << d << " |";

	}

	//go to the next section of the receipt
	cout << endl << "| ---------------------- |";

	float subTotal = p + b + d;
	string subTotalString = to_string(floor(subTotal));

	spaces = "";

	for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

		spaces = spaces + " ";

	}

	//output the subtotal, no mater if their is coupons or discounts or not
	cout << endl << fixed << setprecision(2) << "| " << "Subtotal:\t" << " $" << spaces << subTotal << " |";

	//if there is coupons or discounts enter in a section of the receipt
	//otherwise, move on to the tax section of the receipt
	if (coupon == 'y' || coupon == 'Y' || pizzas > 4) {

		//if there is a coupon for pizza, subtract $2 from the subtotal
		//otherwise, move on to the discount
		if (coupon == 'y' || coupon == 'Y') {

			subTotal -= 2.00;

			spaces = "";

			for (int i = 0; i < roomNeeded - to_string(floor(2.00)).length(); i++) {

				spaces = spaces + " ";

			}
			
			cout << endl << fixed << setprecision(2) << "| " << "Coupon:\t" << "-$" << spaces << 2.00 << " |";

		}

		//if there is more than 4 pizza, apply a 10% discount
		if (pizzas > 4) {

			//calculate discount before applying to subtotal
			float discount = subTotal * .1f;
			string discountString = to_string(floor(discount));
			subTotal *= .9f;

			spaces = "";

			for (int i = 0; i < roomNeeded - discountString.length(); i++) {

				spaces = spaces + " ";

			}

			cout << endl << fixed << setprecision(2) << "| " << "10% Discount:\t" << "-$" << spaces << discount << " |";

		}

		//recreate the end of the first section to move on to taxes
		cout << endl << "| ---------------------- |";

		subTotalString = to_string(floor(subTotal));

		spaces = "";

		for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

			spaces = spaces + " ";

		}

		cout << endl << fixed << setprecision(2) << "| " << "Subtotal:\t" << " $" << spaces << subTotal << " |";

	}

	//calculate the tax amount to be added and figure out the string for proper display purposes
	float tax = subTotal * .06;

	string taxString = to_string(floor(tax));

	spaces = "";

	for (int i = 0; i < roomNeeded - taxString.length(); i++) {

		spaces = spaces + " ";

	}

	cout << endl << fixed << setprecision(2) << "| " << "6% Tax:\t" << "+$" << spaces << tax << " |";

	subTotal *= 1.06;

	//move on to total section, the last section
	cout << endl << "| ---------------------- |";

	//the subtotal from here on is refering to the actual total
	subTotalString = to_string(floor(subTotal));

	spaces = "";

	for (int i = 0; i < roomNeeded - subTotalString.length(); i++) {

		spaces = spaces + " ";

	}

	//again, the subtotal is refering to the actual total here in the program
	cout << endl << fixed << setprecision(2) << "| " << "Total:\t" << " $" << spaces << subTotal << " |" << endl << endl;

	//pause to the user can see the output
	system("pause");

	//end the program
	return 0;

}
