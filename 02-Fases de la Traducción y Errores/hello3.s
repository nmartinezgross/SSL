	.file	"hello3.c"

error al tratar de compilar hello3.i:

hello3.c: In function 'main':
hello3.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf
hello3.c:5:5: error: expected declaration or statement at end of input