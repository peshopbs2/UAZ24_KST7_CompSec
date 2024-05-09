#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#define MAXN 1024

void print_md5(unsigned char *md5)
{
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", md5[i]);
    }
    printf("\n");
}

int main()
{
    char input[MAXN];
    scanf("%s", input);
    
    unsigned char result[MD5_DIGEST_LENGTH];
    
    MD5( (unsigned char*) input, strlen(input), result);
    
    printf("%s = ", input);
    
    print_md5(result);

    return EXIT_SUCCESS;
}
