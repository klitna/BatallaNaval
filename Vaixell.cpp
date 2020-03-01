#include "Vaixell.h"



Vaixell::Vaixell()
{
	m_nCasellesVives = m_nCaselles;
	for (int i = 0; i < m_nCaselles; i++)
		m_estat[i] = VAIXELL;

}

Vaixell Vaixell:: operator=(const Vaixell& v)
{
	Vaixell aux;
	aux.setColumna(v.getColumna());
	aux.setDireccio(v.getDireccio());
	aux.setFila(v.getFila());
	aux.setCaselles(v.getCaselles());

	return aux;
}

int Vaixell::registraAtac(int fila, int columna, bool& nou)
{
	int i=0;
	int aux=0;
	bool trobat = false;
	int estat = AIGUA;
	nou = true;
	for (int i = 0; i < m_nCaselles && nou; i++)
		if (m_estat[i] == ENFONSAT)
			nou = false;

	if(m_direccio == 0 && m_fila == fila && columna >= m_columna && columna < m_columna + m_nCaselles) {
		if (m_estat[columna - m_columna] == VAIXELL) {
			m_nCasellesVives--;
	    }
			m_estat[columna - m_columna] = TOCAT;
			estat = TOCAT;
			
			if (m_nCasellesVives < 1)
				for (i = 0; i < m_nCaselles; i++) {
					m_estat[i] = ENFONSAT;
					estat = ENFONSAT;
				}
			}
	 else
		if (m_direccio == 1 && m_columna == columna && fila >= m_fila && fila < m_fila + m_nCaselles)
		{
		if (m_estat[fila - m_fila] == VAIXELL) {
			m_nCasellesVives--;

			}
				m_estat[fila - m_fila] = TOCAT;
			   estat = TOCAT;
				
                   if (m_nCasellesVives < 1)
						for (i = 0; i < m_nCaselles; i++) {
							m_estat[i] = ENFONSAT;
							estat = ENFONSAT;
						}
			}
	if (nou)
		cout << "NOU" << endl;
	else
		cout << "NO NOU" << endl;

	return estat;
}
