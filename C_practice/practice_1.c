#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *arr, int size)
{

    int index_1 = 0;
    int count = size;

    for (int i = 1; i < size; i++)
    {
        int repeatFlag = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                repeatFlag = 1;
                break;
            }
        }

        if (repeatFlag)
        {
            count = count - 1;

            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            i --;
            size--;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

int countUniqueCharacters(const char * str){
    int charcount[256] = {0};
    int uniquecount = 0;

    for(int i = 0; str[i] != '\0'; i++){
        printf("%c ", str[i]);
        charcount[str[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if(charcount[i] == 1){
            uniquecount++;
        }
    }
    
    return uniquecount;
}

int main()
{
    int staticArr[] = {1, 4, 3, 3, 5, 1, 2, 4};
    int *arr = staticArr;
    //removeDuplicates(arr, 8);
    char arrChar[] = {'a', 'b', 'b', 'c', 'b','q','c', '\0'};

    int result = countUniqueCharacters(arrChar);
    printf("result: %d", result);

}