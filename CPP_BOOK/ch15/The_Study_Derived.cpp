#include <iostream>

using namespace std;

class Base{
	public:
		void pub_mem();
	protected:
		int prot_mem;
	private:
		char priv_mem;
};

struct Pub_Derv:public Base{
	int f() { return prot_mem; }
	void memfcn(Base &b){
		b = *this;
		cout << "Pub_Derv" << endl;
	}
};

struct Priv_Derv::private Base{
	int f1() const { return prot_mem; }
	void memfcun(Base &b){ b = *this; cout << "Priv_Derv" << endl; }
};

struct Prot_Derv:protected Base{
	int f2() { return prot_mem; }
	void memfcn(Base &b) { b = *this; cout << "Prot_Derv" << endl;}
};

struct Derived_from_public: public Pub_Derv{
	int use_base() { return prot_mem; }
	void memfcn(Base &b){ b = *this; cout << "Derived_from_public" << endl;}
};

struct Dervied_from_Protected:protected Prot_Derv{
	int us_base(){ return prot_mem; }
	void memfcn(Base &b){ b = *this; cout << "Derived_from_Protected" << endl; }
};

int main(int argc, const char** argv[])
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	//Dervied_from_Private dd2;
	Dervide_from_Protected dd3;
	Base base;
	Base *p = new Base;
	p = &d1;
	p = &dd1;
	d1.memfcn(base);
	d2.memfcn(base);
	d3.memfcn(base);
	dd1.memfcn(base);
	dd3.memfcn(base);
	return 0;
}
