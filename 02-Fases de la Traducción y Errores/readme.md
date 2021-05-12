- nmartinezgross
- 16-8861-3
- Martinez Gross
- Natalia
- 02 - Fases de la Traduccion y Errores


1. Preprocesador:
   (gcc -E hello.c > hello.i)
   En hello2.i podemos observar que el preprocesador busca dentro de la biblioteca standard de entrada/salida las funciones, 
   constantes y macros que la misma tiene para copiarlas previo a copiar nuestro programa hello2.c.
   Aparte de esto podemos ver que reemplazó los comentarios (en este caso el /*medio*/ dentro de la definición de main) por un espacio.

   La primera linea de hello3.i nos declara la función printf. Viendola más en detalle lo que esta nos define es que:
   - printf es de tipo entero, por lo cual devuelve, justamente, un entero (este será igual al número de caracteres impresos o a -1 si hay algun error)
   - el primer argumento es una constante de cadena (const define que esta cadena no se modificara por la función y char * define que será una cadena de n caracteres)
   - los puntos suspensivos luego de la coma definen que podemos tener tantos argumentos adicionales como queramos

   No se observan diferencias entre hello3.c y hello3.i debido a que el código fuente no poseía comentarios ni bibliotecas a ser incluidas para el correcto funcionamiento del programa.
   
2. Compilación:
   (gcc -S hello.c)
   (as -o hello.o hello.s -> Ensamblado)
   Al tratar de compilar hello3.i, se recibe el siguiente error:

   hello3.c: In function 'main':
   hello3.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf
   hello3.c:5:5: error: expected declaration or statement at end of input

   Debido a esto, se agrega la llave faltante para definir donde concluyen las sentencias de la funcion main.

   Respecto a hello4.s: el código crea la pila, se mueve la dirección de la cadena ASCII en la pila (movl   $L0, (%esp)), se 
   invoca prontf, se almacena el valor de retorno (en este caso 1 ya que hay error) y se destruye la pila.


3. Vinculación:
   Corrección realizada: cambiar prontf por printf
   (gcc -o hello hello.o)
   El resultado recibido al ejecutar el programa es: "La respuesta es 4200880"

4. Corrección de Bug:
   El resultado recibido al ejecutar el programa es: "La respuesta es 42"

5. Remoción de prototipo:
   Al compilar:
   hello7.c: In function 'main':
   hello7.c:3:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
       3 |     printf("La respuesta es %d\n",i);
         |     ^~~~~~
   hello7.c:3:5: warning: incompatible implicit declaration of built-in function 'printf'
   hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
     +++ |+#include <stdio.h>
       1 | int main(void){


   "La respuesta es 42"
   El programa funciona ya que, aunque no estemos declarando printf, ni incluyendo la biblioteca standard de entrada/salida, el 
   compilador reconoce la función de igual manera.
   
6. Compilación Separada: Contratos y Módulos: