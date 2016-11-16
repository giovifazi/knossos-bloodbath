COMPILE := g++

bloodbath: main.o Node.o Map.o Hud.o ClassPlayer.o Menu.o Game.o 
	$(COMPILE) -Wall -o bloodbath main.o Node.o Map.o Hud.o ClassPlayer.o Menu.o Game.o

%.o: %.cpp
	$(COMPILE) -c $< -o $@

%.o: %.hpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f *.o bloodbath *.gch
