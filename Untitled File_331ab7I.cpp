#include <stdio.h>
int main()
{
    int i=1;
    {
        {
       auto i=2;
        printf("%d",i);
        }
        {
            auto i=3;
            printf("%d",i);
        }
        printf("%d",i);
    }
    return 0;
}
