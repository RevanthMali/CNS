#include<stdio.h> 
#include<string.h>
void main(){
    char frame[50][50],str[50][50]; 
    char flag[10];
    strcpy(flag,"flag");  // flag array with flag bytes
    char esc[10];
    strcpy(esc,"esc"); // esc array with esc bytes
    int i , j , k=0 , n;
    strcpy(frame[k++],"flag"); // first byte as a flag byte
    printf("Enter the length of the String: \n");
    scanf("%d",&n);
    printf("Enter the String:\n"); 
    for(i=0;i<=n;i++){
        gets(str[i]);
    } 
    printf("You entered :");
    for(i=0;i<=n;i++){
        puts(str[i]);
    } 
    printf("\n"); 
    for(i=1;i<=n;i++){
        if(strcmp(str[i],flag) !=0 && strcmp(str[i],esc)!=0) {  // check if the bytes in the frame are flag or esc
                strcpy(frame[k++],str[i]);   // if not  copy string to the frame 
         }
        else{   // if equal add the esc byte to the frame by incrementing the 'k'
                strcpy(frame[k++],"esc");
                strcpy(frame[k++],str[i]) ;        
        }            
    }
    strcpy(frame[k++],"flag"); // atlast add the flag byte to indicate the end of the frame 
    printf("-------------------------------------------\n");    
    printf("Byte stuffing at senders side\n");
    printf("-------------------------------------------\n");
    for( i=0;i<k;i++){
        printf("%s\t" ,frame[i]);
    }
 }
