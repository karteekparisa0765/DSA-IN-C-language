int n)
{
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
    g->visited = (int *)malloc(n * sizeof(int));
    g->first = (struct node **)malloc(n * sizeof(struct node *));
    g->vertex = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        g->vertex[i] = (char *)mall