#include <cstdio>
const int N = 2E5 + 7;
int a[N];
void Swap(int &x, int &y){
    int tmp = x; x = y; y = tmp;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] < a[j]){
                cnt++;
                Swap(a[i], a[j]);  // 交换a[i]和a[j]的值
            }
        }
    }

    printf("%lld\n", cnt);
    return 0;
}
