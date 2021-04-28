#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include<fstream>
#include <cstdlib>
#include<iomanip>
using namespace std;
int number_day_sales=0;
time_t t = time(0);
tm *now = localtime(&t);
string day, month;
int year;
fstream f;
double price_A = 11.99, price_B = 12.99, price_C = 14.99, price_D = 15.99;
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

	f << format_sale() << "\t" << setw(10) << left << qty_A << setw(10) << left << qty_B << setw(10) << left << qty_C << setw(10) << left << qty_D << endl;
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
// split datetime to create format
void split_string(string s,string &t, string split_string){
	auto start = 0U;
    auto end = t.find(split_string);
    while (end != std::string::npos)
    {
        t.append(s.substr(start, end - start));
        start = end + 1;
        end = s.find(split_string, start);
    }
	t.append(s.substr(start, end));
}


//task2.1
void read_report_day(string name_sales,int &total_qty_A,int &total_qty_B,int &total_qty_C,int &total_qty_D){
	system("cls");
	int number_of_sale=0;
	string datetime;
	string filename="dayale_";
	cout<<"Enter date to view report(mm/dd/yy): ";
	cin>>datetime;
	cin.ignore();
	// split datetime to create format filename
    split_string(datetime,filename,"/");
	filename.append(".txt");
	ifstream fi(filename);
	if(fi.good() == false){
		cout<<"The file you want to view report which don't exist"<<endl;
	}
	else{
		int qty_A=0,qty_B=0,qty_C=0,qty_D=0;
		string tmp;
		string s;
		while(!fi.eof())
		{
			number_of_sale+=1;
			getline(cin,s);
			stringstream ss;
			ss.str(s);
			ss>>s;
			ss>>tmp;
			qty_A+= stoi(tmp);
			ss>>tmp;
			qty_B+= stoi(tmp);
			ss>>tmp;
			qty_C+= stoi(tmp);
			ss>>tmp;
			qty_D+= stoi(tmp);
		}

		double subtotal = qty_A*price_A + qty_B*price_B + qty_C*price_C + qty_D*price_D;
		double tax = subtotal*0.0825;
		double total = subtotal + tax;
		total_qty_A+=qty_A; total_qty_B+=qty_B;total_qty_C+=qty_C; total_qty_D+=qty_D;
		// print receipt

		cout << setfill('.');
		cout << setw(60) << "." << endl;
		cout << setw(25) << left << "RECEIPT - COMPANY CS" << endl;
		cout << setw(60) << "." << endl;
		cout << setfill(' ');
		cout << setw(52) << left << "Date:" << day << "/" << month << "/" << year << endl;
		cout << setw(40) << left << "Number of sale transactions:" << setw(20) << right << number_of_sale << endl;
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
	}
	system("pause");
}
// task2
void print_ending_day_report(string name_sales){
	system("cls");
	int total_qty_A=0,total_qty_B=0,total_qty_C=0,total_qty_D=0;
	read_report_day(name_sales,total_qty_A,total_qty_B,total_qty_C,total_qty_D);
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
			
			print_ending_day_report(name_sales);
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