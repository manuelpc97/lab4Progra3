#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void llenarMatriz(int***);
void mostrarSubmarinos(int***);
int*** declararMatriz();
int submarinosContrarios(int***);

int main(int argc, char*argv[]){
	srand(time(NULL));
	bool seguir = true;
	int decision = 0;
	int*** tablero1 = declararMatriz();
	int*** tablero2 = declararMatriz();
		

	while(seguir){
	llenarMatriz(tablero1);
	llenarMatriz(tablero2);



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

int*** declararMatriz(){
	int***h=new int**[12];
	
	for(int i = 0; i<12; i++){
		h[i]= new int*[12];		
	}

	for(j = 0; j<12;j++){
		for(k=0;k<12;k++){
			h[i][j] = new int[12];
		}
	}

	return h;	

}

void llenarMatriz(int*** a){
	int numeros[3];
	int contador = 0;
	while(contador<15){
		for(int j = 0; j<3;j++){
			numeros[j]= 1+rand()%(13-1);
		}
		if(a[numeros[0]][numeros[1]][numeros[2]]==0){
			a[numeros[0]][numeros[1]][numeros[2]]=1;
			contador++;
		}
	}
}

