#include "Hud.hpp"
#include "ClassPlayer.hpp"


// Costruttore
Player::Player(std::string n, int life, int att, int np)
{
   name = n;
   hp = life;
   atk = att;
   numPlay = np;
}

// Metodi semplici per il ritorno valori protetti
std::string Player::getShield()   {return shield;}
std::string Player::getName()     {return name;} 
int Player::getAtk()         {return atk;}
int Player::getHp()          {return hp;}
int Player::getNumPlay()      {return numPlay;}

// Imposta hp giocatore
void Player::set_hp(int l)
{
   hp = l;
}

// Controlla se giocatore e` vivo
bool Player:: is_alive()
{
   if (hp <= 0)
    return false;

   return true;
}

// Funzione che fa muovere il giocatore
bool Player::Player_move(char dir, Map& map, Node& curr_node)
{
   // Alias per usare nomi di variabili piu corte
   int xx = pos->get_x();
   int yy = pos->get_y();
   bool ret;                  // true se move in nuovo nodo, false su vecchio nodo

   // Movimento verso un nodo non ancora esistente
   if (pos->get_cardinal(dir)==NULL)
   {
      // Crea il nuovo nodo e aggiorna il valore nella mappa
      pos->add_node((*pos), dir, map, curr_node);
      map.changeValue(xx, yy, map.getValueAt(xx, yy) - numPlay, (-1));
      
      // Sposta il giocatore
      pos = pos->get_cardinal(dir);
      
      // Aggiorna le coordinate alias
      xx = pos->get_x();
      yy = pos->get_y();
    
      // Aggiorna i valori dello spostamento sulla mappa
      map.changeValue(xx, yy, map.getValueAt(xx, yy) + numPlay, 1);
   
      // Contenuto della nuova stanze random, tramite dado
      hud_movement(diceRoll_nr());
      
      ret = true;
   }
   // Movimento verso un nodo già esistente
   else 
   {
      // Toglie sulla mappa il valore del simbolo nella vecchia posizione
      map.changeValue(xx, yy, map.getValueAt(xx, yy) - numPlay, (-1));
      
      // Sposta la posizione del giocatore
      pos = pos->get_cardinal(dir);
      
      // Aggiorna le coordinate alias
      xx = pos->get_x();
      yy = pos->get_y();
      
      // Aggiunge il valore del simbolo nella nuova posizione sulla mappa
      map.changeValue(xx, yy, map.getValueAt(xx, yy) + numPlay, 1);
   
      // Stampo righe vuote per separare schermate
      for(int j=0; j < 40; j++)
         std::cout << "\n"; 
   
      ret = false;
   }            

   return ret;
}


// Funzione che rimuove il valore del numPlay del giocatore sulla mappa
// usata nel main, quando un giocatore muore e non deve piu apparire
void Player::remove_from_map(Map& map)
{
   int xx = pos->get_x();
   int yy = pos->get_y();
   
   map.changeValue(xx, yy, map.getValueAt(xx,yy) - numPlay, (-1));
}

// Funzione di battaglia fra due giocatori
// Precondizione: Passare l' array con tutti i giocatori, la mappa di gioco per aggiornare i valori, il numero
//                di giocatori totali, la posizione nell array del giocatore che inizia il combattimento,     
//                il nodo origine (serve per la funzione Player_move), la variabile dei     
//                giocatori attualmente vivi
//
// Postcondizione: La funzione non permette la morte di entrambi i giocatori, nel caso entrambi muoiono ne
//                 viene riportato in vita uno a caso, inoltre se nel nodo ci fossero piu giocatori 
//                 viene attaccato il giocatore con indice piu basso nell`array (cioe il primo trovato nel ciclo for)
int Player::engage_battle(Player* p[], Map& map, int np, int p1_index, Node& node, int& alive_players)
{
   int x1 = pos->get_x(), y1 = pos->get_y();    // Coordinate di dove avviene lo scontro
   
   int atk2, p2_index;
   std::string shield2;

    
   // Cerco il giocatore nelle stesse coordinate con cui combattere
   for (int i=0; i < np; i++)
      if (i != p1_index && p[i] != NULL)                             // Escludo il giocatore attaccante e i morti dal controllo
         if (p[i]->pos->get_x() == x1 and p[i]->pos->get_y() == y1)
         {
            // salvo le variabili del giocatore che viene attaccato ed esco dal ciclo
            atk2 = p[i]->getAtk();
            shield2 = p[i]->getShield();
            p2_index = i;
            break;
         }

   // prendo i nomi dei giocatori per la stampa dell HUD
   std::string name_p1=getName();
   std::string name_p2=p[p2_index]->getName();		


   // Calcolo la formula per il combattimento (atk1-scudo2 e atk2-scudo1)
   // Sottraggo all attacco di un giocatore i valori dello scudo dell altro
   if (atk2 > 3)
   {
      if (getShield() == "bronze")
         atk2 -= 1;
      else
      if (getShield() == "silver")
         atk2 -= 2;
      else
      if (getShield() == "gold")
         atk2 -= 3;
   }
   else
      atk2 = 0;

   if (atk > 3)
   {
      if (shield2 == "bronze")
         atk -= 1;
      else
      if (shield == "silver")
         atk -= 2;
      else
      if (shield == "gold")
         atk -= 3;
   }
   else
      atk = 0;


   // Tiro il dado per randomizzare lo scontro, aumentanto a caso atk e atk2
   srand(time(0));
   int roll = (rand()%10) +1;
   
   switch (roll)
   {
      case 1:
         atk += 4;
         break;

      case 2:
         atk += 3;
         break;

      case 3:
         atk += 2;
         break;

      case 4:
         atk2 += 4;
         break;

      case 5:
         atk2 += 3;
         break;

      case 6:
         atk2 += 2;
         break;
   }
   

   // Infliggo i rispettivi danni
   p[p2_index]->set_hp(p[p2_index]->getHp() - atk);

   set_hp(hp - atk2);

   // Stampo su schermo i danni inflitti
   for(int j=0; j<40; j++)
      std::cout << "\n";

   // Variabile per stampare nell hud la morte di entrambi i giocatori
   int j=-1;	

   // nel caso muoiano entrambi i giocatori ritorna 1 se il p1 resuscita, 
   // 2 se resuscita p2
   int morte=0;

   // Controlla giocatori uccisi, impedisce la morte di entrambi
   if (!p[p2_index]->is_alive() and !p[p1_index]->is_alive())
   {
      // In caso siano entrambi morti, sceglie a caso chi riportare in vita
      // (con hp = 1)
      roll = (rand()%2) +1;

      if (roll == 1)
      {
         set_hp(1);
         j=1;

         p[p2_index]->remove_from_map(map);
         p[p2_index]->pos = NULL;
         p[p2_index] = NULL;
         alive_players--;  
 
      }
      else
      {
         p[p2_index]->set_hp(1);
         j=2;
         morte=2;
        
      }
   }
   else {
   // Visto che se muore il giocatore due, (cioe` il giocatore che viene
   // attaccato) non essendo il suo turno, non viene effettuato il controllo 
   // sulla sua morte nel main (essendo il turno del giocatore 1),
   // e se non viene rimosso, rimane sulla mappa con gli hp negativi

                if (!p[p1_index]->is_alive()){ j= 0; morte=1;}  //controllo se e' morto il giocatore che attacca e stampa

                if (!p[p2_index]->is_alive())
                {
                        j=3;

                        p[p2_index]->remove_from_map(map);
                        p[p2_index]->pos = NULL;
                        p[p2_index] = NULL;
                        alive_players--;    
                }
        }

   // Stampa grafica
  hud_battle(name_p1, name_p2, atk, atk2, j);
  
  return morte;
}


// Tira il dado per una stanza nuova (_nr sta per new Room)
int Player::diceRoll_nr() 
{
   srand(time(0));
   int roll = (rand()%20) +1;
   switch(roll)
   {
      case 1: case 2: case 3: case 4: case 5:
      // Non succede nulla
      return roll;

      // spada bronzo
      case 6: case 7: case 8: case 9:
         atk += 3;
      return roll;
     
      // spada argento
      case 10: case 11: case 12:
         atk += 4;
      return roll;

      // spada oro
      case 13: case 14: 
         atk += 6;
      return roll;

      // trappola, danno incodizionato dallo scudo
      case 15: case 16: case 17:
         hp -= 4;        
      return roll;

      // combattimento con un mostro danno condizionato da scudo
      case 18: case 19: case 20:
         // scudo oro non prende danno ma si rompe e si trova uno di bronzo
         if (shield == "gold")
         {
            shield = "bronze";
            return 181;
         }
         // scudo argento non si rompe ma si prende poco danno
         else
         if (shield == "silver")
         {
            hp -= 2;
            return 182;
         }
         // scudo bronzo si rompe e si prende danno discreto
         else
         if (shield == "bronze")
         {
            hp -= 4;
            shield = "";
            return 183;
         }
         // senza scudo si prende grosso danno
         else
         if (shield == "")
         {
            hp -= 7;
            return 184;
         }
      break;
      
      // Trovata pozione curativa per chi ha scudo oro/arg
      // Trovato scudo argento per gli altri
      case 21: case 22:
 
            hp += 4;
            return 211;
           
      // Trovata pozione velenosa per scudi oro/arg
      // Trovata super pozione curativa per gli altri
      case 23: case 24:

            hp -= 4;
            return 231;
   }
}

// Tira il dado per cercare oggetti nella stanza (_or sta per old Room)
// La funzione restituisce un intero, in base a quello l'hud stampa l'effetto corrispondente
int Player::diceRoll_or() 
{
   srand(time(0));
   int roll = (rand()%20) +1;
   switch(roll)
   {
      case 1: case 2: case 3: case 4: case 5:
      // non succede niente
      return roll;

      // trovato scudo oro
      case 6:
         shield = "gold";
      return roll;

      // se scudo oro trovata pozione curativa
      // scudo argento altrimenti
      case 7: 
            hp += 8;
            return 71;
         
     case 8:   
            hp -=8;
            return 72;
   
      // se senza scudo trovo scudo bronzo
      // piccola arma altrimenti
      case 9: case 10: case 11: case 12:
         if (shield == "")
         {
            shield = "bronze";
            return 91;
         }
         else
         {
            atk += 1;
            return 92;
         }
      break;
   
      // trappola, danno incodizionato
      case 13: case 14: case 15: case 16: case 17:
         hp -= 4;
      return roll;
   
      // trovata spada argento
      case 18: case 19:
         atk+=4;
      return roll;

      // trovata spada magica
      case 20:
         hp += 5;
         atk += 5;
      return roll;
   }
}

