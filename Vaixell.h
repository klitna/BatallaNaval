#include "joc.h"
class Vaixell
{
public:
	Vaixell();
	~Vaixell() {};
	void setFila(int fila) { m_fila = fila; };
	void setColumna(int col) { m_columna = col; };
	void setDireccio(int direccio) { m_direccio = direccio; };
	void setCaselles(int nCaselles) { m_nCaselles = nCaselles; m_nCasellesVives = nCaselles; for (int i = 0; i < m_nCaselles; i++)m_estat[i] = VAIXELL; };

	int getFila() const { return m_fila; };
	int getColumna()const { return m_columna; };
	int getDireccio()const { return m_direccio; };
	int getCaselles()const { return m_nCaselles; };

	int registraAtac(int fila, int columna, bool& nou);
	
	Vaixell operator=(const Vaixell& v);
private:
	static const int MAX_CASELLES = 4;
	int m_fila;
	int m_columna;
	int m_direccio;
	int m_estat[MAX_CASELLES];
	int m_nCaselles;
	int m_nCasellesVives;
};
