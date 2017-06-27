
typedef int dato;

enum bool{
	false = 0,
	true = 1
};

typedef struct Cola
{
	int frente;
	int n; //numero de elementos en la cola "ID"
	int nmax; //numeor maximo de elementos 
	dato *datos;
}Cola;

bool colaLlena(Cola *c);
bool colaVacia(Cola *c);
dato desEncolar(Cola *c);
void encolar(Cola*c, dato y);
void crear(Cola *c, int max);



