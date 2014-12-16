/*!
 * \author Kenta Goto
 * \file poly.h
 * \brief Project 2.  Header file of linked lists used to represent polynomials.
 */

 /*
 * all returned polynomials are reduced: sorted from low to high
 * degree, like terms combined, terms with zero coefficients
 * removed.
 */
#include <iostream>
using namespace std;


struct term{
 double coef;
 unsigned deg;
 term * next;
};

typedef term * Term;
typedef term * Poly;


class Polynomial{


friend ostream& operator<<(ostream& fout, const Polynomial& H);
friend Polynomial operator+(const Polynomial& O, const Polynomial& T);
friend Polynomial operator-(const Polynomial& O, const Polynomial& T);
friend Polynomial operator*(const Polynomial& O, const Polynomial& T);
friend int operator<( Polynomial& O, Polynomial& T);
friend int operator>(Polynomial& O,Polynomial& T);
friend int operator==(Polynomial& O,Polynomial& T);

private:

	term* HeadNode;
	void msort(term* &L);
	term* split(term* &L);
	void merge(term* &L, term*&R);

public:


//Poly newPoly(); /* returns polynomial with no terms */
Polynomial(); 
Polynomial(const Polynomial & rhs);
Polynomial & operator=(const Polynomial & rhs);
//void deletePoly(Poly *pP); /* returns polynomial with no terms */
~Polynomial();
Poly get_HeadNode()const; /* Access to HeadNode*/
void set_HeadNode(Poly NewHeadNode);
Term newTerm(double coef,unsigned deg);
void insert(double coef, int expo);
Polynomial add(const Polynomial P1,const Polynomial P2)const; /*returns sum*/
Polynomial sub(Polynomial P1,Polynomial P2)const; /*returns difference P1-P2*/
static Polynomial mult(Polynomial P1,Polynomial P2); /*returns product*/
void derivative(); /*returns derivative by reference*/
void antiderivative();/*returns antiderivative w/o arbitrary const*/
void reduce(); /*returns reduced polynomial by reference*/
void Abs(); /*makes all terms positive */
double eval(double x); /* return P(x) */
Polynomial multX(double x); /* returns P = x*P, multiply all terms by x */
void printPoly() ; /*e.g. 2.0 + 3*x^5 */
Polynomial copy(Polynomial P); /*returns duplicate of polynomial P*/
void mergsort();
};

