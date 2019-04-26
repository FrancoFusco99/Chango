#include "funciones.h"


ifstream abrir_archivo(string nom_archivo){

    ifstream entrada;

    entrada.open("nom_archivo");

    if(entrada.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
    }

    return entrada;
}


int calcular_cant_productos(ifstream &archivo){

    string linea;
    int cant_productos = 0;
        while (!archivo.eof()){
            cant_productos++;
        }

    return cant_productos;
}

Gondola crear_gondola(int cant_productos){
    Gondola gondola = Gondola(cant_productos);

return gondola;
}

void cargar_gondola(ifstream &archivo, Gondola gondola){

    int pos_gondola = 0;
    Producto producto_a_ingresar;

    while (!archivo.eof()){
    
        string codigo;
        string nombre;
        string precio;
        string oferta;

        archivo >> codigo >> nombre >> precio >> oferta;

        producto_a_ingresar.asignar_nombre(nombre);
        producto_a_ingresar.asignar_codigo(atoi(codigo.c_str()));
        producto_a_ingresar.asignar_precio(atoi(precio.c_str()));
        producto_a_ingresar.asignar_oferta(atoi(oferta.c_str()));

        gondola.productos[pos_gondola] = producto_a_ingresar;
        pos_gondola ++;
    }
}

Producto tipo_busqueda(Gondola gondola){
    char busqueda;
    Producto producto_a_obtener;
    int nuevo_precio;

    cout<< "ingrese n si desea buscar el producto por su nombre o c si lo desea hacer por codigo de barras"<<endl;
    cin>>busqueda;

    while(busqueda != 'n' && busqueda != 'c'){

        cout<< "letra ingresada invalida"<<endl;
        cout<< "ingrese n si desea buscar el producto por su nombre o c si lo desea hacer por codigo de barras"<<endl;
        cin>>busqueda;
    }

    if(busqueda == 'n'){

        string producto_a_buscar;

        cout<<"ingrese el nombre del producto cuyo precio desea modificar"<<endl;
        cin>>producto_a_buscar;
        producto_a_obtener = buscar_nombre(producto_a_buscar.obtener_nombre());

    }else{

        int codigo_a_buscar;

        cout<<"ingrese el codigo del producto cuyo precio desea modificar"<<endl;
        cin>>codigo_a_buscar;
        producto_a_obtener = buscar_codigo(producto_a_buscar.obtener_codigo());

    }

    return producto_a_obtener;

}

void modificar_precio(Producto producto_a_modificar){

    int nuevo_precio;
    
    cout<<"ingrese el nuevo precio del producto"<<endl;
    cin>>nuevo_precio;

    while(nuevo_precio<=0){
        cout<<"el precio ingresado es erroneo"<<endl;

        cout<<"ingrese el nuevo precio del producto"<<endl;
        cin>>nuevo_precio;
    }
    producto_a_modificar.asignar_precio(nuevo_precio);
    cout<< "el nuevo precio del producto es "<< producto_a_modificar.obtener_precio()<<" $"<<endl;

}

int cantidad_en_oferta(Gondola gondola){

    int cant_prod_oferta = 0;

    for(int i = 0; i<gondola.obtener_cant_productos();i++){
        if(gondola.productos[i].obtener_oferta()) cant_prod_oferta++;
    }

    cout<<"la cantidad de productos en oferta es "<<cant_prod_oferta<<endl;

    return cant_prod_oferta;

}



        







