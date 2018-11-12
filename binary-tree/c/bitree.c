#include <stdio.h>
#include <stdlib.h>

typedef int TElementType;

typedef struct BiTNode {
    int data;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
} BiTNode;

typedef BiTNode* BiTree;

// ���򴴽�������
void CreateBiTree(BiTree *T) {
    TElementType ch;
    scanf("%d", &ch);
    if (ch == -1) {
        *T = NULL;
        return;
    }
    else
    {
        *T = (BiTree) malloc(sizeof(BiTNode));  // �����ڴ�ռ�
        (*T)->data = ch;
        printf("����%d�����ӽڵ㣺",ch);
        CreateBiTree(&(*T)->lChild);  // ����������
        printf("����%d�����ӽڵ㣺",ch);
        CreateBiTree(&(*T)->rChild);  // ����������
    }
}

// ����������������ݹ飩
void PreOrderTraverse(BiTree T) {

    if (T == NULL) {
        return;
    }
    printf("%d", T->data);

    PreOrderTraverse(T->lChild);
    PreOrderTraverse(T->rChild);
}

// �������������
void InOrderTraverse(BiTree T) {

    if (T == NULL) {
        return;
    }

    InOrderTraverse(T->lChild);
    printf("%d", T->data);
    InOrderTraverse(T->rChild);
}

// �������������
void PostOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }

    PostOrderTraverse(T->lChild);
    PostOrderTraverse(T->rChild);
    printf("%d", T->data);
}

// �����������
int TreeDeep(BiTree T) {

    int deep = 0;
    if (T != NULL) {
        int leftDeep = TreeDeep(T->lChild);
        int rightDeep = TreeDeep(T->rChild);
        deep = leftDeep >= rightDeep ? leftDeep + 1 : rightDeep + 1;
    }

    return deep;
}

// Ҷ�ӽڵ�ĸ���
int LeafCount(BiTree T) {
    int count = 0;
    if (T != NULL) {
        if (T->rChild == NULL && T->lChild == NULL) {
            count++;
        }

        LeafCount(T->lChild);
        LeafCount(T->rChild);
    }
    return count;
}

int main() {

    BiTree bTree;

    printf("�������һ���ڵ��ֵ��-1��ʾû��Ҷ�ڵ㣺\n");

    CreateBiTree(&bTree);

    printf("���������������\n");
    PreOrderTraverse(bTree);

    printf("���������������\n");
    InOrderTraverse(bTree);

    printf("���������������\n");
    PostOrderTraverse(bTree);

    printf("�������Ϊ: %d \n", TreeDeep(bTree));

    printf("Ҷ�ӽڵ����Ϊ��%d \n", LeafCount(bTree));

    return 0;
}