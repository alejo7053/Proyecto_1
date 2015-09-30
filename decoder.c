/**
	\def PC
		\brief Macro que define la posicion del registro \a \b PC en el puntero \b dir_reg
*/

#include "decoder.h"
#define PC 15

void decodeInstruction(instruction_t instruction, uint32_t *dir_reg, char *dir_flags, uint8_t *SRAM)
{
	uint8_t *R_activos=instruction.registers_list;
	/* Comparacion de mnemonic y Llamado de las funciones */
	int op=3;
	if( strcmp(instruction.mnemonic,"ADC") == 0 || strcmp(instruction.mnemonic,"ADCS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=ADC(dir_reg[instruction.op2_value], instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=ADC(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"ADDS") == 0 || strcmp(instruction.mnemonic,"ADD") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=ADD(dir_reg[instruction.op2_value], instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=ADD(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"AND") == 0 || strcmp(instruction.mnemonic,"ANDS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=AND(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=AND(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"ASR") == 0 || strcmp(instruction.mnemonic,"ASRS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=ASR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=ASR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BICS") == 0 || strcmp(instruction.mnemonic,"BICS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=BIC(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=BIC(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"CMN" ) == 0 || strcmp(instruction.mnemonic,"CMNS") == 0){
		dir_reg[PC]++;
		CMN(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value],dir_flags);
		op=2;
	}
	
	if( strcmp(instruction.mnemonic,"CMP") == 0 || strcmp(instruction.mnemonic,"CMPS") == 0){
		dir_reg[PC]++;
		CMP(dir_reg[instruction.op1_value],dir_reg[instruction.op2_value],dir_flags);
		op=2;
	}
	
	if( strcmp(instruction.mnemonic,"EOR") == 0 || strcmp(instruction.mnemonic,"EORS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=EOR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=EOR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"LSLS") == 0 || strcmp(instruction.mnemonic,"LSL") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=LSL(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=LSL(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"LSRS") == 0 || strcmp(instruction.mnemonic,"LSR") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=LSR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=LSR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"MOV") == 0 || strcmp(instruction.mnemonic,"MOVS") == 0){
		dir_reg[PC]++;
		if(instruction.op2_type=='#')
			dir_reg[instruction.op1_value]=MOV(instruction.op2_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=MOV(dir_reg[instruction.op2_value],dir_flags);
		op=2;
	}
	
	if( strcmp(instruction.mnemonic,"MUL") == 0 || strcmp(instruction.mnemonic,"MULS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=MUL(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=MUL(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"MVN") == 0 || strcmp(instruction.mnemonic,"MVNS") == 0){
		dir_reg[PC]++;
		dir_reg[instruction.op1_value]=MVN(dir_reg[instruction.op2_value], dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"ORR") == 0 || strcmp(instruction.mnemonic,"ORRS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=ORR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=ORR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"REV") == 0 || strcmp(instruction.mnemonic,"REVS") == 0){
		dir_reg[PC]++;
		dir_reg[instruction.op1_value]=REV(dir_reg[instruction.op2_value]);
	}
	
	if( strcmp(instruction.mnemonic,"REVG") == 0 || strcmp(instruction.mnemonic,"REVGS") == 0){
		dir_reg[PC]++;
		dir_reg[instruction.op1_value]=REVG(dir_reg[instruction.op2_value]);
	}
	
	if( strcmp(instruction.mnemonic,"REVSH") == 0 || strcmp(instruction.mnemonic,"REVSHS") == 0){
		dir_reg[PC]++;
		dir_reg[instruction.op1_value]=REVSH(dir_reg[instruction.op2_value]);
	}
	
	if( strcmp(instruction.mnemonic,"ROR") == 0 || strcmp(instruction.mnemonic,"RORS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=ROR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=ROR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"RSB") == 0 || strcmp(instruction.mnemonic,"RSBS") == 0){
		dir_reg[PC]++;
		dir_reg[instruction.op1_value]=RSB(dir_reg[instruction.op2_value], dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"SBC") == 0 || strcmp(instruction.mnemonic,"SBCS") == 0){
		dir_reg[PC]++;
	}
	
	if( strcmp(instruction.mnemonic,"SUBS") == 0 || strcmp(instruction.mnemonic,"SUB") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=SUB(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=SUB(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"TST") == 0 || strcmp(instruction.mnemonic,"TSTS") == 0){
		dir_reg[PC]++;
		TST(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"NOP") == 0 ){
		NOP(dir_reg);
		op=5;
	}
	
	if( strcmp(instruction.mnemonic,"B") == 0 ){
		op=1;
		B(instruction.op1_value, dir_reg);
	}
	
	if( strcmp(instruction.mnemonic,"BL") == 0 ){
		op=1;
		BL(instruction.op1_value, dir_reg);
	}
	
	if( strcmp(instruction.mnemonic,"BX") == 0 ){
		op=4;
		BX(dir_reg);
	}
	
	if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
		op=1;
		BEQ(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BNE") == 0 ){
		op=1;
		BNE(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BCS") == 0 ){
		op=1;
		BCS(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BCC") == 0 ){
		op=1;
		BCC(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BMI") == 0 ){
		op=1;
		BMI(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BPL") == 0 ){
		op=1;
		BPL(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BVS") == 0 ){
		op=1;
		BVS(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BVC") == 0 ){
		op=1;
		BVC(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BHI") == 0 ){
		op=1;
		BHI(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BLS") == 0 ){
		op=1;
		BLS(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BGE") == 0 ){
		op=1;
		BGE(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BLT") == 0 ){
		op=1;
		BLT(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BGT") == 0 ){
		op=1;
		BGT(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BLE") == 0 ){
		op=1;
		BLE(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BAL") == 0 ){
		op=1;
		BAL(instruction.op1_value, dir_reg);
	}
	if(strcmp(instruction.mnemonic,"PUSH")==0){
		dir_reg[PC]++;
		PUSH(SRAM, dir_reg,R_activos);
	}
	if(strcmp(instruction.mnemonic,"POP")==0){
		dir_reg[PC]++;
		POP(SRAM,dir_reg,R_activos);
	}
	switch(op) //Imprime las instrucciones de acuerdo a la cantidad de parametros 1, 2 o 3
	{
	case 1:
		if(instruction.op1_type=='#')
			mvprintw(4,1,"%s %c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value);
		else
			mvprintw(4,1,"%s %c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value);
		break;	
	
	case 2:
	if(instruction.op2_type=='#')
		mvprintw(4,1,"%s %c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value);
	else
		mvprintw(4,1,"%s %c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value);
	break;
	
	case 3:		
		if( instruction.op3_type=='#' || instruction.op2_type=='#')
			mvprintw(4,1,"%s %c%d,%c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value, instruction.op3_type, instruction.op3_value);
		else
			mvprintw(4,1,"%s %c%d,%c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value, instruction.op3_type, instruction.op3_value);
		break;
		
	case 4:
		mvprintw(4,1,"BX LR");
		break;
		
	case 5:
		mvprintw(4,1,"NOP");
		break;
	}
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;
	
	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */	
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);
	
	/* Separa los operandos */	
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;
							
						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}					
				break;
			
			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
			
			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);			
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}	
	}	
	
	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}
	
	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);	
	
	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */
		
	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */
	
	lines = countLines(fp);	/* Cantidad de líneas*/
	
	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	
	fclose(fp);	/* Cierra el archivo */

	return lines;
}	


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];
	
	while( fgets(buffer, 50, fp) != NULL )
		lines++;
	
	rewind(fp);
	
	return lines;
}