#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    string caja[3]={"Normal", "Amanada","Normal"};
    int experimentos, randomNum, lanzamiento;
    int cara = 0, amanada = 0, amanada2 = 0;
    string respuesta;
    do{
        cout<<"Cuantas veces desea realizar el experimento?: ";
        cin>>experimentos;
        for (int i = 0; i < experimentos; i++)
        {
            randomNum = rand() % 3;
            for (int j = 0; j < 2; j++)
            {
               lanzamiento = rand()%2;
               if(lanzamiento < 0.5 ){
                cara++;
               }

            }
            if(caja[randomNum]=="Amanada"){

                amanada++;
                cara=2;

            }
            if(cara == 2){
                amanada2++;
            }
            
            cara = 0;
        }
        cout<<"Veces que salio amanada: "<<amanada<<endl;
        cout<<"Veces que salio HH: "<<amanada2<<endl;
        cout<<"La probabilidad de que salga amanada es: "<<static_cast<double>(amanada )/(amanada2)<<endl;
        cout<<"Desa repetir?(S/N)"<<endl;
        cin>>respuesta;
        amanada=0;
        amanada2=0;
    
    }while(respuesta == "S" || respuesta == "s");

    return 0;
}