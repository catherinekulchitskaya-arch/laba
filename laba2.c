#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b) {
        if (b > a / 2) {
                return 0;
        }
        if (a % b == 0) {
                return b+sum(a, b+1);
        }
        else {
                return  sum(a, b+1);
        }
}


int izbit(int a) {
        if (a<1) return 0;
        int sumiz = sum(a, 1);
        return sumiz >a;
}


void  chain(int  st, int  end , int  ch[], int dlina, int found){
        if (st > end) {
                return;
        }
        if  (izbit(st)) {
                if (found) {
                ch[0]=st;
                        dlina= 1;
                        chain( st+1, end, ch, dlina, 1);
                }
                else {
                        ch[dlina]=st;
                        (dlina)++;
                        chain( st+1, end, ch, dlina, 1);
                }
        }
        else {
                if (found && dlina > 0);{
                        return;
                }
                if(found && dlina <0)  {
                        chain( st+1, end, ch, dlina, 0);
                }

        }
}
int main() {
        int N, M;

        printf("vvedite dva naturalnih chisla N i M: \n");
        printf("N = ");
        if (scanf("%d", &N) !=1) {
                printf("oshibka vvoda \n");
                return 1;
        }
        printf("M = ");
        if (scanf("%d", &M) !=1) {
                printf("oshibka vvoda \n");
                return 1;
        }

        if (N<1 || M<1 ) {
                printf("oshibka vvoda \n");
                return 1;
        }

        if (N > M) {
                printf("oshibka vvoda \n");
                return 1;
        }

        int ch[100];
        int dlina = 0;
        chain(N, M, ch, dlina, 0);

        if(dlina > 0) {
                printf("chain izbitochnih chisel: ");
                for ( int i = 0; i < dlina; i++){
                        printf("%d", ch[i]);
                        if (i < dlina -1) {
                                printf(", ");
                        }
                }
                printf(" \n");
        }
        else{
                printf("chain izbitochih chisel ne naidena \n");
        }
        return 0;
}
