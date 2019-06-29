# Makefile
SRC_DIR=../source
CODE_DIR=$(SRC_DIR)/code
OUT=example
TEST_DIR=t
 
test:
    make -C $(TEST_DIR)
 
test_clean:
    make -C $(TEST_DIR) clean
 
code.o:
    gcc -c -I$(CODE_DIR) $(CODE_DIR)/code.cpp -o $(CODE_DIR)/code.o
 
main: code.o
    gcc -I$(CODE_DIR) $(CODE_DIR)/code.o $(SRC_DIR)/main.cpp -o $(OUT)
 
all: test main
 
clean: test_clean
    rm $(SRC_DIR)/*.o $(CODE_DIR)/*.o $(OUT)