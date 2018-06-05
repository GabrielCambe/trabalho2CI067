#include <stdio.h>
#include <stdlib.h>


void imprime_normal(char *str);
void imprime_inversa(char *str);
void imprime_sem_spac(char *str);

typedef void ( *ptr_FUNC_VOIDCHARptr )( char* );

void PrintString(char*str, ptr_FUNC_VOIDCHARptr);
//void PrintString(char *str, void (*func) (char *));

int main(int argc, char *argv[]){
  ptr_FUNC_VOIDCHARptr VETOR_func[ 4 ] = { NULL, imprime_normal, imprime_inversa, imprime_sem_spac };
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


void imprime_normal(char *str){
  int i; char c;

  i = 0;
  while ( str[i] != '\n' ){
    putchar( str[ i++ ] );
  }
  putchar( str[i] );
}

void imprime_inversa(char *str){
  int i; char c;

  i = -1;
  while ( str[ ++i ] !=  '\n' );

  while ( i > 0 ){
    putchar( str[ --i ] );
  }
  putchar( '\n' );
  
  
}

void imprime_sem_spac(char *str){
  int i; char c;

  i = 0;
  while ( str[i] != '\n' ){
    if(str[i] != ' ')
      putchar( str[ i ] );
    i++;
  }
  putchar( '\n' );
}

void PrintString( char *str, ptr_FUNC_VOIDCHARptr func){
  return func( str );
}
