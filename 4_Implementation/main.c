#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

 

 int main(){

 printf("LED Flash Start\n");

 FILE *LEDHandle = NULL;

 const char *LEDBrightness="/sys/class/gpio/gpio49/value";

 

 for(int i=0; i<10; i++){ 

 	if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){

 		fwrite("1", sizeof(char), 1, LEDHandle);

 		fclose(LEDHandle);

 	}

 	usleep(1000000);

 

 	if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){

 		fwrite("0", sizeof(char), 1, LEDHandle);

 		fclose(LEDHandle);

 	}

 	usleep(1000000);

  }

  printf("LED Flash End");

 }
