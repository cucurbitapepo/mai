#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, ppid, pgrp;
    uid_t uid, euid;
    gid_t gid, egid;

    pid = getpid();
    ppid = getppid();
    pgrp = getpgrp();
    uid = getuid();
    gid = getgid();
    euid = geteuid();
    egid = getegid();

    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("PGID: %d\n", pgrp);
    printf("Real UID: %d\n", uid);
    printf("Real GID: %d\n", gid);
    printf("Effective UID: %d\n", euid);
    printf("Effective GID: %d\n", egid);

    return 0;
}