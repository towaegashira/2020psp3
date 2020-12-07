#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

int length(const char *s)
{
    int n = 0;
    
    while(*s++ != '\0')
    {
        n++;
    }
    return (n);
}



char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start,pos;

    int text_len = length(text);
    int key_len = length(key);


    for(start=0;text_len-key_len>=start;start++)
    {
        for(pos=0;pos <= length(key)-1;pos++)
        {
            if(text[start+pos] == key[pos])
            {
                if(pos == length(key)-1)
                {
                    return &text[start];
                }
            }
            else
            {
                break;
            }
            
        }
    }
        return NULL;
}


char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int text_len = length(text);
    int key_len = length(key);
    int index;
    int key_index=key_len-1;
    int i;
    int table[256];
    int new_index;

    for(i=0;i <= ALPHABET_LEN ;i++)
    {
        table[key[i]]= key_len;
    }

    for(i=0;i<=key_len;i++)
    {
        table[key[i]] = key_len-i-1;
    }

    for(index=0;index <= text_len -1;)
    {
        for(key_index=key_len-1;key_index>=0;key_index--)
        {
            if(text[index+key_index] == key[key_index])
            {
                if(key_index == 0)
                {
                    return &text[index];
                }
            }
            else
            {
                break;
            }    
        }

        new_index=index + key_index+ table[text[index + key_index]]-key_len+1;
        if(new_index<=index)
        {
            index = index+1;

        } else {
            index = new_index;
        }
    }
     return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}