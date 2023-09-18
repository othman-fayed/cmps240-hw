#include "ass1.h"

/*
            WARNING  WARNING  WARNING  WARNING
            YOU ARE NOT ALLOWED TO USE ANY HEADER OR GLOBAL VARIABLE OTHER THAN THE
            ONE PROVIDED TO YOU.
            YOU ARE FREE TO ADD FUNCTIONS BUT YOUR MAIN OUTPUT FUNCTION SHOULD USE THE DECLARATION AND
            DEFINITION PROVIDED.
*/


//Ex1 ######################################################################################
char* UpsideDownTraingle(const int size){
     // Warning : make sure to allocate enough mem for your buffer to avoid buffer_overflow
    char* _buffer = NULL;
    //########## Your Code Starts Here ####### 
   
    if (size <= 0) {
        return NULL;
    }

    int indentCount = (size / 2) * (1 + size);
    int cols = size + 2;
    _buffer = (char*)malloc(size * cols * 2 + indentCount + 1); // we are allocating more than we need here! basically max cols
    int skipIndex = size;

    int i = 0;
    int index = 0;
    char space = '_';
    for (i = 0; i < size; i++) {
        int j;
        for(j = 0; j < i; j++) {
            _buffer[index++] = space;
        }
        for(j = 0; j < cols; j++) {
            if (j == skipIndex) {
                _buffer[index++] = space;
            } else {
                _buffer[index++] = '#';
                _buffer[index++] = space;
            } 
        }
        index--;
        _buffer[index++] = '\n';
        skipIndex--;
    }
    _buffer[index] = '\0';

    //########## Your Code Ends Here #########
    return _buffer;
}

//Ex2 ######################################################################################
DoubleLinkedList* createList(){

    DoubleLinkedList* _mylist;

    _mylist = malloc(sizeof(DoubleLinkedList*));
    _mylist -> head = malloc(sizeof(Node*));
    _mylist -> tail = malloc(sizeof(Node*));
    _mylist->head->next = _mylist->tail;
    _mylist->tail->previous = _mylist->head;

    _mylist->head->data = -11111;
    _mylist->tail->data = -11111;
    _mylist->size = 0;

    return _mylist;
}
void  AlterAt(DoubleLinkedList* list,const size_t index,const int value){
    
    //Warning: This function cannot create new nodes. 
    //         this function job is to only alter a current node value
   
     Node* itr=NULL;
    //######## Your Starts Here ########

   //######## END OF CODE ##########
}
void  InsertBeg(DoubleLinkedList* list,const int value){
    Node* new_node =NULL;
    //######## Start OF CODE ########

    //######## END OF CODE ##########
    ++list->size;
}
void  InsertEnd(DoubleLinkedList* list,const int value){
    Node* new_node =NULL;
    //######## Start OF CODE ########

    //######## END OF CODE ##########
    ++list->size;
}

void  RemoveNode(DoubleLinkedList* dlist,Node * target_node){
    // Warning: you are not allowed to use a temporary variable other than itr
     Node** itr= &dlist->head;
    //###### Your Code Starts Here ########


    //###### Your Code Ends Here ########
    --dlist->size;
}
void  PrintListForward(const Node* head){
    //######## Your Code Starts Here ######

    //######## Your Code Ends Here ########
}
void  PrintListBackward(const Node* Tail)
{
     //######## Your Code Starts Here ######

     //######## Your Code Ends Here ########
}


//EX3 ######################################################################################
char* FindRelativePath(const char* From,const char* To){

     char * path =NULL;
    //########### Your Code Starts Here ###############



    //########### Your Code Ends Here #################

    return path;
}

//EX4 ######################################################################################

void convolution(float filter[][FILTER_DIM], float* input, float* output, unsigned int width, unsigned int height) {
    //########## Your Code Starts Here ##############

    //########## Your Code Ends Here ################

}

//EX X BONUS ###############################################################################
size_t JAYJAY(size_t K){

    size_t answer=0;
    //########## Your Code Starts Here ##############


    //########## Your Code Ends Here ################

    return answer;
}
