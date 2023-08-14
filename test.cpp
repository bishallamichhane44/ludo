#include<iostream>
#include<windows.h>
#include<string>
#include<time.h>
#include <cstdlib>
using namespace std;
int main(){
  int i=0;
  srand(time(0));
cout << (rand()%6)+1 << " ";
  return 0;
};
