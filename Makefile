CXX=g++
#CXXFLAGS=-Wall -O2 -g -std=c++11
CXXFLAGS=-Wall -O2 -std=c++11

TARGET=main
#SOURCES=$(wildcard *.cpp)
SOURCES=main.cpp bst.cpp
OBJECTS=$(SOURCES:.cpp = .o)
HEADERS=$(wildcard *.h)

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

#%.o : %.cpp $(HEADERS)
	#$(CXX) -c -o $@ $< 

main.o : main.cpp $(HEADERS)
bst.o : bst.cpp $(HEADERS)

clean:
	rm -f *.o $(TARGET)
	

