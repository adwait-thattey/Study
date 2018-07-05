#include <stdio.h>

int main() {

int T;
scanf("%d" ,&T );

    while(T>0) {

        --T;
        long unsigned int N , R;
        scanf("%lu , %lu" , &N , &R);

        long unsigned int Arr[N];

        for(int i = 0 ; i<N ; ++i) {
            scanf("%lu" , &Arr[i]);
        }
        int flag = 0;

        for(int i=1;i<N-1;++i) {

           long int diff = Arr[i] - Arr[i-1];
              if(diff>0) {
            if(Arr[i+1]<=Arr[i-1]){
                    flag=1;

                    break;
            }
           }

           else if(diff<0) {
            if(Arr[i+1]>=Arr[i-1]) {
                    flag=1;

                    break;
            }
           }

           else if(diff==0){

                flag=1;
                break;
            }


        }

        if(flag==1) printf("NO\n");
        else printf("YES\n");

    }

return 0;

}
