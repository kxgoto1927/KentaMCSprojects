/*! \file Item.java
 *	\brief Main item class.
 *	\Author Kenta Goto
 */

class Item{
	private int _currMonth;
	private String _itemName;
	private int _identCode;
	private int _quantityStock;
	private int _desQuantityStock;
	private double _cost;
	private double _price;
	private String _supplier;
	private double _shelfLife;
	private double _avgMonVol;
	private double _totalSales;

	public Item(int currMonth,  String itemName,  int identCode,  int quantityStock,  int desQuantityStock,  double cost,  double price, String supplier,  double shelfLife,  double avgMonVol,  double totalSales){
		_currMonth = currMonth;
		_itemName = itemName;
		_identCode = identCode;
		_quantityStock = quantityStock;
		_desQuantityStock = desQuantityStock;
		_cost = cost;
		_price = price;
		_supplier = supplier;
		_shelfLife = shelfLife;
		_avgMonVol = avgMonVol;
		_totalSales = totalSales;
	}
	Item(){
		_currMonth = -1;
		_itemName = "*";
		_identCode = -1;
		_quantityStock = -1;
		_desQuantityStock = -1;
		_cost = -1;
		_price = -1;
		_supplier = "*";
		_shelfLife = -1;
		_avgMonVol = -1;
		_totalSales = -1;
	}



	public int get_currMonth(){
		return _currMonth;
	}
	public void set_currMonth(int currMonth){
		_currMonth = currMonth;
	}

	public String get_itemName(){
		return _itemName;
	}
	public void set_itemName(String itemName){
		_itemName = itemName;
	}

	public int get_identCode(){
		return _identCode;
	}

	public void set_identCode(int identCode){
		_identCode = identCode;
	}

	public int get_quantityStock(){
		return _quantityStock;
	}
	public void set_quantityStock(int quantityStock){
		_quantityStock = quantityStock;
	}

	public int get_desQuantityStock(){
		return _desQuantityStock;
	}
	public void set_desQuantityStock(int desQuantityStock){
		_desQuantityStock = desQuantityStock;
	}

	public double get_cost(){
		return _cost;
	}
	public void set_cost(double cost){
		_cost = cost;
	}

	public double get_price(){
		return _price;
	}
	public void set_price(double price){
		_price = price;
	}

	public String get_supplier(){
		return _supplier;
	}
	public void set_supplier(String supplier){
		_supplier = supplier;
	}

	public double get_shelfLife(){
		return _shelfLife;
	}
	public void set_shelfLife(double shelfLife){
		_shelfLife = shelfLife;
	}

	public double get_avgMonVol(){
		return _avgMonVol;
	}
	public void set_avgMonVol(double avgMonVol){
		_avgMonVol = avgMonVol;
	}

	public double get_totalSales(){
		return _totalSales;
	}
	public void set_totalSales(double totalSales){
		_totalSales = totalSales;
	}



}