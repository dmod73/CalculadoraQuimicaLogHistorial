/*****************************************************************
//   Programa: Calculadora Quimica de Conversiones, Masas y log  //
//                                                              //
//   Creado por:                                                //
//       Dean M Ortiz Diaz - Y00574317                         //
//       Lewis A Diaz Acevedo - Y00566185                     //
//                                                            //
//   Descripcion:                                              //
//       Programa de consola para convertir temperaturas,     //
//       masas y sumar masas atomicas de la tabla periodica   //
//                                                           //
//   Materia: Programacion Estructurada                       //
***************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// ======================= CODIGO - LEWIS ======================= //
// Manejo del Log de calculos, conversiones de temperatura y masa   //

// Lista para guardar el historial de los calculos (Lewis) //
//se utiliza vector ya que este array no esta fijo a un tamaño
vector<string> historialLog;

// Funcion para mostrar la portada animada (Dean) //
void mostrarPortada() {
    cout << "\n************************************" << endl;
    cout << "*      CALCULADORA Y LOG QUIMICo    *" << endl;
    cout << "*  Dean M Ortiz Diaz - Y00574317    *" << endl;
    cout << "*  Lewis Diaz - Y00566185           *" << endl;
    cout << "************************************\n" << endl;
}

// Funcion para obtener hora actual del sistema (Lewis) //
string obtenerHoraActual() {
    time_t ahora = time(0);
    struct tm tiempoSeguro;
    localtime_s(&tiempoSeguro, &ahora);
    char buffer[10];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", &tiempoSeguro);
    return string(buffer);
}

// Funcion para guardar los calculos en log.txt y mostrarlos en consola (Lewis) //
void guardarLog(string tipo, double resultado, string unidad) {
    string linea = "Tipo de calculo: " + tipo + ", Resultado: " + to_string(resultado) + " " + unidad + ", Hora: [" + obtenerHoraActual() + "]";
    historialLog.push_back(linea);

    ofstream archivo("log.txt", ios::app);
    if (archivo.is_open()) {
        archivo << linea << endl;
        archivo.close();
    }

    cout << linea << endl;
}


// Funcion para mostrar el historial de log (Lewis) //
void HistorialDeLog() {
    ifstream archivo("log.txt");
    if (archivo.is_open()) {
        string linea;
        cout << "\nLog de su uso en nuestra calculadora:\n";
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    }
    else {
        cout << "Error abriendo el archivo de log." << endl;
    }
}

// Funcion para convertir masa de Kilogramos a Miligramos (Lewis) //
double convertirMasa(double masaKg) {
    return masaKg * 1000000.00;
}

// Funcion para realizar conversiones de temperatura (Lewis) //
double convertirTemperatura(int opcion, double temperatura) {
    double resultado = -1;
    if (opcion == 1) resultado = temperatura + 273.15;
    else if (opcion == 2) resultado = temperatura - 273.15;
    else if (opcion == 3) resultado = temperatura * 9 / 5 + 32;
    else if (opcion == 4) resultado = (temperatura - 32) * 5 / 9;
    else if (opcion == 5) resultado = (temperatura - 32) * 5 / 9 + 273.15;
    else if (opcion == 6) resultado = (temperatura - 273.15) * 9 / 5 + 32;
    return resultado;
}

// ======================= FIN CODIGO 1 - LEWIS ======================= //


// ======================= CODIGO 2 - DEAN ======================= //
// Manejo de categorias de la tabla periodica y suma de masas     //

// Definicion de cantidad de elementos por categoria (Dean) //
const int CANTIDAD_ALCALINOS = 4;
const int CANTIDAD_ALCALINOTERREOS = 4;
const int CANTIDAD_TRANSICION = 4;
const int CANTIDAD_METALOIDES = 4;
const int CANTIDAD_NOMETAL = 4;
const int CANTIDAD_HALOGENOS = 4;
const int CANTIDAD_GASES = 4;

// Listas de elementos, simbolos y masas para cada categoria (Dean) //
string metalesAlcalinos[CANTIDAD_ALCALINOS] = { "Litio", "Sodio", "Potasio", "Rubidio" };
string simbolosAlcalinos[CANTIDAD_ALCALINOS] = { "Li", "Na", "K", "Rb" };
float masasAlcalinos[CANTIDAD_ALCALINOS] = { 6.94, 22.99, 39.10, 85.47 };

string alcalinoterreos[CANTIDAD_ALCALINOTERREOS] = { "Berilio", "Magnesio", "Calcio", "Estroncio" };
string simbolosAlcalinoterreos[CANTIDAD_ALCALINOTERREOS] = { "Be", "Mg", "Ca", "Sr" };
float masasAlcalinoterreos[CANTIDAD_ALCALINOTERREOS] = { 9.01, 24.30, 40.08, 87.62 };

string metalesTransicion[CANTIDAD_TRANSICION] = { "Hierro", "Cobre", "Cromo", "Zinc" };
string simbolosTransicion[CANTIDAD_TRANSICION] = { "Fe", "Cu", "Cr", "Zn" };
float masasTransicion[CANTIDAD_TRANSICION] = { 55.85, 63.55, 52.00, 65.38 };

string metaloides[CANTIDAD_METALOIDES] = { "Boro", "Silicio", "Arsenico", "Antimonio" };
string simbolosMetaloides[CANTIDAD_METALOIDES] = { "B", "Si", "As", "Sb" };
float masasMetaloides[CANTIDAD_METALOIDES] = { 10.81, 28.09, 74.92, 121.76 };

string noMetales[CANTIDAD_NOMETAL] = { "Hidrogeno", "Carbono", "Nitrogeno", "Oxigeno" };
string simbolosNoMetales[CANTIDAD_NOMETAL] = { "H", "C", "N", "O" };
float masasNoMetales[CANTIDAD_NOMETAL] = { 1.01, 12.01, 14.01, 16.00 };

string halogenos[CANTIDAD_HALOGENOS] = { "Fluor", "Cloro", "Bromo", "Yodo" };
string simbolosHalogenos[CANTIDAD_HALOGENOS] = { "F", "Cl", "Br", "I" };
float masasHalogenos[CANTIDAD_HALOGENOS] = { 19.00, 35.45, 79.90, 126.90 };

string gasesNobles[CANTIDAD_GASES] = { "Helio", "Neon", "Argon", "Kripton" };
string simbolosGasesNobles[CANTIDAD_GASES] = { "He", "Ne", "Ar", "Kr" };
float masasGasesNobles[CANTIDAD_GASES] = { 4.00, 20.18, 39.95, 83.80 };

// Funcion para mostrar elementos disponibles de una categoria (Dean) //
void mostrarElementos(string lista[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << lista[i] << endl;
    }
}

// ======================= FIN CODIGO - DEAN ======================= //


// ======================= CODIGO PRINCIPAL (Dean + Lewis) ======================= //
int main() {
    int opcionMenu, opcionCategoria, opcionTemp, elemento1, elemento2;
    double valorEntrada;
    double masaElemento1, masaElemento2;

    mostrarPortada(); // Mostrar la portada al usuario //

    do {
        // Menu principal //
        cout << "1. Conversion de Temperatura" << endl;
        cout << "2. Conversion de Masa" << endl;
        cout << "3. Suma de Masas Atomicas" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        switch (opcionMenu) {
        case 1: {
            cout << "\nConversion de Temperatura:" << endl;
            cout << "1. Celsius a Kelvin" << endl;
            cout << "2. Kelvin a Celsius" << endl;
            cout << "3. Celsius a Fahrenheit" << endl;
            cout << "4. Fahrenheit a Celsius" << endl;
            cout << "5. Fahrenheit a Kelvin" << endl;
            cout << "6. Kelvin a Fahrenheit" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcionTemp;
            cout << "Ingrese el valor de temperatura: ";
            cin >> valorEntrada;
            double resultadoTemp = convertirTemperatura(opcionTemp, valorEntrada);
            cout << "Resultado: " << resultadoTemp << " grados" << endl;
            guardarLog("Conversion de Temperatura", resultadoTemp, "grados");
        }
              break;

        case 2: {
            cout << "\nConversion de Masa:" << endl;
            cout << "Esta opcion convierte de kilogramos (kg) a miligramos (mg)." << endl;
            cout << "Ingrese la masa en kilogramos: ";
            cin >> valorEntrada;
            double resultadoMasa = convertirMasa(valorEntrada);
            cout << "Resultado: " << resultadoMasa << " mg" << endl;
            guardarLog("Conversion de Masa", resultadoMasa, "mg");
        }
              break;

        case 3: {
            cout << "\nCategorias disponibles:" << endl;
            cout << "1. Metales Alcalinos" << endl;
            cout << "2. Alcalinoterreos" << endl;
            cout << "3. Metales de Transicion" << endl;
            cout << "4. Metaloides" << endl;
            cout << "5. No Metales" << endl;
            cout << "6. Halogenos" << endl;
            cout << "7. Gases Nobles" << endl;

            cout << "\nPuede combinar elementos de diferentes categorias." << endl;

            // Seleccion de primer elemento //
            cout << "\nSeleccione la categoria del primer elemento: ";
            cin >> opcionCategoria;

            if (opcionCategoria == 1) {
                mostrarElementos(metalesAlcalinos, CANTIDAD_ALCALINOS);
                cin >> elemento1; masaElemento1 = masasAlcalinos[elemento1 - 1];
            }
            else if (opcionCategoria == 2) {
                mostrarElementos(alcalinoterreos, CANTIDAD_ALCALINOTERREOS);
                cin >> elemento1; masaElemento1 = masasAlcalinoterreos[elemento1 - 1];
            }
            else if (opcionCategoria == 3) {
                mostrarElementos(metalesTransicion, CANTIDAD_TRANSICION);
                cin >> elemento1; masaElemento1 = masasTransicion[elemento1 - 1];
            }
            else if (opcionCategoria == 4) {
                mostrarElementos(metaloides, CANTIDAD_METALOIDES);
                cin >> elemento1; masaElemento1 = masasMetaloides[elemento1 - 1];
            }
            else if (opcionCategoria == 5) {
                mostrarElementos(noMetales, CANTIDAD_NOMETAL);
                cin >> elemento1; masaElemento1 = masasNoMetales[elemento1 - 1];
            }
            else if (opcionCategoria == 6) {
                mostrarElementos(halogenos, CANTIDAD_HALOGENOS);
                cin >> elemento1; masaElemento1 = masasHalogenos[elemento1 - 1];
            }
            else if (opcionCategoria == 7) {
                mostrarElementos(gasesNobles, CANTIDAD_GASES);
                cin >> elemento1; masaElemento1 = masasGasesNobles[elemento1 - 1];
            }

            // Seleccion de segundo elemento //
            cout << "\nSeleccione la categoria del segundo elemento: ";
            cin >> opcionCategoria;

            if (opcionCategoria == 1) {
                mostrarElementos(metalesAlcalinos, CANTIDAD_ALCALINOS);
                cin >> elemento2; masaElemento2 = masasAlcalinos[elemento2 - 1];
            }
            else if (opcionCategoria == 2) {
                mostrarElementos(alcalinoterreos, CANTIDAD_ALCALINOTERREOS);
                cin >> elemento2; masaElemento2 = masasAlcalinoterreos[elemento2 - 1];
            }
            else if (opcionCategoria == 3) {
                mostrarElementos(metalesTransicion, CANTIDAD_TRANSICION);
                cin >> elemento2; masaElemento2 = masasTransicion[elemento2 - 1];
            }
            else if (opcionCategoria == 4) {
                mostrarElementos(metaloides, CANTIDAD_METALOIDES);
                cin >> elemento2; masaElemento2 = masasMetaloides[elemento2 - 1];
            }
            else if (opcionCategoria == 5) {
                mostrarElementos(noMetales, CANTIDAD_NOMETAL);
                cin >> elemento2; masaElemento2 = masasNoMetales[elemento2 - 1];
            }
            else if (opcionCategoria == 6) {
                mostrarElementos(halogenos, CANTIDAD_HALOGENOS);
                cin >> elemento2; masaElemento2 = masasHalogenos[elemento2 - 1];
            }
            else if (opcionCategoria == 7) {
                mostrarElementos(gasesNobles, CANTIDAD_GASES);
                cin >> elemento2; masaElemento2 = masasGasesNobles[elemento2 - 1];
            }

            double sumaTotal = masaElemento1 + masaElemento2;
            cout << "\nSuma de masas atomicas: " << sumaTotal << " u" << endl;
            guardarLog("Suma de Masas Atomicas", sumaTotal, "u");
        }
              break;

        case 4:
            cout << "\nGracias por usar la calculadora!" << endl;
            HistorialDeLog();
            break;

        default:
            cout << "Opcion invalida, intente de nuevo." << endl;
        }

    } while (opcionMenu != 4);

    return 0;
}