#include <iostream>

using namespace std;



void MenuAdmin();
void MenuUsuario();
void InsertarPregunta();
void ListarPreguntas();
void ConsultarPregunta();
void ModificarPregunta();
void BorrarPregunta();
int main()
{
    int TipoUsuario;
    cout<<"==================>BIENVENIDO POR FAVOR INGRESE SU TIPO DE USUARIO<========================"<<endl<<endl;

    do
    {
        cout<<"SI ES ADMIN DIGITE 1 O SI ES ALUMNO DIGITE 0"<<endl;
        cout<<"Ingrese aqui su tipo de usuario: ";cin>>TipoUsuario;
        if(TipoUsuario!=1&&TipoUsuario!=0)
        {
            cout<<endl;
            cout<<"Ingreso una opcion incorrecta"<<endl;
            cout<<"Por favor intentelo de nuevo"<<endl;
            cout<<endl;
        }

    }while(TipoUsuario!=1&&TipoUsuario!=0);

    if(TipoUsuario==1)
    {
    MenuAdmin();
    }
    else if(TipoUsuario==0)
    {
        MenuUsuario();
    }
	return 0;
}

void MenuAdmin()
{
    int opcion;

	do{
		system("cls");
		cout << "========ADMINISTRACION BANCOS DE PREGUNTAS=========" << endl << endl;
		cout << "1. Insertar pregunta" << endl;
		cout << "2. Listar preguntas" << endl;
		cout << "3. Consutar pregunta" << endl;
		cout << "4. Modificar pregunta" << endl;
		cout << "5. Borrar pregunta" << endl;
		cout << "6. Salir" << endl << endl;
		cout << "Seleccione una opcion:";
		cin >> opcion;
		switch (opcion){
		  case 1: InsertarPregunta();
		          break;
		  case 2: ListarPreguntas();
		          break;
		  case 3: ConsultarPregunta();
		          break;
		  case 4: ModificarPregunta();
		          break;
		  case 5: BorrarPregunta();
		          break;
		}
	}while (opcion!=6);
}


void MenuUsuario()
{
    cout<<"1. Presentar examen"<<endl;
    cout<<"2. Ver calificaciones"<<endl;
}
void InsertarPregunta()
{

}
void ListarPreguntas()
{

}
void ConsultarPregunta()
{

}
void ModificarPregunta()
{

}
void BorrarPregunta()
{

}
