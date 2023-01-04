TARGET = culDeChouette.out
DE = De
PARTIE = Partie
JOUEUR = Joueur
IHM = Ihm
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

CFLAGS = -std=c++11 -Wall -I.
CXX = g++ $(CFLAGS) -c
LD = g++
RM = rm -f

all: $(TARGET)

$(TARGET): $(DE).o $(PARTIE).o $(JOUEUR).o $(IHM).o
	$(LD) -o $@ $^

$(DE).o: $(DE).cpp $(DE).h
	$(CXX) $<

$(PARTIE).o: $(PARTIE).cpp $(PARTIE).h
	$(CXX) $<

$(JOUEUR).o: $(JOUEUR).cpp $(JOUEUR).h
	$(CXX) $<

$(IHM).o: $(IHM).cpp $(IHM).h
	$(CXX) $<

.PHONY: check cppcheck format clean cleanall

check:
	clang-tidy $(SOURCES) --quiet -header-filter='.*' -checks=-*,boost-*,bugprone-*,performance-*,readability-*,portability-*,modernize-use-nullptr,clang-analyzer-*,cppcoreguidelines-* --format-style=none -- -std=c++11

cppcheck:
	cppcheck --enable=all --std=c++11 --platform=unix64 --suppress=missingIncludeSystem --quiet $(SOURCES)

format:
	find . -regex '.*\.\(cpp\|h\)' -exec clang-format -i --style=file {} \;

clean:
	$(RM) *.o

cleanall:
	$(RM) *.o* *.*~ $(TARGET)
