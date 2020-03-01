#include "joc.h"

class Pantalla
{
public:
	Pantalla();
	~Pantalla();
	void visualitza();
	void inicialitza();
	void setPosicioPropi(int fila, int columna, int estat);
	void setPosicioContrari(int fila, int columna, int estat);
	int getPosicioPropi(int fila, int columna) { return m_taulerPropi[fila][columna]; };
	int getPosicioContrari(int fila, int columna) { return m_taulerContrari[fila][columna]; };

	void getPosicio(int x, int y, int& fila, int&columna, int& tauler);
private:
	int m_taulerPropi[N_FILES][N_COLUMNES];
	int m_taulerContrari[N_FILES][N_COLUMNES];

	Sprite m_tauler;
	Sprite m_taulerBlau;
	Sprite m_vaixell;
	Sprite m_vaixellBlau;
	Sprite m_aigua;
	Sprite m_aiguaBlava;
	Sprite m_tocat;
	Sprite m_tocatBlau;
	Sprite m_enfonsat;
	Sprite m_enfonsatBlau;

};