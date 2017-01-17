#ifndef OPERATION_H
#define OPERATION_H

#include <stdint.h>

enum op_e {
    // control
    HTL,
    JMP,
    CJMP,
    OJMP,
    CALL,
    RET,
    // stack
    PUSH,
    POP,
    // data access
    LOADB,
    LOADW,
    STOREB,
    STOREW,
    LOADI,
    NOP,
    // i/o
    IN,
    OUT,
    // arithmetic
    ADD,
    ADDI,
    SUB,
    SUBI,
    MUL,
    DIV,
    // bitwise
    AND,
    OR,
    NOR,
    NOTB,
    SAL,
    SAR,
    // logic
    EQU,
    LT,
    LTE,
    NOTC
    // fake op
    // BYTE
    // WORD
};

struct op_t1 {
    unsigned : 27;
    unsigned op : 5;
};

struct op_t2 {
    unsigned addr : 24;
    unsigned : 3;
    unsigned op : 5;
};

struct op_t3 {
    unsigned : 24;
    unsigned reg0 : 3;
    unsigned op : 5;
};

struct op_t4 {
    unsigned addr : 24;
    unsigned reg0 : 3;
    unsigned op : 5;
};

struct op_t5 {
    unsigned imme : 16;
    unsigned : 8;
    unsigned reg0 : 3;
    unsigned op : 5;
};

struct op_t6 {
    unsigned port : 8;
    unsigned : 16;
    unsigned reg0 : 3;
    unsigned op : 5;
};

struct op_t7 {
    unsigned : 16;
    unsigned reg2 : 4;
    unsigned reg1 : 4;
    unsigned reg0 : 3;
    unsigned op : 5;
};

struct op_t8 {
    unsigned : 20;
    unsigned reg1 : 4;
    unsigned reg0 : 3;
    unsigned op : 5;
};

union op_u {
    uint32_t litera;
    struct op_t1 t1;
    struct op_t2 t2;
    struct op_t3 t3;
    struct op_t4 t4;
    struct op_t5 t5;
    struct op_t6 t6;
    struct op_t7 t7;
    struct op_t8 t8;
};

#endif
