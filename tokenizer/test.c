#include "mytoc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//method that contains the test cases provided in the lab examples
void testCases(){
  //Initial declaration
  char ** resultingVector;

  resultingVector = mytoc("Hello my dog's name is Darwin.", ' ');
  printVector(resultingVector);
  free(resultingVector);
  
  resultingVector = mytoc("   Hello  World!   ", ' ');
  printVector(resultingVector);
  free(resultingVector);
  
  resultingVector = mytoc("",' ');
  printVector(resultingVector);
  free(resultingVector);
  
  resultingVector = mytoc("       ", ' ');
  printVector(resultingVector);
  free(resultingVector);
  
  resultingVector = mytoc( "HelloWorld", ' ');
  printVector(resultingVector);
  free(resultingVector);
  
  resultingVector = mytoc("Comma,Separated,Example", ',');
  printVector(resultingVector);
  free(resultingVector);
  
  resultingVector = mytoc("Please,,,,,Do,,,,,not,,,,,,,break", ',');
  printVector(resultingVector);
  free(resultingVector);
  
}

//Checks for certain reserved words, 'exit' to finish execution and 'test' to run test cases
int commandCheck(char * buffer){
  if(buffer[0] && buffer[0] == 'e'){
    if(buffer[1] && buffer[1] == 'x'){
      if(buffer[2] && buffer[2] == 'i'){
	if(buffer[3] && buffer[3] == 't'){
	  return 0;
	}
      }
    }
  }
  if(buffer[0] && buffer[0] == 't'){
    if(buffer[1] && buffer[1] == 'e'){
      if(buffer[2] && buffer[2] =='s'){
	if(buffer[3] && buffer[3] == 't'){
	  return 2;
	}
      }
    }
  }
  return 1;
}
int main(){
  testCases();
  int status = 1;
  while(status == 1){    //Status 1 = execution || Status 2 = executing tests || Status 0 = exit
    char buffer[1024];
    write(1, "Please enter a string to tokenize \n", 35);
    write(1, "$ ", 2);
    read(0, buffer, sizeof(buffer));    //Read input from user
    buffer[sizeof(buffer)+sizeof(char)] = '\0';
    status = commandCheck(buffer);      //Check for commands
    if(status == 1){
      char delimiter[2];
      write(1, "Please enter the delimiter \n", 28);
      write(1, "$ ", 2);
      read(0, delimiter, sizeof(delimiter));    //Read the delimiter from the user
      delimiter[1] = '\0';
      write(1, "\n", 1);
      char ** resultingVector =  mytoc(buffer, delimiter[0]);    //Pass user input to the method and generate a vector
      printVector(resultingVector);     //Print the given vector and free its memory
      free(resultingVector);
      for(int i = 0; i<1024; i++){     //Clean the buffer for next user input
	buffer[i] = '\0';
      }
      delimiter[0] = '\0';             //Clean the delimiter for next user input
    }else if(status == 2){
      testCases();
      status = 1;
    }else{
      return 0;
    }
  }
}
	
