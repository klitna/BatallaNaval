#include "Vaixell.h"
#include "joc.h"
#define N_VAIXELLS 10 
class Jugador
{
public:
	Jugador() ;
	~Jugador();
	void afegeixVaixell(int fila, int columna, int direccio, int nCaselles, int i);

	int getNVaixellsVius() const { return m_nVaixellsVius; };
	int consultaAtacEnemic(int fila, int& direccio, int& caselles, int &fil, int &col, int columna);

	void generaPosicioAtac(int& fila, int& columna);
	Vaixell m_llistaVaixells[N_VAIXELLS];

private:

	int m_nVaixellsVius;
};