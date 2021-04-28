#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;
int number_day_sales = 0;
time_t t = time(0);
tm *now = localtime(&t);
string day, month;
int year;
double price_A = 11.99, price_B = 12.99, price_C = 14.99, price_D = 15.99;
fstream f_day, f_month, f_year;
int total_qty_A = 0, total_qty_B = 0, total_qty_C = 0, total_qty_D = 0;
void format_date()
{
	if (now->tm_mday < 10)
	{
		day = "0";
		day.append(to_string(now->tm_mday));
	}
	else
		day = to_string(now->tm_mday);
	if (now->tm_mon + 1 < 10)
	{
		month = "0";
		month.append(to_string(now->tm_mon + 1));
	}
	else
		month = to_string(now->tm_mon);
	year = now->tm_year % 100;
}
// task1
void menu_task1(string name_sales)
{
	system("cls");
	cout << "SALE PRODUCTS CS - " << name_sales << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << setw(10) << right << "Today: " << day << "/" << month << "/" << year << endl;
	cout << "\t 1.\tModel CS21A " << endl;
	cout << "\t 2.\tModel CS21B " << endl;
	cout << "\t 3.\tModel CS21C " << endl;
	cout << "\t 4.\tModel CS21D " << endl;
	cout << "\t 0.\tExit " << endl;
}
string format_sale()
{
	string rs = "";
	rs.append(day);
	rs.append(month);
	string s = to_string(number_day_sales);
	for (int i = 0; i <= (5 - s.length()); i++)
	{
		s = "0" + s;
	}
	rs.append(s);
	return rs;
}
void save_report_the_day(int qty_A, int qty_B, int qty_C, int qty_D)
{

	f_day << format_sale() << "\t" << setw(10) << left << qty_A << setw(10) << left << qty_B << setw(10) << left << qty_C << setw(10) << left << qty_D << endl;
}
void read_file(string filename, int &qty_A, int &qty_B, int &qty_C, int &qty_D, int &number_of_sales)
{
	ifstream fi(filename);
	if (!fi.good())
		return;
	int tmp;
	string s;
	while (!fi.eof())
	{
		number_of_sales += 1;
		getline(fi, s);
		stringstream ss;

		ss.str(s);
		ss >> s;

		ss >> tmp;
		qty_A += tmp;

		ss >> tmp;
		qty_B += tmp;

		ss >> tmp;
		qty_C += tmp;

		ss >> tmp;
		qty_D += tmp;
	}
	fi.close();
}
// task1
void task1(string name_sales)
{
	double subtotal = 0, tax = 0, total = 0, balance = 0, amount_paid = 0;
	int qty_A = 0, qty_B = 0, qty_C = 0, qty_D = 0;
	number_day_sales++;
	while (1)
	{
		menu_task1(name_sales);
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
			total_qty_A += qty_A;
			total_qty_B += qty_B;
			total_qty_C += qty_C;
			total_qty_D += qty_D;
			// print receipt

			cout << setfill('.');
			cout << setw(60) << "." << endl;
			cout << setfill(' ');
			cout << setw(40) << right << "RECEIPT - COMPANY CS" << endl;
			cout << setfill('.');
			cout << setw(60) << "." << endl;
			cout << setfill(' ');
			cout << setw(52) << left << "Date:" << day << "/" << month << "/" << year << endl;
			cout << setw(20) << left << "Sale transaction:" << setw(40) << right << format_sale() << endl;
			cout << setw(20) << left << "Sale employee:" << setw(40) << right << name_sales << endl;
			cout << setfill('.');
			cout << setw(60) << "." << endl;
			cout << setfill(' ');
			cout.precision(2);
			cout.setf(ios::fixed, ios::floatfield);
			cout << "Model CS21A (" << price_A << "/per unit)     " << setw(12) << right << qty_A << setw(15) << right << price_A * qty_A << endl;
			cout << "Model CS21B (" << price_B << "/per unit)     " << setw(12) << right << qty_B << setw(15) << right << price_B * qty_B << endl;
			cout << "Model CS21C (" << price_C << "/per unit)     " << setw(12) << right << qty_C << setw(15) << right << price_C * qty_C << endl;
			cout << "Model CS21D (" << price_D << "/per unit)     " << setw(12) << right << qty_D << setw(15) << right << price_D * qty_D << endl;
			cout << setfill('.');
			cout << setw(60) << "." << endl;
			cout << setfill(' ');
			cout << setw(40) << left << "Subtotal: " << setw(20) << right << subtotal << endl;
			cout << setw(40) << left << "Tax(8.25%) " << setw(20) << right << tax << endl;
			cout << setw(40) << left << "Total:" << setw(20) << right << total << endl;
			cout << setw(40) << left << "Amount paid: " << setw(20) << right << amount_paid << endl;
			cout << setw(40) << left << "Balance: " << setw(20) << right << balance << endl;
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

	save_report_the_day(qty_A, qty_B, qty_C, qty_D);
}

void save_report_the_month()
{
	int total_qty_A = 0, total_qty_B = 0, total_qty_C = 0, total_qty_D = 0;
	int rac = 0;

	for (int i = 1; i <= now->tm_mday; i++)
	{
		if (1 <= i && i <= 9)
		{
			string file_name = "daySale_0" + to_string(i) + month + to_string(year) + ".txt";
			read_file(file_name, total_qty_A, total_qty_B, total_qty_C, total_qty_D, rac);
		}
		else
		{
			string file_name = "daySale_" + to_string(i) + month + to_string(year) + ".txt";

			read_file(file_name, total_qty_A, total_qty_B, total_qty_C, total_qty_D, rac);
		}
	}

	f_month << setw(10) << left << now->tm_mday << setw(10) << left << total_qty_A << setw(10) << left << total_qty_B << setw(10) << left << total_qty_C << setw(10) << left << total_qty_D << endl;
}
void save_report_the_year()
{
	int total_year_A = 0, total_year_B = 0, total_year_C = 0, total_year_D = 0;
	int rac = 0;

	for (int i = 1; i <= now->tm_mon + 1; i++)
	{
		if (1 <= i && i <= 9)
		{
			string file_name = "monthSale_0" + to_string(i) + to_string(year) + ".txt";

			read_file(file_name, total_year_A, total_year_B, total_year_C, total_year_D, rac);
		}
		else
		{
			string file_name = "monthSale_" + to_string(i) + to_string(year) + ".txt";
			read_file(file_name, total_year_A, total_year_B, total_year_C, total_year_D, rac);
		}
	}

	f_year << setw(10) << left << (now->tm_mon + 1) << setw(10) << left << total_year_A << setw(10) << left << total_year_B << setw(10) << left << total_year_C << setw(10) << left << total_year_D << endl;
}
// split datetime to create format
void split_string(string s, string &t, string split_string)
{
	auto start = 0U;
	auto end = s.find(split_string);
	while (end != std::string::npos)
	{
		t.append(s.substr(start, end - start));
		start = end + 1;
		end = s.find(split_string, start);
	}
	t.append(s.substr(start, end));
}

//task2.1
void read_report_day(string name_sales)
{
	system("cls");
	int number_of_sales = 0;
	int qty_A = 0, qty_B = 0, qty_C = 0, qty_D = 0;
	string datetime;
	string filename = "daySale_";
	cout << "Enter date to view report(mm/dd/yy): ";
	cin >> datetime;
	cin.ignore();
	// split datetime to create format filename
	split_string(datetime, filename, "/");
	filename.append(".txt");
	read_file(filename, qty_A, qty_B, qty_C, qty_D, number_of_sales);
	double subtotal = qty_A * price_A + qty_B * price_B + qty_C * price_C + qty_D * price_D;
	double tax = subtotal * 0.0825;
	double total = subtotal + tax;
	// print receipt

	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setw(25) << left << "RECEIPT - COMPANY CS" << endl;
	cout << setw(60) << "." << endl;
	cout << setfill(' ');

	cout << setw(52) << left << "Date:" << datetime << endl;
	cout << setw(40) << left << "Number of sale transactions:" << setw(20) << right << (number_of_sales==0? 0:number_of_sales-1) << endl;
	cout << setw(20) << left << "Sale employee:" << setw(40) << right << name_sales << endl;
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	cout << "Model CS21A (" << price_A << "/per unit)     " << setw(12) << right << qty_A << setw(15) << right << price_A * qty_A << endl;
	cout << "Model CS21B (" << price_B << "/per unit)     " << setw(12) << right << qty_B << setw(15) << right << price_B * qty_B << endl;
	cout << "Model CS21C (" << price_C << "/per unit)     " << setw(12) << right << qty_C << setw(15) << right << price_C * qty_C << endl;
	cout << "Model CS21D (" << price_D << "/per unit)     " << setw(12) << right << qty_D << setw(15) << right << price_D * qty_D << endl;
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout << setw(40) << left << "Subtotal: " << setw(20) << right << subtotal << endl;
	cout << setw(40) << left << "Tax(8.25%) " << setw(20) << right << tax << endl;
	cout << setw(40) << left << "Total:" << setw(20) << right << total << endl;
	//}
	
	system("pause");
}
// task2
void print_ending_day_report(string name_sales)
{
	system("cls");
	read_report_day(name_sales);
}

//task3.1
void read_report_month(string name_sales)
{
	system("cls");
	int number_of_sales = 0;
	int qty_A = 0, qty_B = 0, qty_C = 0, qty_D = 0;
	string datetime;
	string filename = "monthSale_";
	cout << "Enter date to view report(mm/yy): ";
	cin >> datetime;
	cin.ignore();
	// split datetime to create format filename
	split_string(datetime, filename, "/");
	filename.append(".txt");
	read_file(filename, qty_A, qty_B, qty_C, qty_D, number_of_sales);
	double subtotal = qty_A * price_A + qty_B * price_B + qty_C * price_C + qty_D * price_D;
	double tax = subtotal * 0.0825;
	double total = subtotal + tax;
	// print receipt
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setw(25) << left << "RECEIPT - COMPANY CS" << endl;
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout << setw(55) << left << "Month:" << datetime << endl;
	cout << setw(20) << left << "Sale person:" << setw(40) << right << name_sales << endl;
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	cout << "Model CS21A (" << price_A << "/per unit)     " << setw(12) << right << qty_A << setw(15) << right << price_A * qty_A << endl;
	cout << "Model CS21B (" << price_B << "/per unit)     " << setw(12) << right << qty_B << setw(15) << right << price_B * qty_B << endl;
	cout << "Model CS21C (" << price_C << "/per unit)     " << setw(12) << right << qty_C << setw(15) << right << price_C * qty_C << endl;
	cout << "Model CS21D (" << price_D << "/per unit)     " << setw(12) << right << qty_D << setw(15) << right << price_D * qty_D << endl;
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout << setw(40) << left << "Subtotal: " << setw(20) << right << subtotal << endl;
	cout << setw(40) << left << "Tax(8.25%) " << setw(20) << right << tax << endl;
	cout << setw(40) << left << "Total:" << setw(20) << right << total << endl;
	//}
	system("pause");
}
// task3
void print_ending_month_report(string name_sales)
{
	system("cls");
	read_report_month(name_sales);
}

//task 4.1
void read_report_year(string name_sales)
{
	system("cls");
	int number_of_sales = 0;
	int qty_A = 0, qty_B = 0, qty_C = 0, qty_D = 0;
	string datetime;
	string filename = "yearSale_";
	cout << "Enter date to view report(yyyy): ";
	cin >> datetime;
	cin.ignore();
	// split datetime to create format filename
	//split_string(datetime, filename, "/");
	filename.append(datetime);
	filename.append(".txt");
	read_file(filename, qty_A, qty_B, qty_C, qty_D, number_of_sales);
	double subtotal = qty_A * price_A + qty_B * price_B + qty_C * price_C + qty_D * price_D;
	double tax = subtotal * 0.0825;
	double total = subtotal + tax;
	// print receipt
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setw(25) << left << "RECEIPT - COMPANY CS" << endl;
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout << setw(56) << left << "Year:" << datetime << endl;
	cout << setw(20) << left << "Sale person:" << setw(40) << right << name_sales << endl;
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	cout << "Model CS21A (" << price_A << "/per unit)     " << setw(12) << right << qty_A << setw(15) << right << price_A * qty_A << endl;
	cout << "Model CS21B (" << price_B << "/per unit)     " << setw(12) << right << qty_B << setw(15) << right << price_B * qty_B << endl;
	cout << "Model CS21C (" << price_C << "/per unit)     " << setw(12) << right << qty_C << setw(15) << right << price_C * qty_C << endl;
	cout << "Model CS21D (" << price_D << "/per unit)     " << setw(12) << right << qty_D << setw(15) << right << price_D * qty_D << endl;
	cout << setfill('.');
	cout << setw(60) << "." << endl;
	cout << setfill(' ');
	cout << setw(40) << left << "Subtotal: " << setw(20) << right << subtotal << endl;
	cout << setw(40) << left << "Tax(8.25%) " << setw(20) << right << tax << endl;
	cout << setw(40) << left << "Total:" << setw(20) << right << total << endl;
	//}
	system("pause");
}
// task4
void print_ending_year_report(string name_sales)
{
	system("cls");
	read_report_year(name_sales);
}

void menu()
{
	string name_sales;
	cout << "Enter your name: ";
	getline(cin, name_sales);
	string file_name_day = "daySale_" + day + month + to_string(year) + ".txt";
	f_day.open(file_name_day, ios::out | ios::app);

	string file_name_month = "monthSale_" + month + to_string(year) + ".txt";

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
			// task 2.1
			f_month.open(file_name_month, ios::out | ios::trunc);
			print_ending_day_report(name_sales);
			// task 2.2
			save_report_the_month();
			f_month.close();
			break;
		}
		case 3:
		{

			// task 3
			// task 3.1
			string file_name_year = "yearSale_" + to_string(now->tm_year + 1900) + ".txt";
			f_year.open(file_name_year, ios::out);
			print_ending_month_report(name_sales);
			// task 3.2
			save_report_the_year();
			f_year.close();
			break;
		}
		case 4:
		{
			// task 4
			print_ending_year_report(name_sales);
			break;
		}
		default:
			cout << "Good Bye!!! See you again" << endl;
			exit(0);
		}
	}
	f_day.close();
}
int main()
{

	format_date();
	menu();

	return 0;
}