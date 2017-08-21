class Father{
	private: int nPrivate;
	public: int nPublic;
	protected:int nProtected;
};

class Son:public Father{
	void AccessFather(){
		nPublic = 1;//ok
		nPrivate = 1;//Wrong
		nProcted = 1;//Ok
		/*错误写法
		 * Son f;
		 * f.nProtected = 1;*/
	}	
};

int main()
{
	Father f;
	Son s;
	f.nPublic = 1;
	s.nPublic = 1;
	f.nProtected = 1;
	f.nPrivate = 1;
	s.nProtected = 1;//Wrong
	s.nPrivate = 1;//Wrong
	return 0;
}
