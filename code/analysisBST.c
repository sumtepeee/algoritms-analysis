#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Yeni node olusturulamadi..\n");
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *search(Node *root, int key) {
    if (root == NULL || root->value == key) {
        return root;
    }
    if (root->value > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
}


void measurePerformance(int *data,int size, int scenarioIndex){

    Node *root = NULL;
    clock_t start, end;
    double insertTime,searchTime,postOrderTime, preOrderTime;

    //InsertTime

    start=clock();
    for (int i = 0; i < size; i++)
    {
        root=insert(root,data[i]);
    }
    end=clock();

    insertTime=(double)(end - start) / CLOCKS_PER_SEC;

    //SearchTime

    start=clock();

    for (int i = 0; i < size; i++)
    {
        search(root,data[i]);
    }
    end=clock();

    searchTime=(double)(end - start) / CLOCKS_PER_SEC;

    //Post Order Time

    start= clock();

    postorderTraversal(root);

    end=clock();
    postOrderTime=(double)(end - start) / CLOCKS_PER_SEC;

    //Pre Order Traversal

    start= clock();

    preorderTraversal(root);

    end=clock();
    preOrderTime=(double)(end - start) / CLOCKS_PER_SEC;

    printf("Veri Boyutu: %d, Senaryo: %d\n", size, scenarioIndex);
    printf("Ekleme Süresi: %.6f saniye\n", insertTime);
    printf("Arama Süresi: %.6f saniye\n", searchTime);
    printf("Preorder Süresi: %.6f saniye\n", preOrderTime);
    printf("Postorder Süresi: %.6f saniye\n\n", postOrderTime);
}

void createData(int *data, int size, int scenario) {

    switch (scenario)
    {
    case 1:        // Sıralı veri
        for (int i = 0; i < size; i++)
        {
            data[i]=i+1;
        }
        
        break;
    
    case 2:         // Ters sıralı veri

        for (int i = 0; i < size; i++)
        {
            data[i]=size-i;
        }
        break;
    
    case 3:            // Rastgele veri
    
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }

        for (int i = size - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        break;
    case 4:         // Karma veri

        for (int i = 0; i < size / 2; i++) {
            data[i] = i + 1;
        }
        for (int i = size / 2; i < size; i++) {
            data[i] = size - (i - size / 2);
        }
        break;
    
    default:
        break;
    }

}

int main()
{
    srand(time(0));
    int sizes[] = {100,500,1000,2500,5000,10000,50000};
    int numSizes = sizeof(sizes)/sizeof(sizes[0]);

   for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int data[size];
        
        for (int scenario = 1; scenario <= 4; scenario++) {
            createData(data, size, scenario);
            measurePerformance(data, size, scenario);
        }
    }

    return 0;
}