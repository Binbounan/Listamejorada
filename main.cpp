#include <iostream>
#include <string>

using namespace std;

class empleado {
private:
    int claveEm;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

public:

    empleado() : claveEm(0), nombre(""), domicilio(""), sueldo(0.0), reportaA("") {}

    empleado(int CE, string N, string D, float S, string R) : claveEm(CE), nombre(N), domicilio(D), sueldo(S), reportaA(R) {}

    // Sobrecarga del operador de asignación (=)
    empleado& operator=(const empleado& x) {
        claveEm = x.claveEm;
        nombre = x.nombre;
        domicilio = x.domicilio;
        sueldo = x.sueldo;
        reportaA = x.reportaA;
        return *this;
    }

    // Sobrecarga del operador de salida (<<)
    friend ostream& operator<<(ostream& o, const empleado& e) {
        o << "Clave: " << e.claveEm << endl;
        o << "Nombre: " << e.nombre << endl;
        o << "Domicilio: " << e.domicilio << endl;
        o << "Sueldo: " << e.sueldo << endl;
        o << "Reporta a: " << e.reportaA << endl;
        return o;
    }

    // Sobrecarga del operador de entrada (>>)
    friend istream& operator>>(istream& i, empleado& e) {
        cout << "Ingrese la clave del empleado: ";
        i >> e.claveEm;
        cout << "Ingrese el nombre del empleado: ";
        i.ignore(); // Para evitar problemas con getline
        getline(i, e.nombre);
        cout << "Ingrese el domicilio del empleado: ";
        getline(i, e.domicilio);
        cout << "Ingrese el sueldo del empleado: ";
        i >> e.sueldo;
        cout << "Ingrese a quién reporta el empleado: ";
        i.ignore();
        getline(i, e.reportaA);
        return i;
    }

    void muestra() {
        cout << "Clave: " << claveEm << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reportaA << endl;
    }

    int obtenerClaveEm() {
        return claveEm;
    }
};

class ListaEstatica {
private:
    empleado Datos[100]; // Tamaño máximo de la lista
    int Tam;

public:
    ListaEstatica() {
        Tam = 0;
    }

    int Inserta(empleado emp, int pos) {
        if (Tam >= 100) {
            cout << "Esta lista esta llena." << endl;
            return -1;
        }
        if (pos < 0 || pos > Tam) {
            cout << "No se puede insertar en esa posicion." << endl;
            return -1;
        }
        for (int i = Tam; i > pos; i--) {
            Datos[i] = Datos[i - 1];
        }
        Datos[pos] = emp;
        Tam++;
        return 0;
    }

    int Agrega(empleado emp) {
        if (Tam >= 100) {
            cout << "la lista está llena." << endl;
            return -1;
        }
        Datos[Tam] = emp;
        Tam++;
        return 0;
    }

    int Busca(empleado emp) {
        for (int i = 0; i < Tam; i++) {
            if (Datos[i].obtenerClaveEm() == emp.obtenerClaveEm()) {
                cout << "Empleado encontrado en la posición " << i << endl;
                return i;
            }
        }
        cout << "No se encontro al empleado en la lista." << endl;
        return -1;
    }

    int Elimina(int pos) {
        if (pos < 0 || pos >= Tam) {
            cout << "No se puede eliminar, posicion no valida." << endl;
            return -1;
        }
        for (int i = pos; i < Tam - 1; i++) {
            Datos[i] = Datos[i + 1];
        }
        Tam--;
        return 0;
    }

    int Vacia() {
        return (Tam == 0);
    }

    int Llena() {
        return (Tam >= 100);
    }

    int Muestra() {
        if (Tam == 0) {
            cout << "La lista esta vacia." << endl;
            return -1;
        }
        for (int i = 0; i < Tam; i++) {
            cout << "Empleado #" << i + 1 << ":" << endl;
            Datos[i].muestra();
            cout << endl;
        }
        return 0;
    }
};

int main() {
    ListaEstatica lista;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Agregar" << endl;
        cout << "_______________" << endl;
        cout << "2. Buscar" << endl;
        cout << "_______________" << endl;
        cout << "3. Eliminar" << endl;
        cout << "_______________" << endl;
        cout << "4. Insertar" << endl;
        cout << "_______________" << endl;
        cout << "5. Mostrar" << endl;
        cout << "_______________" << endl;
        cout << "6. Salir" << endl;
        cout << "_______________" << endl;
        cout << "Seleccione una opcion ;D : ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    empleado emp;
                    cin >> emp; // Ingresar los datos del empleado
                    if (lista.Agrega(emp) == 0) {
                        cout << "Empleado agregado con éxito." << endl;
                    }
                }
                break;

            case 2:
                {
                    int clave;
                    cout << "Ingrese la clave del empleado a buscar: ";
                    cin >> clave;

                    empleado emp(clave, "", "", 0, "");

                    lista.Busca(emp);
                }
                break;

            case 3:
                {
                    int pos;
                    cout << "Ingrese la posición del empleado a eliminar: ";
                    cin >> pos;

                    if (lista.Elimina(pos) == 0) {
                        cout << "Empleado eliminado :o ." << endl;
                    }
                }
                break;

            case 4:
                {
                    int pos;
                    cout << "Ingrese la posición donde desea insertar el empleado ;D : ";
                    cin >> pos;

                    empleado emp;
                    cin >> emp; // Ingresar los datos del empleado

                    if (lista.Inserta(emp, pos) == 0) {
                        cout << "Empleado insertado con exito." << endl;
                    }
                }
                break;

            case 5:
                lista.Muestra();
                break;

            case 6:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion no disponible Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
