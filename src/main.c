#include <stdio.h>
#include <stdlib.h>


void insert(char *linhas);
void delete(char *linhas);
void find(char *linhas);
void print(char *linhas);
void quit(char *linhas);
void read(char *linhas);
void subst(char *linhas);
void write(char *linhas);


typedef void ( *ptr_FUNC_VOIDCHARptr )( char* ); // Os indicadores e argumentos serão tratados dentro de cada função
void COMANDO(char*str, ptr_FUNC_VOIDCHARptr);


int main(int argc, char *argv[]){
  const ptr_FUNC_VOIDCHARptr MENU[ 8 ] = { NULL, insert, delete, find, print, quit, read, subst, write };

  char c, str[ 1000 ]; int i, opt;

  printf("Digite uma string de > 1000 caracteres:\n");
  i = 0;
  while( ( c = getchar() ) != '\n' ){ str[ i++ ] = c; }
  str[ i ] = c;
  
  if(argc == 2)
    opt = atoi( argv[1] );
    if( ( opt >= 1 ) && ( opt <= 3 ) ){
      
      PrintString( str, VETOR_func[ opt ] );
    }
		   
  return 0;
}


void insert(char *linhas);
void delete(char *linhas);
void find(char *linhas);
void print(char *linhas);
void quit(char *linhas);
void read(char *linhas);
void subst(char *linhas);
void write(char *linhas);


void COMANDO( char *linhas, const ptr_FUNC_VOIDCHARptr func){
  return func( linhas );
}
