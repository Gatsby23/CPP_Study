class CBase{
	public:
		virtual void SomeVirtualFunction(){}
};

class CDerived:public CBase{
	public:
		virtual void SomeVirtualFunction(){}
};

int main()
{
	CDerived ODerived;
	CBase*p = &ODerived;
	p->SomeVirtualFunction();		//调用哪个虚函数取决于p指向哪个类型的对象
	CDerived ODerived;
	CBase &r = ODerived;
	r.SomeVirtualFunction();
	return 0;
}
