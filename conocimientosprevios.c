#include <stdio.h>
#include <string.h>

struct CD {
    int codigo;
    char artista[30];
    char album[30];
    int no_canciones;
    float precio;
    int existencias;
};

int buscar_cd(struct CD cds[], int cantidad_cds, int codigo) {
    int i;
    int encontrado = -1;

    for (i = 0; i < cantidad_cds; i++) {
        if (cds[i].codigo == codigo) {
            encontrado = i;
            break;
        }
    }

    return encontrado;
}

int agregar_cd(struct CD cds[], int cantidad_cds) {
    int codigo;
    int encontrado;

    printf("Agregar un nuevo CD:\n");
    printf("Codigo: ");
    scanf("%d", &codigo);

    do {
        encontrado = buscar_cd(cds, cantidad_cds, codigo);

        if  (encontrado == -1) {
            cds[cantidad_cds].codigo = codigo;
        } else {
            printf("El codigo ya esta en uso, ingrese otro: ");
            scanf("%d", &codigo);
        }
    } while(encontrado != -1);
    
    getchar();
    printf("Artista: ");
    fgets(cds[cantidad_cds].artista, 30, stdin);

    printf("Album: ");
    fgets(cds[cantidad_cds].album, 30, stdin);

    printf("Numero de canciones: ");
    scanf("%d", &cds[cantidad_cds].no_canciones);

    printf("Precio: ");
    scanf("%f", &cds[cantidad_cds].precio);

    printf("Existencias: ");
    scanf("%d", &cds[cantidad_cds].existencias);

    cantidad_cds++;
    printf("%d", cantidad_cds);

    return cantidad_cds;
}

void mostrar_cds(struct CD cds[], int cantidad_cds) {

    int i;
    for (i = 0; i < cantidad_cds; i++) {
        printf("----------------------------------------------\n");
        printf("Codigo: %d \n", cds[i].codigo);
        printf("Artista: %s", cds[i].artista);
        printf("Album: %s", cds[i].album);
        printf("Numero de canciones: %d \n", cds[i].no_canciones);
        printf("Precio: %f \n", cds[i].precio);
        printf("Existencias: %d", cds[i].existencias);
        printf("\n----------------------------------------------\n");
    }
}

void modificar(struct CD cds[], int posicion, int cantidad_cds) {
    int opcion;
    do {
        printf("------------Menu------------\n");
        printf("1. Modificar codigo\n");
        printf("2. Modificar artista\n");
        printf("3. Modificar album\n");
        printf("4. Modificar numero de canciones\n");
        printf("5. Modificar precio\n");
        printf("6. Modificar numero de existencias\n");
        printf("7. Regresar\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                int codigo;
                int encontrado;
                printf("Ingrese el nuevo codigo del cd: ");
                scanf("%d", &codigo);

                do {
                    encontrado = buscar_cd(cds, cantidad_cds, codigo);

                    if  (encontrado == -1 && codigo != cds[posicion].codigo) {
                        cds[posicion].codigo = codigo;
                    } else {
                        printf("El codigo ya esta en uso, ingrese otro: ");
                        scanf("%d", &codigo);
                    }
                } while(encontrado != -1 && codigo != cds[posicion].codigo);
                
                printf("Datos actualizados\n");
                break;
            case 2:
                printf("Ingrese el nuevo artista: ");
                fgets(cds[posicion].artista, 30, stdin);
                printf("Datos actualizados\n");
                break;
            case 3:
                printf("Ingrese el nuevo album: ");
                fgets(cds[posicion].album, 30, stdin);
                printf("Datos actualizados\n");
                break;
            case 4:
                printf("Ingrese el nuevo numero de canciones: ");
                scanf("%d", &cds[posicion].no_canciones);
                printf("Datos actualizados\n");
                break;
            case 5:
                printf("Ingrese el nuevo precio: ");
                scanf("%f", &cds[posicion].precio);
                printf("Datos actualizados\n");
                break;
            case 6:
                printf("Ingrese el nuevo numero de existencias: ");
                scanf("%d", &cds[posicion].existencias);
                printf("Datos actualizados\n");
                break;
            case 7:
            printf("Regresando...\n");
                break;
        }
    } while (opcion != 7);
}

void realizar_venta(struct CD cds[], int posicion) {
    if (cds[posicion].existencias == 0) {
        printf("No existen existencias del CD, no se pudo realizar la compra\n");
    } else {
        cds[posicion].existencias--;
        printf("Compra realizada con exito\n");
    }
}

int main() {
    struct CD cds[50];
    int opcion;
    int cantidad_cds = 0;
    int codigo;
    int encontrado;

    do {
        printf("------------Menu------------\n");
        printf("1. Agregar CD\n");
        printf("2. Mostrar todos CDs\n");
        printf("3. Buscar por codigo\n");
        printf("4. Modificar\n");
        printf("5. Realizar una venta\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            cantidad_cds = agregar_cd(cds, cantidad_cds);
            break;
        case 2:
            printf("Mostrando todos los CDs...\n");
            mostrar_cds(cds, cantidad_cds);
            break;
        case 3:
            if (cantidad_cds == 0) {
                printf("No hay CDs que mostrar\n");
            } else {
                printf("Ingrese el codigo del CD: ");
                scanf("%d", &codigo);
                encontrado = buscar_cd(cds, cantidad_cds, codigo);

                if (encontrado != -1) {
                    printf("----------------------------------------------\n");
                    printf("Codigo: %d \n", cds[encontrado].codigo);
                    printf("Artista: %s", cds[encontrado].artista);
                    printf("Album: %s", cds[encontrado].album);
                    printf("Numero de canciones: %d \n", cds[encontrado].no_canciones);
                    printf("Precio: %f \n", cds[encontrado].precio);
                    printf("Existencias: %d", cds[encontrado].existencias);
                    printf("\n----------------------------------------------\n");
                } else {
                    printf("No hay un CD con el codigo: %d\n", codigo);
                }
            }
            break;
        case 4:
            printf("Modificar CD\n");
            if (cantidad_cds != 0) {
                printf("Ingrese el codigo del CD a modificar: ");
                scanf("%d", &codigo);
                encontrado = buscar_cd(cds, cantidad_cds, codigo);

                if (encontrado != -1) {
                    modificar(cds, encontrado, cantidad_cds);
                } else {
                    printf("No hay un CD con el codigo: %d\n", codigo);
                }
            } else {
                printf("No hay CDs disponibles\n");
            }
            break;
        case 5:
            printf("Realizar venta de CD\n");
            if (cantidad_cds == 0) {
                printf("No hay CDs disponibles\n");
            } else {
                printf("Ingrese el codigo del CD: ");
                scanf("%d", &codigo);
                encontrado = buscar_cd(cds, cantidad_cds, codigo);

                if (encontrado != -1) {
                    realizar_venta(cds, encontrado);
                } else {
                    printf("No hay un CD con el codigo: %d\n", codigo);
                }
            }
            break;
        case 6:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta, intente nuevamente\n");
        }
    } while (opcion != 6);
    
    return 0;
}
