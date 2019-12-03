PROGRAM = image_tint
CPPS = PPMImage.cpp main.cpp
HPPS = PPMImage.cpp 
EXE = $(PROGRAM).exe

.PHONY:all
all:$(EXE)

$(EXE): $(CPPS)
	g++ -std=c++11 -g $(CPPS) -o $@

.PHONY:run
run: $(EXE)
	./$(EXE)

.PHONY:
clean:
	$(RM) $(EXE)
