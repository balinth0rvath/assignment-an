using namespace std;
#include <iostream>
/*
 Copy char array from source to target in reverse direction
 assuming target memory is allocated and has at least the same amount of memory
 allocated as the source.
  @param target
    Pointer to the target array
  @param source
    Pointer to the source array
  @return Pointer to the first char of target when succeeded
          nullptr if target or source is nullptr or source length is 0
*/
char* convert(char* target, char* source);

char* convert(char* target, char* source)
{
  // check initializations partially
  // cannot check dangling pointers
  if (target==nullptr || source==nullptr)
  {
    return nullptr;
  }

  // determine source length
  int len=0; 
  while(*(source+(len++))!=0);
  len--;

  if (!len)
  {
    return nullptr;
  }

  // copy reverse array
  for(int i=0;i<len;++i)
  {
    *(target+len-i-1)=*(source+i);
  }
  return target;
}

void wrapper(char* target, char* source)
{
  static int counter=1;
  std::cout << counter++ << " ";
  if (convert(target,source)) 
  {
    std::cout << target << std::endl;
  } else
  {
    std::cout << "Error occured" << std::endl;
  }
}

int main()
{
  char a[9]="directed";
  char b[9]={};

  wrapper(b,a);

  *(a)=0;
  wrapper(b,a);

  wrapper(a,b);

  char* c=nullptr;
  wrapper(c,a);

  return 0;
}
