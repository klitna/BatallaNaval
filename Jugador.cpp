#include "Jugador.h"
#include<stdlib.h>
#include<time.h>



Jugador::Jugador()
{
	m_nVaixellsVius = 10;
}


Jugador::~Jugador()
{
	

}
void Jugador:: afegeixVaixell(int fila, int columna, int direccio, int nCaselles, int i)
{
	
	m_llistaVaixells[i].setFila(fila);
	m_llistaVaixells[i].setColumna(columna);
	m_llistaVaixells[i].setDireccio(direccio);
	m_llistaVaixells[i].setCaselles(nCaselles);

}

void Jugador:: generaPosicioAtac(int& fila, int& columna)
{
		srand(time(NULL));
		fila = rand() % 10;
		columna = rand() % 10;
}

int Jugador::consultaAtacEnemic(int fila, int& direccio, int& caselles, int &fil, int &col,  int columna)
{
	int estat = VAIXELL;
	bool trobat = false;
	int i = 0;
	bool nou;
	cout << endl;
	
	for (i = 0; i < N_VAIXELLS && !trobat; i++) {
		estat = m_llistaVaixells[i].registraAtac(fila, columna, nou);
		if (estat == TOCAT || estat == ENFONSAT) {
			trobat = true;
			direccio = m_llistaVaixells[i].getDireccio();
			caselles = m_llistaVaixells[i].getCaselles();
			col = m_llistaVaixells[i].getColumna();
			fil = m_llistaVaixells[i].getFila();
		}
	}


	if (estat==ENFONSAT&&nou)
	{
		m_nVaixellsVius--;
	}

	cout << "Vaixells vius " << m_nVaixellsVius << endl << endl;

		return estat;
}

