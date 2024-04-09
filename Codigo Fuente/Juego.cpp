
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirPizarra(int juego[][5], int entradas) {
    printf("\nPizarra del juego:\nEquipo           |");
    for (int i = 0; i <= entradas; ++i) printf(" %d |", i + 1);
    printf("  R |  H |  E |\n-----------------|");
    for (int i = 0; i <= entradas; ++i) printf("---|");
    printf("----|----|----|\nTigres del Licey |");
    for (int i = 0; i <= entradas; ++i) printf(" %d |", juego[i][0]);
    printf(" %d | %d | %d |\nÁguilas Cibaeñas |", juego[entradas][0], juego[entradas][2], juego[entradas][4]);
    for (int i = 0; i <= entradas; ++i) printf(" %d |", juego[i][1]);
    printf(" %d | %d | %d |\n", juego[entradas][1], juego[entradas][3], juego[entradas][4]);
}

int main() {
    srand(time(NULL));
    int juego[14][5] = {{0}};
    char homeClub;
    printf("¿Qué equipo quieres que sea el Homeclub? (A para Tigres del Licey, B para Águilas Cibaeñas): ");
    scanf(" %c", &homeClub);
    if (homeClub != 'A' && homeClub != 'B') {
        printf("¡Opción no válida! Debes elegir entre A y B.\n");
        return 1;
    }
    printf("Tigres del Licey carreras: ");
    scanf("%d", &juego[0][0]);
    printf("Águilas Cibaeñas carreras: ");
    scanf("%d", &juego[0][1]);
    int promedioHitsMLB = 8, promedioErroresMLB = 1;
    int opcionesHits[3] = {promedioHitsMLB - 1, promedioHitsMLB, promedioHitsMLB + 1};
    int opcionesErrores[3] = {promedioErroresMLB - 1, promedioErroresMLB, promedioErroresMLB + 1};
    int hitsLicey, hitsAguilas, erroresLicey, erroresAguilas;
    do {
        printf("Seleccione los hits para Tigres del Licey (opciones: %d, %d, %d): ", opcionesHits[0], opcionesHits[1], opcionesHits[2]);
        scanf("%d", &hitsLicey);
        if (hitsLicey != opcionesHits[0] && hitsLicey != opcionesHits[1] && hitsLicey != opcionesHits[2]) {
            printf("¡Lo siento, escoge uno de estos tres para poder seguir!\n");
        }
    } while (hitsLicey != opcionesHits[0] && hitsLicey != opcionesHits[1] && hitsLicey != opcionesHits[2]);

    do {
        printf("Seleccione los hits para Águilas Cibaeñas (opciones: %d, %d, %d): ", opcionesHits[0], opcionesHits[1], opcionesHits[2]);
        scanf("%d", &hitsAguilas);
        if (hitsAguilas != opcionesHits[0] && hitsAguilas != opcionesHits[1] && hitsAguilas != opcionesHits[2]) {
            printf("¡Lo siento, escoge uno de estos tres para poder seguir!\n");
        }
    } while (hitsAguilas != opcionesHits[0] && hitsAguilas != opcionesHits[1] && hitsAguilas != opcionesHits[2]);

    do {
        printf("Seleccione los errores para Tigres del Licey (opciones: %d, %d, %d): ", opcionesErrores[0], opcionesErrores[1], opcionesErrores[2]);
        scanf("%d", &erroresLicey);
        if (erroresLicey != opcionesErrores[0] && erroresLicey != opcionesErrores[1] && erroresLicey != opcionesErrores[2]) {
            printf("¡Lo siento, escoge uno de estos tres para poder seguir!\n");
        }
    } while (erroresLicey != opcionesErrores[0] && erroresLicey != opcionesErrores[1] && erroresLicey != opcionesErrores[2]);

    do {
        printf("Seleccione los errores para Águilas Cibaeñas (opciones: %d, %d, %d): ", opcionesErrores[0], opcionesErrores[1], opcionesErrores[2]);
        scanf("%d", &erroresAguilas);
        if (erroresAguilas != opcionesErrores[0] && erroresAguilas != opcionesErrores[1] && erroresAguilas != opcionesErrores[2]) {
            printf("¡Lo siento, escoge uno de estos tres para poder seguir!\n");
        }
    } while (erroresAguilas != opcionesErrores[0] && erroresAguilas != opcionesErrores[1] && erroresAguilas != opcionesErrores[2]);

    juego[0][2] = hitsLicey;
    juego[0][3] = hitsAguilas;
    juego[0][4] = erroresLicey;
    juego[0][5] = erroresAguilas;

    for (int i = 1; i < 14 && juego[i - 1][0] == juego[i - 1][1]; ++i)
        for (int j = 2; j < 5; ++j)
            juego[i][j] = rand() % (juego[0][j] + 1);

    int resultadoFinal = juego[9][0] - juego[9][1];
    if (resultadoFinal == 0) {
        int puntajeLicey = hitsLicey - erroresLicey;
        int puntajeAguilas = hitsAguilas - erroresAguilas;
        if (puntajeLicey > puntajeAguilas) {
            resultadoFinal = 1;
        } else if (puntajeLicey < puntajeAguilas) {
            resultadoFinal = -1;
        }
    }

    imprimirPizarra(juego, resultadoFinal == 0 ? 9 : 13);
    if (resultadoFinal > 0) {
        printf("\n¡Esta vez ganan los liceistas pero pronto descenderemos a atacar de nuevo! ¡Felicidades!\n");
    } else if (resultadoFinal < 0) {
        printf("\n¡Siempre en la cima, donde debemos de estar las águilas! ¡Gracias por todo!\n");
    } else {
        printf("\n¡El juego ha terminado en empate después de 13 entradas! ¡Volveremos mañana para ver quién anota la primera carrera!\n");
    }

    return 0;
}