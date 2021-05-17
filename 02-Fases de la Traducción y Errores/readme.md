- nmartinezgross
- 16-8861-3
- Martinez Gross
- Natalia
- 02 - Fases de la Traduccion y Errores
      
      
# 1. Preprocesador:
	(gcc -E hello.c > hello.i)

	En hello2.i podemos observar que el preprocesador trae el contrato de las funciones que están declaradas dentro de la biblioteca standard de entrada/salida (stdio.h).
	Luego, copia el código fuente escrito por nosotros reemplazando los comentarios (en este caso el /medio/ dentro de la definición de main) por un espacio.

	La primera linea de hello3.i nos declara la función de printf. Viendola en más detalle podemos observar que:
	-printf es de tipo entero, por lo cual devuelve, justamente, un entero (este será igual al número de caracteres impresos o a un número negativo si hay algun error)
	-el primer argumento es una constante de cadena (const define que esta cadena no se modificara por la función y char * define que será una cadena de n caracteres)
	-los puntos suspensivos luego de la coma definen que podemos tener tantos argumentos adicionales como queramos

	No se observan diferencias entre hello3.c y hello3.i debido a que el código fuente no poseía comentarios ni bibliotecas a ser incluidas para el correcto funcionamiento del programa.
	


# 2. Compilación:
	(gcc -S hello.c)
	(as -o hello.o hello.s -> Ensamblado)

	Al tratar de compilar hello3.i se recibe el sigueinte error:
	hello3.c: In function 'main': hello3.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration] 5 | prontf("La respuesta es %d\n"); | ^~~~~~ | printf hello3.c:5:5: error: expected declaration or statement at end of input

	Para solucionar este error se agrega la llave faltante para definir donde concluyen las sentencias de la función main dentro de hello4.c.
	Dentro de hello4.s podemos observar que, en rasgos generales, se invoca la función main y, luego, se invoca a prontf.
	crea la pila, se mueve la dirección de la cadena ASCII en la pila (movl $L0, (%esp)), se invoca prontf, se almacena el valor de retorno (en este caso 1 ya que hay error) y se destruye la pila.


# 3. Vinculación:
	(gcc -o hello hello.o)
	Correcciones realizadas dentro de hello5.c: cambiar prontf por printf.
	El resultado recibido al ejecutar el programa hello5 es: "La respuesta es 4200880".
	Esto es debido a que no le estamos pasando la variable que contiene el número a imprimir por pantalla a la función printf.



# 4. Correción de Bug:
	Se corrigió el error mencionado en el punto anterios agregando la variable i luedo de "La respuesta es %d\n" dentro de hello6.c.
	 Al hacer esto el mensaje recibido al ejecutar el rpograma es "La respuesta es 42".



# 5. Remoción de prototipo:
	Dentro de hello7.c se quita la declaración de printf.
	Al compilar recibimos el siguiente warning: 
hello7.c: In function 'main': hello7.c:3:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration] 3 | printf("La respuesta es %d\n",i); | ^~~~~~ hello7.c:3:5: warning: incompatible implicit declaration of built-in function 'printf' hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf' +++ |+#include <stdio.h> 1 | int main(void){

	De todos modos el programa funciona correctamente ya que el compilador reconoce la función printf aunque esta no esté declarada ni estemos incluyendo el contrato de la función.



# 6. Compilación Separada: Contratos y Módulos
	Se utiliza hello8.c y studio1.c
	
	De esta forma se genera el ejecutable incluyendo ambos archivos objeto. Al hacer esto el compilador envía una advertencia por ni estar incluyendo los headers.
	De todos modos el resultado al ejecutar el programa es el correcto ("La respuesta es 42").

	Se utiliza hello9.c, studio2.c y studio.h
	Se agrega el contrato studio.h tanto en el cliente hello9.c como en el proveedor studio2.c.
	De este modo el compilador no envió ningún warning al compilar ambos archivos en un mismo ejecutable.
	El resultado de ejecutar el programa es el mismo que en el punto anterior ("La respuesta es 42")

	La ventaja de incluir los contratos en los clientes y en el proveedor es que se pueden detectar errores mucho antes en el proceso de traducción, ya que el proveedor ya conoce los argumentos que las funciones esperan recibir.