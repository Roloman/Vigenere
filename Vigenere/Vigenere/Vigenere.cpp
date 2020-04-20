// Vigenere.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <vector>

using std::setw;
using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
string clave_completa;
string Clave_completa2;

string CompletarClave(string mensaje, string clave)
{
    string sub_clave = clave;
    string clave_completa;
    int tam_mensaje = mensaje.size();
    while (sub_clave.size() < tam_mensaje)
    {
        sub_clave += clave;
    }
    clave_completa = sub_clave.substr(0, tam_mensaje);
    return clave_completa;
}

string cifrar_ascii (string mensaje, string clave)
{   
    int tam_mensaje = mensaje.size();
    int tam_clave = mensaje.size();
    int tam_alfabeto = alfabeto.size();
    int pos_letra_mensaje, pos_letra_clave;
    int n;
    char msn, clv;
    string cifrado;

    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra_mensaje = int(mensaje[i]);
        pos_letra_clave = int(clave_completa[i]);
        n = pos_letra_mensaje + pos_letra_clave;
        if (n > 127)
        {
            n = n % 127;
        }
        cifrado += char(n);
    }
    return cifrado;
}

string descifrar_ascii(string mensaje, string clave)
{
    int tam_alfabeto = alfabeto.size();
    int pos_letra_mensaje, pos_letra_clave;
    int n;
    char msn;
    string cifrado;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra_mensaje = int(mensaje[i]);
        pos_letra_clave = int(clave_completa[i]);
        n = pos_letra_mensaje - pos_letra_clave;
        if (n < 0)
        {
            n += 127;
        }
        msn = char(n);
        
        cifrado += msn;
    }
    return cifrado;
}

void iteradores(string& a) {
    string::const_iterator iterador1 = a.begin();
    while (iterador1 != a.end()) {
        cout << *iterador1;
        iterador1++;
    }
    cout << endl;
}

string cifrar_decimal(string mensaje, string clave)
{
    string cifrado;
    int tam = alfabeto.size();
    int pos_letra, pos_clave, tmp, n;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        pos_clave = alfabeto.find(clave[i]);
        tmp = pos_clave + pos_letra;
        n = tmp;
        while (n >= tam)
        {
            n -= tam;
        }
        cifrado += alfabeto[n];
    }
    return cifrado;
}

string descifrar_decimal(string mensaje, string clave)
{
    string descifrado;
    int tam = alfabeto.size();
    int pos_letra, pos_clave, tmp, n;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        pos_clave = alfabeto.find(clave[i]);
        tmp = pos_letra - pos_clave;
        n = tmp;
        while (n < 0)
        {
            n += tam;
        }
        descifrado += alfabeto[n];
    }
    return descifrado;
}

void Funcion_Encriptar()
{
    int algoritmo;
    string mensaje;
    string clave;
    string encriptado;
    string desencriptado;
    cout << "Ingrese el mensaje que desea encriptar: ";
    getline(cin, mensaje);
    cout << "Ingrese la clave de encriptacion: ";
    getline(cin, clave);
    clave_completa = CompletarClave(mensaje, clave);
    cout << "Escriba un numero para elegir la opcion de encriptado:" << endl;
    cout << '\t' << "1 Encriptacion Numerico" << endl;
    cout << '\t' << "2 Encriptacion Ascii" << endl;
    cout << '\t' << "3 Encriptacion Hex" << endl;
    cin >> algoritmo;
    while (algoritmo < 1 || algoritmo > 3)
    {
        cout << "Intentemos esto una vez mas:" << endl;
        cout << '\t' << "1 Encriptacion Numerico" << endl;
        cout << '\t' << "2 Encriptacion Ascii" << endl;
        cout << '\t' << "3 Encriptacion Hex" << endl;
        cin >> algoritmo;
    }
    if (algoritmo == 1)
    {
        encriptado = cifrar_decimal(mensaje, clave_completa);
        desencriptado = descifrar_decimal(encriptado, clave_completa);
    }
    if (algoritmo == 2)
    {
        encriptado = cifrar_ascii(mensaje, clave_completa);
        desencriptado = descifrar_ascii(encriptado, clave_completa);
    }
    cout << "El mensaje Encriptado es: ";
    cout << encriptado << endl;
    cout << "El mensaje Desencriptado es: ";
    cout << desencriptado << endl;
}

string Aqui(string mensaje)
{
    string aqui = "aqui";
    int diez = 10;
    for (int i = 0; i < mensaje.size(); i++)
    {
        if ( i > 0 && i % diez == 0)
        {
            mensaje.insert(i, aqui);
            diez += 14;
        }
    }
    return mensaje;
}

string Completa_W(string mensaje)
{
    while (mensaje.size() % 4 != 0)
    {
        mensaje += "W";
    }
    return mensaje;
}

string Elimina_Aqui(string mensaje)
{
    //str.erase(10, 8);
    int diez = 10;
    for (int i = 0; i < mensaje.size(); i++)
    {
        if (i > 0 && i % diez == 0)
        {
            mensaje.erase(diez, 4);
            diez += 10;
        }
    }
    return mensaje;
}

string Elimina_Ws(string mensaje)
{
    string ws = "W";
    string spacio = " ";
    int posicion = mensaje.find(ws);
    while (posicion != string::npos) {
        mensaje.replace(posicion, 4, spacio);
        posicion = mensaje.find(ws, posicion + 1);
    }
    return mensaje;
}

string CompletarClave2(string mensaje, string clave)
{
    string sub_clave = clave;
    string clave_completa2;
    int tam_mensaje = mensaje.size();
    
    sub_clave += mensaje;
    clave_completa2 = sub_clave.substr(0, (tam_mensaje + 1));

    return clave_completa2;
}

void Aqui_Ws()
{
    string mensaje;
    string mensaje_aqui;
    string mensaje_Aqui_Ws;
    string clave;
    string encriptado;
    string desencriptado;
    cout << "Ingrese el mensaje que desea encriptar: ";
    getline(cin, mensaje);
    cout << "Ingrese la clave de encriptacion: ";
    getline(cin, clave);
    Clave_completa2 = CompletarClave2(mensaje, clave);
    cout << "soy clave completa 2 " << Clave_completa2 << endl;
    mensaje_aqui = Aqui(mensaje);
    cout << "Completando Aqui:" << endl;
    cout << mensaje_aqui << endl;
    mensaje_Aqui_Ws = Completa_W(mensaje_aqui);
    cout << "Completando Ws:" << endl;
    cout << mensaje_Aqui_Ws << endl;
    encriptado = cifrar_decimal(mensaje_Aqui_Ws, Clave_completa2);
    cout << "Mensaje cifrado:" << endl;
    cout << encriptado << endl;
    desencriptado = cifrar_decimal(encriptado, Clave_completa2);
    cout << "Mensaje descifrado:" << endl;
    cout << desencriptado << endl;
    mensaje_Aqui_Ws = Elimina_Ws(desencriptado);
    cout << "Mensaje sin Ws:" << endl;
    cout << mensaje_Aqui_Ws << endl;
    mensaje_aqui = Elimina_Aqui(mensaje_Aqui_Ws);
    cout << "Mensaje sin Aqui:" << endl;
    cout << mensaje_aqui << endl;
}

int main()
{   
    //Funcion_Encriptar();
    string mensaje = "Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.";
    string clave = "Pablo Neruda";
    string cifrado;
    string descifrado;
    string mensaje1 = "Llamaremos todos a la misma hora esperando que sea tempranoooo";
    string clave1 = "gola chichon";
    string a;
    string b;
    string c;
    string d;
    //Aqui_Ws();

    a = Aqui(mensaje1);
    b = Completa_W(a);
    c = Elimina_Aqui(b);
    d = Elimina_Ws(c);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    /*string b = "krt";
    char a = 'z';
    int x = 0;
    cout << x << endl;
    x = int(a);
    char y = 'T';
    y = char(x);
    cout << x << endl;
    a = b[0];
    cout << a << endl;
    cout << y << endl;*/
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
