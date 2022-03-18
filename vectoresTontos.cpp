#include <iostream>
#include <vector>
using namespace std;

void imprimirVector(vector<int> v) {
  for (int elemento : v) {
    cout << elemento << " ";
  }
}

vector<int> rellenarVector() {
  vector<int> v;
  int tama;
  int numero;
  cout << "Introduce el tamanio del vector: ";
  cin >> tama;
  for (int i = 0; i < tama; i++) {
    cout << "Introduce un numero: ";
    cin >> numero;
    cout << endl;
    v.push_back(numero);
  }

  return v;
}

int main() {
  vector<int> miVector = {1, 3, 5};

  imprimirVector(miVector);
  cout << "Cambio la posicion [1] a 4." << endl;
  miVector[1] = 4;
  imprimirVector(miVector);
  cout << "Inserto un 3 en la posicion [2]." << endl;
  miVector.insert(miVector.begin()+2, 3);
  imprimirVector(miVector);

  cout <<"Relleno un vector:" << endl;
  vector<int> vectorRellenado = rellenarVector();
  cout << "Imprimo el vector relleno:";
  imprimirVector(vectorRellenado);



  return 0;
}
