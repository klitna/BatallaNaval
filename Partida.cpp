#include "Partida.h"
#include<iostream>
using namespace std;


Partida::Partida()
{
    m_torn = 0; 
 for (int i = 0; i < N_FILES; i++)
	 for (int j = 0; j < N_COLUMNES; j++)
		 m_tauler.setPosicioPropi(i, j, 0);
 for (int i = 0; i < N_FILES; i++)
	 for (int j = 0; j < N_COLUMNES; j++)
		 m_tauler.setPosicioContrari(i, j, 0);
}

Partida::~Partida()
{

}

int Partida::canviTorn()
{ 
	if (m_torn == 0)
		m_torn = 1; 
	else
		m_torn = 0;
	
	return m_torn;
}

void Partida::inicialitza(const string& fitxer2, const string& fitxer1)
{
	m_tauler.inicialitza();

	ifstream fitxer_1;
	int estat=0;
	fitxer_1.open(fitxer1);
	int fila, columna, direccio, ncaselles;
	if (fitxer_1.is_open())
	{
		
			for (int x = 0; x < 10&&!fitxer_1.eof(); x++) {
				fitxer_1 >> fila >> columna >>  ncaselles>>direccio ;
				if(ncaselles>0){
				m_jugador1.afegeixVaixell(fila-1, columna-1, direccio, ncaselles, x);

				if (direccio == 0) {

					for (int i = columna; i < columna + ncaselles; i++) {
						m_tauler.setPosicioContrari(fila - 1, i - 1, VAIXELL);
					}
				}
				if (direccio == 1) {

					for (int i = fila; i < fila + ncaselles; i++)
						m_tauler.setPosicioContrari(i - 1, columna - 1, VAIXELL);
				}
			}
			}
		
	}
	fitxer_1.close();
	cout << "Vaixells vius " << m_jugador1.getNVaixellsVius() << endl << endl;
	
	ifstream fitxer_2;
	fitxer_2.open(fitxer2);
	if (fitxer_2.is_open())
	{

		for (int x = 0; x < 10 && !fitxer_2.eof(); x++) {
			fitxer_2 >> fila >> columna >> ncaselles >> direccio;
			if (ncaselles>0){
				m_jugador2.afegeixVaixell(fila - 1, columna - 1, direccio, ncaselles, x);

			  if (ncaselles > 0) {

				if (direccio == 0) {

					for (int i = columna; i < columna + ncaselles; i++) {
						m_tauler.setPosicioPropi(fila - 1, i - 1, VAIXELL);
					}
				}
				if (direccio == 1) {

					for (int i = fila; i < fila + ncaselles; i++)
						m_tauler.setPosicioPropi(i - 1, columna - 1, VAIXELL);
				}
			  }
			}
		}

	}
	fitxer_2.close();

	ofstream fitxer_11;
	fitxer_11.open("data/tauler_huma.txt");
	if (fitxer_11.is_open())
	{

		for (int i = 0; i < N_FILES; i++) {
			for (int j = 0; j<N_COLUMNES; j++)
			{
				estat = m_tauler.getPosicioPropi(i, j);
				fitxer_11 << estat << " ";
			}
			fitxer_11 << endl;
		}
		
	}
		fitxer_11.close();
		ofstream fitxer_22;
		fitxer_22.open("data/tauler_ordinador.txt");
		if (fitxer_22.is_open())
		{

			for (int i = 0; i < N_FILES; i++) {
				for (int j=0; j<N_COLUMNES; j++)
				{
					estat = m_tauler.getPosicioContrari(i, j);
					fitxer_22 << estat << " ";
				}
				fitxer_22 << endl;
			}

		}
		fitxer_22.close();

	

}

void Partida::visualitza()
{
	m_tauler.visualitza();

}

bool Partida::fesMoviment(int y, int x )
{
	int fila=0, columna=0;
	int tauler;
	bool repite = false;
	int aux=0;	

	int dir=0, fil=0, col=0, cas=0;

	m_tauler.getPosicio(y, x,  columna,fila, tauler);
	
		//----FER ATAC JUGADOR HUMA
	if (tauler == 1) {
		if (m_torn == 0)
		{
			if (m_tauler.getPosicioContrari(fila, columna) == AIGUA)
				repite = true;
			int atac1 = m_jugador1.consultaAtacEnemic(fila, dir, cas, fil, col, columna);
			m_tauler.setPosicioContrari(fila, columna, atac1);


			if (atac1 == ENFONSAT)
			{
				if (dir == 0)
					for (int j = col; j < col + cas; j++)
						m_tauler.setPosicioContrari(fil, j, atac1);
				else
					for (int i = fil; i < fil + cas; i++)
						m_tauler.setPosicioContrari(i, col, atac1);
			}


			if (atac1 == TOCAT || atac1 == ENFONSAT && !finalPartida(aux))
				repite = true;

		}

		//----GENERAR ATAC COMPUTADOR


		if (m_torn == 1)
		{
			if (m_tauler.getPosicioPropi(fila, columna) == AIGUA)
				repite = true;

			repite = false;
			m_jugador2.generaPosicioAtac(fila, columna);
			int atac2 = m_jugador2.consultaAtacEnemic(fila, dir, cas, fil, col, columna);

			if (atac2 == ENFONSAT)
			{
				if (dir == 0)
					for (int j = col; j < col + cas; j++)
						m_tauler.setPosicioPropi(fil, j, atac2);
				else
					for (int i = fil; i < fil + cas; i++)
						m_tauler.setPosicioPropi(i, col, atac2);
			}
			else
				m_tauler.setPosicioPropi(fila, columna, atac2);

			if (atac2 == TOCAT || atac2 == ENFONSAT && !finalPartida(aux))
				repite = true;
		}
	}
	return repite;
}


bool Partida::finalPartida(int& guanyador)
{
	guanyador = 1;
	bool fi = false;
	if ((m_jugador1.getNVaixellsVius() < 1) || (m_jugador2.getNVaixellsVius() < 1)) {
		fi = true;
		if (m_jugador1.getNVaixellsVius() < m_jugador2.getNVaixellsVius())
			guanyador = 0;
	}
	return fi;

}