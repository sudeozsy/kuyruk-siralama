#include <stdio.h>
#include <stdlib.h>
//eklerken siralama

struct que
{
    int data;
    struct que* next;
};
struct que* start=NULL;
struct que* temp=NULL;
int node = 0;
void enqueue()
{
    int data;
    printf("Deger girin->");
    scanf("%d",&data);

    struct que* newd = (struct que*)malloc(sizeof(struct que));
    newd->data = data;

    if(start == NULL)
    {
        newd->next = newd;
        start = newd;
        node++;
    }
    else
    {
        temp = start;
        if(temp->next == start) //2. eleman
        {
            temp->next = newd;
            newd->next = start;
            if(temp->data < newd->data)
            {
                start = temp->next;
            }
            node++;
        }
        else
        {
            if(temp->data < newd->data) // ilk elemandan büyükse
            {
                while(temp->next != start)
                {
                    temp = temp->next;
                }
                temp->next = newd;
                newd->next = start;
                start = newd;
            }
            else
            {
                while(temp->next != start && newd->data < temp->next->data)
                {
                    temp = temp->next;
                }
                if(temp->next == start)
                {
                    temp->next = newd;
                    newd->next = start;
                }
                else
                {
                    newd->next = temp->next;
                    temp->next = newd;
                }
            }
            node++;
        }
    }
    main();
}
void dequeue()
{
    if(start == NULL)
    {
        printf("Kuyruk yapisi bos.\n");
    }
    else if(start->next == start)
    {
        temp =start;
        free(temp);
        start= NULL;
        node--;
    }
    else
    {
        temp = start;
        while(temp->next != start)
        {
            temp= temp->next;
        }
        temp->next = start->next;
        free(start);
        start = temp->next;
        node--;
    }
    main();
}
void show()
{
    if(start == NULL)
    {
        printf("Kuyruk yapisi bos.");
    }
    else
    {
        temp = start;
        while(temp->next != start)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
    main();
}
void MedyanBul()
{
    if(start == NULL)
    {
        printf("Kuyruk yapisi bos.");
    }
    else if(start->next == start)
    {
        printf("Listedeki elemanlarin medyani %d",start->data);
    }
    else
    {
        temp = start;
        if(node%2 != 0)
        {
            for(int i=0 ; i<(node+1)/2 ;i ++)
            {
                temp = temp->next;
            }
            printf("Listedeki elemanlarin medyani %d",temp->data);
        }
        else
        {
            for(int i=0 ; i<node/2-1 ; i++)
            {
                temp = temp->next;
            }
            printf("Listedeki elemanlarin medyani %d",(temp->data+temp->next->data)/2);
        }
    }
    main();
}
int main()
{
    int choose;
    printf("\nEkleme(1)\nSilme(2)\nListeleme(3)\nMedyan Bul(4)\nCikis(0)\n\tSecin:");
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        show();
        break;
    case 4:
        MedyanBul();
        break;
    case 0:
        return 0;
    }
    return 0;
}
