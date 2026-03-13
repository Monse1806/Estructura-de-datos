#include <iostream> // libreria para entrada y salida (cout, cin)
#include <vector>   // libreria para usar vectores
#include <string>   // libreria para usar el tipo string

using namespace std;

// Estructura del prestamo
// se puso todos los atributos que conlleva 
struct Prestamo
{
    string id;              // identificador del prestamo
    string tituloLibro;     // titulo del libro prestado
    string autorLibro;      // autor del libro
    string codigoLibro;     // codigo del libro en la biblioteca
    string nombreLector;    // nombre de la persona que pide el libro
    string cedulaLector;    // cedula del lector
    string fechaPrestamo;   // fecha en que se realizo el prestamo
    string estadoPrestamo;  // estado del prestamo (Prestado, Devuelto o Vencido)
    string fechaDevolucion; // fecha en que se debe devolver el libro
};

// Vector donde se almacenan todos los prestamos
// Cada posicion del vector representa un prestamo
vector<Prestamo> prestamos;

// Funcion para verificar si el ID existe
// Esta funcion revisa si ya existe un prestamo con el mismo ID dentro del vector
bool idExiste(string id)
{
    for(int i=0;i<prestamos.size();i++)
    {
        if(prestamos[i].id == id)
        {
            return true; // si encuentra el ID devuelve verdadero
        }
    }
    return false; // si no existe devuelve falso
}

// Menu del sistema
void menu()
{
    cout<<"\n===== SISTEMA DE PRESTAMOS =====\n";
    cout<<"1. Registrar prestamo\n";
    cout<<"2. Mostrar todos los prestamos\n";
    cout<<"3. Buscar prestamo\n";
    cout<<"4. Modificar prestamo\n";
    cout<<"5. Eliminar prestamo\n";
    cout<<"6. Reporte de prestamos\n";
    cout<<"7. Salir\n";
    cout<<"Seleccione una opcion: ";
}

// Cargar los 10 datos iniciales 
void cargarDatos()
{
    prestamos.push_back({"1","Cien anos de soledad","Gabriel Garcia Marquez","L001","Ana Torres","0102030405","01/03/2026","Prestado","10/03/2026"});
    prestamos.push_back({"2","El principito","Antoine de Saint Exupery","L002","Carlos Ruiz","0203040506","02/03/2026","Devuelto","09/03/2026"});
    prestamos.push_back({"3","1984","George Orwell","L003","Maria Lopez","0304050607","03/03/2026","Prestado","12/03/2026"});
    prestamos.push_back({"4","Don Quijote","Miguel de Cervantes","L004","Luis Perez","0405060708","04/03/2026","Prestado","13/03/2026"});
    prestamos.push_back({"5","Sapiens","Yuval Noah Harari","L005","Sofia Castro","0506070809","05/03/2026","Devuelto","11/03/2026"});
    prestamos.push_back({"6","Harry Potter","J.K Rowling","L006","Pedro Vega","0607080910","06/03/2026","Prestado","15/03/2026"});
    prestamos.push_back({"7","Clean Code","Robert Martin","L007","Daniela Mora","0708091011","07/03/2026","Prestado","16/03/2026"});
    prestamos.push_back({"8","Breve historia del tiempo","Stephen Hawking","L008","Jorge Salas","0809101112","08/03/2026","Prestado","17/03/2026"});
    prestamos.push_back({"9","La Odisea","Homero","L009","Valentina Rios","0910111213","09/03/2026","Devuelto","14/03/2026"});
    prestamos.push_back({"10","El alquimista","Paulo Coelho","L010","Andres Flores","1011121314","10/03/2026","Prestado","18/03/2026"});
}

// Registrar prestamo
// registrar un nuevo prestamo ingresando todos los datos por teclado
void registrarPrestamo()
{
    Prestamo p; // se crea una variable de tipo Prestamo

    cout<<"\nIngrese ID del prestamo: ";
    cin>>p.id;

    // verificamos si el ID ya existe
    if(idExiste(p.id))
    {
        cout<<"Ese ID ya existe.\n";
        return;
    }

    cin.ignore(); // limpiar buffer

    // se piden los datos del libro y del lector
    cout<<"Titulo del libro: ";
    getline(cin,p.tituloLibro);

    cout<<"Autor del libro: ";
    getline(cin,p.autorLibro);

    cout<<"Codigo del libro: ";
    getline(cin,p.codigoLibro);

    cout<<"Nombre del lector: ";
    getline(cin,p.nombreLector);

    cout<<"Cedula del lector: ";
    getline(cin,p.cedulaLector);

    cout<<"Fecha de prestamo (DD/MM/AAAA): ";
    getline(cin,p.fechaPrestamo);

    cout<<"Estado del prestamo (Prestado / Devuelto / Vencido): ";
    getline(cin,p.estadoPrestamo);

    cout<<"Fecha de devolucion (DD/MM/AAAA): ";
    getline(cin,p.fechaDevolucion);

    // se guarda el prestamo en el vector
    prestamos.push_back(p);

    cout<<"Prestamo registrado correctamente.\n";
}

// Mostrar prestamos
// se recorre el vector y muestra todos los prestamos registrados
void mostrarPrestamos()
{
    cout<<"\nLISTA DE PRESTAMOS\n";

    for(int i=0;i<prestamos.size();i++)
    {
        cout<<"\nID: "<<prestamos[i].id<<endl;
        cout<<"Titulo: "<<prestamos[i].tituloLibro<<endl;
        cout<<"Autor: "<<prestamos[i].autorLibro<<endl;
        cout<<"Codigo libro: "<<prestamos[i].codigoLibro<<endl;
        cout<<"Nombre lector: "<<prestamos[i].nombreLector<<endl;
        cout<<"Cedula lector: "<<prestamos[i].cedulaLector<<endl;
        cout<<"Fecha prestamo: "<<prestamos[i].fechaPrestamo<<endl;
        cout<<"Estado: "<<prestamos[i].estadoPrestamo<<endl;
        cout<<"Fecha devolucion: "<<prestamos[i].fechaDevolucion<<endl;
    }
}

// Buscar prestamo
// se buscar un prestamo usando el ID
void buscarPrestamo()
{
    string id;

    cout<<"Ingrese ID a buscar: ";
    cin>>id;

    for(int i=0;i<prestamos.size();i++)
    {
        if(prestamos[i].id==id)
        {
            cout<<"\nPrestamo encontrado\n";

            cout<<"Titulo: "<<prestamos[i].tituloLibro<<endl;
            cout<<"Autor: "<<prestamos[i].autorLibro<<endl;
            cout<<"Lector: "<<prestamos[i].nombreLector<<endl;
            cout<<"Estado: "<<prestamos[i].estadoPrestamo<<endl;

            return;
        }
    }

    cout<<"Prestamo no encontrado\n";
}

// Modificar prestamo
void modificarPrestamo()
{
    string id;

    cout<<"Ingrese ID del prestamo a modificar: ";
    cin>>id;
    cin.ignore();

    for(int i=0;i<prestamos.size();i++)
    {
        if(prestamos[i].id==id)
        {
            cout<<"Nuevo estado (Prestado / Devuelto / Vencido): ";
            getline(cin,prestamos[i].estadoPrestamo);

            cout<<"Nueva fecha de devolucion (DD/MM/AAAA): ";
            getline(cin,prestamos[i].fechaDevolucion);

            cout<<"Prestamo modificado correctamente\n";
            return;
        }
    }

    cout<<"Prestamo no encontrado\n";
}

// Eliminar prestamo
// permite eliminar un prestamo del vector
void eliminarPrestamo()
{
    string id;

    cout<<"Ingrese ID a eliminar: ";
    cin>>id;

    for(int i=0;i<prestamos.size();i++)
    {
        if(prestamos[i].id==id)
        {
            prestamos.erase(prestamos.begin()+i); // elimina el elemento del vector
            cout<<"Prestamo eliminado\n";
            return;
        }
    }

    cout<<"Prestamo no encontrado\n";
}

// Reporte del sistema
// mostramos un resumen de los prestamos
void reporte()
{
    int prestados=0;
    int devueltos=0;
    int vencidos=0;

    // recorremos el vector para contar los estados
    for(int i=0;i<prestamos.size();i++)
    {
        if(prestamos[i].estadoPrestamo=="Prestado")
        prestados++;

        if(prestamos[i].estadoPrestamo=="Devuelto")
        devueltos++;

        if(prestamos[i].estadoPrestamo=="Vencido")
        vencidos++;
    }

    cout<<"\nREPORTE DEL SISTEMA\n";
    cout<<"Total de prestamos: "<<prestamos.size()<<endl;
    cout<<"Prestados: "<<prestados<<endl;
    cout<<"Devueltos: "<<devueltos<<endl;
    cout<<"Vencidos: "<<vencidos<<endl;
}

//inicio del programa
int main()
{
    int opcion;

    cargarDatos(); // se cargan los datos iniciales

    do
    {
        menu(); // se muestra el menu
        cin>>opcion;

        // segun la opcion se ejecuta una funcion
        switch(opcion)
        {
            case 1: registrarPrestamo(); break;
            case 2: mostrarPrestamos(); break;
            case 3: buscarPrestamo(); break;
            case 4: modificarPrestamo(); break;
            case 5: eliminarPrestamo(); break;
            case 6: reporte(); break;
            case 7: cout<<"Saliendo del sistema...\n"; break;
            default: cout<<"Opcion incorrecta\n";
        }

    }while(opcion!=7); // el programa se repite hasta elegir salir

    return 0;
}
