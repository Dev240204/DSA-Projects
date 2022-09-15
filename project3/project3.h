#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
# define SIZE 5

struct UserEntry {
    char Name[20];
    char Priority;
    int Number[12];
};
struct UserEntry Person[SIZE];

int arrVip[SIZE];
int arrNom[SIZE];
int arrList[SIZE];
int ind=0;

void Check(){
    FILE *fdata;
    fdata = fopen("Data.txt","rb");
    if(fdata==NULL){
        printf("\nError cannot open the file");
    }
    fread(Person,sizeof(struct UserEntry),SIZE,fdata);
    int j=0,k=0;
    for(int i=0;i<SIZE;i++){
        char ask = Person[i].Priority;
        if(ask=='V'){
            arrList[j] = i;
            ind++;
            j++;
        }else if (ask=='N'){
            arrNom[k] = i;
            k++;
        }
    }
    int p = ind;
    for(int i=0;i<ind+1;i++){
        arrList[p] = arrNom[i];
        p++;
    }
    fclose(fdata);
}

void Display(){
    FILE *fdata;
    fdata = fopen("Data.txt","rb");
    if(fdata==NULL){
        printf("\nError cannot open the file");
    }
    fread(Person,sizeof(struct UserEntry),SIZE,fdata);
    int i=0;
    while(i<SIZE){
        printf("\nEntry of Member %d",i+1);
        printf("\nName : %s",Person[arrList[i]].Name);
        printf("\nMobile Number : %s",Person[arrList[i]].Number);
        printf("\nPriority : %c",Person[arrList[i]].Priority);
        printf("\n");
        printf("Entry done sucessfully!!!\n");
        Sleep(2000);
        i++;
    }
    fclose(fdata);
}
void DataInput(){
    FILE *fdata;
    fdata = fopen("Data.txt","wb");
    if(fdata==NULL){
        printf("\nError cannot open the file");
    }
    printf("\nEnter the Details of Members ");
    for(int i=0;i<SIZE;i++){
        printf("\nEnter the Name of %d Person : ",i+1);
        scanf("%s",&Person[i].Name);
        printf("Enter the Mobile Number of %d Person : ",i+1);
        scanf("%s",&Person[i].Number);
        printf("Enter the priority of %d Person written on the pass (V OR N): ",i+1);
        scanf("%s",&Person[i].Priority);
    }
    fwrite(Person,sizeof(struct UserEntry),SIZE,fdata);
    printf("\nAll the data stored sucessfully in file");
    fclose(fdata);
}