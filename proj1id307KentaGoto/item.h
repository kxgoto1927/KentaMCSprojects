/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 1
 *	\file item.cpp
 *	\brief Contains function and class prototypes.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*!
 * \class Item
 * \brief An Item class, used to make different types of products for a grocery store.
 */


class Item{
public:
	/*! 
	* A constructor.  There is no default constructor.  Every instance of class Item is controlled by the program.
	*/
	Item(int currMonth,  string itemName,  int identCode,  int quantityStock,  int desQuantityStock,  double cost,  double price, string supplier,  double shelfLife,  double avgMonVol,  double totalSales){ _currMonth = currMonth; _itemName = itemName; _identCode = identCode; _quantityStock = quantityStock; _desQuantityStock = desQuantityStock; _cost = cost; _price = price; _supplier = supplier; _shelfLife = shelfLife; _avgMonVol = avgMonVol; _totalSales = totalSales;}
	/*!
	 * Accessor and Mutator functions for private members.
	 */
	
	int get_currMonth()const;         
	void set_currMonth(int currMonth);  


	string get_itemName()const;
	void set_itemName(string itemName);


	int get_identCode()const;
	void set_identCode(int identCode);

	int get_quantityStock()const;
	void set_quantityStock(int quantityStock);

	int get_desQuantityStock()const;
	void set_desQuantityStock(int desQuantityStock);

	double get_cost()const;
	void set_cost(double cost);

	double get_price()const;
	void set_price(double price);

	string get_supplier()const;
	void set_supplier(string supplier);

	double get_shelfLife()const;
	void set_shelfLife(double shelfLife);

	double get_avgMonVol()const;
	void set_avgMonVol(double avgMonVol);

	double get_totalSales()const;
	void set_totalSales(double totalSales);

	~Item() {}



private:
	int _currMonth;
	string _itemName;
	int _identCode;
	int _quantityStock;
	int _desQuantityStock;
	double _cost;
	double _price;
	string _supplier;
	double _shelfLife;
	double _avgMonVol;
	double _totalSales;

};




/*!
 * Menu function to interact with client.
 */

void menu();










