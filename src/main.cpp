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

float calculerTempsRecharge(float capacite, float puissance){
  return (capacite/puissance)*60;
}

void modifierBorne(float dist[], int indiceBorne, float nouvelleDist){
  
  dist[indiceBorne]=nouvelleDist;
}

int main() {
  int borne = 0;
  float capacite = 0.0;
  int newDist=0;
  int choix=0;
  float puissances[5] = {50.0, 22.0, 11.0, 150.0, 7.4};
  float distances[5] = {12.5, 35.0, 8.0, 60.0, 2.3};

  do{
    cout << "\n1. Afficher toutes les bornes\n";
    cout << "2. Afficher la borne la plus proche\n";
    cout << "3. Estimer temps de recharge\n";
    cout << "4. Modifier une borne\n";
    cout << "5. Quitter\n";
    cout << " \n";
    cout << " Quel est votre choix ?"; cin >> choix;

    switch(choix){
      case 1: afficherBornes(puissances, distances, 5);
      break;
      case 2:
        cout << "La borne la plus proche est la borne :"
           << indiceBorneLaPlusProche(distances, 5)+1 << "\n";
      break;
      case 3:
        cout << "Quelle borne souhaitez vous utiliser ? "; cin >> borne;
        cout << "Quelle est la capacité du véhicule ? "; cin >> capacite;
        cout << "Le temps de recharge est estimé à : "<< calculerTempsRecharge(capacite,puissances[borne-          1]) << " min. \n";
      break;
      case 4:
        cout << "Quelle borne souhaitez vous modifier la distance ? ";cin >> borne;
        cout << "Quelle distance ?"; cin >> newDist;
        modifierBorne(distances, borne-1, newDist);
        cout << "Changement effectué \n";
      break;
      case 5: break;
      default: cout << "Choisissez un nombre entre 1 et 5";
    }
    
  }while(choix!=5);

  return 0;
}