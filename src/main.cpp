#include <iostream>
using namespace std;

void afficherBornes(const float puiss[], const float dist[], int taille) {
  for (int i = 0; i < taille; i++) {
    cout << "Borne " << i + 1 << " : " << puiss[i] << " kW à " << dist[i]
         << " km. \n";
  }
}

int indiceBorneLaPlusProche(const float dist[], int taille) {
  float min = dist[0];
  int indice = 0;
  for (int i = 0; i < taille; i++) {
    if (dist[i] < min) {
      min = dist[i];
      indice = i;
    }
  }
  return indice;
}

int main() {
  float puissances[5] = {50.0, 22.0, 11.0, 150.0, 7.4};
  float distances[5] = {12.5, 35.0, 8.0, 60.0, 2.3};

  afficherBornes(puissances, distances, 5);
  cout << "La borne la plus proche est la borne :"
       << indiceBorneLaPlusProche(distances, 5)+1 << "\n";

  return 0;
}