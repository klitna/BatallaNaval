#include <string>
#include "Pantalla.h"
#include "Jugador.h"
#include <fstream>
using namespace std;

class Partida
{
public:
	Partida();
	~Partida();
	void inicialitza(const string& fitxer1, const string& fitxer2);
	void visualitza();
	bool fesMoviment(int x, int y);
	bool finalPartida(int& guanyador);
	int canviTorn();
private:
	Pantalla m_tauler;
	Jugador m_jugador1;
	Jugador m_jugador2;
	int m_torn;
};