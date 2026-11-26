#include <iostream>
using namespace std;
long long pb[50001], pc[50001], aux[50001];
void interclasare(long long a[], int st, int mij, int dr) {
    int i=st;
    int j=mij+1;
    int k=st;
    while(i<=mij&&j<=dr) {
        if(a[i]<=a[j]) {
            aux[k]=a[i];
            i++;
        }
        else {
            aux[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mij) {
        aux[k]=a[i];
        i++;
        k++;
    }
    while(j<=dr) {
        aux[k]=a[j];
        j++;
        k++;
    }
    for(int i=st; i<=dr; i++) {
        a[i]=aux[i];
    }
}
void mergeSort(long long a[], int st, int dr) {
   if(st<dr) {
      int mij=(st+dr)/2;
      mergeSort(a, st, mij);
      mergeSort(a, mij+1, dr);
      interclasare(a, st, mij, dr);
   }
}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>pb[i];
    }
    for(int i=0; i<m; i++) {
        cin>>pc[i];
    }
    mergeSort(pb, 0, n-1);
    mergeSort(pc, 0, m-1);
    for(int i=0; i<m/2; i++) {
        long long aux=pc[i];
        pc[i]=pc[m-1-i];
        pc[m-1-i]=aux;
    }
    for(int i=0; i<n&&i<m; i++) {
        if(pc[i]>pb[i])
            pb[i]=pc[i];
        else 
            break;
    }
    long long suma=0;
    for(int i=0; i<n; i++) {
        suma+=pb[i];
    }
    cout<<suma;
    
    return 0;
}
