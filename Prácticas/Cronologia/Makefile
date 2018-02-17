SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC)
DOC=doc
DATOS=datos


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion :
	@echo "Generando documentación..."
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/pruebacronologia : $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/pruebacronologia.o
	@echo "Generando ejecutable..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/pruebacronologia $(OBJ)/Cronologia.o  $(OBJ)/FechaHistorica.o $(OBJ)/pruebacronologia.o
	@echo "El programa ha sido diseñado para que la salida funcione correctamente con el archivo timeline_movies.txt"

$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp
	@echo "Generando código objeto..."
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Cronologia.o -c $(SRC)/Cronologia.cpp


$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp
	@echo "Generando código objeto..."
	$(CXX) $(CPPFLAGS) -o $(OBJ)/FechaHistorica.o -c $(SRC)/FechaHistorica.cpp

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacronologia.o -c $(SRC)/pruebacronologia.cpp

# ************ Limpieza ************
clean :
	@echo "Limpiando archivos objeto y temporales..."
	rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(INC)/*.gch

mrproper : clean
	@echo "Limpiando ejecutables..."
	rm -rf $(BIN)/* doc/html/*
