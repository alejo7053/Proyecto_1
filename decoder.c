/**
	\def PC
		\brief Macro que define la posicion del registro \a \b PC en el puntero \b dir_reg
*/

#include "decoder.h"
#define PC 15
uint8_t data;
uint16_t *dec;
void decodeInstruction(instruction_t instruction, uint32_t *dir_reg, char *dir_flags, uint8_t *SRAM, uint16_t *dec)
{
	uint8_t *R_activos=instruction.registers_list;
	/* Comparacion de mnemonic y Llamado de las funciones */
	if( strcmp(instruction.mnemonic,"ADC") == 0 || strcmp(instruction.mnemonic,"ADCS") == 0){
		dir_reg[PC]++;
		*dec=16704;
		*dec=*dec|instruction.op3_value<<3|instruction.op1_value;
		dir_reg[instruction.op1_value]=ADC(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}

	if( strcmp(instruction.mnemonic,"ADDS") == 0 || strcmp(instruction.mnemonic,"ADD") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#'){
			*dec=7168;
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;
			dir_reg[instruction.op1_value]=ADD(dir_reg[instruction.op2_value], instruction.op3_value,dir_flags);
			mvprintw(4,20,"%X",*dec);}
		else{
			*dec=6144;
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;
			dir_reg[instruction.op1_value]=ADD(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);}
	}
	
	if( strcmp(instruction.mnemonic,"AND") == 0 || strcmp(instruction.mnemonic,"ANDS") == 0){
		dir_reg[PC]++;
		*dec=16384;
		if(instruction.op3_type=='#'){
			dir_reg[instruction.op1_value]=AND(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);}
		else
			dir_reg[instruction.op1_value]=AND(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"ASR") == 0 || strcmp(instruction.mnemonic,"ASRS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#'){
			*dec=4096;
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;
			dir_reg[instruction.op1_value]=ASR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);}
		else{
			*dec=16640;
			*dec=*dec|instruction.op3_value<<3|instruction.op1_value;
			dir_reg[instruction.op1_value]=ASR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);}
	}
	
	if( strcmp(instruction.mnemonic,"BICS") == 0 || strcmp(instruction.mnemonic,"BICS") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=BIC(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else{
			*dec=17280;
			dir_reg[instruction.op1_value]=BIC(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op3_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"CMN" ) == 0 || strcmp(instruction.mnemonic,"CMNS") == 0){
		dir_reg[PC]++;
		CMN(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value],dir_flags);
		*dec=17088;
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
		mvprintw(4,20,"%X",*dec);
	}
	
	if( strcmp(instruction.mnemonic,"CMP") == 0 || strcmp(instruction.mnemonic,"CMPS") == 0){
		dir_reg[PC]++;
		CMP(dir_reg[instruction.op1_value],dir_reg[instruction.op2_value],dir_flags);
		*dec=17024;
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
		mvprintw(4,20,"%X",*dec);
	}
	
	if( strcmp(instruction.mnemonic,"EOR") == 0 || strcmp(instruction.mnemonic,"EORS") == 0){
		dir_reg[PC]++;
		*dec=16448;
		if(instruction.op3_type=='#')
			dir_reg[instruction.op1_value]=EOR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
		else
			dir_reg[instruction.op1_value]=EOR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"LSLS") == 0 || strcmp(instruction.mnemonic,"LSL") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#'){
			*dec=0;
			dir_reg[instruction.op1_value]=LSL(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=16512;
			dir_reg[instruction.op1_value]=LSL(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op3_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"LSRS") == 0 || strcmp(instruction.mnemonic,"LSR") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#'){
			*dec=2048;
			dir_reg[instruction.op1_value]=LSR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=16576;
			dir_reg[instruction.op1_value]=LSR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op3_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"MOV") == 0 || strcmp(instruction.mnemonic,"MOVS") == 0){
		dir_reg[PC]++;
		if(instruction.op2_type=='#'){
			*dec=8192;
			dir_reg[instruction.op1_value]=MOV(instruction.op2_value,dir_flags);
			*dec=*dec|instruction.op1_value<<8|instruction.op2_value;}
		else{
			*dec=0;
			dir_reg[instruction.op1_value]=MOV(dir_reg[instruction.op2_value],dir_flags);
			*dec=*dec|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"MUL") == 0 || strcmp(instruction.mnemonic,"MULS") == 0){
		dir_reg[PC]++;
		*dec=17216;
		if(instruction.op3_type=='#'){
			dir_reg[instruction.op1_value]=MUL(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);}
		else{
			dir_reg[instruction.op1_value]=MUL(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"MVN") == 0 || strcmp(instruction.mnemonic,"MVNS") == 0){
		dir_reg[PC]++;
		*dec=17344;
		dir_reg[instruction.op1_value]=MVN(dir_reg[instruction.op2_value], dir_flags);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"ORR") == 0 || strcmp(instruction.mnemonic,"ORRS") == 0){
		dir_reg[PC]++;
		*dec=17152;
		if(instruction.op3_type=='#'){
			dir_reg[instruction.op1_value]=ORR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);}
		else{
			dir_reg[instruction.op1_value]=ORR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op3_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"REV") == 0 || strcmp(instruction.mnemonic,"REVS") == 0){
		dir_reg[PC]++;
		*dec=47616;
		dir_reg[instruction.op1_value]=REV(dir_reg[instruction.op2_value]);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"REVG") == 0 || strcmp(instruction.mnemonic,"REVGS") == 0){
		dir_reg[PC]++;
		*dec=47680;
		dir_reg[instruction.op1_value]=REVG(dir_reg[instruction.op2_value]);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"REVSH") == 0 || strcmp(instruction.mnemonic,"REVSHS") == 0){
		dir_reg[PC]++;
		*dec=47808;
		dir_reg[instruction.op1_value]=REVSH(dir_reg[instruction.op2_value]);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"ROR") == 0 || strcmp(instruction.mnemonic,"RORS") == 0){
		dir_reg[PC]++;
		*dec=16832;
		if(instruction.op3_type=='#'){
			dir_reg[instruction.op1_value]=ROR(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);}
		else{
			dir_reg[instruction.op1_value]=ROR(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op3_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"RSB") == 0 || strcmp(instruction.mnemonic,"RSBS") == 0){
		dir_reg[PC]++;
		*dec=16690;
		dir_reg[instruction.op1_value]=RSB(dir_reg[instruction.op2_value], dir_flags);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"SBC") == 0 || strcmp(instruction.mnemonic,"SBCS") == 0){
		dir_reg[PC]++;
		*dec=16768;
		SBC(dir_reg[instruction.op1_value],dir_reg[instruction.op2_value], dir_flags);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"SUBS") == 0 || strcmp(instruction.mnemonic,"SUB") == 0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#'){
			*dec=7680;
			dir_reg[instruction.op1_value]=SUB(dir_reg[instruction.op2_value],instruction.op3_value,dir_flags);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=6656;
			dir_reg[instruction.op1_value]=SUB(dir_reg[instruction.op2_value],dir_reg[instruction.op3_value],dir_flags);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if( strcmp(instruction.mnemonic,"TST") == 0 || strcmp(instruction.mnemonic,"TSTS") == 0){
		dir_reg[PC]++;
		*dec=16896;
		TST(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], dir_flags);
		*dec=*dec|instruction.op2_value<<3|instruction.op1_value;
	}
	
	if( strcmp(instruction.mnemonic,"NOP") == 0 ){
		NOP(dir_reg);
		*dec=48896;
	}
	
	if( strcmp(instruction.mnemonic,"B") == 0 ){
		*dec=57344;
		*dec=*dec|instruction.op1_value;
		B(instruction.op1_value, dir_reg);
	}
	
	if( strcmp(instruction.mnemonic,"BL") == 0 ){
		BL(instruction.op1_value, dir_reg);
	}
	
	if( strcmp(instruction.mnemonic,"BX") == 0 ){
		*dec=18176;
		BX(dir_reg);
	}
	
	if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
		BEQ(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BNE") == 0 ){
		BNE(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BCS") == 0 ){
		BCS(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BCC") == 0 ){
		BCC(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BMI") == 0 ){
		BMI(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BPL") == 0 ){
		BPL(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BVS") == 0 ){
		BVS(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BVC") == 0 ){
		BVC(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BHI") == 0 ){
		BHI(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BLS") == 0 ){
		BLS(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BGE") == 0 ){
		BGE(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BLT") == 0 ){
		BLT(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BGT") == 0 ){
		BGT(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BLE") == 0 ){
		BLE(instruction.op1_value, dir_reg, dir_flags);
	}
	
	if( strcmp(instruction.mnemonic,"BAL") == 0 ){
		BAL(instruction.op1_value, dir_reg);
	}
	
	if(strcmp(instruction.mnemonic,"PUSH")==0){
		dir_reg[PC]++;
		*dec=46080;
		PUSH(SRAM, dir_reg,R_activos);
	}
	
	if(strcmp(instruction.mnemonic,"POP")==0){
		dir_reg[PC]++;
		*dec=48128;
		POP(SRAM,dir_reg,R_activos);
	}
	
	data=(uint8_t)dir_reg[instruction.op1_value];
	if(strcmp(instruction.mnemonic,"LDR")==0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#' || instruction.op3_type=='N'){
			*dec=26624;
			if((dir_reg[instruction.op2_value]+(instruction.op3_value<<2))>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(instruction.op3_value<<2)), &data,Read);
			else
				dir_reg[instruction.op1_value]=LDR(dir_reg[instruction.op2_value], instruction.op3_value<<2, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value|instruction.op1_value;}
		else{
			*dec=22528;
			if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value]), &data,Read);
			else
				dir_reg[instruction.op1_value]=LDR(dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if(strcmp(instruction.mnemonic,"LDRB")==0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#' || instruction.op3_type=='N'){
			*dec=30720;
			if((dir_reg[instruction.op2_value]+instruction.op3_value)>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+instruction.op3_value), &data,Read);	
			else
				dir_reg[instruction.op1_value]=LDRB(dir_reg[instruction.op2_value], instruction.op3_value, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=23552;
			if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value]), &data,Read);
			else 
				dir_reg[instruction.op1_value]=LDRB(dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if(strcmp(instruction.mnemonic,"LDRH")==0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#' || instruction.op3_type=='N'){
			*dec=34816;
			if((dir_reg[instruction.op2_value]+(instruction.op3_value<<1))>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(instruction.op3_value<<1)), &data,Read);
			else
				dir_reg[instruction.op1_value]=LDRH(dir_reg[instruction.op2_value], instruction.op3_value<<1, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=23040;
			if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value]), &data,Read);
			else
				dir_reg[instruction.op1_value]=LDRH(dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if(strcmp(instruction.mnemonic,"LDRSB")==0){
		dir_reg[PC]++;
		*dec=22016;
		*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;
		if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
			IOAccess((uint8_t)(dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value]), &data,Read);
		else
			dir_reg[instruction.op1_value]=LDRSB(dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
	}
	
	if(strcmp(instruction.mnemonic,"LDRSH")==0){
		dir_reg[PC]++;
		*dec=24064;
		*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;
		if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
			IOAccess((uint8_t)(dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value]), &data,Read);
		else
			dir_reg[instruction.op1_value]=LDRSH(dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
	}
	
	if(strcmp(instruction.mnemonic,"STR")==0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#' || instruction.op3_type=='N'){
			*dec=24576;
			if((dir_reg[instruction.op2_value]+(instruction.op3_value<<2))>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(instruction.op3_value<<2)), &data,Write);
			else
				STR(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], instruction.op3_value<<2, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=20480;
			if((dir_reg[instruction.op2_value]+dir_reg[instruction.op2_value])>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(dir_reg[instruction.op3_value])), &data,Write);
			else
				STR(dir_reg[instruction.op1_value], instruction.op2_value, instruction.op3_value, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if(strcmp(instruction.mnemonic,"STRB")==0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#' || instruction.op3_type=='N'){
			*dec=28672;
			if(dir_reg[instruction.op2_value]+instruction.op3_value>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+instruction.op3_value), &data,Write);
			else			
				STRB(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], instruction.op3_value, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=21504;
			if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(dir_reg[instruction.op3_value])), &data,Write);
			else
				STRB(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
	}
	
	if(strcmp(instruction.mnemonic,"STRH")==0){
		dir_reg[PC]++;
		if(instruction.op3_type=='#' || instruction.op3_type=='N'){
			*dec=32768;
			if(((dir_reg[instruction.op2_value])+(instruction.op3_value<<1))>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(instruction.op3_value<<1)),&data,Write);
			else
				STRH(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], instruction.op3_value<<1, SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
		else{
			*dec=20992;
			if((dir_reg[instruction.op2_value]+dir_reg[instruction.op3_value])>=0x40000000)
				IOAccess((uint8_t)(dir_reg[instruction.op2_value]+(dir_reg[instruction.op3_value])), &data,Write);
			else
				STRH(dir_reg[instruction.op1_value], dir_reg[instruction.op2_value], dir_reg[instruction.op3_value], SRAM);
			*dec=*dec|instruction.op3_value<<6|instruction.op2_value<<3|instruction.op1_value;}
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