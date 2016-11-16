// IN OGNI FILE DOVE SI USA IL TIPO MAP, TOCCA INCLUDERE NODE.HPP
#include <cmath>
#include "Map.hpp"
#include <sstream>  // Required for stringstreams
#include <string> 

// Funzione per la conversione
std::string IntToString (int num)
{
  std::ostringstream oss;

  // Funziona come un cout
  oss << num;

  // ritrna la stringa
  return oss.str();
}

//Costruttore
Map::Map(int w, int h) {width = w; height = h;}

// Metodo per ritornare il pressvalue del nodo xy
int Map::getPresAt(int x, int y)
{
  // -99999 è il valore di ritorno in caso di coordinate sbagliate
  // Calcolo il numero di spostamenti per arrivare alla cella (x,y)
  int Xmoves = std::abs(mostLeft) + (x);
  int Ymoves = mostUp - (y);

  bool exit = false;  // Serve per uscire dal metodo se ci sono problemi

  // Controllo se vado o meno out of bounds, in tale caso stampa errore
  if ((Ymoves >= height) || (Ymoves < 0))
  {
    //std::cout << "Map get y value is out of bounds (" << y << ")\n";
    exit = true;
  }

  if ((Xmoves >= width) || (Xmoves < 0))
  {
    //std::cout << "Map get x value is out of bounds (" << x << ")\n";
    exit = true;
  }

  // Se i valori x,y sono legali sposta i puntatori lungo gli assi e cambia il val
  if (exit == false)
  {
    listaY* itery = origin;             // iteratore per l' asse y

    for (int i = 0; i < Ymoves; i++)
      itery = itery->down;

    listaX* iterx = itery->h;           // iteratore per l' asse x

    for (int k = 0; k < Xmoves; k++)
      iterx = iterx->next;

    return(iterx->pres);                 // Ritorno il valore
  }
  else
  // se ho coordinate illegali ritorna il valore di errore
    return(-99999);
}

// Metodo per inizializzare la matrice dinamica usata per la parte grafica della mappa
void Map::init(int playerNum)
{
  // inizializza la lista delle ordinate per la matrice
  origin = new listaY;
  origin->down = NULL;

  // inizializza la lista delle ascisse
  origin->h = new listaX;
  origin->h->next = NULL;
  origin->h->val = playerNum;

  // inizializza le coordinate del nodo più in alto a sx
  mostUp = 0;
  mostLeft = 0;
}

// Metodo per la cancellazione di una mappa
void Map::delete_map(bool garbage)
{
   if (garbage)
   {
      // Creo due iteratori per la mappa
      listaY *itery = NULL, *itery_prec = NULL;
      listaX *iterx = NULL, *iterx_prec = NULL;

      // Sposto itery fino all' ultimo nodo listaY della mappa e itery_prec al
      // penultimo
      for (int i = 0; i < height; i++)
      {
         //print_raw();
         itery = origin;
         itery_prec = itery;

         while (itery->down != NULL)
         {
            itery_prec = itery;
            itery = itery->down;
         }

         // Sposto iterx fino all' ultimo nodo listaX della mappa e iterx_prec
         // al penultimo
         for (int k = 0; k < width; k++)
         {
            //print_raw();
            iterx = itery->h;
            iterx_prec = iterx;

            while (iterx->next != NULL)
            {
               iterx_prec = iterx;
               iterx = iterx->next;
            }

            // Controllo se rimane un solo nodo nella riga piu in basso
            if (iterx != iterx_prec)
            {
               // Cancello il nodo più in basso a dx della mappa e rinizio il ciclo
               delete iterx;
               iterx_prec->next = NULL;
            }
            else
            {
               // Se rimane un solo nodo colonna non reimposto a NULL itery_prec
               if (itery_prec != itery)
                  itery_prec->down = NULL;
               
               // Se rimane un nodo riga cancello pure il puntatore colonna
               delete itery->h;           // Cancello ultimo nodo riga
               delete itery;              // Cancello il nodo colonna piu in basso
            }
         }       
      }
   }
      
   // Reinizializza il tutto
   origin = new listaY;
   origin->down = NULL;

   origin->h = new listaX;
   origin->h->next = NULL;
   origin->h->val = 0;

   width = 1;
   height = 1;

   mostUp = 0;
   mostLeft = 0;
}


// Funzione sia di debug, sia usata per la ricerca nodi, stampa la matrice dei val
void Map::draw_search()
{
  // Crea due puntatori che iterano per la matrice
  listaY* ordi = origin;
  listaX* asci;

  while(ordi != NULL)
  {
    asci = ordi->h;

    while(asci != NULL)
    {
      // in base al valore nella ascissa disegna cose diverse
      std::cout << asci->val;

      // scorre alla ascissa successiva
      asci = asci->next;
    }

    // Se il ciclo arriva qui, significa che ha finito una riga
    std::cout << "\n";
    ordi = ordi->down;    // passo alla riga successiva
  }

  //////////////////////////////////////////////
  //DEBUG STUFF
  std::cout << "Top left coordinate";
  std::cout << "(" << mostLeft << ", " << mostUp << ")\n";
  std::cout << "width = " << width << "\nheight = " << height << std::endl;
}

// Funzione per la stampa grafica della mappa, itera le liste di ascisse e
// ordinate per stampare a schermo
//
// Precond: passare il numero di giocatori n per far contare quanti spazi
//          servono fra i nodi
void Map::draw(int n)
{
   // Crea due puntatori che iterano per la matrice
   listaY* ordi = origin;
   listaX* asci;
   
   // Contatore di quanti spazi stampare dentro i nodi in base al num di giocatori
   int spaces = 1;

   // parentesi quadrate usate per stampare nodi dove non avviene il turno
   char parentesiSx = '[';
   char parentesiDx = ']';
   
   // Conto il numero di spazi
   while (n/=10)
		spaces++;

   // Stampa bordo superiore alla mappa
   std::cout << "╔";
   
   for (int j=0; j<(spaces+2)*width; j++)
      std::cout << "═";

   std::cout << "╗\n";

   // Iterazione sulle liste
   while(ordi != NULL)
   {
      asci = ordi->h;

      std::cout << "║";

      while(asci != NULL)
      {
        
		   // Stampa nodo vuoto aka celle non visitate
		   if (asci->val == 0)
		   {
		      for (int j=0; j<spaces+2;j++)
		         std::cout << " ";
		   }
         // Stampa cella vuota ma visitata []
         else if (asci->val == 1)
         {
            bool exitt = false;
            std::cout << parentesiSx;
            
            for (int j=0; j<spaces; j++)
		         std::cout << " ";
            
            std::cout << parentesiDx;
         }
         else
         // Stampa celle dove ci sono giocatori
         {
            // Se siamo nella cella dove avviene il turno cambia parentesi
			   if (asci->turn)
			   {
				   parentesiSx = '{';
				   parentesiDx = '}';
				
			   }

            // Stampa cella con piu di un giocatore [X]
            if (asci->pres > 1)
            {
               std::cout << parentesiSx;
              
               for(int j=0; j<spaces; j++)
                  std::cout << "X";
				
				   std::cout << parentesiDx;
				}
			   // Stampa cella con un giocatore aka stampa il numero giocatore [int] o {int}
			   else if (asci->pres == 1)
			   {				
				   int tmpVal = asci->val-1, lenght = 1;	

				   // NB al numero giocatore nel nodo e` implicitamente contato +1 per via del nodo visitato
				   std::cout << parentesiSx << asci->val - 1;
						
					// Conto cifre numero giocatore
               while (tmpVal /= 10)
		            lenght++;
					
					// stampo tanti spazi quanto e` la differenza cifre e spazi
					for (int j=0;j<spaces-lenght;j++)
						std::cout<<" ";

		    	     std::cout <<parentesiDx;
		    	}		
		    	 
		    	// Reimposto le parentesi normali per altre celle
				parentesiSx = '[';
				parentesiDx = ']';
		   }
	
		   // Passo alla ascissa successiva
		   asci = asci->next;
		}

		// Se il ciclo arriva qui, significa che ha finito una riga
		std::cout << "║\n";
		ordi = ordi->down;    // passo alla riga successiva
  }
   
   // Stampa bordo inferiore mappa
	std::cout << "╚";
  	
	for (int j=0; j<(spaces+2)*width; j++)
		std::cout << "═";
  	
	std::cout << "╝\n";

  //////////////////////////////////////////////
  //DEBUG STUFF
 /* std::cout << "Top left coordinate";
  std::cout << "(" << mostLeft << ", " << mostUp << ")\n";
  std::cout << "width = " << width << "\nheight = " << height << std::endl;  */
}
       
// Fa un aggiunta in testa (onTop true) o in coda (onTop false) alle liste di ascisse
void Map::addColumn(bool onTop)
{
  // aumento la larghezza della mappa
  width++;

  // creo un iteratore per la listaY
  listaY *itery = origin;

  if (onTop)
  {
    // Aggiorna il valore mostLeft
    mostLeft--;

    // Fa un head insert per ogni nodo listaY
    while (itery != NULL)
    {
      listaX *old_head = itery->h;    // salvo la vecchia testa
      itery->h = new listaX;          // creo un nuovo nodo
      itery->h->val = 0;              // gli metto valore 0
	   itery->h->pres = 0;             // imposto 0 giocatori nel nodo
      itery->h->next = old_head;      // lo collego al resto della lista

      itery = itery->down;            // itero in avanti
    }
  }
  else  // If (onTop == false)
  {
    listaX *iterx;

    while (itery != NULL)
    {
      iterx = itery->h;

      // faccio scorrere iterx alla fine della listaX
      if (iterx->next != NULL)
        while (iterx->next != NULL)
          iterx = iterx->next;

      iterx->next = new listaX;
      iterx->next->val = 0;
      iterx->next->pres = 0;
      iterx->next->next = NULL;

      itery = itery->down;
    }
  }
}


// Fa una aggiunta in testa (onTop true) oppure in coda (onTop false) alle liste di ordinate
void Map::addLine(bool onTop)
{
   // aumento la altezza della mappa
   height++;

   // Crea una nuova riga
   listaY* newLine = new listaY;
   newLine->down = NULL;
   newLine->h = new listaX;
   newLine->h->next = NULL;
   newLine->h->val = 0;
   newLine->h->pres = 0;

   // Popolo la riga appena creata
   // i conta da 1 perchè un nodo lo ho gia' creato sopra
   for (int i = 1; i < width; i++)
   {
      // salva il vecchio nodo
      listaX* tmpx = newLine->h;

      // crea il nuovo nodo in testa
      newLine->h = new listaX;
      newLine->h->val = 0;
      newLine->h->pres = 0;
      newLine->h->next = tmpx;
   }

   // mette la riga creata in testa o in coda
   if (onTop)
   {
      // Aggiorna il valore mostUp
      mostUp++;

      // Se in testa
      listaY* tmpy = origin;

      origin = newLine;
      origin->down = tmpy;
   }
   else
   {
      // Se in coda
      listaY* iter = origin;

      while(iter->down != NULL) // scorro fino alla ultima riga
         iter = iter->down;

      iter->down = newLine;
   }
}

// Ritorna il val della posizione xy della mappa grafica, -99999 altrimenti
int Map::getValueAt(int x, int y)
{
  // -99999 è il valore di ritorno in caso di coordinate sbagliate
  // Calcolo il numero di spostamenti per arrivare alla cella (x,y)
  int Xmoves = std::abs(mostLeft) + (x);
  int Ymoves = mostUp - (y);

  bool exit = false;  // Serve per uscire dal metodo se ci sono problemi

  // Controllo se vado o meno out of bounds, in tale caso stampa errore
  if ((Ymoves >= height) || (Ymoves < 0))
  {
    //std::cout << "Map get y value is out of bounds (" << y << ")\n";
    exit = true;
  }

  if ((Xmoves >= width) || (Xmoves < 0))
  {
    //std::cout << "Map get x value is out of bounds (" << x << ")\n";
    exit = true;
  }

  // Se i valori x,y sono legali sposta i puntatori lungo gli assi e cambia il val
  if (exit == false)
  {
    listaY* itery = origin;             // iteratore per l' asse y

    for (int i = 0; i < Ymoves; i++)
      itery = itery->down;

    listaX* iterx = itery->h;           // iteratore per l' asse x

    for (int k = 0; k < Xmoves; k++)
      iterx = iterx->next;

    return(iterx->val);                 // Ritorno il valore
  }
  else
  // se ho coordinate illegali ritorna il valore di errore
    return(-99999);
}

// Cambia i valori val e pressvalue del nodo xy
void Map::changeValue(int x, int y, int v, int p)
{
  // Calcolo il numero di spostamenti per arrivare alla cella (x,y)
  int Xmoves = std::abs(mostLeft) + (x);
  int Ymoves = mostUp - (y);

  bool exit = false;  // Serve per uscire dal metodo se ci sono problemi

  // Controllo se vado o meno out of bounds, in tale caso stampa errore
  if ((Ymoves >= height) || (Ymoves < 0))
  {
    //std::cout << "Map change y value out of bounds (" << y << ")\n";
    exit = true;
  }

  if ((Xmoves >= width) || (Xmoves < 0))
  {
    //std::cout << "Map change x value out of bounds (" << x << ")\n";
    exit = true;
  }

  // Se i valori x,y sono legali sposta i puntatori lungo gli assi e cambia il val
  if (exit == false)
  {
    listaY* itery = origin;             // iteratore per l' asse y

    for (int i = 0; i < Ymoves; i++)
      itery = itery->down;

    listaX* iterx = itery->h;           // iteratore per l' asse x

    for (int k = 0; k < Xmoves; k++)
      iterx = iterx->next;

    iterx->val = v;                     // Cambio il valore
    iterx->pres = iterx->pres + p;
  }
  else
  // se ho coordinate illegali esci
    return;
}

// Cambia il valore turn per stabilire dove avviene il turno sulla mappa
void Map::set_Turn(int x, int y, bool t)
{
  // Calcolo il numero di spostamenti per arrivare alla cella (x,y)
  int Xmoves = std::abs(mostLeft) + (x);
  int Ymoves = mostUp - (y);

  bool exit = false;  // Serve per uscire dal metodo se ci sono problemi

  // Controllo se vado o meno out of bounds, in tale caso stampa errore
  if ((Ymoves >= height) || (Ymoves < 0))
  {
    //std::cout << "Map change y value out of bounds (" << y << ")\n";
    exit = true;
  }

  if ((Xmoves >= width) || (Xmoves < 0))
  {
    //std::cout << "Map change x value out of bounds (" << x << ")\n";
    exit = true;
  }

  // Se i valori x,y sono legali sposta i puntatori lungo gli assi e cambia il val
  if (exit == false)
  {
    listaY* itery = origin;             // iteratore per l' asse y

    for (int i = 0; i < Ymoves; i++)
      itery = itery->down;

    listaX* iterx = itery->h;           // iteratore per l' asse x

    for (int k = 0; k < Xmoves; k++)
      iterx = iterx->next;

    iterx->turn = t;
  }
  else
  // se ho coordinate illegali esci
    return;
}

