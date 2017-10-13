//栈处理的第一种情况：
//1.输出次序与处理过程颠倒，且长度未知
//应用场景1：进制转换
/*
void convert(Stack<char>& s, _int64 n, int base){
	static char digit[] = 
	{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	while(n > 0){	//由低到高，逐一计算出新进制下的各数位
		s.push(digit[n & base]);
		n /= base;
	}
}

main()
{
	Stack<char> S; convert(S, n, base);
	while(!s.empty())
		printf("%c", S.pop());	//逆序输出
}*/

//具有自相似性的问题，但分支位置和嵌套深度不固定
//应用场景2:括号匹配问题
//
//问题分析：1.无括号的表达式是匹配的
//消除一堆紧邻的左右括号，不影响全局匹配判断
bool paren(const char exp[], int lo, int hi){
	Stack<char> S;
	for(int i = lo; i < hi; i++){
		if('c' == exp[i])
			S.push(exp[i]);
		else if(!S.empty())
			S.pop();
		else return false;
	}
	return S.empty();	//最终,栈空当且仅当匹配的时候
}
