/*! \file Inventory class.
 *	\brief Main file to execute the program.
 *	\Author Kenta Goto
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.util.*;
import java.io.*;

class Inventory extends Item
{
	public static void readFile(String file,ArrayList<Item> itemList){
		FileInputStream fin;
		try{
			fin = new FileInputStream(file);
			BufferedReader d = new BufferedReader(new InputStreamReader(fin));
			//System.out.println(new DataInputStream(fin).readLine());
			String line;
			d.readLine();
			while ((line = d.readLine())!= null){
			//System.out.println(line);
			String[] parts = line.split(" ");
				int currMonth = Integer.parseInt(parts[0]);
				String itemName = parts[1];
				int identCode = Integer.parseInt(parts[2]);
				int quantityStock = Integer.parseInt(parts[3]);
				int desQuantityStock = Integer.parseInt(parts[4]);
				double cost = Double.parseDouble(parts[5]);
				double price = Double.parseDouble(parts[6]);
				String supplier = parts[7];
				double shelfLife = Double.parseDouble(parts[8]);
				double avgMonVol = Double.parseDouble(parts[9]);
				double totalSales = Double.parseDouble(parts[10]);
				itemList.add(new Item(currMonth,itemName,identCode,quantityStock,desQuantityStock,cost,price,supplier,shelfLife,avgMonVol,totalSales));
		}
			fin.close();
		}
		catch (IOException e){
			System.err.println("Unable to read from file");
			System.exit(-1);
		}
	}
	public static void writeFile(String name, ArrayList<Item> itemList){
BufferedWriter writer = null;
try
{
    writer = new BufferedWriter( new FileWriter( name));
    writer.write( "#-Month-Item-ID-RealQuantity-DesiredQuantity-Cost-Price-Supplier-Shelflife-AvgMonthyVolume-Totalsales");
    writer.newLine();
    	for (int i=0; i < itemList.size(); i++){
    	String currMonth = Integer.toString(itemList.get(i).get_currMonth());
		String itemName = itemList.get(i).get_itemName();
		String identCode = Integer.toString(itemList.get(i).get_identCode());
		String quantityStock = Integer.toString(itemList.get(i).get_quantityStock());
		String desQuantityStock = Integer.toString(itemList.get(i).get_desQuantityStock());
		String cost = Double.toString(itemList.get(i).get_cost());
		String price = Double.toString(itemList.get(i).get_price());
		String supplier = itemList.get(i).get_supplier();
		String shelfLife = Double.toString(itemList.get(i).get_shelfLife());
		String avgMonVol = Double.toString(itemList.get(i).get_avgMonVol());
		String totalSales = Double.toString(itemList.get(i).get_totalSales());
		//String finalString = currMonth + " " + itemName + " " + identCode + " " + quantityStock + " " + desQuantityStock + " " + cost " " + price + " " + supplier + " " + shelfLife + " " + avgMonVol + " " + totalSales;
		writer.write(currMonth);
		writer.write(" ");
		writer.write(itemName);
		writer.write(" ");
		writer.write(identCode);
		writer.write(" ");
		writer.write(quantityStock);
		writer.write(" ");
		writer.write(desQuantityStock);
		writer.write(" ");
		writer.write(cost);
		writer.write(" ");
		writer.write(price);
		writer.write(" ");
		writer.write(supplier);
		writer.write(" ");
		writer.write(shelfLife);
		writer.write(" ");
		writer.write(avgMonVol);
		writer.write(" ");
		writer.write(totalSales);
		writer.newLine();
	}
}
catch ( IOException e)
{
}
finally
{
    try
    {
        if ( writer != null)
        writer.close( );
    }
    catch ( IOException e)
    {
    }
}

	}

	

	public static void main (String[] args){
		System.out.println("*****  kenVentory Tracker 1.0  *****");
		boolean usert = true;
		ArrayList<Item> itemList = new ArrayList<Item>();
		while(usert){
		System.out.println("0. Exit");
		System.out.println("1. Item Sale");
		System.out.println("2. Daily Report");
		System.out.println("3. Weekly Check");
		System.out.println("4. Monthly Update");
		System.out.println("5. Load Inventory");
		System.out.println("6. Sort File by Key");
		System.out.println("7. Save Inventory to a File");
		System.out.println("8. Add a New Item");
		System.out.println("9. Edit an Item");
		System.out.println("10. Delete an Item");
		System.out.print(">>");
		Scanner input = new Scanner(System.in);
		int choice;
		choice = input.nextInt();
		switch(choice){
			case 0:
				usert = false;
				break;
			case 1: 
				System.out.println("------- All Items -------");
				for(int i=0; i < itemList.size(); i++){
					System.out.println("-------- Item#" + (i+1) + " -------");
					System.out.println("Item: " + (itemList.get(i)).get_itemName());
					System.out.println("ID: " + (itemList.get(i)).get_identCode());
				}
				Scanner itemid = new Scanner(System.in);
				System.out.println("--------------");
				System.out.print("Enter ID:");
				int itemx;
				itemx = itemid.nextInt();
				System.out.print("Enter quantity of sales: ");
				int salesx;
				int foundx = 0;
				salesx = itemid.nextInt();
				for (int j = 0; j< itemList.size(); j++){
					if (itemList.get(j).get_identCode()==itemx){
						double pricex;
						pricex = itemList.get(j).get_price();
						itemList.get(j).set_totalSales(salesx*pricex);
						foundx++;
					}
				}
				if(foundx==0)
					System.out.println("Error, did not find item");

				break;
			case 2:

				System.out.println(" Total Number of Items: " + itemList.size());
				for(int i=0; i< itemList.size(); i++){
					System.out.println("-------- Item#" + (i+1) + " -------");
					System.out.println("Item: " + (itemList.get(i)).get_itemName());
					System.out.println("ID: " + (itemList.get(i)).get_identCode());
					System.out.println("Total Sales: " + "$" + (itemList.get(i)).get_totalSales());
				}
				break;
			case 3:
				System.out.println("Checking for low supply....");
				for(int i=0; i < itemList.size(); i++){
					int x;
					int y;
					x = itemList.get(i).get_quantityStock();
					y = itemList.get(i).get_desQuantityStock();
					if (x < y){
						System.out.println("Item:" + itemList.get(i).get_itemName());
					}
					else
						System.out.println("No items are in low supply");
				}
				break;
			case 4:
				System.out.println("------- Monthly Update -------");
				Scanner answer = new Scanner(System.in);
				for(int i=0; i < itemList.size(); i++){
					System.out.println("-------- Item#" + (i+1) + " -------");
					System.out.println("Item: " + (itemList.get(i)).get_itemName());
					System.out.println("ID: " + (itemList.get(i)).get_identCode());
					System.out.println("Would you like to carry over ACTUAL previous quantity in stock(1-yes 2-no)");
					int option;
					int k = 0;
					int l = 0;
					int quantity;
					option = answer.nextInt();
					if (option==2){
						System.out.print("Enter actual quantity in stock: ");
						quantity = answer.nextInt();
						itemList.get(i).set_quantityStock(quantity);

					}
					System.out.println("Would you like to carry over DESIRED previous quantity in stock(1-yes 2-no)");
					option = answer.nextInt();
					if (option==2){
						System.out.print("Enter desired quantity in stock: ");
						quantity = answer.nextInt();
						itemList.get(i).set_desQuantityStock(quantity);
					}
				}
				break;
			case 5:
				System.out.println("Reading in a File....");
				System.out.print("Name of file: ");
				String nameFile;
				Scanner fileput = new Scanner(System.in);
				nameFile = fileput.nextLine();
				readFile(nameFile,itemList);
				break;
			case 6:
				System.out.println("Sort By...");
				System.out.println("0. Alphabetical Order ");
				System.out.println("1. Quantity in stock");
				System.out.println("2. Cost");
				System.out.println("3. Price");
				System.out.println("4. Shelflife(Expirationdate)");
				System.out.println("5. Average monthly volume");
				System.out.println("6. Total Sales");
				System.out.println("7. ID");
				Scanner newchoice = new Scanner(System.in);
				int numb = newchoice.nextInt();
				if (numb == 0){
 					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && (itemList.get(j-1)).get_itemName().compareTo((itemList.get(j)).get_itemName()) > 0; j--)
							Collections.swap(itemList, j-1,j);

 						}
 				else if (numb == 1){
 					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && (itemList.get(j-1)).get_quantityStock() > (itemList.get(j)).get_quantityStock(); j--)
							Collections.swap(itemList,j-1,j);
						}
						
				else if (numb == 2){
					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && itemList.get(j-1).get_cost() > itemList.get(j).get_cost(); j--)
							Collections.swap(itemList,j-1,j);

						}
				else if (numb == 3){
					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && itemList.get(j-1).get_price() > itemList.get(j).get_price(); j--)
							Collections.swap(itemList,j-1,j);

						}
				else if (numb == 4){
					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && itemList.get(j-1).get_shelfLife() > itemList.get(j).get_shelfLife(); j--)
							Collections.swap(itemList,j-1,j);

						}
				else if (numb == 5){
					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && itemList.get(j-1).get_avgMonVol() > itemList.get(j).get_avgMonVol(); j--)
							Collections.swap(itemList,j-1,j);

						}
				else if (numb == 6){
					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && itemList.get(j-1).get_totalSales() > itemList.get(j).get_totalSales(); j--)
							Collections.swap(itemList,j-1,j);

						}
				else if (numb == 7){
					for(int i=1; i < itemList.size(); i++)
        				for(int j=i; j>0 && itemList.get(j-1).get_identCode() > itemList.get(j).get_identCode(); j--)
							Collections.swap(itemList,j-1,j);
				}

				else
					System.out.println("ERROR: Invalid option");
				
				break;
			case 7:
			System.out.print("Name of File: ");
			Scanner file1 = new Scanner(System.in);
			String filename;
			filename = file1.nextLine();
			writeFile(filename,itemList);

			break;

			case 8:
			int icurrMonth;
			String iitemName;
			int iidentCode;
			int iquantityStock;
			int idesQuantityStock;
			double icost;
			double iprice;
			String isupplier;
			double ishelfLife;
			double iavgMonVol = 0;
			double itotalSales = 0;
			Scanner newitem1 = new Scanner(System.in);
			System.out.println("Adding Item...");
			System.out.println("Do you have the name of item?(1-yes 2-no)");
			int input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter name: ");
				iitemName = newitem1.next();

			}
			else
				iitemName = "*";

			System.out.println("Do you know the current month(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter current month(1-Jan, 2-feb,3-march,etc..): ");
				icurrMonth = newitem1.nextInt();
			}
			else
				icurrMonth = -1;

			System.out.println("Do you have the unique identification code(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter unique identification code: ");
				iidentCode = newitem1.nextInt();
			}
			else
				iidentCode = -1;

			System.out.println("Do you have the number of quantity in stock(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter quantity in stock");
				iquantityStock = newitem1.nextInt();
			}
			else
				iquantityStock = -1;

			System.out.println("Do you know the DESIRED quantity in stock(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter desired quantity: ");
				idesQuantityStock = newitem1.nextInt();
			}
			else
				idesQuantityStock = -1;

			System.out.println("Do you have the cost of the item(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter cost: ");
				icost = newitem1.nextDouble();
			}
			else
				icost = -1;

			System.out.println("Do you have the price of the item(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter price: ");
				iprice = newitem1.nextDouble();
			}
			else
				iprice = -1;

			System.out.println("Do you have the name of supplier of item(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter name of supplier: ");
				isupplier = newitem1.next();
			}
			else
				isupplier = "*";

			
			System.out.println("Do you have the expiration date of the item(1-yes 2-no)?");
			input1 = newitem1.nextInt();
			if (input1==1){
				System.out.print("Enter expiration date(11.01014 - Nov 1st, 2014; 11.02015 - Nov 2nd, 2015; etc..): ");
				ishelfLife = newitem1.nextDouble();
			}
			else
				ishelfLife = -1;
			itemList.add(new Item(icurrMonth,iitemName,iidentCode,iquantityStock,idesQuantityStock,icost,iprice,isupplier,ishelfLife,iavgMonVol,itotalSales));
			break;
			case 9:
			System.out.println("Editiong Item...");
			System.out.println("------- All Items -------");
				for(int i=0; i < itemList.size(); i++){
					System.out.println("-------- Item#" + (i+1) + " -------");
					System.out.println("Item: " + (itemList.get(i)).get_itemName());
					System.out.println("ID: " + (itemList.get(i)).get_identCode());
				}
			System.out.println("------- All Items -------");
			System.out.print("Enter ID:");
			Scanner idNum = new Scanner(System.in);
			int numbb = idNum.nextInt();
			int foundxy = 0;
			int menuOption;
			for (int j = 0; j< itemList.size(); j++){
					if ((itemList.get(j)).get_identCode()==numbb){
						//double pricex;
						//pricex = itemList.get(j).get_price();
						//itemList.get(j).set_totalSales(salesx*pricex);
						System.out.println("What would you like to edit about this item?");
						System.out.println("0. Name");
						System.out.println("1. Current Month");
						System.out.println("2. Unique Identification Code");
						System.out.println("3. Quantity in Stock");
						System.out.println("4. Desired Quantity in Stock");
						System.out.println("5. Cost");
						System.out.println("6. Price");
						System.out.println("7. Supplier");
						System.out.println("8. ShelfLife");
						System.out.println("9. Average Monthly Sales");
						System.out.println("10. Total Sales");
						menuOption = idNum.nextInt();
						double doubleval;
						String name2;
						if (menuOption==0){
							System.out.print("NEW Name: ");
							name2 = idNum.next();
							(itemList.get(j)).set_itemName(name2);


						}
						else if (menuOption==1){
							System.out.print("Enter NEW current month(1-Jan, 2-feb,3-march,etc..): ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_currMonth(menuOption);
							
						}
						else if (menuOption==2){
							System.out.print("Enter NEW Identification Code: ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_identCode(menuOption);
							
						}
						else if (menuOption==3){
							System.out.print("Enter NEW quantity in stock: ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_quantityStock(menuOption);
						}
						else if (menuOption==4){
							System.out.print("Enter NEW Desired Quantity in Stock: ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_desQuantityStock(menuOption);
						}
						else if (menuOption==5){
							System.out.print("Enter NEW cost: ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_cost(menuOption);
						}
						else if (menuOption==6){
							System.out.print("Enter NEW price: ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_price(menuOption);
						}
						else if (menuOption==7){
							System.out.print("Enter NEW supplier: ");
							name2 = idNum.next();
							(itemList.get(j)).set_supplier(name2);
						}
						else if (menuOption==8){
							System.out.print("Enter NEW expiration date(11.01014 - Nov 1st, 2014; 11.02015 - Nov 2nd, 2015; etc..) ");
							doubleval = idNum.nextDouble();
							(itemList.get(j)).set_shelfLife(doubleval);
						}
						else if (menuOption==9){
							System.out.print("Enter NEW average Monthly volume: ");
							menuOption = idNum.nextInt();
							(itemList.get(j)).set_avgMonVol(menuOption);
						}
						else if (menuOption==10){
							System.out.print("Enter NEW total sales: ");
							doubleval = idNum.nextDouble();
							(itemList.get(j)).set_totalSales(doubleval);
						}
						else
							System.out.println("Error, invalid option");


						foundxy++;
					}
				}
				if(foundxy==0)
					System.out.println("Error, did not find item");
			break;
			case 10:
			System.out.println("Delete an Item....");
			System.out.println("------- All Items -------");
				for(int i=0; i < itemList.size(); i++){
					System.out.println("-------- Item#" + (i+1) + " -------");
					System.out.println("Item: " + (itemList.get(i)).get_itemName());
					System.out.println("ID: " + (itemList.get(i)).get_identCode());
				}
			System.out.println("------- All Items -------");
			System.out.print("Enter ID:");
			Scanner idNum1 = new Scanner(System.in);
			int numbb1 = idNum1.nextInt();
			for (int j = 0; j< itemList.size(); j++){
					if ((itemList.get(j)).get_identCode()==numbb1){
						itemList.remove(j);
					}
				}
			break;

		}
		}
		
	}
}