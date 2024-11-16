#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Estructura del Cliente
struct Cliente {
    string nombre;
    string transaccion;
    double saldo;

    Cliente(string n, string t, double s) : nombre(n), transaccion(t), saldo(s) {}
};

// Nodo para la lista enlazada
struct Nodo {
    Cliente cliente;
    Nodo* siguiente;

    Nodo(Cliente c) : cliente(c), siguiente(nullptr) {}
};

// Clase para la fila implementada con una lista enlazada
class Fila {
private:
    Nodo* head;  // Puntero al primer nodo
    Nodo* tile;  // Puntero al último nodo

public:
    Fila() : head(nullptr), tile(nullptr) {}

    // Verifica si la fila está vacía
    bool estaVacia() const {
        return head == nullptr;
    }

    // Inserta a un cliente en la fila
    void insertarCliente(Cliente cliente) {
        Nodo* nuevoNodo = new Nodo(cliente);
        if (estaVacia()) {
            head = tile = nuevoNodo;
        } else {
            tile->siguiente = nuevoNodo;
            tile = nuevoNodo;
        }
    }

    // Elimina y retorna al cliente al frente de la fila
    Cliente atenderCliente() {
        if (estaVacia()) {
            throw runtime_error("La fila está vacía. No hay clientes para atender.");
        }
        Nodo* temp = head;
        Cliente clienteAtendido = head->cliente;
        head = head->siguiente;
        delete temp;

        if (head == nullptr) {
            tile = nullptr;
        }

        return clienteAtendido;
    }

    // Muestra los clientes en la fila
    void mostrar() const {
        if (estaVacia()) {
            cout << "\nFila vacía." << endl;
            return;
        }

        cout << "\nClientes en la fila:" << endl;
        Nodo* actual = head;
        while (actual != nullptr) {
            cout << actual->cliente.nombre << " (" << actual->cliente.transaccion << ")";
            if (actual->cliente.saldo >= 0) {
                cout << " - Saldo: $" << fixed << setprecision(2) << actual->cliente.saldo;
            }
            cout << endl;
            actual = actual->siguiente;
        }
    }

    // Destructor para liberar la memoria
    ~Fila() {
        while (!estaVacia()) {
            atenderCliente();
        }
    }
};

// Función para realizar operaciones de transacción
void realizarTransaccion(Cliente& cliente) {
    if (cliente.transaccion == "Retiro de dinero") {
        cout << "Ingrese el monto a retirar: ";
        double monto;
        cin >> monto;

        if (monto > cliente.saldo) {
            cout << "Fondos insuficientes. Transacción no completada." << endl;
        } else if (monto <= 0) {
            cout << "Monto no válido. Transacción no completada." << endl;
        } else {
            cliente.saldo -= monto;
            cout << "Retiro exitoso. Nuevo saldo: $" << fixed << setprecision(2) << cliente.saldo << endl;
        }
    } else if (cliente.transaccion == "Depósito de dinero") {
        cout << "Ingrese el monto a depositar: ";
        double monto;
        cin >> monto;

        if (monto <= 0) {
            cout << "Monto no válido. Transacción no completada." << endl;
        } else {
            cliente.saldo += monto;
            cout << "Depósito exitoso. Nuevo saldo: $" << fixed << setprecision(2) << cliente.saldo << endl;
        }
    } else {
        cout << "Transacción procesada correctamente. Gracias por su consulta." << endl;
    }
}

// Función para atender clientes de las filas
void atenderClientes(Fila& filaCaja, Fila& filaAtencionCliente) {
    while (true) {
        int opcion;
        cout << "\n¿Desde qué fila desea atender al cliente?\n"
             << "1. Fila de Caja\n"
             << "2. Fila de Atención al Cliente\n"
             << "3. Regresar al menú principal\n"
             << "Opción: ";
        cin >> opcion;

        if (cin.fail() || opcion < 1 || opcion > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opción no válida. Por favor, intente nuevamente." << endl;
            continue;
        }

        try {
            if (opcion == 1) {
                if (filaCaja.estaVacia()) {
                    cout << "La fila de Caja está vacía." << endl;
                } else {
                    Cliente cliente = filaCaja.atenderCliente();
                    cout << "\nAtendiendo al cliente: " << cliente.nombre 
                         << " (" << cliente.transaccion << ")" << endl;
                    realizarTransaccion(cliente);
                }
            } else if (opcion == 2) {
                if (filaAtencionCliente.estaVacia()) {
                    cout << "La fila de Atención al Cliente está vacía." << endl;
                } else {
                    Cliente cliente = filaAtencionCliente.atenderCliente();
                    cout << "\nAtendiendo al cliente: " << cliente.nombre 
                         << " (" << cliente.transaccion << ")" << endl;
                    realizarTransaccion(cliente);
                }
            } else if (opcion == 3) {
                break;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

// Función para agregar clientes a las filas correspondientes
void agregarClientes(Fila& filaCaja, Fila& filaAtencionCliente) {
    while (true) {
        cout << "\n=== BANCO INTERMEDIARIO ===\n";
        cout << "Ingrese el nombre del cliente: ";
        string nombre;
        cin >> nombre;

        int opcion;
        while (true) {
            cout << "\nSeleccione el tipo de transacción que desea realizar:\n"
                 << "1. Retiro de dinero\n"
                 << "2. Depósito de dinero\n"
                 << "3. Temas con su tarjeta de crédito\n"
                 << "4. Apertura de cuenta\n"
                 << "5. Consultas generales\n"
                 << "Opción: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 5." << endl;
            } else if (opcion < 1 || opcion > 5) {
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 5." << endl;
            } else {
                break;
            }
        }

        string transaccion;
        switch (opcion) {
            case 1: 
                transaccion = "Retiro de dinero"; 
                break;
            case 2: 
                transaccion = "Depósito de dinero"; 
                break;
            case 3: 
                transaccion = "Temas con su tarjeta de crédito"; 
                break;
            case 4: 
                transaccion = "Apertura de cuenta"; 
                break;
            case 5: 
                transaccion = "Consultas generales"; 
                break;
        }

        double saldo = (transaccion == "Retiro de dinero" || transaccion == "Depósito de dinero") ? rand() % 1000 + 100 : -1.0;
        Cliente nuevoCliente(nombre, transaccion, saldo);

        if (transaccion == "Retiro de dinero" || transaccion == "Depósito de dinero") {
            filaCaja.insertarCliente(nuevoCliente);
            cout << "\nEl cliente " << nombre << " ha sido agregado a la fila de Caja." << endl;
        } else {
            filaAtencionCliente.insertarCliente(nuevoCliente);
            cout << "\nEl cliente " << nombre << " ha sido agregado a la fila de Atención al Cliente." << endl;
        }

        cout << "\n¿Desea agregar otro cliente? (S/N): ";
        char respuesta;
        cin >> respuesta;

        if (cin.fail() || (respuesta != 's' && respuesta != 'S')) {
            break;
        }
    }
}

// Función principal
int main() {
    srand(time(0)); // Semilla para números aleatorios

    Fila filaCaja;
    Fila filaAtencionCliente;

    while (true) {
        int opcion;
        cout << "\n=== Bienvenido al Banco Intermediario ===\n"
             << "\nSeleccione del menú la tarea que desea realizar:\n"
             << "1. Agregar clientes\n"
             << "2. Atender clientes\n"
             << "3. Terminar la sesión\n"
             << "Opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opción no válida. Intente nuevamente." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                agregarClientes(filaCaja, filaAtencionCliente);
                break;
            
            case 2:
                atenderClientes(filaCaja, filaAtencionCliente);
                break;
            
            case 3:
                cout << "Gracias por preferir al Banco Intermediario. ¡Vuelva pronto!" << endl;
                return 0;
            
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
