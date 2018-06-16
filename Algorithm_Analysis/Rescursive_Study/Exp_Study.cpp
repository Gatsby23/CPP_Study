#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int i;
double exp(){
  // 读入一个逆波兰表达式, 并计算其值
  i++;
  char s[20];
  cin >> s;
  std::cout << "The " << i << " times the s is " << s << std::endl ;
  switch(s[0]){
    case '+' : return exp() + exp();
    case '-': return exp() - exp();
    case '*': return exp() * exp();
    case '/': return exp() / exp();
    default: return atof(s);
    break;
  }
}

int main()
{
  printf("%lf", exp());
  return 0;
}
