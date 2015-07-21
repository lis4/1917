#include <stdio.h>
#include <stdlib.h>

typedef struct _node *Node;
typedef struct _node {
    int value;
    Node next;
} node;

typedef struct _list *List;
typedef struct _list {
    Node first;
} list;

List createList(void) {
    List l = malloc(sizeof(list));
    l->first = NULL;
    return l;
}

Node createNode(int data){
    Node new = malloc(sizeof(node));
    new->value = data;
    new->next = NULL;
    return new;
}

void printList(List l) {
    Node curr = l->first;
    while (curr != NULL) {
        printf("[%d]->", curr->value);
        curr = curr->next;
    }
    printf("[X]\n");
}

int countNodes(List l) {
    Node curr = l->first;
    int count = 0;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

int sumNodes(List l) {
    Node curr = l->first;
    int sum = l->first->value;
    while (curr->next != NULL) {
        curr = curr->next;
        sum += curr->value;
    }
    return sum;
}

void lastToFront(List l) {
    if (l->first != NULL && l->first->next != NULL) {
        Node curr = l->first;
        Node prev = NULL;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        curr->next = l->first;
        l->first = curr;
        prev->next = NULL;
    }
}

void firstToEnd(List l) {
    if (l->first != NULL && l->first->next != NULL) {
        Node curr = l->first;
        Node second = l->first->next;
        Node end = l->first;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = end;
        l->first = second;
        end->next = NULL;
    }
}

void deleteValue(List l, int toDelete) {
    Node curr = l->first;
    while (curr->next->value != toDelete) {
        curr = curr->next;
    }
    Node hold = curr->next->next;
    free(curr->next);
    curr->next = hold;
}

void deleteNth(List l, int nth) {
    Node curr = l->first;
    int count = 1; // start at node 1
    while (count < nth - 1) {
        curr = curr->next;
        count++;
    }
    Node hold = curr->next->next;
    free(curr->next);
    curr->next = hold;
}

void deleteList(List l) {
    Node curr = l->first;
    Node prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(l->first);
}

void insertNth(List l, int nth, int data) { // insert AFTER nth
    Node curr = l->first;
    int count = 1; // start at node 1
    while (count < nth) {
        curr = curr->next;
        count++;
    }
    Node new = malloc(sizeof(node));
    new->value = data;
    new->next = curr->next;
    curr->next = new;
}

void deleteFirst(List l) {
    Node hold = l->first->next;
    free(l->first);
    l->first = hold;
}

void deleteLast(List l) {
    Node curr = l->first;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void orderedDelete (List l) {
    Node curr = l->first;
    Node prev = NULL;
    if (l->first != NULL && l->first->next != NULL) {
        while (curr != NULL) {
            if (curr->value < prev->value) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void removeDuplicate (List l) {
    Node curr = l->first;
    Node prev = l->first;
    if (l->first != NULL && l->first->next != NULL) {
        while (curr != NULL) {
            if (curr->value == prev->value) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

int main(int argc, char *argv[]) {

    // create first node
    Node node1 = createNode(1);

    //create next nodes and append to end
    Node node2 = createNode(2);
    node1->next = node2;
    Node node3 = createNode(3);
    node2->next = node3;
    Node node4 = createNode(4);
    node3->next = node4;
    Node node5 = createNode(5);
    node4->next = node5;

    // create a list called "test"
    List test = createList();
    test->first = node1;

    //test->first = node1;
    printList(test);
    removeDuplicate(test);
    printList(test);

    return EXIT_SUCCESS;
}
