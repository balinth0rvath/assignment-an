CXXFLAGS = -O2 -pipe -g -feliminate-unused-debug-types
OBJ = main.o 

%.o: %.cpp $(DEPS) $(LIBDIR)$(LIBHEADER)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ) 
	$(CXX) -o $@ $^ $(CXXFLAGS) 

clean:
	rm main *.o 
