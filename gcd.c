#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

static void print_banner(const char *line)
{
    printf("*** >>> %s <<< ***\n", line);
}

static void print_header(void)
{
    printf("******************************\n");
    printf("***   GCD CALCULATOR       ***\n");
    printf("***   Euclidean algorithm  ***\n");
    printf("******************************\n");
    printf("\n");
}

static long read_number(const char *prompt)
{
    char buf[256];

    for (;;) {
        printf("%s", prompt);
        fflush(stdout);

        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("No input, exiting.\n");
            exit(1);
        }

        errno = 0;
        char *end = NULL;
        long n = strtol(buf, &end, 10);

        if (end == buf) {
            printf("Not a number, try again.\n");
            continue;
        }

        while (*end != '\0' && isspace((unsigned char)*end))
            end++;

        if (*end != '\0') {
            printf("Not a number, try again.\n");
            continue;
        }

        if (errno == ERANGE) {
            printf("Number out of range, try again.\n");
            continue;
        }

        return n;
    }
}

static long gcd_euclid(long a, long b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    print_header();

    long a = read_number(">>> First number:  ");
    long b = read_number(">>> Second number: ");

    long g = gcd_euclid(a, b);

    printf("\n");
    print_banner("RESULT");
    printf(">>> GCD(%ld, %ld) = %ld\n", a, b, g);
    print_banner("DONE");

    return 0;
}