#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<iomanip>
using namespace std;
time_t t = time(0);
tm *now = localtime(&t);
string day, month,year;
void format_date(){    
    if(now->tm_mday < 10)
    {
        day= "0";
        day.append(to_string(now->tm_mday));
    }
    else day= to_string(now->tm_mday);
    if(now->tm_mon +1 < 10)
    {
        month= "0" ;
        month.append( to_string(now->tm_mon +1));
    }
    else month = to_string(now->tm_mon);
	year = now->tm_year %100;
}
// task1
void task1(string name_sales)
{
	double subtotal = 0, tax = 0, total = 0, balance = 0, amount_paid = 0;
	double price_A = 11.99, price_B = 12.99, price_C = 14.99, price_D = 15.99;
	int qty_A = 0, qty_B = 0, qty_C = 0, qty_D = 0;
	while (1)
	{
		system("cls");
		cout << "SALE PRODUCTS CS - " << name_sales << endl;
		cout<<setfill('.');
		cout << setw(50)<<'.'<<endl;
		cout << "\tToday: " << day << "/" << 	month << "/" << year << endl;
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
			cout<<setfill('.');
			cout << setw(50)<<'.' << endl;
			cout << "RECEIPT - COMPANY CS" << endl;
			cout<<setfill('.');
			cout << setw(50)<<'.' << endl;
			cout << "Date:"<<setw(40)<<left<< day << "/" << month << "/" << year << endl;
			cout << "Sale transaction:"<<setw(40)<<left<<"03010001" << endl;
			cout << "Sale employee:"<<setw(40) <<left<<name_sales<< endl;
			cout<<setfill('.');
			cout << setw(50)<<'.' << endl;
			cout << "Model CS21A (" << price_A << "/per unit)     " << setw(10)<<left<<qty_A << setw(10)<<right<<price_A*qty_A << endl;
			cout << "Model CS21B (" << price_B << "/per unit)     " << setw(10)<<left<<qty_B << setw(10)<<right<<price_B*qty_B << endl;
			cout << "Model CS21C (" << price_C << "/per unit)     " << setw(10)<<left<<qty_C << setw(10)<<right<<price_C*qty_C << endl;
			cout << "Model CS21D (" << price_D << "/per unit)     " << setw(10)<<left<<qty_D << setw(10)<<right<<price_D*qty_D << endl;
			cout<<setfill('.');
			cout << setw(50)<<'.' << endl;
			cout << "Subtotal: "<<setw(40)<<left<<subtotal << endl;
			cout << "Tax(8.25%) "<<setw(40)<<left<<subtotal<<tax<< endl;
			cout << "Total:"<<setw(40)<<left<<subtotal<<total << endl;
			cout << "Amount paid: "<<setw(40)<<left<<subtotal<<amount_paid<< endl;
			cout << "Balance: "<<setw(40)<<left<<subtotal<<balance << endl;
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
	
	while (1)
	{
		system("cls");
		cout << "SALE PRODUCTS CS - " << name_sales << endl;
		cout << "----------------------------------------------------------------------\n";
		cout << "\tToday: " << day << "/" << month << "/" << year << endl;
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
			task1(name_sales);
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
	format_date();
	menu();
	return 0;
}