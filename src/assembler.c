#include "../inc/assembler.h"
#include "../inc/util.h"

/* DO NOT MODIFY THE GIVEN API*/
int assembler(FILE *input_file,
              FILE *output_file) {
  /*YOUR CODE HERE*/
  /*GET ONE OF THE INPUT CODE*/
  char input[100];
  memset(input, EOF, 100);
  char* ptr = NULL;
  while(!feof(input_file)){
    IMMEDIATE_ERROR=0;
    REGISTER_ERROR = 0;
    INSTRUCTION_ERROR=0;
    char* ret = fgets(input,64,input_file);
    if(ret==NULL){
      break;
    }
    if(input==NULL){
      break;
    }
    int flag=0;
    char temp[10][40];
    memset(temp, 0, 400);
    char* token=NULL;
    const char s[2] = " ";
    token=strtok(input, s);
    while(token!=NULL){ 
      strcpy(temp[flag], token);
      token=strtok(NULL, s);
      flag++;
    }
    int len_0=strlen(temp[0]);
    int len_1=strlen(temp[1]);
    int len_2=strlen(temp[2]);
    int len_3=strlen(temp[3]);
    for(int i=len_0-1;i>=0;i--){
      if(temp[0][i]=='\n'){
        temp[0][i]='\0';
      }
    }
    for(int i=len_1-1;i>=0;i--){
      if(temp[1][i]=='\n'){
        temp[1][i]='\0';
      }
    }
    for(int i=len_2-1;i>=0;i--){
      if(temp[2][i]=='\n'){
        temp[2][i]='\0';
      }
    }
    for(int i=len_3-1;i>=0;i--){
      if(temp[3][i]=='\n'){
        temp[3][i]='\0';
      }
    }
    /*GET ONE OF THE INPUT CODE*/
    uint32_t code=0;
    uint32_t code2=0;
    if(strcmp(temp[0],"add")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"mul")==0){
      code=code+1*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"sub")==0){
      code=code+32*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"sll")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+1*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"mulh")==0){
      code=code+1*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+1*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"slt")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+2*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"sltu")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+3*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"xor")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+4*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"div")==0){
      code=code+1*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+4*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"srl")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+5*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"sra")==0){
      code=code+32*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+5*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"or")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+6*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"rem")==0){
      code=code+1*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+6*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"and")==0){
      code=code+0*(1<<25)+change(temp[3])*(1<<20)+change(temp[2])*(1<<15)+7*(1<<12)+change(temp[1])*(1<<7)+51;
    }
    else if(strcmp(temp[0],"lb")==0){
      ptr = extract_char(temp[2]);
      code=code+0*(1<<25)+extract_reg_12(temp[2])*(1<<20)+change(ptr)*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+3; 
      free(ptr);
    }
    else if(strcmp(temp[0],"lh")==0){
      ptr = extract_char(temp[2]);
      code=code+0*(1<<25)+extract_reg_12(temp[2])*(1<<20)+change(ptr)*(1<<15)+1*(1<<12)+change(temp[1])*(1<<7)+3; 
      free(ptr);
    }
    else if(strcmp(temp[0],"lw")==0){
      ptr = extract_char(temp[2]);
      code=code+0*(1<<25)+extract_reg_12(temp[2])*(1<<20)+change(ptr)*(1<<15)+2*(1<<12)+change(temp[1])*(1<<7)+3; 
      free(ptr);
    }
    else if(strcmp(temp[0],"lbu")==0){
      ptr = extract_char(temp[2]);
      code=code+0*(1<<25)+extract_reg_12(temp[2])*(1<<20)+change(ptr)*(1<<15)+4*(1<<12)+change(temp[1])*(1<<7)+3; 
      free(ptr);
    }
    else if(strcmp(temp[0],"lhu")==0){
      ptr = extract_char(temp[2]);
      code=code+0*(1<<25)+extract_reg_12(temp[2])*(1<<20)+change(ptr)*(1<<15)+5*(1<<12)+change(temp[1])*(1<<7)+3; 
      free(ptr);
    }
    else if(strcmp(temp[0],"addi")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"slli")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+1*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"slti")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+2*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"sltiu")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+3*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"xori")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+4*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"srli")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+5*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"srai")==0){
      code=code+32*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+5*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"ori")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+6*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"andi")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+7*(1<<12)+change(temp[1])*(1<<7)+19; 
    }
    else if(strcmp(temp[0],"jalr")==0){
      code=code+0*(1<<25)+str_to_uint_12(temp[3])*(1<<20)+change(temp[2])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+103; 
    }
    else if(strcmp(temp[0],"ecall")==0){
      code=code+115; 
    }
    else if(strcmp(temp[0],"sb")==0){
      ptr = extract_char(temp[2]);
      code=code+(extract_reg_12(temp[2])/32)*(1<<25)+change(temp[1])*(1<<20)+change(ptr)*(1<<15)+0*(1<<12)+((extract_reg_12(temp[2]))%(1<<5))*(1<<7)+35; 
      free(ptr);
    }
    else if(strcmp(temp[0],"sh")==0){
      ptr = extract_char(temp[2]);
      code=code+(extract_reg_12(temp[2])/32)*(1<<25)+change(temp[1])*(1<<20)+change(ptr)*(1<<15)+1*(1<<12)+((extract_reg_12(temp[2]))%(1<<5))*(1<<7)+35; 
      free(ptr);
    }
    else if(strcmp(temp[0],"sw")==0){
      ptr = extract_char(temp[2]);
      code=code+(extract_reg_12(temp[2])/32)*(1<<25)+change(temp[1])*(1<<20)+change(ptr)*(1<<15)+2*(1<<12)+((extract_reg_12(temp[2]))%(1<<5))*(1<<7)+35; 
      free(ptr);
    }
    else if(strcmp(temp[0],"beq")==0){
      uint32_t imm = str_to_uint_13(temp[3]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+change(temp[2])*(1<<20)+change(temp[1])*(1<<15)+0*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"bne")==0){
      uint32_t imm = str_to_uint_13(temp[3]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+change(temp[2])*(1<<20)+change(temp[1])*(1<<15)+1*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"blt")==0){
      uint32_t imm = str_to_uint_13(temp[3]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+change(temp[2])*(1<<20)+change(temp[1])*(1<<15)+4*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"bge")==0){
      uint32_t imm = str_to_uint_13(temp[3]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+change(temp[2])*(1<<20)+change(temp[1])*(1<<15)+5*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"bltu")==0){
      uint32_t imm = str_to_uint_13(temp[3]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+change(temp[2])*(1<<20)+change(temp[1])*(1<<15)+6*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"bgeu")==0){
      uint32_t imm = str_to_uint_13(temp[3]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+change(temp[2])*(1<<20)+change(temp[1])*(1<<15)+7*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"auipc")==0){
      uint32_t imm = str_to_uint_21(temp[2]);
      code=code+imm*(1<<12)+change(temp[1])*(1<<7)+23;
    }
    else if(strcmp(temp[0],"lui")==0){
      uint32_t imm = str_to_uint_21(temp[2]);
      code=code+imm*(1<<12)+change(temp[1])*(1<<7)+55;
    }
    else if(strcmp(temp[0],"jal")==0){
      uint32_t imm = str_to_uint_21(temp[2]);
      code=code+((imm%(1<<21))/(1<<20))*(1<<31)+((imm%(1<<11))/(1<<1))*(1<<21)+((imm%(1<<12))/(1<<11))*(1<<20)+((imm%(1<<20))/(1<<12))*(1<<12)+change(temp[1])*(1<<7)+111;
    }
    else if(strcmp(temp[0],"beqz")==0){
      uint32_t imm = str_to_uint_13(temp[2]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+0*(1<<20)+change(temp[1])*(1<<15)+0*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"bnez")==0){
      uint32_t imm = str_to_uint_13(temp[2]);
      code=code+(imm/(1<<12))*(1<<31)+((imm%(1<<11))/(1<<5))*(1<<25)+0*(1<<20)+change(temp[1])*(1<<15)+1*(1<<12)+((imm%(1<<5))/(1<<1))*(1<<8)+((imm%(1<<12))/(1<<11))*(1<<7)+99;
    }
    else if(strcmp(temp[0],"j")==0){
      uint32_t imm = str_to_uint_21(temp[1]);
      code=code+((imm%(1<<21))/(1<<20))*(1<<31)+((imm%(1<<11))/(1<<1))*(1<<21)+((imm%(1<<12))/(1<<11))*(1<<20)+((imm%(1<<20))/(1<<12))*(1<<12)+0*(1<<7)+111;
    }
    else if(strcmp(temp[0],"jr")==0){
      code=code+0*(1<<25)+0*(1<<20)+change(temp[1])*(1<<15)+0*(1<<12)+0*(1<<7)+103; 
    }
    else if(strcmp(temp[0],"li")==0){
      int32_t imm = str_to_uint(temp[2]);
      if((imm>=-2048)&&(imm<=2047)){
        uint32_t imm_u = str_to_uint_12(temp[2]);
        code=code+0*(1<<25)+imm_u*(1<<20)+0*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+19;
      }
      else{
        uint32_t imm_u = str_to_uint_32(temp[2]);
        code=code+(imm_u/(1<<12))*(1<<12)+change(temp[1])*(1<<7)+55;
        code2=code2+0*(1<<25)+(imm_u%(1<<12))*(1<<20)+change(temp[1])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+19;
      }
    }
    else if(strcmp(temp[0],"mv")==0){
      code=code+0*(1<<25)+0*(1<<20)+change(temp[2])*(1<<15)+0*(1<<12)+change(temp[1])*(1<<7)+19;
    }
    else{
      INSTRUCTION_ERROR = 1;
    }
    if((REGISTER_ERROR)||(INSTRUCTION_ERROR)||(IMMEDIATE_ERROR)){
      dump_error_information(output_file);
      continue;
    }
    dump_code(output_file, code);
    if(code2!=0){
      dump_code(output_file, code2);
    }

  }
  return 0;
}

