/*
dot8_i8 rd, rs1, rs2

rd is not accumulated here.
*/

require_rv64;

// sreg_t is the 64-bit signed register type provided by riscv
sreg_t sum = 0;

for (int i = 0; i < 8; i++) {
    // shift right by 8 bits to get the next int
    int8_t a = (int8_t)(RS1 >> (8 * i) & 0xFF);
    int8_t b = (int8_t)(RS2 >> (8 * i) & 0xFF);
    
    sum += (sreg_t)(a * b);
}

WRITE_RD(sum);
