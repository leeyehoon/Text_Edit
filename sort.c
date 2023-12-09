#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
    FILE *fp_in;
    FILE *fp_out;
    char **buf;
    char c;
    char* del_line_p;
    
    /*malloc*/
    buf = (char**) malloc(sizeof(char*) * 1000);
    for(int i=0;i<1000;i++){
        buf[i] = (char*) malloc(sizeof(char) * 20);
    }

    /*file open*/   
    fp_in = fopen("input.txt","r");
    fp_out = fopen("output.txt","w");
    
    /*error note*/
    if(fp_in == NULL){
        fprintf(fp_out,"file is empty");
        exit(0);
    }
    
    int line = 0;
    
    /*count line*/
    while((c=fgetc(fp_in))!=EOF){
        if(c=='\n'){
            line++;   
        }
    }
    
    /*reset pointer position*/
    fseek(fp_in,0,SEEK_SET);


    /*input_data -> buf*/
    for(int i=0;i<line;i++){
        fgets(buf[i],20,fp_in);
        if((del_line_p = (char*)strchr(buf[i],'\n')) != NULL){
            *del_line_p = '\0';
        }
    }

    
    /*buf -> output.txt*/
    for(int j=0;j<line;j++){
        if(j<(line-1)){
            fprintf(fp_out,"%s, ",buf[j]);
        }
        else if(j==(line-1)){
            fprintf(fp_out,"%s",buf[j]);
            fprintf(fp_out,"\nTotal data number : %d",line);
        }
    }
    
    /*free*/
    for(int i=0; i<1000; i++){
        free(buf[i]);
    }
    free(buf);
    
    fclose(fp_in);
    fclose(fp_out);
    
    return 0;
} 