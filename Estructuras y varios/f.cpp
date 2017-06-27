#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

void simplificar(char separar[], char simplificar[]);
void init_pila();
int push(char Elem);
int jerarquia(char Operador);
int aridad(char Exp[], int position);
int traduce(char exp[], char exp_pos[]);

#define MAX 100
char pila[MAX];
int top;


int main(void) {
    char Exp[MAX];
    char Exp_simpli[MAX] = {0};
    char Exp_pos[MAX] = {0};
    int indicador = 0;

    printf("\nIntroduce la expresion: ");
    fgets(Exp, MAX, stdin);
    simplificar(Exp, Exp_simpli);

    indicador = traduce(Exp_simpli, Exp_pos);
    puts(Exp_pos);
    system("PAUSE");
    return indicador;
}


void simplificar(char separar[], char simplificar[]) {
    int i = 0;
    int j = 0;

    while ( separar[j] ) {
        if ( !isspace(separar[j]) ) {
            simplificar[i++] = separar[j];
        }
        j++;
    }
}

void init_pila() {
    top = -1;
}


int push(char Elem) {
    if (top == MAX - 1)         
        return -1;
    pila[++top] = Elem;
    return 0;
}


int pop(char *Elem) {
    if (top == -1)              
        return -1;
    *Elem = pila[top--];
    return 0;
}



int jerarquia(char Operador) {
    switch (Operador) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        default:
            return 0;
    }
}



int aridad(char Exp[], int position) {
    if ( jerarquia(Exp[position]) == 1 ) {
        if ( (position == 0) ||
             ((jerarquia(Exp[position - 1]) >= 1) &&
              (jerarquia(Exp[position - 1]) <= 3)) ) {
            return 1;
        } else {
            return 2;
        }
    } else if ( (jerarquia(Exp[position]) > 1) &&
                (jerarquia(Exp[position]) <= 3) ) {
        return 2;
    } else {
        return jerarquia(Exp[position]);
    }
}


int traduce(char exp[], char exp_pos[]) {
    int i = 0, j = 0, ind = 0;
    char trash = ' ';

    init_pila();

    while ( exp[i] ) {
        if ( aridad(exp, i) == 0 ) {
            exp_pos[j++] = exp[i];
        } else if ( aridad(exp, i) == 1 ) {
            switch (exp[i]) {
                case '-':
                    exp_pos[j++] = exp[i];
                    break;
                case '+':
                    trash = exp_pos[i];
                    break;
                default:
                    assert(0);
            }
        } else if (aridad(exp, i) == 2) {
            while ( (top != -1) &&
                    (jerarquia(pila[top]) >= jerarquia(exp[i])) &&
                    pila[top] != '(' ) {
                ind = pop(&exp_pos[j++]);
            }
            ind = push(exp[i]);
        } else if ( jerarquia(exp[i]) == 4 ) {
            ind = push(exp[i]);
        } else if ( jerarquia(exp[i]) == 5 ) {
            while ( (top != -1) && (pila[top] != '(') ) {
                ind = pop(&exp_pos[j++]);
            }
            if ( (top != - 1) && pila[top] == '(') {
                ind = pop(&trash);
            }
        }
        i++;
    }

    while (top != -1) {
        ind = pop(&exp_pos[j++]);
    }

    return ind;
}
void *__gxx_personality_v0;
