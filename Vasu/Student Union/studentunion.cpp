//Add threshold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define WIDTH 110
#define HEIGHT 110
 
void Enqueue(int,int);
bool Dequeue(int *,int *);
int FloodFill8Queue(int ,int , int , int);
int mTotalColumns = 0;
int mTotalRows = 0;
char mData[WIDTH][HEIGHT];
char mData2[WIDTH][HEIGHT];
 
int main()
{
    freopen("input.txt","r",stdin);
    int caseCount,i,mLineCount,mRow,mColumn,j,k;
    scanf("%d\n",&caseCount);
    char tempChar[110];
 
    for(i=0;i<caseCount;i++){
        mLineCount = 0;
 
        readInputAgain:
        gets(tempChar);
        if(feof(stdin)) break;
        if(tempChar[0] == 'J' || tempChar[0] == 'C'){
            strcpy(&mData[mLineCount++][0], tempChar);
            strcpy(&mData2[mLineCount-1][0], tempChar);
            goto readInputAgain;
 
        }else if(isdigit(tempChar[0])){
            mTotalRows = mLineCount;
            mTotalColumns = strlen(&mData[0][0]);
            sscanf(tempChar,"%d%d",&mRow,&mColumn);
            memcpy(mData,mData2,sizeof(mData2));
            printf("%d\n",FloodFill8Queue(mRow-1,mColumn-1,'J','C'));
 
            goto readInputAgain;
 
        }else if(tempChar[0] == '\0'){
            printf("\n");
            continue;
 
        }
    }
 
    return 0;
}
 
struct smQueue{
    int smX;
    int smY;
    struct smQueue *next;
};
 
typedef struct smQueue smNode;
smNode *smFirstNode, *smLastNode, *tempNode;
bool firstTime = true;
 
void Enqueue(int valX,int valY){
    smNode *node = malloc(1 * sizeof(smNode));
    if(firstTime){
        firstTime = false;
        smFirstNode = node;
        smLastNode = node;
        smLastNode->smX = valX;
        smLastNode->smY = valY;
        smLastNode->next = NULL;
 
    }
    smLastNode->next = node;
    smLastNode = node;
    smLastNode->smX = valX;
    smLastNode->smY = valY;
    smLastNode->next = NULL;
 
}
 
bool Dequeue(int *smValueX, int *smValueY){
 
    if(smFirstNode!=NULL){
        *smValueX = smFirstNode->smX;
        *smValueY = smFirstNode->smY;
        tempNode = smFirstNode->next;
        free(smFirstNode);
        smFirstNode = tempNode;
        if(smFirstNode==NULL){
            firstTime = true;
        }
        return true;
    }
    return false;
}
 
int FloodFill8Queue(int x,int y, int targetChar, int replaceWith){
 
    if(targetChar == replaceWith) return 0;
    int p=0;
    Enqueue(x,y);
    while(Dequeue(&x,&y)){
        if(mData[x][y] != targetChar) continue;
        mData[x][y] = replaceWith;
        p++;
        if(x+1<mTotalRows && mData[x+1][y] == targetChar ){
            Enqueue(x+1,y);
        }
        if( x-1>=0 && mData[x-1][y] == targetChar ){
            Enqueue(x-1,y);
        }
        if( y+1<mTotalColumns && mData[x][y+1] == targetChar ){
            Enqueue(x,y+1);
        }
        if( y-1>=0 && mData[x][y-1] == targetChar ){
            Enqueue(x,y-1);
        }
        if( x+1<mTotalRows && y+1<mTotalColumns && mData[x+1][y+1] == targetChar){
            Enqueue(x+1,y+1);
        }
        if( x+1<mTotalRows && y-1>=0 && mData[x+1][y-1] == targetChar){
            Enqueue(x+1,y-1);
        }
        if( x-1>=0 && y+1<mTotalColumns && mData[x-1][y+1] == targetChar){
            Enqueue(x-1,y+1);
        }
        if( x-1>=0 && y-1>=0 && mData[x-1][y-1] == targetChar){
            Enqueue(x-1,y-1);
        }
 
    }
    return p;
}