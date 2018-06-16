#include <iostream>
using namespace std;
void Hanoi(int n, char src, char mid, char dest){
  if(n == 1){
    std::cout << src << "->" << dest << std::endl;
    return;
  }
  Hanoi(n-1, src, dest, mid);
  std::cout << src << "->" << dest << std::endl;
  Hanoi(n-1, mid, src, dest);
  return;
}
int main()
{
  int n;
  std::cout << "Please input the number of Hanoi: " << std::endl;
  std::cin >> n;
  Hanoi(n, 'A', 'B', 'C');
  return 0;
}
