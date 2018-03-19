#include "Television.h"

int main()
{
  std::cout<<"====================================="<<std::endl;
  std::cout<<"Television Information Validation"<<std::endl;
  std::cout<<"====================================="<<std::endl;

  Television tv;
  std::cin >> tv;

  std::cout<<"====================================="<<std::endl;
  std::cout<<"====================================="<<std::endl;
  std::cout<<"==== Your Television Information ===="<<std::endl;
  std::cout<<"====================================="<<std::endl;
  std::cout<<"====================================="<<std::endl;
  
  std::cout << tv;

  return 0;
}
