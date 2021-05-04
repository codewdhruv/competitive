class Solution
{
    public:
    int count(struct node* head, int search_for)
{
    int res = 0;
    
    while(head)
    {
        if(head->data == search_for)
        {
            res++;
        }
        
        head = head->next;
    }
    
    return res;
}
};
