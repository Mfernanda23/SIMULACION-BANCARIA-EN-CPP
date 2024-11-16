# SIMULACION-BANCARIA-EN-CPP
Simulación bancaria de organización de atención al cliente en un banco. Creado en el lenguaje de C++

#**Descripción**

  El programa simula la gestión de clientes en un banco con dos filas de atención:
  1.	`Fila de Caja`: Para transacciones de retiro y depósito de dinero.
  2.	`Fila de Atención al Cliente`: Para otros servicios como problemas con tarjetas de crédito, aperturas de cuenta, y consultas generales.
   
  Los clientes se agregan a estas filas dependiendo de su tipo de transacción, y son atendidos en orden de llegada. El sistema permite     realizar transacciones como depósitos y retiros de dinero, además de mostrar la información actual de los clientes.

#**Funcionalidades**
  1. **Agregar Clientes**
   
  Los usuarios pueden agregar clientes a la fila de Caja o a la fila de Atención al Cliente según el tipo de transacción que deseen realizar.
  
  Los clientes pueden realizar un retiro, depósito, o consultar sobre problemas con su tarjeta de crédito, apertura de cuentas, o     consultas generales.

3. **Atender Clientes**
   
Los empleados pueden atender a los clientes de las filas, procesando las transacciones según el tipo seleccionado.

4. **Transacciones**

`Retiro de dinero`: Permite a los clientes retirar dinero de su cuenta si tienen saldo suficiente.

`Depósito de dinero`: Permite a los clientes depositar dinero en su cuenta.

5. **Interfaz**
   
El programa interactúa con el usuario mediante un menú en consola que permite seleccionar acciones como agregar clientes, atenderlos o terminar la sesión.

#**Estructura del Código**
1. Estructuras y Clases
`Cliente`: Contiene los datos del cliente, como nombre, tipo de transacción, y saldo.
`Nodo`: Representa un nodo de la lista enlazada que almacena un cliente.
`Fila`: Implementa una fila de clientes usando una lista enlazada, con métodos para agregar, atender y mostrar clientes.
2. Funciones
`agregarClientes`: Permite agregar nuevos clientes a las filas de acuerdo con el tipo de transacción.
`atenderClientes`: Permite a los empleados atender a los clientes de las filas.
`realizarTransaccion`: Realiza las transacciones de retiro o depósito de dinero para un cliente.

#**Compilación y Ejecución**

**Requisitos**

El usuario debe tener un compilador C++ (como g++).

**Compilación**

Para compilar el programa, puedes usar el siguiente comando:

`g++ -o bancoIntermediario bancoIntermediario.cpp`

#**Ejecución**

Una vez compilado, puedes ejecutar el programa con:

`./bancoIntermediario`

#**Ejemplo de Uso**
1.	`Agregar clientes`: El usuario ingresa el nombre del cliente y selecciona el tipo de transacción (retiro, depósito, etc.).
   
2.	`Atender clientes`: El empleado selecciona la fila de Caja o la fila de Atención al Cliente, y el cliente es atendido según su tipo de transacción.
   
#**Notas**

•	El sistema genera montos aleatorios para los saldos de los clientes en el caso de que deseen realizar retiro o ahorro.

•	La fila de atención de clientes y la fila de caja se gestionan por separado, y los clientes son atendidos de forma secuencial según el orden de inclusión al sistema.
