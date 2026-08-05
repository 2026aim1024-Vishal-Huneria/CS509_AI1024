CXX = g++
CXXFLAGS = -std=c++17 -O2

TARGET = gemm_mc

SRC = driver.cpp gemm.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)