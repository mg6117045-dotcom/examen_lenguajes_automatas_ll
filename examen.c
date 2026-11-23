#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int es_digito(char c) {
    int estado = 0;

    if (c >= '0' && c <= '9') {
        estado = 1;
    }

    return estado;
}


int es_operador(char c) {
    int estado = 0;

    if (c == '+' || c == '-' || c == '*' || c == '/') {
        estado = 1;
    }

    return estado;
}


int es_parentesis(char c) {
    int estado = 0;

    if (c == '(' || c == ')') {
        estado = 1;
    }

    return estado;
}

int es_palabrar(char * token) {
    int estado = 0;

    if (strcmp(token, "for") == 0 || strcmp(token, "if") == 0 || strcmp(token, "where") == 0 ) {
        estado = 1;
    }

    return estado;
}

int es_finl(char c) {
    int estado = 0;

     if (c == ';')  {
        estado = 1;
    }

    return estado;
}
int es_asignacion(char c) {
    int estado = 0;

     if (c == '=')  {
        estado = 1;
    }

    return estado;
}

int es_tipo(char * token) {
    int estado = 0;

    if (strcmp(token, "float") == 0 || strcmp(token, "int") == 0 || strcmp(token, "char") == 0 ) {
        estado = 1;
    }

    return estado;
}

int es_instruccion(char * token) {
    int estado = 0;

    if (strcmp(token, "while") == 0 || strcmp(token, "for") == 0 || strcmp(token, "if") == 0 ) {
        estado = 1;
    }

    return estado;
}

int es_alfanum(char c) {
    int estado = 0;

    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
        estado = 1;
    }

    return estado;
}







void print_token(char *token) {
    printf("El token es: %s\n", token);
}


void quitar_salto_de_linea(char *texto) {
    texto[strcspn(texto, "\r\n")] = '\0';
}


int token_es_numero(char *token) {

    int i = 0;
    char c = token[i];
    int estado = 1;

    while (c != '\0') {

        estado = es_digito(c);

        if (estado == 0) {
            break;
        }

        i++;
        c = token[i];
    }

    return estado;
}


int token_es_operador(char *token) {

    int estado = 0;

    if (strlen(token) == 1) {

        char c = token[0];

        estado = es_operador(c);
    }

    return estado;
}


int token_es_parentesis(char *token) {

    int estado = 0;

    if (strlen(token) == 1) {

        char c = token[0];

        estado = es_parentesis(c);
    }

    return estado;
}

int token_es_palabrar(char *token) {

    int estado = 0;

    estado = es_palabrar(token);

    return estado;
}

int token_es_finl(char *token) {

    int estado = 0;

    if (strlen(token) == 1) {

        char c = token[0];

        estado = es_finl(c);
    }

    return estado;
}

int token_es_asignacion(char *token) {

    int estado = 0;

    if (strlen(token) == 1) {

        char c = token[0];

        estado = es_asignacion(c);
    }

    return estado;
}

int token_es_tipo(char *token) {

    int estado = 0;

    estado = es_tipo(token);

    return estado;
}
int token_es_instruccion(char *token) {

    int estado = 0;

    estado = es_instruccion(token);

    return estado;
}

int token_es_alfanum(char *token) {
    int i = 0;
    char c = token[i];
    int estado = 1; 

    while (c != '\0') {
        
        estado = es_alfanum(c);

        
        if (estado == 0) {
            break;
        }

        i++;
        c = token[i];
    }

    return estado;
}




int linea_tiene_fin(char *linea) {
    int estado = 0;
    int i = strlen(linea) - 1;

    while (i >= 0 && isspace(linea[i])) {
        i--;
    }

    if (i >= 0 && linea[i] == ';') {
        estado = 1;
    }

    return estado;
}









int main() {
    FILE *archivo;
    char buffer[256]; // Almacenará cada línea leída
    char *token;
    // Abrir el archivo en modo lectura ("r")
    archivo = fopen("/home/miguel/Descargas/ejemplo.txt", "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Leer línea por línea hasta llegar al final del archivo (EOF)
    while (fgets(buffer, sizeof(buffer), archivo)!= NULL) {
        quitar_salto_de_linea(buffer);

      token = strtok (buffer, " \t\n\r ");
    


 while (token != NULL) {

        print_token(token);

        if (token_es_numero(token)) {
            printf("Es un numero\n");
        }
        else if (token_es_operador(token)) {
            printf("Es un operador\n");
        }
        else if (token_es_parentesis(token)) {
            printf("Es un parentesis\n");
        }
        else if (token_es_palabrar(token)) {
            printf("Es una palabra reserveada\n");
        }
        else if (token_es_finl(token)) {
            printf("Es fin de instruccion\n");
        }
        else if (token_es_asignacion(token)) {
            printf("Es Asignacion\n");
        }
        else if (token_es_tipo(token)) {
            printf("Es Tipo de Dato\n");
        }
        else if (token_es_instruccion(token)) {
            printf("Es instruccion\n");
        }
        else if (token_es_alfanum(token)) {
            printf("Es una variable\n");
        }
        else {
            printf("Token no valido\n");
        }

        

token = strtok (NULL, " \t\n\r ");
}
}
    // Cerrar siempre el archivo al terminar
    fclose(archivo);

    return 0;
}
