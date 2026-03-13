#include <iostream>
using namespace std;

struct Borne{
  float puissance;
  float distance;
};

void afficherBornes(const Borne borne[], int taille) {
  for (int i = 0; i < taille; i++) {
    cout << "Borne " << i + 1 << " : " << borne[i].puissance << " kW à " << borne[i].distance
         << " km. \n";
  }
}

int indiceBorneLaPlusProche(const Borne borne[], int taille) {
  float min = borne[0].distance;
  int indice = 0;
  for (int i = 0; i < taille; i++) {
    if (borne[i].distance < min) {
      min = borne[i].distance;
      indice = i;
    }
  }
  return indice;
}

float calculerTempsRecharge(float capacite, float puissance){
  return (capacite/puissance)*60;
}

void modifierBorne(Borne borne[], int indiceBorne, float nouvelleDist){
  
  borne[indiceBorne].distance=nouvelleDist;
}



int main() {
  //Déclaration des bornes
  Borne bornes[5] = {{50.0,12.5}, {22.0,35.0}, {11.0,8.0}, {150.0,60.0}, {7.4,2.3}};
  
  //Variables utilisateur
  int borne = 0;
  float capacite = 0.0;
  int newDist=0;
  int choix=0;

  do{
    cout << "\n1. Afficher toutes les bornes\n";
    cout << "2. Afficher la borne la plus proche\n";
    cout << "3. Estimer temps de recharge\n";
    cout << "4. Modifier une borne\n";
    cout << "5. Quitter\n";
    cout << " \n";
    cout << " Quel est votre choix ?"; cin >> choix;

    switch(choix){
      case 1: afficherBornes(bornes, 5);
      break;
      case 2:
        cout << "La borne la plus proche est la borne :"
           << indiceBorneLaPlusProche(bornes, 5)+1 << "\n";
      break;
      case 3:
        cout << "Quelle borne souhaitez vous utiliser ? "; cin >> borne;
        cout << "Quelle est la capacité du véhicule ? "; cin >> capacite;
        cout << "Le temps de recharge est estimé à : "<< calculerTempsRecharge(capacite,bornes[borne-          1].puissance) << " min. \n";
      break;
      case 4:
        cout << "Quelle borne souhaitez vous modifier la distance ? ";cin >> borne;
        cout << "Quelle distance ?"; cin >> newDist;
        modifierBorne(bornes, borne-1, newDist);
        cout << "Changement effectué \n";
      break;
      case 5: break;
      default: cout << "Choisissez un nombre entre 1 et 5";
    }
    
  }while(choix!=5);

  return 0;
}