/*!
 * \author Kenta Goto
 * \file poly.cpp
 * \brief Implementation file used to define member functions of class Polynomial.
 */
 #include <iostream>
 #include "poly.h"
 #include <string>
 #include <sstream>
 #include <cmath>


 using namespace std;
 	/*!
 	 * This overloaded insertion operator will print in order.
 	 * Also finds certain strings and replaces them with logical output expected as if done in real life.
 	 */
 ostream& operator<<(ostream& fout,const Polynomial& H){
 	stringstream stin;
 	Poly h = H.get_HeadNode();

    while (h!=0){
 	stin << h->coef << "x^" << h->deg;
 	if((h->next)!=0){
 		stin << " + ";
 	}
 	h = h->next;
}
	stin << endl;
	
	
	string test = stin.str();
	
	
	int index = test.find(" + -");
	while (index!=std::string::npos){
	test.replace(index, 4, " - ");
	index = test.find(" + -", index);
	}

	int indexx = test.find("x^0");
	while (indexx!=std::string::npos){
	test.replace(indexx, 3, "");
	indexx = test.find("x^0", indexx);
	}

	int indexxx = test.find("x^1");
	while (indexxx!=std::string::npos){
	test.replace(indexxx, 3, "x");
	indexxx = test.find("x^1", indexxx);
	}

	int inde = test.find("0x + ");
	while (inde!=std::string::npos){
	test.replace(inde, 5, "");
	inde = test.find("0x", inde);
	}

	int indi = test.find("0x - ");
	while (indi!=std::string::npos){
	test.replace(indi, 5, "");
	indi = test.find("0x", indi);
	}

	int ind = test.find("1x");
	while (ind!=std::string::npos){
	test.replace(ind, 2, "x");
	ind = test.find("1x", ind);
	}

	int indix = test.find(" + 0x");
	while (indix!=std::string::npos){
	test.replace(indix, 7, "");
	indix = test.find("0x", indix);
	}

	int indax = test.find(" - 0x");
	while (indax!=std::string::npos){
	test.replace(indax, 7, "");
	indax = test.find("0x", indax);

	}
	

	fout << test;
 	return fout;
 
}

Polynomial operator+(const Polynomial& O, const Polynomial& T){
	Poly M = O.get_HeadNode();
 	Poly two = T.get_HeadNode();
 
 	Polynomial* L = new Polynomial;

 	while(two!=0){
 		while(M!=0){
 			double k = M->coef;
 			int j = M->deg;
 			L->insert(k,j);
 			M = M->next;
 		}
 		double n = two->coef;
 		int m = two->deg;
 		L->insert(n,m);
 		two = two->next;
 	}

 	return *L;

}

Polynomial operator-(const Polynomial& O, const Polynomial& T){
	Polynomial Neww;
	return Neww.Polynomial::sub(O,T);
}


Polynomial operator*(const Polynomial& O, const Polynomial& T){
	return Polynomial::mult(O,T);
}

int operator<(Polynomial& O,  Polynomial& T){
	O.mergsort();
	T.mergsort();
	term* t = O.get_HeadNode();
	term* e = T.get_HeadNode();
	/*! Make pass to Last term, which has the highest degree because they were sorted*/
	while((t->next)!=0){
		t = t->next;
	}
	while ((e->next)!=0){
		e = e->next;
	}
	cout << e->deg << endl;
	cout << t->deg << endl;
	if (e->deg == t->deg || e->deg < t->deg){
		return 0;
	}

	else
		return 1;
	
}

int operator>(Polynomial& O,Polynomial& T){
	O.mergsort();
	T.mergsort();
	term* t = O.get_HeadNode();
	term* e = T.get_HeadNode();
	/*! Make pass to Last term, which has the highest degree because they were sorted*/
	while((t->next)!=0){
		t = t->next;
	}
	while ((e->next)!=0){
		e = e->next;
	}
	cout << e->deg << endl;
	cout << t->deg << endl;
	if (e->deg == t->deg || e->deg > t->deg){
		return 0;
	}

	else
		return 1;
	

}
int operator==(Polynomial& O,Polynomial& T){
	O.mergsort();
	T.mergsort();
	term* t = O.get_HeadNode();
	term* e = T.get_HeadNode();
	/*! Make pass to Last term, which has the highest degree because they were sorted*/
	while((t->next)!=0){
		t = t->next;
	}
	while ((e->next)!=0){
		e = e->next;
	}
	cout << e->deg << endl;
	cout << t->deg << endl;
	if (e->deg == t->deg){
		return 1;
	}

	else
		return 0;
	


}


Polynomial::~Polynomial(){

}

 Polynomial::Polynomial(){
 HeadNode = NULL;
 }

 Polynomial::Polynomial(const Polynomial & rhs){
 	HeadNode = new term;
 	*HeadNode = *rhs.get_HeadNode();
 }

Polynomial& Polynomial::operator=(const Polynomial & rhs){
	if (this == &rhs)
		return *this;
	HeadNode = rhs.get_HeadNode();
	return *this;
}

Term Polynomial::newTerm(double coef,unsigned deg){
 	Term t = new term;
 	t->coef = coef;
 	t->deg = deg;
 	t->next = NULL;
 	return t;
 	 }
Poly Polynomial::get_HeadNode()const{
	return HeadNode;
}
void Polynomial::set_HeadNode(Poly newHeadNode){
	HeadNode = newHeadNode;
}
 void Polynomial::insert(double cef, int expo){
 	/* This should be used inside the program.  User-friendly insert will be added later.*/
 	
 	
 	Poly* pP = &HeadNode;

 		if(expo < 0){
 			cout << "ERROR Polynomials cannot contain negative exponents" << endl;
 			return;
 		}

 		Term tp = newTerm(cef,expo);

 	
 	
 	if(HeadNode!= NULL){

 	while((*pP)!=NULL){
 		pP = &((*pP)->next);
 	}
 	tp->next = NULL;
 	*pP = tp;
 	
 }
 	else {
 		HeadNode = tp;
 		
 	}
  }
 

 void Polynomial::printPoly(){
 	/*!
 	 * This will print in order.  The Nodes are inserted at the end to make things much easier.
 	 * 
 	 */
 	stringstream stin;

 	Poly t = HeadNode;
 	while (t!=0){
 	stin << t->coef << "x^" << t->deg;
 	if(t->next!=0)
 	 	stin << " + ";
 	t = t->next;
 }
 	/* Use stringstreams to simplify signs */
 	stin << endl;
 	string test = stin.str();
 	int index = test.find(" + -");
	while (index!=std::string::npos){
	test.replace(index, 4, " - ");
	index = test.find(" + -", index);
	}

	int indexx = test.find("x^0");
	while (indexx!=std::string::npos){
	test.replace(indexx, 3, "");
	indexx = test.find("x^0", indexx);
	}

	int indexxx = test.find("x^1");
	while (indexxx!=std::string::npos){
	test.replace(indexxx, 3, "x");
	indexxx = test.find("x^1", indexxx);
	}

	int inde = test.find(" 0x + ");
	while (inde!=std::string::npos){
	test.replace(inde, 5, "");
	inde = test.find(" 0x", inde);
	}

	int ind = test.find("1x");
	while (ind!=std::string::npos){
	test.replace(ind, 2, "x");
	ind = test.find("1x", ind);
	}
	int indi = test.find(" 0x - ");
	while (indi!=std::string::npos){
	test.replace(indi, 5, "");
	indi = test.find("0x", indi);
	}

	int indix = test.find(" + 0x");
	while (indix!=std::string::npos){
	test.replace(indix, 7, "");
	indix = test.find("0x", indix);
	}

	int indax = test.find(" - 0x");
	while (indax!=std::string::npos){
	test.replace(indax, 7, "");
	indax = test.find("0x", indax);
	}

	int inxx = test.find(" 0x^");
	while (inxx!=std::string::npos){
	test.replace(inxx, 4, "");
	inxx = test.find(" 0x^", inxx);
	}
	
	
	cout << test;

 	}



 

 Polynomial Polynomial::add(const Polynomial P1,const Polynomial P2)const{
 	Poly M = P1.get_HeadNode();
 	Poly two = P2.get_HeadNode();
 	Polynomial L;

 	while(two!=0){
 		while(M!=0){
 			double k = M->coef;
 			int j = M->deg;
 			L.insert(k,j);
 			M = M->next;
 		}
 		double n = two->coef;
 		int m = two->deg;
 		L.insert(n,m);
 		two = two->next;
 	}

 	return L;

 }

 Polynomial Polynomial::sub(Polynomial P1,Polynomial P2)const{
 	Poly One = P1.get_HeadNode();
 	Poly Two = P2.get_HeadNode();
 	Poly * pP = &One;
 	Poly temp = Two;
	Polynomial N;
 	/* Distribute minus sign in the second Polynomial*/
 	while (One!=0){
 		double n = One->coef;
 		double m = One->deg;
 		N.insert(n,m);
 		One = One->next;
 	}
 	while (temp!=NULL){
 			double k = temp->coef * -1;
 			int l = temp->deg;
 			N.insert(k,l);
 			temp = temp->next;
 	}
 	/* Connect two Polynomials together*/
 	
 	
 	

 	return N;





 }

 Polynomial Polynomial::mult(Polynomial P1,Polynomial P2){
 	Poly One = P1.get_HeadNode();
 	Poly Two = P2.get_HeadNode();
 	Poly temp = Two;

 	Polynomial Prod;
 	Poly mult = Prod.get_HeadNode();
 	double k;
 	int n;
 

 	while ((One)!=NULL){
 		temp = Two;
 		while (temp!=NULL){
 			k = ((One)->coef) * (temp->coef);
 			n = ((One)->deg) + (temp->deg);
 			Prod.insert(k,n);
 			temp = temp->next;
 			
 			


 		}
 		One = One->next;
 	}
 
 	return Prod;


 }

 void Polynomial::derivative(){
 	Poly p = HeadNode;
 	while (p!=0){
 		if(p->deg > 0){
 			p->coef = p->coef * p->deg;
 			p->deg = p->deg - 1;
 		}

 		if (p->deg == 0){
 			p->coef = 0;
 		}
 		p = p->next;
 	}
 }

 void Polynomial::antiderivative(){
 	Poly p = HeadNode;

 	while(p!=0){
 		p->deg = p->deg + 1;
 		p->coef = p->coef / p->deg;
 		p = p->next;

 	}

 }

 void Polynomial::reduce(){
 	/* Combines like-terms and properly organizes polyinomial from highest degree to lowest.*/
 	Poly p = HeadNode;
 	Poly tp = HeadNode;
 	Poly temp = NULL;
 	Poly f = p;
 	Poly prev = HeadNode;
 	while (p!=0){
 		tp = p->next;
 		prev = p;
 		while(tp!=0){
 		
 		if(tp->deg==p->deg){
 			p->coef = p->coef + tp->coef;
 			temp = tp;
 			if((tp->next)==0){
 				prev->next = NULL;
 			}
 			else if((tp->next)!=0){
 				prev->next = tp->next;
 			}
 			tp = tp->next;
 			delete temp;


 		}
 		else{
 			prev = tp;
 			tp = tp->next;
 		}
 	}
 	p = p->next;

 	}

 	

 }
	 /*!
 	 * The following three functions will sort the polynomial from lowest degree to the highest degree and reduce them.
 	 * 
 	 */
void Polynomial::mergsort(){
	msort(HeadNode);

}

void Polynomial::msort(term* &L){
	if(L==0 || L->next==0)
		return;
	term* R = split(L);
	msort(L);
	msort(R);
	merge(L,R); 
}
term* Polynomial::split(term* &L){
	term* p = L;
	int n = 0; 
	
	while(p!=0){ 
		n++;
		p = p->next;
	}
	n = n/2;  
	term** pp = &L; 
	for(int i=0; i!=n; i++){ 
		pp = &((*pp)->next);
    }
	term* R = *pp; 
	*pp = 0; 
	return R;  

}
void Polynomial::merge(term* &L, term*&R){
	Polynomial* t = new Polynomial;
    term** pp = &(t->HeadNode); 
    while(L!=0 && R!=0){ 
        if(L->deg <= R->deg){
            *pp = L;
            L = L->next;
            (*pp)->next = 0;
        }else{
            *pp = R;
            R = R->next;
            (*pp)->next = 0;
        }
        pp = &((*pp)->next); 
    }
    if(L!=0) 
        *pp = L;
    if(R!=0) 
        *pp = R;
    t->reduce();
    L = t->HeadNode; 

}
void Polynomial::Abs(){
	Poly p = HeadNode;
	while (p!=0){
		if(p->coef < 0){
			p->coef = -1 * p->coef;
		}
		p = p->next;
	}


}
double Polynomial::eval(double x){
	Poly p = HeadNode;
	double total = 0;
	double onecal = 0;
	while(p!=0){
		onecal = p->coef * pow(x,p->deg);
		total = total + onecal;
		p = p->next;

	}
	return total;

}

Polynomial Polynomial::multX(double x){
	Poly p = HeadNode;
	double k;
	int l;
	Polynomial N;
	while(p!=0){
		k = p->coef * x;
		l = p->deg;
		N.insert(k,l);
		p = p->next;
	}
	return N;

}
Polynomial Polynomial::copy(Polynomial P){
	Poly h = P.get_HeadNode();
	Polynomial copy;
	double ccoef;
	int cdeg;

	while (h!=0){
		ccoef = h->coef;
		cdeg = h->deg;
		copy.insert(ccoef,cdeg);
		h = h->next;
	}
	return copy;
}
 




