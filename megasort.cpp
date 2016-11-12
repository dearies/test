#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
 
typedef int* List;
 
List Merge(List L1, List L2, int k1, int k2){   // k la do dai tung chuoi
    List L = (List) malloc (sizeof(int)*(k1+k2));
    int i1= 0, i2=0, j=0;
    while(i1<k1 && i2<k2){
        if (L1[i1]<L2[i2]){
            L[j++] = L1[i1++];
        }else{
            L[j++] = L2[i2++];
        }
    }
 
    if (i1<k1){
        for (;i1<k1;i1++){
            L[j++]= L1[i1];
        }
    }else if(i2<k2){
        for (;i2<k2;i2++){
            L[j++]= L2[i2];
        }
    }else{
        printf ("\n Ca hai mang deu thua!!! -> Loi!");
    }

    return L;
}
 
 
List MergeSort(List L, int n){
    List L1= (List) malloc(sizeof(int)*n), L2= (List) malloc(sizeof(int)*n);
   
    if (1==n) return L;
    if(0==n%2){
        int i;
        for(i=0; i<n/2;++i){
            L1[i] = L[i];
        }
        for(i=n/2; i<n;++i){
            L2[i-n/2] = L[i];
        }
        return Merge(MergeSort(L1, n/2), MergeSort(L2, n/2), n/2, n/2);
    }else{
        int i, k1= (int)n/2 + 1, k2= n-k1;
        for(i=0; i<k1;++i){
            L1[i] = L[i];
        }
        for(i=k1; i<n;++i){
            L2[i-k1] = L[i];
        }
        return Merge(MergeSort(L1, k1), MergeSort(L2, k2), k1, k2);
    }  
}
 
int main(){
    List L;
    int i, n;
   
    printf ("\n Nhap so luong phan tu: "); fflush(stdin); scanf("%d", &n);
    L= (List) malloc(sizeof(int)*n);
   
    srand(time(0));
    for (i= 0; i<n;){
        L[i++] = rand()%100;
    }
    printf ("\n\n Mang tao ngau nhien: \n");
    for (i=0; i<n;++i){
        printf (" %4d", L[i]);
    }
   
    L = MergeSort(L, n);
    printf ("\n Sap xep theo Merge Sort: \n");
    for (i=0; i<n;++i){
        printf (" %4d", L[i]);
    }
    getch();
    return 1;
}
