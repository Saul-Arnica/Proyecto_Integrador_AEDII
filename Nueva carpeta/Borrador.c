/*
    switch(opc) {
        case 1:{

            break;
        }
        case 2:{

            break;
        }
        case 3:{    

            break;

        }
        case 4:{    

            break;

        }
    }   

typedef char tString[MAX_CHAR];

typedef struct {
    tString usuario;
    tString contraseña;
}usuarioInfo;

typedef usuarioInfo usuario[] = {
    {"ADMIN", "Juli123"},
    {"ENCARGADO", "Agus123"},
};

void abrirArchivo();
void ingresarUsuario();
void procesarUsuario();
void cerrarArchivo();

FILE *archivoAdmin;

void abrirArchivo() {
    archivoAdmin = fopen("usuario.dat", "rb");
    if(archivoAdmin != NULL) {
        printf("El archivo pudo abrirse con exito!...");
    }else {
        printf("El archivo no pudo abrirse!...);
        exit(EXIT_FAILURE);
    }
}

void ingresarUsuario() {
    printf("Ingrese su nombre de usuario: ");
    fflush(stdin);
    scanf("%[^\n]s", &usuario);
    printf("Ingrese su contrasena: ");
    fflush(stdin);
    scanf("%[^\n]s", &contrasena);
}

void procesarUsuario() {
    int i, usuarioValido = 0;
    for (i = 0; i < sizeof(usuarios) / sizeof(usuarios[0]); i++) {
        if (strcmp(usuario, usuario[i].usuario) == 0 && strcmp(contrasena, usuario[i].contraseña) == 0) {
            printf("Bienvenido %s, puede modificar los productos!...", usuario);
            usuarioValido = 1;
        }
    }
    if(!usuarioValido) {
        printf("Nombre de usuario o contraseña incorrectos.No tiene acceso a las modificaciones!...");
    }
}

void cerrarArchivo() {
    fclose(archivoAdmin);
    printf("El archivo se cerro exitosamente!...");
}








typedef char tString[MAX_CHAR];

typedef struct {
    tString usuario;
    tString contraseña;
}usuarioInfo;
typedef usuarioInfo usuarios[MAX_USERS];

void abrirArchivo();
void ingresarUsuario();
void crearUsuario();
void procesarUsuario();
void cerrarArchivo();

int cantUsuarios = 0;
FILE *archivoAdmin;

void abrirArchivo() {
    archivoAdmin = fopen("usuario.dat", "rb");
    if(archivoAdmin != NULL) {
        printf("El archivo pudo abrirse con exito!...");
    }else {
        printf("El archivo no pudo abrirse!...);
        exit(EXIT_FAILURE);
    }
}

void ingresarUsuario() {
    printf("Ingrese su nombre de usuario: ");
    fflush(stdin);
    scanf("%[^\n]s", &usuario);
    printf("Ingrese su contrasena: ");
    fflush(stdin);
    scanf("%[^\n]s", &contrasena);
}

void crearUsuario() {
    if (cantUsuarios == 0) {
        printf("No hay usuarios creados. Debe crear el primer usuario.\n");
        ingresarUsuario();
    }
}

void procesarUsuario() {
    int i, usuarioValido = 0;
    for (i = 0; i < sizeof(usuarios) / sizeof(usuarios[0]); i++) {
        if (strcmp(usuario, usuario[i].usuario) == 0 && strcmp(contrasena, usuario[i].contraseña) == 0) {
            printf("Bienvenido %s, puede modificar los productos!...", usuario);
            usuarioValido = 1;
        }
    }
    if(!usuarioValido) {
        printf("Nombre de usuario o contraseña incorrectos.No tiene acceso a las modificaciones!...");
    }
}

void cerrarArchivo() {
    fclose(archivoAdmin);
    printf("El archivo se cerro exitosamente!...");
}
*/

