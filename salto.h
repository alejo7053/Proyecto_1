#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void B(uint32_t label, uint32_t *dir_reg);
void BL(uint32_t label, uint32_t *dir_reg);
void BX(uint32_t *dir_reg);
void BNE(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BCC(uint32_t label, uint32_t *dir_reg, char *dir_flags);