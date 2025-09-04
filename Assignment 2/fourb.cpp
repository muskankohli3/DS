#include <iostream>
using namespace std;

int main(){
  char str[6]="Apple";
  int i=0;
  int n=5;
  while(i <n/2){
    char temp = str[i];
    str[i] = str[n-1-i];
    str[n-1-i] = temp;
    i++;
  }
  for(int i=0;i<n;i++){
    cout<< str[i];
  }
  return 0;
}