#include "ass1.h"

/*
            WARNING  WARNING  WARNING  WARNING
            YOU ARE NOT ALLOWED TO USE ANY HEADER OR GLOBAL VARIABLE OTHER THAN THE
            ONE PROVIDED TO YOU.
            YOU ARE FREE TO ADD FUNCTIONS BUT YOUR MAIN OUTPUT FUNCTION SHOULD USE THE DECLARATION AND
            DEFINITION PROVIDED.
*/

// Ex1 ######################################################################################
char *UpsideDownTraingle(const int size)
{
    // Warning : make sure to allocate enough mem for your buffer to avoid buffer_overflow
    char *_buffer = NULL;
    // ########## Your Code Starts Here #######

    if (size <= 0)
    {
        return NULL;
    }

    int indentCount = (size / 2) * (1 + size);
    int cols = size + 2;
    _buffer = (char *)malloc(size * cols * 2 + indentCount + 1); // we are allocating more than we need here! basically max cols
    int skipIndex = size;

    int i = 0;
    int index = 0;
    char space = ' ';
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            _buffer[index++] = space;
        }
        for (j = 0; j < cols; j++)
        {
            if (j == skipIndex)
            {
                _buffer[index++] = space;
            }
            else
            {
                _buffer[index++] = '#';
                _buffer[index++] = space;
            }
        }
        index--;
        _buffer[index++] = '\n';
        skipIndex--;
    }

    _buffer[index] = '\0';
    // ########## Your Code Ends Here #########
    return _buffer;
}

// Ex2 ######################################################################################
DoubleLinkedList *createList()
{

    DoubleLinkedList *_mylist;

    _mylist = malloc(sizeof(DoubleLinkedList *));
    _mylist->head = malloc(sizeof(Node *));
    _mylist->tail = malloc(sizeof(Node *));
    _mylist->head->next = _mylist->tail;
    _mylist->head->previous = NULL;
    _mylist->tail->next = NULL;
    _mylist->tail->previous = _mylist->head;

    _mylist->head->data = -11111;
    _mylist->tail->data = -11111;
    _mylist->size = 0;

    return _mylist;
}
void AlterAt(DoubleLinkedList *list, const size_t index, const int value)
{

    // Warning: This function cannot create new nodes.
    //          this function job is to only alter a current node value

    Node *itr = NULL;
    // ######## Your Starts Here ########
    if (list == NULL || index >= list->size)
    {
        return;
    }
    itr = list->head->next;
    size_t i;
    for (i = 0; i < list->size && i < index; i++)
    {
        itr = itr->next;
    }

    if (i == index)
    {
        itr->data = value;
    }
    // ######## END OF CODE ##########
}
void InsertBeg(DoubleLinkedList *list, const int value)
{
    Node *new_node = NULL;
    // ######## Start OF CODE ########

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }

    new_node->data = value;
    new_node->previous = list->head;
    new_node->next = list->head->next;
    list->head->next = new_node;

    if (list->tail->previous == list->head)
    {
        list->tail->previous = new_node;
    }

    // ######## END OF CODE ##########
    ++list->size;
}
void InsertEnd(DoubleLinkedList *list, const int value)
{
    Node *new_node = NULL;
    // ######## Start OF CODE ########

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }

    new_node->data = value;
    new_node->next = list->tail;
    new_node->previous = list->tail->previous;
    list->tail->previous = new_node;

    if (list->head->next == list->tail)
    {
        list->head->next = new_node;
    }

    // ######## END OF CODE ##########
    ++list->size;
}

void RemoveNode(DoubleLinkedList *dlist, Node *target_node)
{
    // Warning: you are not allowed to use a temporary variable other than itr
    Node **itr = &dlist->head;
    // ###### Your Code Starts Here ########
    if (target_node == dlist->head || target_node == dlist->tail)
    {
        return;
    }

    while (*itr != NULL && *itr != target_node)
    {
        itr = &(*itr)->next;
    }

    if (*itr != target_node)
    {
        return;
    }
    target_node->previous->next = target_node->next;
    target_node->next->previous = target_node->previous;
    free(target_node);

    // ###### Your Code Ends Here ########
    --dlist->size;
}
void PrintListForward(const Node *head)
{
    // ######## Your Code Starts Here ######
    const Node *itr = head;
    while (itr->next != NULL && itr->next->next != NULL)
    {
        itr = itr->next;
        printf("%d ", itr->data);
    }
    printf("\n");
    // ######## Your Code Ends Here ########
}
void PrintListBackward(const Node *Tail)
{
    // ######## Your Code Starts Here ######
    const Node *itr = Tail;
    while (itr->previous != NULL && itr->previous->previous != NULL)
    {
        itr = itr->previous;
        printf("%d ", itr->data);
    }
    printf("\n");
    // ######## Your Code Ends Here ########
}

// EX3 ######################################################################################
char *FindRelativePath(const char *From, const char *To)
{

    char *path = NULL;
    // ########### Your Code Starts Here ###############
    if (From == NULL || To == NULL || From[0] != '/' || To[0] != '/' || strlen(From) > 512 || strlen(To) > 512) {
        return "Error_Path_Unavailable";
    }

    size_t i = 0;
    while (From[i] != '\0' && To[i] != '\0' && From[i] == To[i]) {
        i++;
    }
    if (i == 0) {
        // no common start
        return "Error_Path_Unavailable";
    }

    // counting the folder difference '../'
    int num_up = 0;
    size_t j = i;
    while (From[j] != '\0') {
        if (From[j] == '/') {
            num_up++;
        }
        j++;
    }

    size_t result_len = (num_up * 3) + strlen(To) - i + 1;
    if (result_len > 512) {
        return "Error_Path_Unavailable";
    }

    path = (char*)malloc(result_len);
    
    strcpy(path, "");
    // add the '../'
    for (int k = 0; k < num_up; k++) {
        strcat(path, "../");
    }
    strcat(path, To + i);

    // ########### Your Code Ends Here #################

    return path;
}

// EX4 ######################################################################################
// #define FILTER_DIM 5
// float filter_c_[FILTER_DIM][FILTER_DIM];
// void convolution(float filter[][FILTER_DIM], float *input, float *output, unsigned int width, unsigned int height)
// {
//     // ########## Your Code Starts Here ##############
//     return;
//     // ########## Your Code Ends Here ################
// }

// // EX X BONUS ###############################################################################
// size_t JAYJAY(size_t K)
// {

//     size_t answer = 0;
//     // ########## Your Code Starts Here ##############
//     K = K + 1;
//     // ########## Your Code Ends Here ################

//     return answer;
// }