#include <stdio.h>
#include <stdlib.h>

int x; //入力する変数

struct LIST{
    int data;
    struct LIST *next;
}*head, *new_r, *tail;

void InitLIST() //tailが定義するため最初のデータを入力する
{
    scanf("%d",&x);
    new_r = (struct LIST *) malloc(sizeof(struct LIST));
    new_r->data = x;
    new_r->next = NULL;
    head = new_r;
    tail = new_r;
}

int main(){
    InitLIST();
    
    while(scanf("%d",&x)) //入力が終わるまで繰り返し
    {
        new_r = (struct LIST *) malloc(sizeof (struct LIST)); //データ領域確保
        new_r->data = x; //データの格納
        tail->next = new_r; //格納したデータを連結
        new_r->next = NULL; //格納したデータが末尾であることを示す
        tail = new_r; //次の連結先
    }
    
    while(head->next != NULL) //連結リスト結果表示
    {
        printf("%d, ",head->data);
        head = head->next;
    } 
    printf("%d\n",head->data);
    return 0;
}
