#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void llenarMatriz(int***);
void mostrarSubmarinos(int***);
int*** declararMatriz();
int submarinosContrarios(int***);

int main(int argc, char*argv[]){
	bool seguir = true;
	int decision = 0;

	while(seguir){




		cout<<"Desea seguir jugando: "
		<<endl<<"1. Si"
		<<endl<<"2. NO"
		<<endl;
		cin>>decision;

		if(decision==1)
			seguir =true;
		else
			seguir =false;		
	}	
return 0;
}
trarsubmarinos(int*** ñ){
	for(int x=0;x<12;x++){
		for(int y=0;y<12;y++){
			for(int z=0;z<12;z++){
					if(ñ[x][y][z]==1){
						cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
						
					}
			}	
		}		
	}


}
int submarinosContrarios(int*** ñ){
int contador=0;
	for(int x=0;x<12;x++){
			for(int y=0;y<12;y++){
				for(int z=0;z<12;z++){
						if(ñ[x][y][z]==1){
							contador++;					
						}
				}	
			}		
		}


	}
	return contador;	

}
