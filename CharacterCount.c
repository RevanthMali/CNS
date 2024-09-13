 #include<stdio.h>
#include<string.h>
void main(){ 
    char str[100];
    int i,j,n,c=0,count=0; 
    printf("FRAMING METHOD : CHARACTER COUNT\n\n");
   printf("Enter the String: \n");
    scanf("%s",str);
    printf("Enter the no.of Frames:");
    scanf("%d",&n);
    int frames[n];
    for(i=0;i<n;i++){
        printf("Frame size %d: ",i);
        scanf("%d",&frames[i]);
    } 
    for(i=0;i<n;i++){ 
    int flen = frames[i];
    
    printf("Content of the Frame %d: ",i);
    j=i+1;
    while(c<strlen(str)&&j<flen){ 
        printf("%c",&str[c]); 
        c = c+1;
        if(str[c]!='\0'){ 
             scanf("%c",&str[j]);
             count++;
        }
        c=c+1;
        j=j+1;   
    } 
    printf("\nsize of the frame %d : %d\n",i,(count+1));
    count=0;
    }
}
