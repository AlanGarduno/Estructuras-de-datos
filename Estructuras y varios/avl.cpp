#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct Nodo {
    string llave, valor;
    unsigned char altura;
    Nodo* izq;
    Nodo* der;
    Nodo(string nllave, string nvalor) {
        llave = nllave;
        valor = nvalor;
        izq = der = 0;
        altura = 1;
    }
};

unsigned char altura(Nodo* p) {
    return p ? p->altura : 0;
}

int calcBalance(Nodo* p) {
    return altura(p->der) - altura(p->izq);
}

void recalcAltura(Nodo* p) {
    unsigned char hl = altura(p->izq);
    unsigned char hr = altura(p->der);
    p->altura = max(hl, hr) + 1;
}

Nodo* rotaDer(Nodo* p) {
    Nodo* q = p->izq;
    p->izq = q->der;
    q->der = p;
    recalcAltura(p);
    recalcAltura(q);
    return q;
}

Nodo* rotaIzq(Nodo* q) {
    Nodo* p = q->der;
    q->der = p->izq;
    p->izq = q;
    recalcAltura(q);
    recalcAltura(p);
    return p;
}

Nodo* balancea(Nodo* p) {
    recalcAltura(p);
    if(calcBalance(p) == 2) {
        if(calcBalance(p->der) < 0)
            p->der = rotaDer(p->der);
        return rotaIzq(p);
    }
    if (calcBalance(p) == -2) {
        if (calcBalance(p->izq) > 0)
            p->izq = rotaIzq(p->izq);
        return rotaDer(p);
    }
    return p;
}

Nodo* inserta(Nodo* p, string llave, string valor) {
    if (!p) return new Nodo(llave, valor);
    if (llave < p->llave)
        p->izq = inserta(p->izq, llave, valor);
    else
        p->der = inserta(p->der, llave, valor);
    return balancea(p);
}

Nodo* buscaMin(Nodo* p) {
    return p->izq ? buscaMin(p->izq) : p;
}

Nodo* borraMin(Nodo* p) {
    if(p->izq==0)
        return p->der;
    p->izq = borraMin(p->izq);
    return balancea(p);
}

Nodo* busca(Nodo* p, string k) {
    if (!p) return 0;
    if (k < p->llave)
        return busca(p->izq, k);
    else if (k > p->llave)
        return busca(p->der, k);
    return p;
}

Nodo* borra(Nodo* p, string k) {
    if (!p) return 0;
    if (k < p->llave)
        p->izq = borra(p->izq, k);
    else if (k > p->llave)
        p->der = borra(p->der, k);
    else {
        Nodo* q = p->izq;
        Nodo* r = p->der;
        delete p;
        if(!r) return q;
        Nodo* min = buscaMin(r);
        min->der = borraMin(r);
        min->izq = q;
        return balancea(min);
    }
    return balancea(p);
}

Nodo *avl;

void opInserta() {
    string k, v;
    cout << "Ingrese palabra: ";
    getline(cin, k);
    cout << "Ingrese significado: ";
    getline(cin, v);
    avl = inserta(avl, k, v);
    cout << "Palabra agregada (ENTER para continuar).";
    getline(cin, k);
}

void opBusca() {
    string k;
    cout << "Palabra a buscar: ";
    getline(cin, k);
    Nodo *r = busca(avl, k);
    if (r) {
        cout << endl;
        cout << k << ":" << endl;
        cout << "    " << r->valor << endl;
        cout << endl;
    }
    else cout << "La palabra no existe. ";
    cout << "(ENTER para continuar).";
    getline(cin, k);
}

void opBorra() {
    string k;
    cout << "Palabra a borrar: ";
    getline(cin, k);
    Nodo *r = busca(avl, k);
    if (r) {
        avl = borra(avl, k);
        cout << "La palabra ha sido borrada. ";
    }
    else cout << "La palabra no existe. ";
    cout << "(ENTER para continuar).";
    getline(cin, k);
}

void cargaDicc() {
    string k, v;
    ifstream dicc;
    dicc.open("dicc.txt");
    while (getline(dicc, k), getline(dicc, v), !dicc.fail()) {
        avl = inserta(avl, k, v);
    }
    dicc.close();
}

void guardaPre(ofstream &dicc, Nodo *p) {
    if (!p) return;
    dicc << p->llave << endl;
    dicc << p->valor << endl;
    guardaPre(dicc, p->izq);
    guardaPre(dicc, p->der);
}

void guardaDicc() {
    ofstream dicc;
    dicc.open("dicc.txt");
    guardaPre(dicc, avl);
    dicc.close();
}

int main() {
    int op;
    string l;
    int x,y;
    system("color D");
    printf("%c",201);
    x=1;
    for(x>=1;x<=78;x++)
    {
         printf("%c",205);
    }
    printf("%c",187);
    printf("%c                                                                              %c",186,186);
    printf("%c                                                                              %c",186,186);
    printf("%c                             ESTRUCTURAS DE DATOS                             %c",186,186);
    printf("%c                                                                              %c",186,186);
    printf("%c                                                                              %c",186,186);
	printf("%c                                                                              %c",186,186);
	printf("%c                                GRUPO: 1CM8                                   %c",186,186);

	printf("%c                                                                              %c",186,186);
	printf("%c                                INTEGRANTES:                                  %c",186,186);
	printf("%c                           GARDUNO VELAZQUEZ ALAN                             %c",186,186);
	printf("%c                        ROMERO GONZALEZ ALEXIS DE JESUS                       %c",186,186);
	printf("%c                                                                              %c",186,186);
	printf("%c                                                                              %c",186,186);
	
	
	printf("%c",200);
    y=1;
    for(y>=1;y<=78;y++)
    {
         printf("%c",205);
    }
    printf("%c",188);
    Beep(20,7000);
    system("cls");
    
    cargaDicc();
    do {
        op = 0;
        cout << endl << endl;
        cout << "\n\t\t\t       DICCIONARIO      \t\t\t\n"<<endl;
        int x,y;
       system ("color 5f");//color de la pantalla y texto
    //Margen arriba
	printf("%c",201);
    x=1;
    for(x>=1;x<=78;x++)
    {
         printf("%c",205);
    }
    printf("%c",187);
    //termina margen de arriba
    printf("%c                                                                              %c", 186,186 );
    printf("%c                    1: AGREGAR palabra al diccionario.                        %c", 186,186 );
    printf("%c                    2: BUSCAR significado de una palabra.                     %c", 186,186 );
    printf("%c                    3: BORRAR palabra del diccionario.                        %c", 186,186 );
    printf("%c                    4: Salir.                                                 %c", 186,186 );
    //margen de abajo
	printf("%c",200);
    y=1;
    for(y>=1;y<=78;y++)
    {
         printf("%c",205);
    }
    printf("%c",188);
    //termina el margen de abajo
        cout << endl;
        cout << "Seleccione una opcion: ";
        do {
            cin >> op;
            getline(cin, l); // Limpiar linea
            cout << endl;
            switch (op) {
                case 1:
                    opInserta();
                    break;
                case 2:
                    opBusca();
                    break;
                case 3:
                    opBorra();
                case 4:
                    break;
                default:
                    cout << "La opcion no existe. Intente de nuevo: ";
            }
        } while (op < 1 || 4 < op);
    }while (op != 4);
    guardaDicc();
    return 0;
}
