
#include "Partida.h"
#include <iostream>
using namespace std;



void joc()
{
	int torn = 0;
	bool mov_ok = false;
	int x = 0, y = 0;
	int guanyador = 0;

	Screen jocLib(2 * MIDA_X, MIDA_Y);
	jocLib.init();
	jocLib.show();

	Partida p;
	p.inicialitza("data/vaixells_jugador_huma.txt", "data/vaixells_jugador_ordinador.txt");

	bool repite = true;
	do {

		jocLib.show();
		jocLib.update();
		jocLib.processEvents();

		p.visualitza();

		if (Mouse_getButLeft())
		{
			x = Mouse_getY();
			y = Mouse_getX();

			repite = p.fesMoviment(x, y);
			if (!repite)
				torn=p.canviTorn();

		}
		if(torn==1){
			repite = p.fesMoviment(x,y);
			if (!repite)
				torn = p.canviTorn();		
		}
		
	
	} while (!p.finalPartida(guanyador)&&(!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)));


	if (guanyador == 0)
		cout <<"      -------------------------HAS GANADO-------------------------" << endl;
	else
		cout <<"      -------------------------HAS PERDIDO-------------------------" << endl;
	system("PAUSE");
}
