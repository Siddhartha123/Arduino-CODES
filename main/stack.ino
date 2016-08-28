#pragma pack(1)
#define NULL 0
struct node
{
    int direction;
    struct node *ptr;
};
struct node *top=NULL,*top1,*temp; 
 struct node *front,*rear;




void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(sizeof(struct node));
        top->ptr = NULL;
        top->direction = data;
    }
    else
    {
        temp =(struct node *)malloc(sizeof(struct node));
        temp->ptr = top;
        temp->direction = data;
        top = temp;
    }
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        Serial.println("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        Serial.println( top1->direction);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        Serial.println("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
   // Serial.println("\n Popped value : "+ top->direction+"   "+top->is_alternate);
    free(top);
    top = top1;
}
 
/* Return top element */
int topelement()
{
    return(top->direction);
}
 
/* Check if stack is empty or not */
boolean empty()
{
    if (top == NULL)
        return true;
    else
         return false;
}

