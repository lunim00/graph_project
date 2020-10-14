ifeq ($(OS), Windows_NT)
	INCLUDES := include\\
	BUILD := build\\
	BIN := bin\\
	EXECUTABLE := $(BIN)Project.exe
	SOURCE := src\\
	DELETE := del
else
	INCLUDES := include/
	BUILD := build/
	BIN := bin/
	EXECUTABLE := $(BIN)Project
	SOURCE := src/
	DELETE := rm
endif

CPP := g++ 
CPPFLAGS := -g -std=c++17 -Wall -Wextra -Wpedantic -Werror

implementation: $(EXECUTABLE)
#skriv körningen för implementationen med dina egna tester i :D
$(EXECUTABLE): $(BUILD)diffusionTime.o $(BUILD)hashing.o $(BUILD)independentCascadeModel.o  $(BUILD)informedNodes.o $(BUILD)main.o $(BUILD)networkHandler.o $(BUILD)node.o $(BUILD)nodeList.o
	$(CPP) $(CPPFLAGS) $(BUILD)diffusionTime.o $(BUILD)hashing.o $(BUILD)independentCascadeModel.o  $(BUILD)informedNodes.o $(BUILD)main.o $(BUILD)networkHandler.o $(BUILD)node.o $(BUILD)nodeList.o -o $(EXECUTABLE)

$(BUILD)diffusionTime.o: $(SOURCE)diffusionTime.cpp $(INCLUDES)diffusionTime.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)diffusionTime.cpp -I$(INCLUDES) -o $(BUILD)diffusionTime.o

$(BUILD)hashing.o: $(SOURCE)hashing.cpp $(INCLUDES)hashing.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)hashing.cpp -I$(INCLUDES) -o $(BUILD)hashing.o

$(BUILD)independentCascadeModel.o: $(SOURCE)independentCascadeModel.cpp $(INCLUDES)independentCascadeModel.hpp $(INCLUDES)networkHandler.hpp $(INCLUDES)diffusionTime.hpp $(INCLUDES)informedNodes.hpp $(INCLUDES)nodeList.hpp $(INCLUDES)node.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)independentCascadeModel.cpp -I$(INCLUDES) -o $(BUILD)independentCascadeModel.o

$(BUILD)informedNodes.o: $(SOURCE)informedNodes.cpp $(SOURCE)diffusionTime.cpp $(SOURCE)hashing.cpp $(INCLUDES)diffusionTime.hpp $(INCLUDES)hashing.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)informedNodes.cpp -I$(INCLUDES) -o $(BUILD)informedNodes.o

$(BUILD)main.o: $(SOURCE)main.cpp $(INCLUDES)networkHandler.hpp $(INCLUDES)independentCascadeModel.hpp $(INCLUDES)informedNodes.hpp $(INCLUDES)node.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)main.cpp -I$(INCLUDES) -o $(BUILD)main.o

$(BUILD)networkHandler.o: $(SOURCE)networkHandler.cpp $(INCLUDES)networkHandler.hpp $(INCLUDES)node.hpp $(INCLUDES)nodeList.hpp $(INCLUDES)diffusionTime.hpp $(INCLUDES)hashing.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)networkHandler.cpp -I$(INCLUDES) -o $(BUILD)networkHandler.o

$(BUILD)node.o: $(SOURCE)node.cpp $(INCLUDES)node.hpp $(INCLUDES)diffusionTime.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)node.cpp -I$(INCLUDES) -o $(BUILD)node.o

$(BUILD)nodeList.o: $(SOURCE)nodeList.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)nodeList.cpp -I$(INCLUDES) -o $(BUILD)nodeList.o

clean:
	-$(DELETE) $(EXECUTABLE)  
	-$(DELETE) $(BUILD)diffusionTime.o
	-$(DELETE) $(BUILD)hashing.o
	-$(DELETE) $(BUILD)independentCascadeModel.o
	-$(DELETE) $(BUILD)informedNodes.o
	-$(DELETE) $(BUILD)main.o
	-$(DELETE) $(BUILD)networkHandler.o
	-$(DELETE) $(BUILD)node.o
	-$(DELETE) $(BUILD)nodeList.o