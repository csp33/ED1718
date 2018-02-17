SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
#SRC = .
#INC = .
#OBJ = .
#BIN = .

CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -std=c++11
DOC=doc
DATOS=datos


all: $(BIN)/pruebacronologia $(BIN)/union_cronologias $(BIN)/filtradoPalabraClave $(BIN)/filtradoIntervalo $(BIN)/estadisticaEventos

# *************************** Generación de documentación **************************************** #

documentacion :
	@echo "Generando documentación..."
	doxygen doc/doxys/Doxyfile

# *************************** Compilación de módulos ********************************************* #

###############***Binarios****########################

$(BIN)/estadisticaEventos : $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/union_cronologias.o %(OBJ)/estadisticaEventos.o
	@echo "Generando ejecutable de estadisticaEventos..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/estadisticaEventos $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/estadisticaEventos.o

$(BIN)/union_cronologias : $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/union_cronologias.o
	@echo "Generando ejecutable de union_cronologias..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/union_cronologias $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/union_cronologias.o

$(BIN)/filtradoPalabraClave : $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/filtradoPalabraClave.o
	@echo "Generando ejecutable de filtradoPalabraClave..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/filtradoPalabraClave $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/filtradoPalabraClave.o

$(BIN)/filtradoIntervalo : $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/filtradoIntervalo.o
	@echo "Generando ejecutable de filtradoIntervalo..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/filtradoIntervalo $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/filtradoIntervalo.o

$(BIN)/pruebacronologia : $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/pruebacronologia.o
	@echo "Generando ejecutable de pruebacronologia..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/pruebacronologia $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/pruebacronologia.o
###############***Objetos****########################

$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp
	@echo "Generando código objeto..."
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Cronologia.o -c $(SRC)/Cronologia.cpp

$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp
	@echo "Generando código objeto..."
	$(CXX) $(CPPFLAGS) -o $(OBJ)/FechaHistorica.o -c $(SRC)/FechaHistorica.cpp

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o -c $(SRC)/pruebacronologia.cpp

$(OBJ)/union_cronologias.o : $(SRC)/union_cronologias.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/union_cronologias.o -c $(SRC)/union_cronologias.cpp

$(OBJ)/filtradoPalabraClave.o : $(SRC)/filtradoPalabraClave.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/filtradoPalabraClave.o -c $(SRC)/filtradoPalabraClave.cpp

$(OBJ)/filtradoIntervalo.o : $(SRC)/filtradoIntervalo.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/filtradoIntervalo.o -c $(SRC)/filtradoIntervalo.cpp

%(OBJ)/estadisticaEventos.o : $(SRC)/estadisticaEventos.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/estadisticaEventos.o -c $(SRC)/estadisticaEventos.cpp

# ***************************************** Limpieza *********************************************** #
clean :
	@echo "Limpiando archivos objeto y temporales..."
	rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(INC)/*.gch

mrproper : clean
	@echo "Limpiando ejecutables..."
	rm -rf $(BIN)/* doc/html/*
