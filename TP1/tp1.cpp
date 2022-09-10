#include <iostream>
#include <fstream>

// Funcion para calcular el cliente con la mayor cantidad de productos que pasaron los 13000kg // 

int maximo(int vec[], int dim)
{
	int max {};
	for (int i = 0; i < dim; i++)
		if (vec[i] > vec[max])
			max = i;
	return max;
}

int main()
{



    // Declaro arrays y dimensiones //

    const int cantclientes {8};
    const int cantproductos {5};
    std::string Clientes[cantclientes]{};
    std::string Productos[cantproductos]{};

    // Declaro y abro el archivo que contiene los nombres //

    std::ifstream nombres;
    nombres.open ("nombres.txt");
    if (!nombres)
    {
        std::cout << "El archivo no puede abrirse." << std::endl;
        return 1;
    }
    for (int i = 0; i < cantclientes && nombres >> Clientes[i]; ++i);
	for (int i = 0; i < cantproductos && nombres >> Productos[i]; ++i);
    
    //Cierro el archivo con nombres.

    nombres.close();

    //Realice esto para revisar que los datos esten cargados correctamente en los arrays. //

    /* for (int i = 0; i < cantclientes; i++)
    {
        std::cout << Clientes[i] << std::endl;
    }

    for (int i = 0; i < cantproductos; i++)
    {
        std::cout << Productos[i] << std::endl;
    } */
    

    // Declaro arrays y dimensiones //

    int NroCliente;
    int NroProducto;
    float Km;
    float Kg;
    long double Kgtotal[cantclientes][cantproductos]{};
    long double Kilometrototal[cantclientes][cantproductos]{};
    int prodxcliente[cantclientes]{};
    int cantproducto [cantproductos]{}; 
    int kmproducto[cantproductos]{};
    
    // Abro el archivo de datos 

    std::ifstream documentacion;
    documentacion.open("Datos.txt");
    if (!documentacion)
    {
        std::cout << "El archivo no pudo abrirse. " << std::endl;
        return 1;
    }

    // Leo el archivo con los datos 

    while (documentacion >> NroCliente >> NroProducto >> Kg >> Km)
    {
        Kgtotal[NroCliente][NroProducto] += Kg;
        Kilometrototal[NroCliente][NroProducto] += Km;  
        cantproducto[NroProducto]++;  
        kmproducto[NroProducto] += Km;
    }
     
    documentacion.close();

    /* Emita un listado donde para cada cliente liste los tipos de producto tal que la cantidad total de 
    kilos transportados es mayor a 13000. */

    std::cout << std::endl << "---------------------------PUNTO 1 ------------------------------" << std::endl << std::endl;

    for (int i = 0; i < cantclientes; i++)
    {
        for (int j = 0; j < cantproductos ; j++)
        {
            if (Kgtotal[i][j] > 13000)
            {
                std::cout << Clientes[i] << " Vendio mas de 13000kg de: " << Productos[j] << std::endl;
                prodxcliente[i]++;
            }       
        } 
    }
    std::cout << std::endl << "--------------------------PUNTO 2----------------------------"<< std::endl << std::endl;

    /* . Para el cliente con mayor cantidad tipos de productos que hayan superado 13000 kg en el punto
    anterior, emita un listado con nombre de tipo de producto y total de kilómetros recorridos,
    ordenado por total de kilómetros en forma ascendente.
    Nota: No alterar el vector de nombres */

    int productomayor = maximo(prodxcliente, cantclientes);
    std::cout << "El cliente con mas ventas por arriba de los 13000kg es: " << Clientes[productomayor] << "." << std::endl;
    
    double KmTotal[cantproductos]{};

    for (int i = 0; i < cantproductos; i++)
    {
        KmTotal[i] = Kilometrototal[productomayor][i];
       /* std::cout << Productos[i] << "\t" << KmTotal[i] << std::endl; Esta parte de codigo es puramente de verificacion para corroborar que se hayanc cargado bien los datos en la array  */
    } 

    //Definimos array con nombres de producto.
    std::string ProductosOrd[cantproductos]{};
    for (int i = 0; i < cantproductos; i++)
    {
        ProductosOrd[i] = Productos[i];
    }
     //Ordenamos la array de valores en km y la de nombres de producto para que queden en conjunto.
    double aux{};
    std::string aux2{};
    for (int i = 0; i < cantproductos; i++)
    {
        for (int j =  i + 1; j < cantproductos; j++)
        {
            if (KmTotal[i] > KmTotal[j])
            {
                aux = KmTotal[i];
                KmTotal[i] = KmTotal [j];
                KmTotal[j] = aux;

                aux2 = ProductosOrd[i];
                ProductosOrd[i] = ProductosOrd [j];
                ProductosOrd[j] = aux2;
            }
            
        }
        
    }

    std::cout << "Los productos enumerados que vende bi son: " << std::endl;

    // Muestro valores arreglados de las arrays. 

    for (int i = 0; i < cantproductos; i++)
    { 
        std::cout << ProductosOrd[i] << "\t" << KmTotal[i] << std::endl; 
    }
    
    
    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl << std::endl;

    /* Del listado anterior, tome el tipo de producto con mayor cantidad de kilómetros recorridos e
    informe cuantas entregas se hicieron para ese tipo de producto (sin importar para que cliente).
    */

    


return 0;

}
