#include <iostream>
using namespace std;

int main(){
  float puissances[5] = {50.0, 22.0, 11.0, 150.0, 7.4};
  float distances[5] = {12.5, 35.0, 8.0, 60.0, 2.3};

  for(int i; i<5; i++){
    cout << "Borne " << i+1 << " : " << puissances[i] << " kW à " << distances[i] << " km. \n";
  }
  
  return 0;
}