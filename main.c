#include <stdio.h>
#include<stdlib.h>
#include<time.h>
// Definimos una estructura para representar una casilla del tablero
typedef struct Casilla {
  int tiene_serpiente;  // 1 si hay una serpiente en la casilla, 0 en caso contrario
  int tiene_escaleras;  // 1 si hay una escalera en la casilla, 0 en caso contrario
  int casilla_destino;  // Si hay una serpiente o una escalera, a qué casilla se mueve el jugador al caer en ella
} Casilla;

// Definimos una estructura para representar el tablero del juego
typedef struct Tablero {
  int tamanio;  // Tamaño del tablero (número de casillas)
  Casilla* casillas;  // Matriz de casillas
} Tablero;

// Definimos una estructura para representar a un jugador
typedef struct Jugador {
  int posicion;  // Posición actual del jugador en el tablero
} Jugador;

// Función para mover al jugador a una nueva posición
void mover_jugador(Jugador* jugador, int nueva_posicion) {
  jugador->posicion = nueva_posicion;
}

// Función para lanzar los dados y avanzar al jugador según el resultado
void lanzar_dados(Jugador* jugador, Tablero* tablero) {
  // Generamos un número aleatorio entre 1 y 6 para simular el lanzamiento de los dados
  	int dado1 = rand() % 6 + 1;
  	//int dado2 = rand() % 6 + 1;
  	int avance = dado1;
	printf("\nSe lanza el dado y obtiene %d\n", avance);
	system("pause");
  // Calculamos la nueva posición del jugador
  
  	int nueva_posicion = jugador->posicion + avance;
// Si la nueva posición se sale del tablero, no avanzamos al jugador
	if (nueva_posicion >= tablero->tamanio) {
		return;
	}

	// Si la casilla a la que se mueve el jugador tiene una serpiente o una escalera, actualizamos su posición al destino de esa casilla
	Casilla* casilla = &tablero->casillas[nueva_posicion];
	if (casilla->tiene_serpiente) {
		nueva_posicion = casilla->casilla_destino;
		printf("\n                  __");
		printf("\n      _______    /*_>-<");
		printf("\n  ___/ _____ \__/ /");
		printf("\n< ____/     \____/");
		printf("\nEncuentra una serpiente y baja a la casilla %d\n", nueva_posicion+1);
		system("pause");
	} else if (casilla->tiene_escaleras) {
		nueva_posicion = casilla->casilla_destino;
		printf("\n |--|");
		printf("\n |--|");
		printf("\n |--|");
		printf("\n |--|");
		printf("\nEncuentra una escalera y sube a la casilla %d\n", nueva_posicion + 1);
		system("pause");

	}
	
	// Movemos al jugador a la nueva posición
	mover_jugador(jugador, nueva_posicion);
	printf("Se encuentra en la casilla %d \n", nueva_posicion+1);
}

int main() {
	
	//interfaz inicial
	printf("\n********************************************************");
	printf("\n*  ___  ___  ___   ___  ___  ___       ___  ___  ___   *");
	printf("\n* |___ |___ |___| |___|  |  |___  |* |  |  |___ |___   *");
	printf("\n*  ___||___ | *.  |     _|_ |___  | *|  |  |___  ___|  *");
	printf("\n*  ___  ___  ___   ___        ___   ___   ___    ___   *");
	printf("\n* |___ |___ |     |___| |    |___  |___| |___|  |___   *");
	printf("\n* |___  ___||___  |   | |___ |___  | *.  |   |   ___|  *");
	printf("\n********************************************************");
	printf("\nBY: Randy Chanchay\n");
	system("pause");
	system("cls");
	printf("Hola vamos a jugar serpientes y escaleras donde tendremos 2 jugadores\n");
	printf("\nSerpientes y Escaleras es un juego de mesa en el que dos o más jugadores lanzan dados para mover sus fichas en un tablero.");
	printf("\nEl tablero se compone de una colección de cuadrados numerados y está adornado con 'serpientes' y 'escaleras', ");
	printf("\nque unen dos cuadrados en el tablero.");
	printf("\nLas serpientes unen los cuadrados hacia abajo mientras que las escaleras los unen hacia arriba.  ");
	printf("\nEsto significa que aterrizar en la parte inferior deuna escalera te lleva a la parte superior de esa escalera,mientras que aterrizar \nen la parte superior de una serpiente te lleva a la parte inferior de ");
	printf("\nesa serpiente. El objetivo del juego es llevar tu ficha a la casilla final antes que tus oponentes.\n");
	system("pause");
	system("cls");
	// Creamos el tablero y los jugadores
	Tablero tablero;
	tablero.tamanio = 100;
	tablero.casillas = malloc(sizeof(Casilla) * tablero.tamanio);
	
	// Inicializamos las casillas del tablero
	int i;
	for (i = 0; i < tablero.tamanio; i++) {
		tablero.casillas[i].tiene_serpiente = 0;
		tablero.casillas[i].tiene_escaleras = 0;
		tablero.casillas[i].casilla_destino = 0;
	}
	
	// Establecemos algunas serpientes y escaleras en el tablero
	//serpientes
	tablero.casillas[15].tiene_serpiente = 1;
	tablero.casillas[15].casilla_destino = 5;
	tablero.casillas[45].tiene_serpiente = 1;
	tablero.casillas[45].casilla_destino = 24;
	tablero.casillas[48].tiene_serpiente = 1;
	tablero.casillas[48].casilla_destino = 10;
	tablero.casillas[61].tiene_serpiente = 1;
	tablero.casillas[61].casilla_destino = 18;
	tablero.casillas[63].tiene_serpiente = 1;
	tablero.casillas[63].casilla_destino = 59;
	tablero.casillas[73].tiene_serpiente = 1;
	tablero.casillas[73].casilla_destino = 52;
	tablero.casillas[88].tiene_serpiente = 1;
	tablero.casillas[88].casilla_destino = 67;
	tablero.casillas[92].tiene_serpiente = 1;
	tablero.casillas[92].casilla_destino = 88;
	tablero.casillas[94].tiene_serpiente = 1;
	tablero.casillas[94].casilla_destino = 74;
	tablero.casillas[98].tiene_serpiente = 1;
	tablero.casillas[98].casilla_destino = 79;

	//escaleras
	tablero.casillas[1].tiene_escaleras = 1;
	tablero.casillas[1].casilla_destino = 37;
	tablero.casillas[6].tiene_escaleras = 1;
	tablero.casillas[6].casilla_destino = 13;
	tablero.casillas[7].tiene_escaleras = 1;
	tablero.casillas[7].casilla_destino = 30;
	tablero.casillas[14].tiene_escaleras = 1;
	tablero.casillas[14].casilla_destino = 25;
	tablero.casillas[20].tiene_escaleras = 1;
	tablero.casillas[20].casilla_destino = 41;
	tablero.casillas[27].tiene_escaleras = 1;
	tablero.casillas[27].casilla_destino = 83;
	tablero.casillas[35].tiene_escaleras = 1;
	tablero.casillas[35].casilla_destino = 43;
	tablero.casillas[50].tiene_escaleras = 1;
	tablero.casillas[50].casilla_destino = 66;
	tablero.casillas[70].tiene_escaleras = 1;
	tablero.casillas[70].casilla_destino = 90;
	tablero.casillas[77].tiene_escaleras = 1;
	tablero.casillas[77].casilla_destino = 97;
	tablero.casillas[86].tiene_escaleras = 1;
	tablero.casillas[86].casilla_destino = 93;
	
	Jugador jugador1;
	jugador1.posicion = 0;
	
	Jugador jugador2;
	jugador2.posicion = 0;
	
	
	// Lanzamos los dados y movemos a los jugadores hasta que alguno llegue a la última casilla del tablero
	while (jugador1.posicion < tablero.tamanio - 1 && jugador2.posicion < tablero.tamanio - 1) {
		printf("\n*******TURNO JUGADOR 1********\n");
		system("pause");
		lanzar_dados(&jugador1, &tablero);
		system("pause");
		system("cls");
		printf("\n*******TURNO JUGADOR 2********\n");
		system("pause");
		lanzar_dados(&jugador2, &tablero);
		system("pause");
		system("cls");

	}
	
	
	// Imprimimos un mensaje de felicitación al ganador
	if (jugador1.posicion >= tablero.tamanio - 1) {
		printf("\n¡Felicidades, jugador 1! ¡Has ganado el juego de las serpientes y escaleras!");
	} else if (jugador2.posicion >= tablero.tamanio - 1) {
		printf("\n¡Felicidades, jugador 2! ¡Has ganado el juego de las serpientes y escaleras!");
	}
	printf("\n*************************************************");
	printf("\n*               GRACIAS                         *");
	printf("\n*             by:Rafch17                        *");
	printf("\n*************************************************\n");
	system("pause");
	return 0;
}
