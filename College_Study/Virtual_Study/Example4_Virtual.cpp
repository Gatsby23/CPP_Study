class myClass{
	public:
		virtual void hell(){ cout << "hello from myclass" << endl;}
		virtual void bye() { cout << "bye from myclass" << endl;}
};

class son:public myclass{
	public:
		void hello(){ cout << "hello from son" << endl; }
		son(){ hello(); }
		~son(){ bye(); }
};

class grandson:public son{
	public:
		void hello(){ cout << "hello from grandson" << endl;}
		void bye(){ cout << "Bye from grandson" << endl;}
		grandson(){ cout << "constructing grandson" << endl;}
		~grandson(){ cout << "destructing the grandson" << endl;}
}

int main()
{
	grandson gson;
	son *pson;
	pson = &gson;
	pson->hello();
	return 0;
}
