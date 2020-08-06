#include <stdio.h>
#include <stdlib.h>

int x; //入力する変数
int len = 1; //追加できる範囲表示用

struct LIST{
    int data;
    struct LIST *next;
}*head, *new_r, *tail, *p, *h;

void InitLIST() //tailが定義するため最初のデータを入力する
{
    printf("値を入力(0以外の値)：");
    scanf("%d",&x);
    new_r = (struct LIST *) malloc(sizeof(struct LIST));
    len++; //追加できる範囲
    new_r->data = x;
    new_r->next = NULL;
    head = new_r;
    h = new_r;  //表示後headを先頭に戻すためのポインタ構造体
    tail = new_r;
}

void InputLIST(){
     while(1) 
    {
        printf("値を入力(0で終了)："); //0が入力されるまで繰り返し
        scanf("%d",&x);
        if(x == 0) break;
        new_r = (struct LIST *) malloc(sizeof (struct LIST)); //データ領域確保
        len++; //追加できる範囲
        new_r->data = x; //データの格納
        tail->next = new_r; //格納したデータを連結
        new_r->next = NULL; //格納したデータが末尾であることを示す
        tail = new_r; //次の連結先
    }
}

void PrintLIST(){
    while(head->next != NULL) //連結リスト結果表示
    {
        printf("%d, ",head->data);
        head = head->next;
    } 
    printf("%d\n",head->data);
    head = h; //headを先頭に戻す
}

void InsertLIST(int n) //LISTの追加　挿入する番号を引数に持つ
{
    len++; //追加できる範囲
    if(n == 1) //先頭に挿入する場合
    {
        new_r = (struct LIST *) malloc(sizeof (struct LIST));
        new_r->data = x;
        new_r->next = head; //新しいデータの次の連結先を既存のheadから取得
        head = new_r; //新しいデータをheadにする
        h = new_r; //表示のため同様
    }
    else //それ以外の場所に挿入
    {
        p = head;  //探すポインタを初期化
        for(int i=1; i<n-1; i++){
            p = p->next;  //挿入する1つ前のポインタにｐを置く
        }
        new_r = (struct LIST *) malloc(sizeof (struct LIST));
        new_r->data = x;
        new_r->next = p->next; //新しいデータの次の連結先をp->nextから取得
        p->next = new_r; //p->nextの連結先をnew_rに連結
    }
}

void DeleteLIST() //LISTの削除　削除する値を引数に持つ
{
    struct LIST *Backp; //末尾だった場合のpの前のポインタ
    p = head;
    while( (p->data) != x){
        Backp = p; //pの前のポインタ
        p = p->next;
    }
    if(p->next == NULL) //末尾なら
    {
        p = Backp; //pの前のポインタ
        p->next = NULL; //pの前のポインタ
    }
    else{
        p->data = (p->next) -> data; //pで示される値の削除
        p->next = (p->next) -> next;
    }
    len--;
}

int main(){
    int n,j;
    InitLIST();
    InputLIST();
    PrintLIST();
    while(1) //終了するか、追加するか、削除するか
    {
        printf("終了(0), 追加(1)，削除(2)：");
        scanf("%d",&j);
        if(j == 0) break;
        if(j == 1){
            printf("追加する場所(1～%2d),追加する値：",len+1);
            scanf("%d,%d",&n,&x);
            InsertLIST(n);
            PrintLIST();
        }
        if(j == 2){
            printf("削除する値：");
            scanf("%d",&x);
            DeleteLIST();
            PrintLIST();
        }
    }
    return 0;
}
