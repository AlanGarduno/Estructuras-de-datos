#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nomardatos "diezprimeros.txt"
#define ANCHOMEMI 300 /* ancho de la memoria intermedia */
#define ANCHOPANT 80 /* ancho de la pantalla por defecto */

int anchura = ANCHOPANT;

struct dato {
  char nombre[20];
  char dni[20];
  int dia;
  int mes;
  int anio;
};

struct cola {
  int fr; /* el frente de la cola */
  int n; /* número de elementos de la cola */
  int nmax; /* número máximo de elementos de la cola */
  struct dato *p;
};

int colallena(struct cola *x) {
  return (x->n == x->nmax);
}

int colavacia(struct cola *x) {
  return (x->n == 0);
}

struct dato extraecola(struct cola *x) {
  struct dato z; /* valor de retorno */
  int i;
  if (!colavacia(x)) {
    i = x->fr; /* índice del frente */
    z = x->p[i]; /* valor contenido en el frente */
    i = (i + 1) % (x->nmax); /* incrementa el frente */
    x->fr = i; /* actualiza el frente */
    --(x->n); /* uno menos */
    return z;
  }
}

void insertacola(struct cola *x, struct dato y) {
  int i;
  if (!colallena(x)) {
    i = (x->fr + x->n) % (x->nmax); /* índice del lugar a insertar el nuevo elemento */
    x->p[i] = y; /* guardarlo */
    ++(x->n); /* uno más */
  }
}

void inicializacola(struct cola *x, int nmax) {
  struct dato *q; /* auxiliar */
  q = (struct dato *)malloc(nmax * sizeof(struct dato));
  x->fr = 0;
  x->n = 0;
  x->nmax = nmax;
  x->p = q;
}

void imprimecola(struct cola *x) {
  int i,j;
  if (!colavacia(x)) {
    for (i = x->fr; i < x->fr + x->n; ++i) {
      j = i % (x->nmax);
      printf("Indice ............ = %d\n",j);
      printf("Nombre ............ = %s\n",x->p[j].nombre);
      printf("Dni ............... = %s\n",x->p[j].dni);
      printf("Fecha de nacimiento = %d/%d/%d\n\n",x->p[j].dia,x->p[j].mes,x->p[j].anio);
    }
  }
}

void centracad(char *cadena, int ancho, char *d) {
  int r,l,i,j;
  l = strlen(cadena);
  r = (ancho - l)/2;
  for (i = 0; i < r; ++i)
    d[i] = ' ';
  for (j = 0; j < l; ++j) {
    d[i] = cadena[j];
    ++i;
  }
  for (j = 0; j < ancho - r - l; ++j) {
    d[i] = ' ';
    ++i;
  }
  d[i] = '\0';
}

  
void procesanodos(struct cola *x,int *lg, int nodoini, int nodofin, int indfinal) {
  char auxiliar[ANCHOMEMI],auxi[50];
  int i,j,m,k,ind;
  /* fila 0, los frentes */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i - (x->fr)];
    j = i % (x->nmax);
    sprintf(auxi,"(%d)",j);
    centracad(auxi,m + 4,auxiliar);
    printf("%s",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
  /* primera fila */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i - (x->fr)];
    printf("+");
    for (k = 0; k < m + 2; ++k)
      printf("-");
    printf("+");
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
  /* fila del nombre */
  for (i = nodoini; i <= nodofin; ++i) {
    j = i % (x->nmax);
    m = lg[i - (x->fr)];
    centracad(x->p[j].nombre,m + 2,auxiliar);
    printf("|%s|",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
  /* fila del dni */
  for (i = nodoini; i <= nodofin; ++i) {
    j = i % (x->nmax);
    m = lg[i - (x->fr)];
    centracad(x->p[j].dni,m + 2,auxiliar);
    printf("|%s|",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      printf(" -> ");
    }
  }
  printf("\n");

  /* fila de la fecha */
  for (i = nodoini; i <= nodofin; ++i) {
    j = i % (x->nmax);
    sprintf(auxi,"%d - %d - %d",x->p[j].dia,x->p[j].mes,x->p[j].anio);
    m = lg[i - (x->fr)];
    centracad(auxi,m + 2,auxiliar);
    printf("|%s|",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");

  /* última fila (igual que la primera) */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i - (x->fr)];
    printf("+");
    for (k = 0; k < m + 2; ++k)
      printf("-");
    printf("+");
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
}

void imprimenombres(struct cola *x) {
  int i,j,k,l,m,nn,ind,s,indfinal,np,p;
  int *lg;
  char auxiliar[ANCHOMEMI];
  if (!colavacia(x)) {
    /* Calcular las longitudes máximas de cada entrada y almacenarlas en un vector */
    nn = x->n;
    lg = (int *)malloc(nn * sizeof(int)); /* vector para almacenar las longitudes */
    k = 0;
    for (i = x->fr; i < x->fr + nn; ++i) {
      j = i % (x->nmax);
      /* calcular la longitud máxima */
      sprintf(auxiliar,"(%d)",j);
      l = strlen(auxiliar);
      m = strlen(x->p[j].nombre);
      if (m > l)
	l = m;
      m = strlen(x->p[j].dni);
      if (m > l)
	l = m;
      sprintf(auxiliar,"%d - %d - %d",x->p[j].dia,x->p[j].mes,x->p[j].anio);
      m = strlen(auxiliar);
      if (m > l)
	l = m;
      lg[k] = l; /* asignarlo */
      ++k;
    }
    /* Procesar los nodos */
    i = x->fr;
    k = 0;
    while (i < x->fr + nn) {
      s = 0;
      indfinal = 1; /* por defecto hay que poner el enlace al final */
      ind = 1;
      np = 0; /* número de nodos a procesar */
      while (ind && k < nn) {
	if (k == nn - 1)
	  p = 4 + lg[k]; /* necesito este espacio */
	else
	  p = 8 + lg[k]; /* necesito este espacio */
	if (s + p <= anchura) { /* este nodo cabe */
	  s += p;
	  ++np;
	  indfinal = (k == nn - 1) ? 0 : 1;
	  ++k;
	} else /* no cabe */
	  ind = 0;
      }
      if (np == 0) { /* nodo demasiado grande, overflow, procesarlo aunque se salga de la pantalla */
	np = 1;
	++k;
      }
      procesanodos(x,lg,i,i + np -1,indfinal);
      i += np;
    }
    free(lg); /* libera memoria */
  }
} /* fin de la función */
	  

struct dato tomadatos(void) {
  struct dato x; /* dato a retornar */
  char nombre[20];
  char dni[20];
  int dia;
  int mes;
  int anio;
  printf("Introduce nombre: ");
  scanf("%s",nombre);
  printf("Introduce dni: ");
  scanf("%s",dni);
  printf("Introduce fecha de nacimiento en la forma \"dia/mes/año\": ");
  scanf("%d/%d/%d",&dia,&mes,&anio);
  strcpy(x.nombre,nombre);
  strcpy(x.dni,dni);
  x.dia = dia;
  x.mes = mes;
  x.anio = anio;
  return x;
}

int menuprograma(void) {
  int opcion;
  printf("\n");
  printf("1) Insertar en la cola\n");
  printf("2) Extraer de la cola\n");
  printf("3) Imprimir la cola\n");
  printf("4) Mostrar la cola gráficamente\n");
  do {
    printf("Introduzca opción (1,2,3 o 4), 0 (cero) para salir: ");
    scanf("%d",&opcion);
  } while (opcion < 0 || opcion > 4);
  printf("\n");
  return opcion;
}

main(int argc, char *argv[]) {
  FILE *fp;
  char nomfich[40];
  int ind,dia,mes,anio,n,i;
  struct dato x; /* para tomar los datos */
  struct cola c; /* esta es la cola */
  char nombre[30],dni[30];
  if (argc <= 1) /* sin argumentos */
    strcpy(nomfich,nomardatos);
  else {
    strcpy(nomfich,argv[1]);
    if (argc >= 3) {
      i = atoi(argv[2]);
      if (i > 0)
	anchura = i;
    }
  }
  /* Imprimir las entradas */
  printf("Archivo de datos = \"%s\"\n",nomfich);
  printf("Ancho de pantalla = %d\n",anchura);

  fp = fopen(nomfich,"r");
  if (fp == NULL) {
    printf("No se ha podido abrir \"%s\" para leer.\n",nomfich);
    exit(1);
  }
  /* Calcular el número de personas contenidas en el archivo de datos */
  ind = 1;
  n = 0; /* número de datos leídos */
  while (ind) {
    i = fscanf(fp,"%s",nombre);
    if (i == EOF)
      ind = 0;
    else {
      fscanf(fp,"%s",dni);
      fscanf(fp,"%d/%d/%d",&dia,&mes,&anio);
      ++n;
    }
  }
  if (n <= 0) { /* no hay datos */
    printf("Sin datos en \"%s\" para leer.\n",nomfich);
    exit(2);
  }
  inicializacola(&c,n); /* crear la cola */
  fseek(fp,0l,SEEK_SET); /* situarse otra vez al comienzo */
  ind = 1;
  while (ind) {
    i = fscanf(fp,"%s",nombre);
    if (i == EOF)
      ind = 0;
    else {
      fscanf(fp,"%s",dni);
      fscanf(fp,"%d/%d/%d",&dia,&mes,&anio);
      strcpy(x.nombre,nombre);
      strcpy(x.dni,dni);
      x.dia = dia;
      x.mes = mes;
      x.anio = anio;
      insertacola(&c,x);
    }
  }
  fclose(fp);

  while (1) {
    i = menuprograma();
    switch(i) {
    case 0:
      exit(0); /* salir */
      break;
    case 1: /* Insertar */
      if (!colallena(&c)) { /* procede la inserción */
	x = tomadatos(); /* dato leido */
	insertacola(&c,x);
      } else
	printf("La cola está llena. No se puede insertar nada más.\n");
      break;
    case 2: /* Extraer */
      if (!colavacia(&c)) { /* procede la extracción */
	x = extraecola(&c);
	printf("Nombre ............ = \"%s\"\n",x.nombre);
	printf("Dni ............... = \"%s\"\n",x.dni);
	printf("Fecha de nacimiento = %d/%d/%d\n",x.dia,x.mes,x.anio);
      } else
	printf("La cola está vacía. No es posible la extracción.\n");
      break;
    case 3: /* Imprimir la cola */
      imprimecola(&c);
      break;
    case 4: /* Mostrar la cola gráficamente */
      imprimenombres(&c);
      break;
    default: /* por si las moscas */
      printf("Opción incorrecta: opcion = %d\n",i);
      break;
    }
  }
}
