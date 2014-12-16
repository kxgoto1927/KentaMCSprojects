/**!
 * \author Kenta Goto
 * \file main.cpp
 * \brief Project 2.  Main file used to prompt for user-friendly menu driven program. Also contains test code.
 */
 #include <iostream>
 #include "poly.h"
 #include <vector>

 using namespace std;
void menu();
 int main() {
 	

 	/* Test multiply
	
	Polynomial Kenta;

	Kenta.insert(2,1);
	Kenta.insert(-5,1);

	cout << endl << Kenta << endl;
	Kenta.printPoly();
	
	Polynomial Goto;

	Goto.insert(-2,2);
	Goto.insert(-3,5);
	cout << endl << Goto << endl;
	Polynomial testmult;

	testmult = Polynomial::mult(Kenta,Goto);
	cout << endl << testmult << endl;
	testmult.printPoly();
	
	*/

	 /*Test Derivative
	Polynomial Deriv;

	Deriv.insert(-4,0);
	Deriv.insert(3,2);
	Deriv.insert(2,3);
	Deriv.derivative();
	cout << Deriv;
	*/

	/* Test Integral
	Polynomial Integ;

	Integ.insert(0,2);
	Integ.insert(0,4);
	Integ.antiderivative();
	cout << Integ;
	*/

	/* Testing Reduce.  Combines like terms.  Sorting will be done later.
	Polynomial Reduce;

	Reduce.insert(-4,3);
	Reduce.insert(1,3);
	Reduce.insert(1,3);
	Reduce.insert(1,4);
	Reduce.insert(5,3);
	Reduce.insert(3,2);
	Reduce.insert(3,5);
	Reduce.insert(-4,5);
	Reduce.insert(-2,2);
	Reduce.insert(-2,2);
	Reduce.insert(2,0);
	Reduce.insert(-4,0);
	Reduce.insert(0,0);

	cout << endl << Reduce << endl;

	Reduce.reduce();

	cout << endl << Reduce << endl;
	*/
	/* Testing overloading + operator
	Polynomial Test1;
	Polynomial Test2;
	Polynomial Test3;

	Test1.insert(1,1);
	cout << endl << Test1 << endl;
	Test2.insert(-2,2);
	cout << endl << Test2 << endl;
	Test3 = Test1 + Test2;
	cout << endl << Test3 << endl;
	*/
	/*Testing overloading - operator
	Polynomial Test4;
	Polynomial Test5;
	Polynomial Test6;

	Test4.insert(1,1);
	cout << endl << Test4 << endl;
	Test5.insert(-2,2);
	Test5.insert(-3,2);
	cout << endl << Test5 << endl;
	Test6 = Test4 - Test5;
	cout << endl << Test6 << endl;
	*/

	/*Testing overloading * operator
	Polynomial Test7;
	Polynomial Test8;
	Polynomial Test9;

	Test7.insert(1,1);
	cout << endl << Test7 << endl;
	Test8.insert(-2,2);
	Test8.insert(-3,2);
	cout << endl << Test8 << endl;
	Test9 = Test7 * Test8;
	cout << endl << Test9 << endl;
	*/

	/* Test mergsort to sort Polynomial in descending degree order.

	Polynomial Kenta;
	Kenta.insert(1,1);
	Kenta.insert(2,2);
	Kenta.insert(1,0);
	Kenta.insert(3,3);
	Kenta.insert(2,3);
	Kenta.insert(3,2);

	cout << endl << Kenta << endl;

	Kenta.mergsort();

	cout << endl << Kenta << endl;
	*/
	/*Testing overloading < > == operators. 
	Polynomial Ken;
	Polynomial Got;
	Ken.insert(1,2);
	Ken.insert(2,1);
	Ken.insert(2,3);
	Ken.insert(4,2);

	Got.insert(1,2);
	Got.insert(2,1);
	Got.insert(2,3);
	Got.insert(4,5);
	
	int test;
	test = Ken == Got;
	cout << test << endl;
	*/
	
	/* Testing absolute value
	Polynomial A;
	A.insert(-1,2);
	A.insert(-3,4);
	cout << endl << A << endl;
	A.Abs();
	cout << endl << A << endl;
	*/
	/* Testing evaluating function
	Polynomial B;
	double value;
	B.insert(-1,2);
	B.insert(3,1);
	B.insert(1,0);
	cout << endl << B << endl;
	value = B.eval(2);
	cout << endl << value << endl;
	*/
	/* Testing multiplying polynomial by a constant
	Polynomial C;
	C.insert(-1,2);
	C.insert(2,1);
	C.insert(4,0);
	cout << endl << C << endl;
	C.multX(3);
	cout << endl << C << endl;
	*/
	// Testing deep copy constructor and copy function
	/*
	Polynomial D;
	D.insert(2,2);

	Polynomial E = D;

	D.insert(-1,2);
	D.insert(2,2);
	D.insert(3,0);

	cout << endl << D << endl;
	cout << endl << E << endl;
	*/
	

	vector<Polynomial> apoly;
	bool valid = true;
	cout << "\t **Make-a-Poly Program Initiated** \t" << endl << endl;
	int n =0;
	while (valid){
	menu();
	int option;
	
	cin >> option;
	switch (option){
		case 0:
		{
		valid = false;
		break;
		}
		case 1:
		{
		cout << "How many terms will your Polynomial have? >>";
		int numTerms;
		//Polynomial * temp;
		cin >> numTerms;
		Polynomial x;
		double _coef;
		int _expo;
		for (int i = 0; i < numTerms; i++){
			cout << "Enter coefficient of Term #" << i+1 << ": ";
			cin >> _coef;
			cout << "Enter Exponent: ";
			cin >> _expo;
			x.insert(_coef,_expo);

		}
		cout << endl;
		x.mergsort();
		cout << "Your Polynomial: ";
		x.printPoly();
		apoly.push_back(x);
		n++;

		break;
		}
		case 3:
		{
			cout << endl << "\t **Polynomial Store ** \t" << endl;
		for (int i = 0; i < apoly.size(); i++){
			cout << "Polynomial #" << i+1 << ": ";
			apoly[i].printPoly();
			}
		break;
		}
		case 2:
		{
		int num;
		int pone;
		int ptwo;
		double pthree;
		Polynomial y;
		Polynomial d;
		//Polynomial z;
		cout << "Making a Composite Polynomial...(Of existing Polynomials.  Refer to Store)" << endl;
		cout << "1. Add Two Polynomials" << endl;
		cout << "2. Subtract Two Polynomials" << endl;
		cout << "3. Multiply Polynomial by a constant" << endl;
		cout << "4. Multiply Two Polynomials" << endl;
		cout << "5. Take the Derivative of a Polynomial" << endl;
		cout << "6. Integrate a Polynomial" << endl;
		cout << "7. Take the Absolute value" << endl;
		cin >> num;
		if(num==1){
			cout << "Which Two Polynomials would you like to add?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			cin >> ptwo;
			//y = apoly[pone-1] + apoly[ptwo-1];
			y = apoly[pone-1] + apoly[ptwo-1];
			y.mergsort();
			apoly.push_back(y);


		}
		else if(num==2){
			cout << "Which Two Polynomials would you like to subtract?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			cin >> ptwo;
			y = apoly[pone-1] - apoly[ptwo-1];
			y.mergsort();
			apoly.push_back(y);

		}
		else if(num==3){
			cout << "Which Polynomial and by what constant?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			cin >> pthree;
			cout << pthree;
			d = apoly[pone-1];
			cout << endl << d;
			y = d.multX(pthree);
			cout << endl << y ;
			y.mergsort();
			cout << endl << y;
			apoly.push_back(y);
		}
		else if(num==4){
			cout << "Which Two Polynomials would you like to multiply?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			cin >> ptwo;
			y = apoly[pone-1] * apoly[ptwo-1];
			apoly.push_back(y);
		}
		else if(num==5){
			cout << "Which Polynomial would you like to differentiate?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			y = y.Polynomial::copy(apoly[pone-1]);
			y.derivative();
			apoly.push_back(y);
		}
		else if(num==6){
			cout << "Which Polynomial would you like to integrate?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			y = y.Polynomial::copy(apoly[pone-1]);
			y.antiderivative();
			apoly.push_back(y);
		}

		else if(num==7){
			cout << "Which Polynomial would you like to take the absolute value of?(Refer to Store if not sure, Press Enter after each number)" << endl;
			cin >> pone;
			y = y.Polynomial::copy(apoly[pone-1]);
			y.Abs();
			apoly.push_back(y);
		}
		else
			cout << endl << "ERROR, you must enter numbers 1-7" << endl;
		
		}
		break;
		case 4:
		{
		int p;
		double val;
		double totall;
		Polynomial x;
		cout << endl << "****Evaluating Polynomial****" << endl;
		cout << "Which Polynomial and what value of x? (Press Enter after each number)" << endl;
		cin >> p;
		cin >> val;
		cout << "Polynomial#" << p << ": ";
		apoly[p-1].printPoly();
		cout << endl;
		cout << "evaluating for x = " << val << endl;
		x = x.Polynomial::copy(apoly[p-1]);
		totall = x.eval(val);
		cout << "value = " << totall << endl;
		break;
		}


		

	}






}

	

	
/*
Polynomial One;
Polynomial Two;
Polynomial Three;


One.insert(1,2);
One.insert(-2,3);
One.insert(4,4);
cout << endl << One << endl;

Two.insert(3,2);
Two.insert(-1,2);
Two.insert(5,5);

cout << endl << Two << endl;

Three = One - Two;
cout << endl << One << endl;
cout << endl << Two << endl;
cout << endl << Three << endl;
*/











 	return 0;
 }
void menu(){
	cout << endl;
	cout << "0. Exit" << endl;
	cout << "1. Make raw Polynomial " << endl;
	cout << "2. Make composite Polynomial" << endl;
	cout << "3. Polynomial Storage" << endl;
	cout << "4. Evaluate Polynomial" << endl;
	cout << ">>";




}








