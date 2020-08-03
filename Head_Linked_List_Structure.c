#include <stdio.h>
#include <stdlib.h>

struct LIST{
    int data;
    struct LIST *next;
};

int main(){
    struct LIST *head, *new_r;
    int x;
    
    head = NULL; //先頭から連結する
    while(scanf("%d",&x)) //入力が終わるまで繰り返し
    {
        new_r = (struct LIST *) malloc(sizeof (struct LIST)); //データ領域確保
        new_r->data = x; //データの格納
        new_r->next = head; //格納したデータを連結
        head = new_r; //次の連結先
    }
    
    while(head->next != NULL) //連結リスト結果表示
    {
        printf("%d, ",head->data);
        head = head->next;
    } 
    printf("%d\n",head->data);
    return 0;
}
