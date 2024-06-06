  int n;
    int data;
    printf("please enter the number of nodes to create:");
    scanf("%d", &n);
    struct node *ptr[n];
    //-------------------------data entering into nodes--------------
    for (int i = 0; i < n; i++)
    {
        printf("please enter the data of the node '%d':", i);
        scanf("%d", &data);
        ptr[i] = createnode(data);
    }
    //---------------------linking the nodes------------------------
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            ptr[i]->next = NULL;
        }
        else
        {
            ptr[i]->next = ptr[i + 1];
        }
    }
    printf("please enter the index to insert the node at:");
    int index;
    scanf("%d", &index);
    printf("please enter the data to be inserted in the node:");
    int newdata;
    scanf("%d", &newdata);
    struct node *newhead;
    newhead = insertionatindex(ptr[0], index, newdata);