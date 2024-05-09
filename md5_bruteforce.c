#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#define MAXN 1024

int main()
{
    char input[MAXN];
    char hexDigits[16] = "0123456789abcdef";
    scanf("%s", input);
    
    for(char l1 = 'a'; l1 <= 'z'; l1++)
    {
        for(char l2 = 'a'; l2 <= 'z'; l2++)
        {
            for(char l3 = 'a'; l3 <= 'z'; l3++)
            {
                char data[] = {l1, l2, l3, '\0'};
                unsigned char result[MD5_DIGEST_LENGTH];
                
                MD5( (unsigned char*) data, strlen(data), result);
                
                char hash[MD5_DIGEST_LENGTH * 2 + 1];
                for(int i = 0; i < MD5_DIGEST_LENGTH; i++ )
                {
                    hash[i*2]   = hexDigits[(result[i] >> 4) & 0xF];
                    hash[i*2+1] = hexDigits[result[i] & 0xF];
                }
                hash[MD5_DIGEST_LENGTH*2] = '\0';

                printf("%s\n", hash);
                
                if(strcmp(input, hash) == 0)
                {
                    printf("%s", data);
                    return EXIT_SUCCESS;
                }
            }
        }
    }
    
    return EXIT_SUCCESS;
}
