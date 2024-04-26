#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class generadorcontrasena { 
private:
    char caracteres[93]; 
public:
    generadorcontrasena() {
        for (int i = 0; i < 93; ++i) {
            caracteres[i] = static_cast<char>(i + 33);
        }
    }

    string generarContrasena() {
        string contrasena;
        const int tamano= 15; 
       
        srand(static_cast<unsigned int>(time(NULL))); 

        
        while (contrasena.length() < tamano) {
            char caracter = caracteres[rand() % 93]; 
            
            if (contrasena.find(caracter) == string::npos) {
                contrasena += caracter; 
            }
        }

        return contrasena;
    }
};

int main() {
    generadorcontrasena generador; 
    cout << "Contrasena generada: " << generador.generarContrasena() << endl;
    return 0;
}

