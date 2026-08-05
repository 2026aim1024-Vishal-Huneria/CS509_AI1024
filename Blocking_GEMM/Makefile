CXX = g++

CXXFLAGS = -std=c++17 -O2

TARGET = gemm_blocking

SRC = driver.cpp gemm_blocking.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)