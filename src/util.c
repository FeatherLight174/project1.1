#include "../inc/util.h"

/* YOUR CODE HERE */

/* DO NOT MODIFY CODES BELOW*/

/* Store code into file_ under fixed format */
void dump_code(FILE *file_, uint32_t code) { fprintf(file_, "0x%.8X\n", code); }

/* Output error information to file_ */
void dump_error_information(FILE *file_) {
  fprintf(file_, "Assembling Error\n");
}

uint32_t change(char* x){
  if(strcmp(x,"zero")==0){
    return 0;
  }
  else if(strcmp(x,"x0")==0){
    return 0;
  }
  else if(strcmp(x,"ra")==0){
    return 1;
  }
  else if(strcmp(x,"x1")==0){
    return 1;
  }
  else if(strcmp(x,"sp")==0){
    return 2;
  }
  else if(strcmp(x,"x2")==0){
    return 2;
  }
  else if(strcmp(x,"gp")==0){
    return 3;
  }
  else if(strcmp(x,"x3")==0){
    return 3;
  }
  else if(strcmp(x,"tp")==0){
    return 4;
  }
  else if(strcmp(x,"x4")==0){
    return 4;
  }
  else if(strcmp(x,"t0")==0){
    return 5;
  }
  else if(strcmp(x,"x5")==0){
    return 5;
  }
  else if(strcmp(x,"t1")==0){
    return 6;
  }
  else if(strcmp(x,"x6")==0){
    return 6;
  }
  else if(strcmp(x,"t2")==0){
    return 7;
  }
  else if(strcmp(x,"x7")==0){
    return 7;
  }
  else if(strcmp(x,"s0")==0){
    return 8;
  }
  else if(strcmp(x,"x8")==0){
    return 8;
  }
  else if(strcmp(x,"s1")==0){
    return 9;
  }
  else if(strcmp(x,"x9")==0){
    return 9;
  }
  else if(strcmp(x,"a0")==0){
    return 10;
  }
  else if(strcmp(x,"x10")==0){
    return 10;
  }
  else if(strcmp(x,"a1")==0){
    return 11;
  }
  else if(strcmp(x,"x11")==0){
    return 11;
  }
  else if(strcmp(x,"a2")==0){
    return 12;
  }
  else if(strcmp(x,"x12")==0){
    return 12;
  }
  else if(strcmp(x,"a3")==0){
    return 13;
  }
  else if(strcmp(x,"x13")==0){
    return 13;
  }
  else if(strcmp(x,"a4")==0){
    return 14;
  }
  else if(strcmp(x,"x14")==0){
    return 14;
  }
  else if(strcmp(x,"a5")==0){
    return 15;
  }
  else if(strcmp(x,"x15")==0){
    return 15;
  }
  else if(strcmp(x,"a6")==0){
    return 16;
  }
  else if(strcmp(x,"x16")==0){
    return 16;
  }
  else if(strcmp(x,"a7")==0){
    return 17;
  }
  else if(strcmp(x,"x17")==0){
    return 17;
  }
  else if(strcmp(x,"s2")==0){
    return 18;
  }
  else if(strcmp(x,"x18")==0){
    return 18;
  }
  else if(strcmp(x,"s3")==0){
    return 19;
  }
  else if(strcmp(x,"x19")==0){
    return 19;
  }
  else if(strcmp(x,"s4")==0){
    return 20;
  }
  else if(strcmp(x,"x20")==0){
    return 20;
  }
  else if(strcmp(x,"s5")==0){
    return 21;
  }
  else if(strcmp(x,"x21")==0){
    return 21;
  }
  else if(strcmp(x,"s6")==0){
    return 22;
  }
  else if(strcmp(x,"x22")==0){
    return 22;
  }
  else if(strcmp(x,"s7")==0){
    return 23;
  }
  else if(strcmp(x,"x23")==0){
    return 23;
  }
  else if(strcmp(x,"s8")==0){
    return 24;
  }
  else if(strcmp(x,"x24")==0){
    return 24;
  }
  else if(strcmp(x,"s9")==0){
    return 25;
  }
  else if(strcmp(x,"x25")==0){
    return 25;
  }
  else if(strcmp(x,"s10")==0){
    return 26;
  }
  else if(strcmp(x,"x26")==0){
    return 26;
  }
  else if(strcmp(x,"s11")==0){
    return 27;
  }
  else if(strcmp(x,"x27")==0){
    return 27;
  }
  else if(strcmp(x,"t3")==0){
    return 28;
  }
  else if(strcmp(x,"x28")==0){
    return 28;
  }
  else if(strcmp(x,"t4")==0){
    return 29;
  }
  else if(strcmp(x,"x29")==0){
    return 29;
  }
  else if(strcmp(x,"t5")==0){
    return 30;
  }
  else if(strcmp(x,"x30")==0){
    return 30;
  }
  else if(strcmp(x,"t6")==0){
    return 31;
  }
  else if(strcmp(x,"x31")==0){
    return 31;
  }
  else{
    REGISTER_ERROR = 1;
    return 0;
  }
}

char* extract_char(char* x){
  int i = 0;
  int j = strlen(x)-1;
  char* r = malloc(64);
  while(*(x+i)!='('){
    i++;
  }
  while(*(x+j)!=')'){
    j--;
  }
  memcpy(r, x+i+1, j-i-1);
  *(r+j-i-1)='\0';
  return r;
}

uint32_t extract_reg_12(char* x){
  int i = 0;
  char* r = malloc(64);
  while(*(x+i)!='('){
    i++;
  }
  memcpy(r, x, i);
  *(r+i)='\0';
  return str_to_uint_12(r);
}

int32_t str_to_uint(char* x){
  char* tmp = NULL;
  int32_t result = 0;
  if(*x=='-'){
    for(size_t i=1;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
    result=-result;
  }
  else{
    
    for(size_t i=0;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
  }
  return result;
}

uint32_t str_to_uint_12(char* x){ 
  char* tmp = NULL;
  uint32_t result = 0;
  if((*x!='-')||(*x!='1')||(*x!='2')||(*x!='3')||(*x!='4')||(*x!='5')||(*x!='6')||(*x!='7')||(*x!='8')||(*x!='9')||(*x!='0')){
    IMMEDIATE_ERROR = 1;
    return 0;
  }
  else{
    if(*x=='-'){
      for(size_t i=1;i<strlen(x);i++){
        tmp=x+i;
        if(*tmp=='('){
          break;
        }
        else{
          result=result*10+*tmp-48;       
        }
      }
      result=(1<<12)-result;
    }
    else{
      
      for(size_t i=0;i<strlen(x);i++){
        tmp=x+i;
        if(*tmp=='('){
          break;
        }
        else{
          result=result*10+*tmp-48;       
        }
      }
    }
    return result;
  }
}

uint32_t extract_reg_13(char* x){
  int i = 0;
  char* r = malloc(64);
  while(*(x+i)!='('){
    i++;
  }
  memcpy(r, x, i);
  *(r+i)='\0';
  return str_to_uint_13(r);
}

uint32_t str_to_uint_13(char* x){ 
  char* tmp = NULL;
  uint32_t result = 0;
  if((*x!='-')||(*x!='1')||(*x!='2')||(*x!='3')||(*x!='4')||(*x!='5')||(*x!='6')||(*x!='7')||(*x!='8')||(*x!='9')||(*x!='0')){
    IMMEDIATE_ERROR = 1;
    return 0;
  }
  else{
  if(*x=='-'){
    for(size_t i=1;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
    result=(1<<13)-result;
  }
  else{
    
    for(size_t i=0;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
  }
  return result;
  }
}

uint32_t extract_reg_32(char* x){
  int i = 0;
  char* r = malloc(64);
  while(*(x+i)!='('){
    i++;
  }
  memcpy(r, x, i);
  *(r+i)='\0';
  return str_to_uint_32(r);
}

uint32_t str_to_uint_32(char* x){ 
  char* tmp = NULL;
  uint32_t result = 0;
  if((*x!='-')||(*x!='1')||(*x!='2')||(*x!='3')||(*x!='4')||(*x!='5')||(*x!='6')||(*x!='7')||(*x!='8')||(*x!='9')||(*x!='0')){
    IMMEDIATE_ERROR = 1;
    return 0;
  }
  else{
  if(*x=='-'){
    for(size_t i=1;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
    result=(1<<31)-result+(1<<31);
  }
  else{
    
    for(size_t i=0;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
  }
  return result;
  }
}

uint32_t extract_reg_21(char* x){
  int i = 0;
  char* r = malloc(64);
  while(*(x+i)!='('){
    i++;
  }
  memcpy(r, x, i);
  *(r+i)='\0';
  return str_to_uint_21(r);
}

uint32_t str_to_uint_21(char* x){ 
  char* tmp = NULL;
  uint32_t result = 0;
  if((*x!='-')||(*x!='1')||(*x!='2')||(*x!='3')||(*x!='4')||(*x!='5')||(*x!='6')||(*x!='7')||(*x!='8')||(*x!='9')||(*x!='0')){
    IMMEDIATE_ERROR = 1;
    return 0;
  }
  else{
  if(*x=='-'){
    for(size_t i=1;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
    result=(1<<21)-result;
  }
  else{
    
    for(size_t i=0;i<strlen(x);i++){
      tmp=x+i;
      if(*tmp=='('){
        break;
      }
      else{
        result=result*10+*tmp-48;       
      }
    }
  }
  return result;
  }
}