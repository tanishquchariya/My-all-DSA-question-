// delete head
// Node *deleteHead2dLL(Node *head)
// {
//     if (head == NULL && head->next == NULL)
//     {
//         return NULL;
//     }

//     Node *prev = head;
//     head = head->next;
//     head->back = NULL;
//     prev->next = NULL;
//     delete prev;
//     return head;
// }
// // delete head of 2D LL
// Node *deleteTail2dLL(Node *head)
// {
//     if (head == NULL && head->next == NULL)
//     {
//         return NULL;
//     }
//     Node *tail = head;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }

//     Node *prev = tail->back;
//     prev->next = NULL;
//     tail->back = NULL;

//     delete tail;
//     return head;
// }