#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void B(uint32_t label, uint32_t *dir_reg);
void BL(uint32_t label, uint32_t *dir_reg);
void BX(uint32_t *dir_reg);
void BEQ(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BNE(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BCS(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BCC(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BMI(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BPL(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BVS(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BVC(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BHI(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BLS(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BGE(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BLT(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BGT(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BLE(uint32_t label, uint32_t *dir_reg, char *dir_flags);
void BAL(uint32_t label, uint32_t *dir_reg);