#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#define MAXN 1024

void print_sha256(unsigned char *sha)
{
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", sha[i]);
    }
    printf("\n");
}

int main()
{
    char input[MAXN];
    scanf("%s", input);
    
    unsigned char result[SHA256_DIGEST_LENGTH];
    
    SHA256( (unsigned char*) input, strlen(input), result);
    
    printf("%s = ", input);
    
    print_sha256(result);

    return 0;
}
