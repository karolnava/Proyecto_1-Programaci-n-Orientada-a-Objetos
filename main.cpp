#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{

    ifstream archivoplantilla;
    ifstream archivodatos;

    std::string plantilla;
    std::string datos;
    std::string mensaje;
    std::string strPlantilla;
    std::string strdatos;
    std::string strmensaje; //
    std::string strdato;
    std::string strdatoNuevo;

    int posI;
    int posF;
    int posstrdato;
    int linetam;
    int datotam;

    int startIndicador = 1;

    cout << "Especifica el nombre del archivo que contiene la plantilla, omitiendo el '.txt')" << endl;
    getline(cin, plantilla);
    plantilla = plantilla + ".txt";

    archivoplantilla.open(plantilla);

    if(archivoplantilla.good() == 0)
    {
        cout << "El archivo que contiene la plantilla con el nombre: " << plantilla <<" no existe, verifica que se encuentre en la misma carpeta" << endl;
        return 0;
    }

    cout << " " << endl;
    cout << "Especifica el nombre del archivo que contiene los datos, omitiendo el '.txt')" << endl;
    getline(cin, datos);
    datos = datos + ".txt";

    archivodatos.open(datos);

    if(archivodatos.good() == 0)
    {
        cout << "El archivo que contiene los datos con el nombre: " << datos <<" no existe, verifica que se encuentre en la misma carpeta" << endl;
        return 0;
    }

    cout << " " << endl;
    cout << "Especifica el nombre del archivo resultante, omitiendo el '.txt')" << endl;
    getline(cin, mensaje);
    mensaje = mensaje + ".txt";

    ofstream archivoMensaje(mensaje); //Empieza programa

    while(getline(archivoplantilla, strPlantilla)){strmensaje = strmensaje + strPlantilla + '\n';}


    while(startIndicador == 1){ //Remplazo

        linetam = strmensaje.size();
        posI = strmensaje.find("<");
        posF = strmensaje.find(">");
        if(posI != -1 && posI <= linetam && posF != -1 && posI <= linetam)
        {
            datotam = posF - posI + 1;
            strdato = strmensaje.substr(posI, datotam);
            while(getline(archivodatos, strdatos))
            {

                linetam = strdatos.size();
                posstrdato = strdatos.find(strdato);
                if(posstrdato != -1 && posstrdato <= linetam)
                {

                    strdatoNuevo = strdatos.substr(datotam + 1 );
                    strmensaje.replace(posI, datotam, strdatoNuevo);
                }
            }

            archivodatos.close();
            archivodatos.open(datos);
        } else {startIndicador = 0;}
    }

    archivoMensaje << strmensaje;

    archivoplantilla.close();
    archivodatos.close();
    archivoMensaje.close();
    return 0;
}
