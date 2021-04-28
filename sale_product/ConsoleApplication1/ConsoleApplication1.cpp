#include <iostream>
#include<string>
#include<ctime>
using namespace std;
// define struct product
typedef struct product {
	string name_product;
	float price;
}Product;

void menu(){
	string name_sales;
	cout << "Enter your name: ";
	cin >> name_sales;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	while(1) {
		system("cls");
		cout << "SALE PRODUCTS CS - " << name_sales << endl;
		cout << "--------------------------------";
		cout << "\tToday: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_year << endl;
	}
}
int main(){
	menu();
	return 0;

}