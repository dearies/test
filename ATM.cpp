#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct {
    char tienchu[25];
    int tienso, soto;
}TienType;
 
TienType* readFromFile(int *n){
    FILE* f = fopen("E:\\code\\atm\\loaitienATM.inp", "r");
    int i=0;
   	TienType *dslt;
   	dslt =(TienType*)malloc (sizeof(TienType));
    while(!feof(f)){
        fscanf(f,"%d",&dslt[i].tienso);
        fgets(dslt[i].tienchu,25,f);
        dslt[i].tienchu[strlen(dslt[i].tienchu)-1]=0;
        dslt[i].soto=0;
        i++;
        dslt = (TienType*) realloc(dslt, (i+1)*sizeof(TienType));
    }
    fclose(f);
    (*n) = i;
    return dslt;
}
 
void indstien(TienType* dslt, int n){
    int i;
    for(i=0; i<n; i++){
        printf ("\n %d | %s", dslt[i].tienso, dslt[i].tienchu);
    }
}
 
void insertSort(TienType* dslt, int n){
    if (n>0){
        int i,j;
        for (i=0; i<n;++i){
            j=i;
            while(j>0 && dslt[j].tienso>dslt[j-1].tienso){
                TienType temp= dslt[j];
                dslt[j]= dslt[j-1];
                dslt[j-1]= temp;
                j--;
            }
        }
    }
}
 
void GreedyRutTien(int sotienrut, TienType* dslt, int n){
    int i=0, tiengoc= sotienrut;
    while(sotienrut>0 && i<n){
        dslt[i].soto = sotienrut/dslt[i].tienso;
        sotienrut -= dslt[i].soto*dslt[i].tienso;
        ++i;
    }
   
    printf ("\n |=> Ket qua: ");
    printf ("\n .---|-----------|--------------------------------|--------------.");
    printf ("\n |STT| Loai tien | Thanh chu                      | So to can rut|");
    printf ("\n |---|-----------|--------------------------------|--------------|");
    for (i=0; i<n;i++){
        if (dslt[i].soto>0){
            printf ("\n |%3d|%11d|%32s|%14d|", i+1, dslt[i].tienso, dslt[i].tienchu, dslt[i].soto);
        }
    }
    printf ("\n '---|-----------|--------------------------------|--------------'\n");
   
    printf ("\n\n |> So tien muon rut: %d", tiengoc);
    printf ("\n |> Tong tien da rut la: %d", tiengoc-sotienrut);
    printf ("\n |> So tien chua rut duoc: %d", sotienrut);
}
 
int main(){
    TienType* dslt;
    int n;
    dslt = readFromFile(&n);
	printf ("\n So loai tien: %d", n); 
    insertSort(dslt, n);
    printf ("\n\n | Danh sach cac loai tien | \n");
    indstien(dslt, n);
    printf ("\n\n > Nhap so tien can rut: ");
    fflush(stdin); int sotienrut; scanf("%d", &sotienrut);
    GreedyRutTien(sotienrut, dslt, n);
    free(dslt);
    getch();
    return 1;
}
