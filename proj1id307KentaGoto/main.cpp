/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 1
 *	\file main.cpp
 *	\brief Main file.  Switch statement used to give user options.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "item.h"
using namespace std;
/*!
 *
 */

void inputFile(vector<Item*> &t, int &multFileOpen);
void expSort(vector<Item*> &t,int sortOption);
void swap(vector<Item*> & a, vector<Item*> & b);
void outputFile(vector<Item*> &t);
void addItem(vector<Item*> &t);
void editItem(vector<Item*> &t);
void deleteItem(vector<Item*> &t);

/*!
 *	Main function contains a switch case statement that calls functions based on user input.
 */

int main(){
	vector<Item*> vectorItem;
	bool valid = true;
	int multFileOpen = 0;
	int tosave;
	cout <<"\t ** kenVentory Tracker 1.0 **" << endl << endl;
	while(valid){
	menu();
	int optionChoice, identNum, QuantSold;
	cin >> optionChoice;
	int itemTest = 0;
	int sortOption;
	Item* testPointer;
	switch (optionChoice) {
		case 0:
			cout << endl << "Would you like to save your file? 1-yes 2-no" << endl;
			cin >> tosave;
			if(tosave==1)
				outputFile(vectorItem);
			valid = false;
			break;
		
		case 1:
			
			cout << "Enter Item Identification number: ";
			cin >> identNum;
			

			for(size_t i = 0; i < vectorItem.size();i++ ){
				if (identNum == vectorItem[i]->get_identCode()){
					
					itemTest++;
					testPointer = vectorItem[i];

				}

			}
			
	        if (itemTest == 0)
	        	cout << "ERROR: Item was NOT found " << endl << endl;
	        cout << "Item: " << testPointer->get_itemName() << endl;
	        cout << "Enter Quantity Sold: ";
			cin >> QuantSold;
			testPointer->set_quantityStock(testPointer->get_quantityStock() - QuantSold);
					testPointer->set_totalSales(testPointer->get_totalSales() + QuantSold * testPointer->get_price());
	        
			//cout << vectorItem[0]->get_quantityStock() << endl;
			//cout << vectorItem[0]->get_totalSales() << endl;
			break;
		
		case 2:
			cout << "Generating report..." << endl << endl;
			for(size_t i = 0; i < vectorItem.size();i++ ){
				cout << "Name: " << vectorItem[i]->get_itemName() << endl;
				cout << "Identification Number: " << vectorItem[i]->get_identCode() << endl;
				cout << "Current total sales: " << vectorItem[i]->get_totalSales() << endl << endl;
			}
			break;
		case 3:
			cout << "The following items are low in supply:" << endl << endl;
			for(size_t i = 0; i < vectorItem.size();i++ ){
				if((vectorItem[i]->get_quantityStock()) < (vectorItem[i]->get_desQuantityStock())){
					cout << "Item: " << vectorItem[i]->get_itemName() << endl;
					cout << "Actual Stock: " << vectorItem[i]->get_quantityStock() << endl;
					cout << "Desired Stock: " << vectorItem[i]->get_desQuantityStock() << endl << endl;
				}
			}
			break;
		case 4:
			cout << "Monthly Update processing..." << endl << endl;
			int aquant, adesquant;
			int carry;
			int carry2;
			for(size_t i = 0; i < vectorItem.size();i++ ){
				cout << "------- Item#" << i+1 << " -------" << endl;
				cout << "Item: " << vectorItem[i]->get_itemName() << endl;
				cout << "ID: " << vectorItem[i]->get_identCode() << endl;
				cout << "Would you like to carry over ACTUAL previous quantity in stock(1-yes 2-no)?" << endl;
				cin >> carry;
				if (carry==2){
				cout << "Enter actual quantity in stock: "; cin >> aquant;
				vectorItem[i]->set_quantityStock(aquant);
				}
				cout << "Would you like to carry over previous DESIRED quantity in stock(1-yes 2-no)?" << endl;
				cin >> carry2;
				if (carry2==2){
				cout << "Enter desired quantity in stock: "; cin >> adesquant; cout << endl;
				vectorItem[i]->set_desQuantityStock(adesquant);
				}
				vectorItem[i]->set_totalSales(0);
			}

			break;
		case 5:
			cout << "Reading in file ..." << endl << endl;
			inputFile(vectorItem,multFileOpen);
			cout << "Done." << endl << endl;
			break;
		case 6:
			cout << "\t Sort Option" << endl << endl;

			cout << "How would you like to sort your Items? " << endl << endl;

			cout << "0. In Alphabetical Order " << endl;
			cout << "1. By Quantity in stock" << endl;
			cout << "2. By Cost" << endl;
			cout << "3. By Price" << endl;
			cout << "4. By expiration date(Shelf life)" << endl;
			cout << "5. By Average monthly volume" << endl;
			cout << "6. By total sales" << endl;
			cout << "7. By ID number" << endl;

			cin >> sortOption;

			expSort(vectorItem,sortOption);
			//cout << vectorItem[0]->get_itemName() << endl;
			cout << "Done " << endl << endl;
			break;
		case 7:
			outputFile(vectorItem);
			break;
		case 8:
			cout << "Adding Item ..." << endl << endl;
			addItem(vectorItem);
			break;
		case 9:
			cout << "*******\t STOCK INVENTORY\t*******" << endl;
			for(size_t i = 0; i < vectorItem.size();i++ ){
					cout << "------- Item#" << i+1 << " -------" << endl;
					cout << "Item: " << vectorItem[i]->get_itemName() << endl;
					cout << "ID: " << vectorItem[i]->get_identCode() << endl;
				
			}
			cout << "Enter item identification code to edit: ";
			editItem(vectorItem);
			break;
		case 10:
			cout << "Enter item identification code to delete: ";
			deleteItem(vectorItem);
			break;
		default:
			cout << "ERROR, you must enter an integer from 0 to 10" << endl << endl; 








}
			
			
	
			



	}











	return 0;
}
/*!
 *	This function reads a file into the program.  Vector of type pointer to Item grows as
 * 	number of items is read.
 */

void inputFile(vector<Item*> &t, int &multFileOpen){
	int fcurrMonth;
	string fitemName;
	int fidentCode;
	int fquantityStock;
	int fdesQuantityStock;
	double fcost;
	double fprice;
	string fsupplier;
	double fshelfLife;
	double favgMonVol;
	double ftotalSales;
	string invFile;
	ifstream file;
	string header;
	string testagain;
	stringstream stin;
	string line;
	int decision;
	if(multFileOpen > 0){
		cout << "WAIT! you have already loaded a file. Would you like to continue? 1-yes 2-no " << endl;
		cout << "If you press 1, file will be loaded and added to current items(no overrides will occur) " << endl;
		cout << ">>";
		cin >> decision;
		if (decision==2)
			return;
	}
	cout << "File name of inventory file: ";
	cin >> invFile;
	Item* pI;
	file.open(invFile.c_str());
	while (!file.is_open()){
		cout << "ERROR could not open this file" << endl;
		cout << "Re-enter File name of inventory file: ";
		cin >> invFile;
		file.open(invFile.c_str());
	}
	getline(file,header);
	multFileOpen++;
	bool FalsetoStop = true;
	if(header[0]=='#'){
	while(FalsetoStop){
		
		getline(file,line);
		if(line=="#end"){
			FalsetoStop = false;
			break;
		}
		stin.str(line);
		
		stin >> fcurrMonth;
		stin >> fitemName;
		stin >> fidentCode;
		stin >> fquantityStock;
		stin >> fdesQuantityStock;
		stin >> fcost;
		stin >> fprice;
		stin >> fsupplier;
		stin >> fshelfLife;
		stin >> favgMonVol;
		stin >> ftotalSales;


		t.push_back(pI);
		t[t.size() - 1] = new Item(fcurrMonth, fitemName, fidentCode, fquantityStock, fdesQuantityStock, fcost, fprice, fsupplier, fshelfLife, favgMonVol, ftotalSales);
		stin.clear();
		


		
	}
	cout <<"Number of Items in inventory: " <<t.size() << endl;
	file.close();
}


}


/*!
 *	This feature of the program is very useful.  When collecting data of any sort, it is often desirable to sort
 *	the data is some way.  This function allows the items to be sorted based on what user wants.
 */
 void expSort(vector<Item*> &t, int sortOption){
 	
 	if (sortOption == 0){
 		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_itemName() > t[j]->get_itemName(); j--)
				swap(t[j-1],t[j]);

 	}

 	else if (sortOption == 1){
 		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_quantityStock() > t[j]->get_quantityStock(); j--)
				swap(t[j-1],t[j]);
	}
	else if (sortOption == 2){
		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_cost() > t[j]->get_cost(); j--)
				swap(t[j-1],t[j]);

	}
	else if (sortOption == 3){
		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_price() > t[j]->get_price(); j--)
				swap(t[j-1],t[j]);

	}
	else if (sortOption == 4){
		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_shelfLife() > t[j]->get_shelfLife(); j--)
				swap(t[j-1],t[j]);

	}
	else if (sortOption == 5){
		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_avgMonVol() > t[j]->get_avgMonVol(); j--)
				swap(t[j-1],t[j]);

	}
	else if (sortOption == 6){
		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_totalSales() > t[j]->get_totalSales(); j--)
				swap(t[j-1],t[j]);

	}
	else if (sortOption == 7){
		for(size_t i=1; i < t.size(); i++)
        	for(size_t j=i; j>0 && t[j-1]->get_identCode() > t[j]->get_identCode(); j--)
				swap(t[j-1],t[j]);
	}

	else
		cout << "ERROR: Invalid option" << endl << endl;


 



}

/*!
 *	Small function to swap two pointers.
 */

void swap(vector<Item*> & a, vector<Item*> & b){
	vector<Item*> t;
	t = a;
	a = b;
	b = t;
}

/*!
 *	When the user is done with his/her list of items. It's common sense to be able to save it to a file.  
 *	This function does just that. 
 */

void outputFile(vector<Item*> &t){
	cout << "Enter filename to write Items: ";
	string filename;
	ofstream myfile;
	cin >> filename;
	myfile.open(filename.c_str());


	if (!myfile.is_open()){
		cout << "ERROR could not open this file" << endl;
	}
	myfile << "#-Month-Item-ID-RealQuantity-DesiredQuantity-Cost-Price-Supplier-Shelflife-AvgMonthyVolume-Totalsales" << endl;
	for(size_t i = 0; i < t.size(); i++){
		myfile << t[i]->get_currMonth() << " ";
		myfile << t[i]->get_itemName() << " ";
		myfile << t[i]->get_identCode() << " ";
		myfile << t[i]->get_quantityStock() << " ";
		myfile << t[i]->get_desQuantityStock() << " ";
		myfile << t[i]->get_cost() << " ";
		myfile << t[i]->get_price() << " ";
		myfile << t[i]->get_supplier() << " ";
		myfile << t[i]->get_shelfLife() << " ";
		myfile << t[i]->get_avgMonVol() << " ";
		myfile << t[i]->get_totalSales() << endl;

	}
	myfile << "#end";
	myfile.close();


}
/*!
 *	Function to individually add an item.
 */

void addItem(vector<Item*> &t){
	int icurrMonth;
	string iitemName;
	int iidentCode;
	int iquantityStock;
	int idesQuantityStock;
	double icost;
	double iprice;
	string isupplier;
	double ishelfLife;
	double iavgMonVol;
	double itotalSales;
	Item* k;
	int ans;
	cout << "Do you have the name of item?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter name of new Item: "; 
	cin >> iitemName;
	}
	else
		iitemName = "*";
	cout << endl;



	cout << "Do you know the current Month?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter current month(1-Jan, 2-Feb, 3-March, etc ...) : "; 
	cin >> icurrMonth;
	}
	else
		icurrMonth = -1;
	cout << endl;
	

	cout << "Do you have the unique identification code?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter unique identification code: "; 
	cin >> iidentCode;
	}
	else
		iidentCode = -1;
	cout << endl;


	cout << "Do you have the number of quantity in stock?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter quantity: "; 
	cin >> iquantityStock;
	}
	else
		iquantityStock = -1;
	cout << endl;
	

	cout << "Do you the number of DESIRED quantity in stock?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter desired quantity: "; 
	cin >> idesQuantityStock;
	}
	else
		idesQuantityStock = -1;
	cout << endl;
	
	cout << "Do you have the cost of the item?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter cost: "; 
	cin >> icost;
	}
	else
		icost = -1;
	cout << endl;
	

	cout << "Do you have the price of the item?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter price: "; 
	cin >> iprice;
	}
	else
		iprice = -1;
	cout << endl;
	

	cout << "Do you have the name of supplier of the item?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter name of supplier: "; 
	cin >> isupplier;
	}
	else
		isupplier = "*";
	cout << endl;

	cout << "Do you have the expiration date of item?" << endl;
	cout << "\t1. YES  2. NO" << endl;
	cin >> ans;


	if (ans==1){
	cout << "Enter expiration date(11.01014 - Nov 1st, 2014; 11.02015 - Nov 2nd,2015; etc...): "; 
	cin >> ishelfLife;
	}
	else
		ishelfLife = -1;
	cout << endl;
	

	
	

	iavgMonVol = 0;
	itotalSales = 0;
	t.push_back(k);
	t[t.size() - 1] = new Item(icurrMonth, iitemName, iidentCode, iquantityStock, idesQuantityStock, icost, iprice, isupplier, ishelfLife, iavgMonVol, itotalSales);
	cout << t.size() << endl;





}

/*!
 *	Function to edit existing items.
 */

void editItem(vector<Item*> &t){
	int identNum;
	int change;
	string s_change;
	int i_change;
	double d_change;
	cin >> identNum;
	int success = 0;
	cout << "What would you like to edit about this Item?" << endl << endl;
	cout << "1. Current Month(1-January, 2-February, 3-March, etc...)" << endl;
	cout << "2. Item name" << endl;
	cout << "3. Identification number" << endl;
	cout << "4. Quantity in stock" << endl;
	cout << "5. Desired quantity in stock" << endl;
	cout << "6. Cost" << endl;
	cout << "7. Price" << endl;
	cout << "8. Supplier" << endl;
	cout << "9. Expiration date(11.01014- Nov 1st,2014 11.02015 - Nov 2nd,2015 etc...)" << endl;
	cout << "10. Average Monthly Volume" << endl;
	cout << "11. Total sales" << endl << endl;
	cin >> change;
	cout << "Enter change: ";
	if (change == 2 || change == 8)
		cin >> s_change;
	else if (change == 1 || change == 3 || change == 4 || change == 5)
		cin >> i_change;
	else
		cin >> d_change;

	for(size_t i = 0; i < t.size();i++ ){
		if (identNum == t[i]->get_identCode()){
			success++;
			if (change==1)
				t[i]->set_currMonth(i_change);
			else if (change==2)
				t[i]->set_itemName(s_change);
			else if (change==3)
				t[i]->set_identCode(i_change);
			else if (change==4)
				t[i]->set_quantityStock(i_change);
			else if (change==5)
				t[i]->set_desQuantityStock(i_change);
			else if (change==6)
				t[i]->set_cost(d_change);
			else if (change==7)
				t[i]->set_price(d_change);
			else if (change==8)
				t[i]->set_supplier(s_change);
			else if (change==9)
				t[i]->set_shelfLife(d_change);
			else if (change==10)
				t[i]->set_avgMonVol(d_change);
			else if (change==11)
				t[i]->set_totalSales(d_change);



		}
	}
	if (success == 0)
		cout << "Error: item not found, try again" << endl << endl;

}
/*!
 *	Function to delete existing Items.
 */
void deleteItem(vector<Item*> &t){
	int identiCode;
	cin >> identiCode;
	

	for(size_t i = 0; i < t.size();i++ ){
		if (identiCode == t[i]->get_identCode()){
			delete t[i];
			t.erase(t.begin()+i);
	}		
	}
}















