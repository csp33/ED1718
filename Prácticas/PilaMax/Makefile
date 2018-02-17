SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC)
DOC=doc
DATOS=datos


all: $(BIN)/main
# ************ Generación de documentación ******************
documentacion :
	@echo "Generando documentación..."
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/main :  $(OBJ)/PilaMaxVD.o $(OBJ)/PilaMaxCola.o $(OBJ)/main.o
	@echo "Generando ejecutable..."
	$(CXX) $(CPPFLAGS) -o $(BIN)/main $(OBJ)/PilaMaxVD.o $(OBJ)/PilaMaxCola.o $(OBJ)/main.o 

$(OBJ)/PilaMaxVD.o : $(SRC)/PilaMaxVD.cpp
	@echo "Generando código objeto..."
	$(CXX) $(CPPFLAGS) -o $(OBJ)/PilaMaxVD.o -c $(SRC)/PilaMaxVD.cpp

$(OBJ)/PilaMaxCola.o : $(SRC)/PilaMaxCola.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/PilaMaxCola.o -c $(SRC)/PilaMaxCola.cpp


$(OBJ)/main.o : $(SRC)/main.cpp
	@echo "Generando código objeto..."
	$(CXX) $(CPPFLAGS) -o $(OBJ)/main.o -c $(SRC)/main.cpp


# ************ Limpieza ************
clean :
	@echo "Limpiando archivos objeto y temporales..."
	rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(INC)/*.gch

mrproper : clean
	@echo "Limpiando ejecutables..."
	rm -rf $(BIN)/* doc/html/*
