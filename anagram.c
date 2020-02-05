#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LIMIT 20

int main(int argc, char* argv[]){
	char* firstWord=argv[1];
	char* secondWord=argv[2];
	if(firstWord==NULL||secondWord==NULL){
		return 1;
	}
	else{
		if(strlen(firstWord)==strlen(secondWord)){
			for(int i=0; i<strlen(firstWord); i++){
				for(int j=0;j<strlen(secondWord);j++){
					if(secondWord[j]!='0'){
						if(firstWord[i]==secondWord[j]){
							secondWord[j]='0';
							break;
						}
					}
					if(j==strlen(secondWord)-1){
						return 1;
					}
				}
				if(i==strlen(firstWord)-1){
					return 0;
				}
			}	
		}
		else{
			return 1;
		}
	}
}
