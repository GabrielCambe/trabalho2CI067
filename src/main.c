#include <stdio.h>
#include <stdlib.h>


int mapsto ( const char opr );
void insert ( char *linhas );
void delete ( char *linhas );
void find ( char *linhas );
void print ( char *linhas );
void quit ( char *linhas );
void read ( char *linhas );
void subst ( char *linhas );
void write ( char *linhas );
typedef void ( *ptr_FUNC_VOIDCHARptr )( char* ); // Os indicadores e argumentos serão tratados dentro de cada função
void exe ( char* linhas, ptr_FUNC_VOIDCHARptr );
  

int main( int argc, char *argv[] ){
  const ptr_FUNC_VOIDCHARptr MENU[ 9 ] = { NULL, insert, delete, find, print, quit, read, subst, write };
  int oper; char c;

  if ( argc > 1 ){
    printf( "O ARQUIVO SE ENCONTRA EM: %s\n", argv[1] );
    c = getc( stdin );
    if ( ( oper = mapsto(c) ) > 0 ){
      exe( NULL, MENU[ oper ] ); // o argumento passado para o programa foi válido

    }else{
      printf( "? \n" );

    }
    
  }else{
    printf( "Não tem arquivo especificado\n");
    // funciona sem arquivo especificado
  }

  
  return 0;
}


int mapsto ( const char opr ){
  //{ NULL, insert, delete, find, print, quit, read, subst, write }
  switch ( opr ){
  case 'i':
    return 1;
    
  case 'd':
    return 2;
    
  case 'f':
    return 3;
    
  case 'p':
    return 4;
    
  case 'q':
    return 5;
    
  case 'r':
    return 6;
    
  case 's':
    return 7;
    
  case 'w':
    return 8;
    
  default:
    return -1; 
  }
}


void insert ( char *linhas ){
  printf("INSERE\n");
}


void delete ( char *linhas ){
  printf("DELETE\n");
}


void find ( char *linhas ){
  printf("ENCONTRA\n");
}


void print ( char *linhas ){
  printf("IMPRIME\n");
}


void quit ( char *linhas ){
  printf("SAIR\n");
}


void read ( char *linhas ){
  printf("LER\n");
}


void subst ( char *linhas ){
  printf("SUBST\n");
}


void write ( char *linhas ){
  printf("ESCREVE\n");
}


void exe ( char *linhas, const ptr_FUNC_VOIDCHARptr func ){
  return func( linhas );
}
