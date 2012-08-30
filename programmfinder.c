#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * strdub(char * str){
	int len = strlen(str);
	char * buff = malloc(sizeof(char) * len);
	int i = 0;
	for(i=0; i<len; i++){
		buff[i] = str[i];
	}
	return buff;
}

int main(){
	char * readSystemPath = getenv("PATH");
	int systemPathLen = strlen(readSystemPath);
	char * systemPath = malloc(systemPathLen * sizeof(char));
	strcpy(systemPath,readSystemPath);
	
	//printf("path: %s\nlen:  %i\n\n",systemPath,systemPathLen);
	
	//count ":"
	unsigned int i = 0;
	unsigned int anz = 0;
	for(i = 0; i < strlen(systemPath) ; i++){
		//printf("compare: %c(%i) == %c(%i)\n",systemPath[i],systemPath[i],':',':');
		if(systemPath[i] == ':'){
			anz++;
		}
	}

	//printf("path: %s\nlen:  %i\nanz:  %i\n",systemPath,systemPathLen,anz);

	
	char ** paths = malloc((anz+1)*sizeof(char*));
	//cut paths
	for(i=0;i<anz;i++){
		int j = 0;
		for(j=0;systemPath[j] != ':'; j++){}
		char * path = malloc(j*sizeof(char));
		strncpy(path,systemPath,j);
		paths[i] = path;
		systemPath = systemPath + ((j+1)*sizeof(char));
	}
	char * path = malloc(strlen(systemPath)*sizeof(char));
	strcpy(path,systemPath);
	paths[anz] = path;

	for(i=0;i<=anz;i++){
		printf("%s\n",paths[i]);
	}
	
	return 0;
}