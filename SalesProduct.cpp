#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
// define struct product
typedef struct product
{
	string name_product;
	float price;
} Product;
// task1
void task1(string name_sales, int day, int month, int year)
{
	double subtotal = 0, tax = 0, total = 0, balance = 0, amount_paid = 0;
	double price_A = 11.99, price_B = 12.99, price_C = 14.99, price_D = 15.99;
	int qty_A = 0, qty_B = 0, qty_C = 0, qty_D = 0;
	while (1)
	{
		system("cls");
		cout << "SALE PRODUCTS CS - " << name_sales << endl;
		cout << "----------------------------------------------------------------------\n";
		cout << "\tToday: " << (day < 10 ? '0' + (day + '0') : day) << "/" << (month < 10 ? '0' + (month + '0') : month) << "/" << year % 100 << endl;
		cout << "\t 1.\tModel CS21A " << endl;
		cout << "\t 2.\tModel CS21B " << endl;
		cout << "\t 3.\tModel CS21C " << endl;
		cout << "\t 4.\tModel CS21D " << endl;
		cout << "\t 0.\tExit " << endl;
		int choice;
		do
		{
			cout << "Please choose a choice: ";
			cin >> choice;
			cin.ignore();
		} while (choice < 0 || choice > 4);
		int qty = 0;
		if (choice == 0)
		{
			cout << "Enter amount paid: ";
			cin >> amount_paid;
			cin.ignore();
			subtotal = price_A * qty_A + price_B * qty_B + price_C * qty_C + price_D + qty_D;
			tax = subtotal * 0.0825;
			total = subtotal + tax;
			balance = amount_paid - total;
			// print receipt
			cout << "............................................." << endl;
			cout << "RECEIPT - COMPANY CS" << endl;
			cout << "............................................." << endl;
			cout << "Date:                                "<< (day < 10 ? '0' + (day + '0') : day) << "/" << (month < 10 ? '0' + (month + '0') : month) << "/" << year % 100 << endl;
			cout << "Sale transaction:                    03010001" << endl;
			cout << "Sale employee:                      " <<name_sales<< endl;
			cout << "............................................." << endl;
			cout << "Model CS21A (" << price_A << "/per unit)     " << 10 << "    119.90" << endl;
			cout << "Model CS21B (" << price_B << "/per unit)     " << 10 << "    129.90" << endl;
			cout << "Model CS21C (" << price_C << "/per unit)     " << 10 << "    149.90" << endl;
			cout << "Model CS21D (" << price_D << "/per unit)     " << 10 << "    159.90" << endl;
			cout << "............................................." << endl;
			cout << "Subtotal:                             "<<subtotal<<"" << endl;
			cout << "Tax(8.25%)                             "<<tax<< endl;
			cout << "Total:                                 "<<total << endl;
			cout << "Amount paid:                           "<<amount_paid<< endl;
			cout << "Balance:                                "<<balance << endl;
			system("pause");
			break;
		}
		else
		{
			do
			{
				cout << "Please product which customer want to buy: ";
				cin >> qty;
				cin.ignore();
			} while (qty < 0);
			if (choice == 1)
			{
				// Model CS21A
				qty_A += qty;
			}
			else if (choice == 2)
			{
				// Model CS21B
				qty_B += qty;
				
			}
			else if (choice == 3)
			{
				// Model CS21C
				qty_C += qty;
			}
			else if (choice == 4)
			{
				// Model CS21D
				qty_D += qty;
			}
		}
	}
}
void menu()
{
	string name_sales;
	cout << "Enter your name: ";
	getline(cin, name_sales);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int day = ltm->tm_mday;
	int month = (1 + ltm->tm_mon);
	int year = 1990 + ltm->tm_year;
	while (1)
	{
		system("cls");
		cout << "SALE PRODUCTS CS - " << name_sales << endl;
		cout << "----------------------------------------------------------------------\n";
		cout << "\tToday: " << (day < 10 ? '0' + (day + '0') : day) << "/" << (month < 10 ? '0' + (month + '0') : month) << "/" << year % 100 << endl;
		cout << "\t\t1.\tSale Product CS " << endl;
		cout << "\t\t2.\tEnding day sale report  " << endl;
		cout << "\t\t3.\tEnding month sale report " << endl;
		cout << "\t\t4.\tEnding year sale report " << endl;
		cout << "\t\t0.\tExit " << endl;
		int choice;
		do
		{
			cout << "Please choose a choice: ";
			cin >> choice;
			cin.ignore();
		} while (choice < 0 || choice > 4);
		switch (choice)
		{
		case 1:
		{
			// task 1
			task1(name_sales, day, month, year);
			break;
		}
		case 2:
		{
			// task 2
			break;
		}
		case 3:
		{
			// task 3
			break;
		}
		case 4:
		{
			// task 4
			break;
		}
		default:
			cout << "Good Bye!!! See you again" << endl;
			exit(0);
		}
	}
}
int main()
{
	menu();
	return 0;
}