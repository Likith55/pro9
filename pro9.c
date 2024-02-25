#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
             int coef;
             int xexp, yexp, zexp;
             struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
            NODE x;
            x = (NODE) malloc(sizeof(struct node));
            if(x == NULL)
            {
                        printf("Running out of memory \n");
                        return NULL;
            }
            return x;
}

NODE attach(int coef, int xexp, int yexp, int zexp, NODE head)
{
            NODE temp, cur;
            temp = getnode();
            temp->coef = coef;
            temp->xexp = xexp;
            temp->yexp = yexp;
            temp->zexp = zexp;
            cur = head->link;
            while(cur->link != head)
            {
                        cur = cur->link;
            }
            cur->link = temp;
            temp->link = head;
            return head;
}

NODE read_poly(NODE head)
{
            int i, j, coef, xexp, yexp, zexp, n;
            printf("\nEnter the no of terms in the polynomial: ");
            scanf("%d", &n);
            for(i=1; i<=n; i++)
            {
                        printf("\n\tEnter the %d term: ",i);
                        printf("\n\t\tCoef =  ");
                        scanf("%d", &coef);
                        printf("\n\t\tEnter Pow(x) Pow(y) and Pow(z): ");
                        scanf("%d", &xexp);
                        scanf("%d", &yexp);
                        scanf("%d", &zexp);
                        head = attach(coef, xexp, yexp, zexp, head);
            }
              return head;
}

void display(NODE head)
{
            NODE temp;
            if(head->link == head)
            {
                         printf("\nPolynomial does not exist.");
                         return;
            }
            temp = head->link;

            while(temp != head)
            {
                         printf("%dx^%dy^%dz^%d", temp->coef, temp->xexp, temp->yexp, temp->zexp);
                         temp = temp->link;
                         if(temp != head)
                                    printf(" + ");
            }
}

int poly_evaluate(NODE head)
{
            int x, y, z, sum = 0;
            NODE poly;

            printf("\nEnter the value of x,y and z: ");
            scanf("%d %d %d", &x, &y, &z);

            poly = head->link;
            while(poly != head)
            {
                        sum += poly->coef * pow(x,poly->xexp)* pow(y,poly->yexp) * pow(z,poly->zexp);
                        poly = poly->link;
            }
            return sum;
}
void main()
{
  NODE head;
  int res, ch;
  head =  getnode();     /* For polynomial evalaution */
  head->link=head;
 

  while(1)
  {
        printf("\n~~Menu~~");
        printf("\n1.Represent and Evaluate a Polynomial P(x,y,z)");
        printf("\n2.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:             printf("\n~~~Polynomial evaluation P(x,y,z)~~\n");
                                    head = read_poly(head);
                                    printf("\nRepresentation of Polynomial for evaluation: \n");
                                    display(head);
                                    res = poly_evaluate(head);
                                    printf("\nResult of polynomial evaluation is : %d \n", res);
                                    break;
                                                                        

            
            case 2:         exit(1);
        }
    }
}


/*
output:

~~Menu~~
1.Represent and Evaluate a Polynomial P(x,y,z)
2.exit
Enter your choice:1

~~~Polynomial evaluation P(x,y,z)~~

Enter the no of terms in the polynomial: 2

        Enter the 1 term: 
                Coef =  1

                Enter Pow(x) Pow(y) and Pow(z): 1 1 1

        Enter the 2 term: 
                Coef =  2

                Enter Pow(x) Pow(y) and Pow(z): 2 3 1

Representation of Polynomial for evaluation: 
1x^1y^1z^1 + 2x^2y^3z^1
Enter the value of x,y and z: 2 1 3 

Result of polynomial evaluation is : 30 

~~Menu~~
1.Represent and Evaluate a Polynomial P(x,y,z)
2.exit
Enter your choice:2


...Program finished with exit code 1
Press ENTER to exit console.*/
