#include<iostream>
using namespace std;

int main(){
  char str[] = "Umbrella";
  int i=0;
  int n=9;
  while(i<=9){
    if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U'){
      cout<< str[i];
    }
    i++;
  }
  return 0;
}