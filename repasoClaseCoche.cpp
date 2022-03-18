#include <iostream>
using namespace std;


class Motor{
private:
  bool estado;
public:
  // Constructor.
  Motor (bool estado = false) {
    this->estado = estado;
  }
  // Destructor.
  ~Motor(){
    cout << "El motor ha sido destruido." << endl;
  }
  // Métodos.
  void setEstado(bool estado){
    this->estado = estado;
  }
  bool getEstado(){
    return this->estado;
  }
  void arrancar(){
    this->setEstado(true);
  }
  void apagar(){
    this->setEstado(false);
  }
  // Imprimir.
  void imprimir(){
    if (this->estado) {
      cout << "El motor está encendido." << endl;
    } else { cout << "El motor está apagado." << endl;
    }
  }
};

class Ventana {
private:
  bool estado;
public:
  // Constructor y destructor.
  Ventana (bool estado = false) {
    this->estado = estado;
  }
  ~Ventana(){
    cout << "La ventana ha sido destruida." << endl;
  }
  // Métodos.
  void setEstado(bool estado){
    this->estado = estado;
  }
  bool getEstado(){
    return this->estado;
  }
  void abrirVentana(){
    this->setEstado(true);
  }
  void cerrarVentana(){
    this->setEstado(false);
  }
  // Imprimir.
  void imprimir(){
    if (this->estado) {
      cout << "La ventana está abierta." << endl;
    } else {
      cout << "La ventana está cerrada." << endl;
    }
  }
};

class Puerta{
private:
  bool estado;
  Ventana ventanilla;
public:
  // Constructor y destructor.
  Puerta(bool estado = false) {
    this->estado = estado;
    // No hace falta poner la variable ventanilla como instrucción, el constructor crea todas las variables.
  }
  ~Puerta(){
    cout << "La puerta ha sido destruida." << endl;
  }
  // Getters and Setters.
  void setEstado(bool estado){
    this->estado = estado;
  }
  bool getEstado() {
    return this->estado;
  }
  Ventana & getVentanilla(){
    return this->ventanilla;
  }
  // Otros métodos.
  void abrirPuerta(){
    this->setEstado(true);
  }
  void cerrarPuerta(){
    this->setEstado(false);
  }
  // Imprimir.
  void imprimir(){
    if (this->estado) {
      cout << "La puerta está abierta." << endl;
    } else {
      cout << "La puerta está cerrada." << endl;
    }
    cout << "Su ventanilla: "; this->ventanilla.imprimir();
  }
};

class Coche{
private:
  bool estado;
  Puerta puertaDer;
  Puerta puertaIzq;
  Motor motor;
public:
  // Constructor y destructor.
  Coche(bool estado = false) {
    this->estado = estado;
  }
  ~Coche(){
    cout << "El coche ha sido destruido." << endl;
  }
  // Getters and Setters.
  void setEstado(bool estado){
    this->estado = estado;
  }
  bool getEstado(){
    return this->estado;
  }
  Puerta & getPuertaDer(){
    return this->puertaDer;
  }
  Puerta & getPuertaIzq(){
    return this->puertaIzq;
  }
  Motor & getMotor(){
    return this->motor;
  }
  // Otros métodos.
  void abrirCoche(){
    this->setEstado(true);
  }
  void cerrarCoche(){
    this->setEstado(false);
  }
  // Imprimir.
  void imprimir(){
    if (this->estado) {
      cout << "El coche esta abierto" << endl;
    } else {
      cout << "El coche está cerrado" << endl;
    }
    cout << "Puerta derecha: "; this->puertaDer.imprimir();
    cout << "Puerta izquierda: "; this->puertaIzq.imprimir();
    this->motor.imprimir();
  }
};

int main(){
  // Variables.
  Motor miMotor;
  Ventana miVentana;
  Puerta miPuerta;
  Coche miCoche;

  // Programa.
  cout << "Motor por defecto:" << endl;
  miMotor.imprimir();
  cout << "Cambio el motor por defecto a encendido." << endl;
  miMotor.arrancar();
  miMotor.imprimir();
  cout << "Vuelvo a apagar el motor por defecto." << endl;
  miMotor.apagar();
  miMotor.imprimir();

  cout << "Ventana por defecto:" << endl;
  miVentana.imprimir();
  cout << "Abro la ventana." << endl;
  miVentana.abrirVentana();
  miVentana.imprimir();
  cout << "Vuelvo a cerrar la ventana." << endl;
  miVentana.cerrarVentana();
  miVentana.imprimir();

  cout << "Puerta por defecto:" << endl;
  miPuerta.imprimir();
  cout << "Abro la puerta." << endl;
  miPuerta.abrirPuerta();
  miPuerta.imprimir();
  cout << "Vuelvo a cerrar la puerta." << endl;
  miPuerta.cerrarPuerta();
  miPuerta.imprimir();
  cout << "Abro la ventanilla." << endl;
  miPuerta.getVentanilla().abrirVentana();
  miPuerta.imprimir();
  cout << "Vuelvo a cerrar la ventanilla" << endl;
  miPuerta.getVentanilla().cerrarVentana();
  miPuerta.imprimir();

  cout << "Coche por defecto:" << endl;
  miCoche.imprimir();
  cout << "Abro el coche," << endl;
  miCoche.abrirCoche();
  miCoche.imprimir();
  cout << "Abro la puerta derecha." << endl;
  miCoche.getPuertaDer().abrirPuerta();
  miCoche.imprimir();
  cout << "Abro la ventanilla de la puerta izquierda." << endl;
  miCoche.getPuertaIzq().getVentanilla().abrirVentana();
  miCoche.imprimir();

  return 0;
}
