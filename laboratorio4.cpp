#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void llenarMatriz(int***);
void mostrarSubmarinos(int***);
void declararMatriz(int***);
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
