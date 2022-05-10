
#include <unistd.h>
#include <sys/types.h>

int main() {
    char *sh = "/bin/sh";
    char *data[2];
    data[0] = sh;
    data[1] = NULL;
    
    setuid(0);
    execve(data[0], data, NULL);
    
    return 0;
}
