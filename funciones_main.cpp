#include "funciones.h"



int main(int argc, char *argv[]){

    
    ifstream archivo = abrir_archivo("productos.txt");
    int cant_productos = calcular_cant_productos(archivo);
    Gondola gondola = crear_gondola (cant_productos);
    cargar_gondola(archivo,gondola);
    
   
    
    char comando;
    char continuar_operando = 's';

    while(continuar_operando == 's'){

       
        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;
        
        cout<<"a. buscar producto indicando su nombre"<< endl;
        cout<<"b. buscar producto por codigo de barra"<< endl;
        cout<<"c. modificar el precio de algun producto"<< endl;
        cout<<"d. quitar un producto de la gondola"<< endl;
        cout<<"e. consultar la cantidad de productos en oferta que se encuentran en la gondola"<< endl;
        cout<<"f. agregar al chango todos los producto de la gondola"<< endl;

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;
        cout<<"ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'){

            cout<<"comando invalido"<<endl;
            cout<<"ingrese un comando"<< endl;
            cin>> comando;

        }

        switch(comando){

            case 'a':
                string producto_a_buscar;
                Producto producto;

                cout<<"ingrese el nombre del producto que desea buscar"<<endl;
                cin>>producto_a_buscar;

                producto = buscar_nombre(producto_a_buscar);

                break;

            case 'b':

                int producto_a_buscar;
                Producto producto;

                cout<<"ingrese el codigo del producto que desea buscar"<<endl;
                cin>>producto_a_buscar;

                producto = buscar_codigo(producto_a_buscar);

                break;

            case'c':
                Producto producto_a_modificar = tipo_busqueda(gondola);
                modificar_precio(producto_a_modificar);
                break;

            case 'd':
                Producto producto_a_quitar = tipo_busqueda(gondola);
                quitar_producto(producto_a_quitar);
                break;

            case'e':
                cantidad_en_oferta(gondola)

                break;

            case'f':

                

                break;


        }

    cout<<"si desea realizar otra operacion ingrese s"<< endl;
    cin>> continuar_operando;

    }

    return 0;

}
