/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 1
 *	\file item.cpp
 *	\brief Contains definition for members of class Item. The implementations.
 */
#include "item.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
/*!
 * All members of class Item and funciton menu() defined here.
 */


int Item::get_currMonth()const{
	return _currMonth;
}

void Item::set_currMonth(int currMonth){
	_currMonth = currMonth;
}


string Item::get_itemName()const{
 	return _itemName;

}
void Item::set_itemName(string itemName){
	_itemName = itemName;
}

int Item::get_identCode()const{
	return _identCode;
}

void Item::set_identCode(int identCode){
	_identCode = identCode;
}
int Item::get_quantityStock()const{
	return _quantityStock;
}

void Item::set_quantityStock(int quantityStock){
	_quantityStock = quantityStock;
}

int Item::get_desQuantityStock()const{
	return _desQuantityStock;
}

void Item::set_desQuantityStock(int desQuantityStock){
	_desQuantityStock = desQuantityStock;
}

double Item::get_cost()const{
	return _cost;
}
void Item::set_cost(double cost){
	_cost = cost;
}

double Item::get_price()const{
	return _price;
}
void Item::set_price(double price){
	_price = price;
}

string Item::get_supplier()const{
	return _supplier;
}
void Item::set_supplier(string supplier){
	_supplier = supplier;
}

double Item::get_shelfLife()const{
	return _shelfLife;
}
void Item::set_shelfLife(double shelfLife){
	_shelfLife = shelfLife;
}

double Item::get_avgMonVol()const{
	return _avgMonVol;
}

void Item::set_avgMonVol(double avgMonVol){
	_avgMonVol = avgMonVol;
}
double Item::get_totalSales()const{
	return _totalSales;
}

void Item::set_totalSales(double totalSales){
	_totalSales = totalSales;
}



void menu(){

	cout <<"0. Exit" << endl;
	cout <<"1. Item Sale" << endl;
	cout <<"2. Daily Report" << endl;
	cout <<"3. Weekly Check" << endl;
	cout <<"4. Monthly Update" << endl;
	cout <<"5. Load Inventory File" << endl;
	cout <<"6. Sort File by Key" << endl;
	cout <<"7. Save Inventory to a File" << endl;
	cout <<"8. Add a New Item" << endl;
	cout <<"9. Edit an Item" << endl;
	cout <<"10. Delete an Item" << endl;
	cout << ">>";
}


	

