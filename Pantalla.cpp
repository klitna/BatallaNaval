#include "Pantalla.h"

Pantalla::Pantalla()
{
	Sprite m_tauler("data/caselles.png");
	Sprite m_vaixell("data/vaixell.png");
	Sprite m_aigua("data/aigua.png");
	Sprite m_tocat("data/tocat.png");

}


Pantalla::~Pantalla()
{

}
void Pantalla::inicialitza()
{
	m_tauler.create("data/caselles.png");
	m_taulerBlau.create("data/caselles_blau.png");
	m_vaixell.create("data/vaixell.png");
	m_aigua.create("data/aigua.png");
	m_tocat.create("data/tocat.png");
	m_enfonsat.create("data/enfonsat.png");

	m_enfonsatBlau.create("data/enfonsat_blau.png");
	m_vaixellBlau.create("data/vaixell_blau.png");
	m_aiguaBlava.create("data/aigua_blava.png");
	m_tocatBlau.create("data/tocat_blau.png");

}

void Pantalla::visualitza()
{
	m_taulerBlau.draw(INI_PANTALLA_X, INI_PANTALLA_Y);

	
	for (int i = 0; i < N_FILES; i++)
		for (int j = 0; j < N_COLUMNES; j++){
			//	if (m_taulerContrari[i][j] == VAIXELL) {
			//	m_vaixellBlau.draw(j * MIDA_CASELLA, i*MIDA_CASELLA);
		//	}
			//else
				if (m_taulerContrari[i][j] == AIGUA)
					m_aiguaBlava.draw(j * MIDA_CASELLA, i*MIDA_CASELLA);
				else
					if (m_taulerContrari[i][j] == TOCAT)
						m_tocatBlau.draw((j *MIDA_CASELLA), (MIDA_CASELLA * i));
					else
						if (m_taulerContrari[i][j] == ENFONSAT) 
							m_enfonsatBlau.draw((j *MIDA_CASELLA), (MIDA_CASELLA * i));


						}

		m_tauler.draw(INI_PANTALLA_X+(MIDA_CASELLA*10), INI_PANTALLA_Y);


		for (int i = 0; i < N_FILES; i++)
			for (int j = 0; j < N_COLUMNES; j++)
			{
				
				if (m_taulerPropi[i][j] == VAIXELL)
					m_vaixell.draw((MIDA_CASELLA * j)+(10 * MIDA_CASELLA), (i *MIDA_CASELLA));
				else
					if(m_taulerPropi[i][j] == AIGUA)
						m_aigua.draw((MIDA_CASELLA * j) + (10 * MIDA_CASELLA),(i *MIDA_CASELLA));
					else
						if(m_taulerPropi[i][j]==TOCAT)
							m_tocat.draw((MIDA_CASELLA * j) + (10 * MIDA_CASELLA),(i *MIDA_CASELLA));
						else
							if (m_taulerPropi[i][j] == ENFONSAT)
								m_enfonsat.draw((MIDA_CASELLA * j) + (10 * MIDA_CASELLA),(i *MIDA_CASELLA));

			}
	

	//------------------------------------------------------------------------------------
	

	
}

void Pantalla:: setPosicioPropi(int fila, int columna, int estat) 
{
	m_taulerPropi[fila][columna] = estat;
}

void Pantalla::setPosicioContrari(int fila, int columna, int estat)
{
	m_taulerContrari[fila][columna] = estat;
}

void Pantalla::getPosicio(int y, int x, int& fila, int&columna, int& tauler)
{
	tauler = 1;
	fila = x / 52;
	columna = y / 52;
	if (x >= MIDA_CASELLA * 10) {
		
		tauler = 2;
		fila = (x - (MIDA_CASELLA * 10))/52;
		columna = (y / 52);
	}
}