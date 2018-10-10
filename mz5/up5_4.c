#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

struct Task
{
    unsigned uid;
    int gid_count;
    unsigned gids[10];
};

enum 
{
    GROUP_OFFSET = 3,
    USER_OFFSET = 6
};

static int check_rights(unsigned access, unsigned rights){
    for(int t = 0; t < 3; t++){
        if ((access & 1) == 1 && (rights & 1) == 0){
            return 0;
        }
        access >>= 1;
        rights >>= 1;
    }
    return 1;
}
int myaccess(const struct stat *stb, const struct Task *task, int access){
    if (task->uid == stb->st_uid && 
        check_rights(access, (stb->st_mode & S_IRWXU) >> USER_OFFSET)){
        return 1;
    
    }
    for (int t = 0; t < task->gid_count; t++) {
        if (task->gids[t] == stb->st_gid && 
            check_rights(access, (stb->st_mode & S_IRWXG) >> GROUP_OFFSET)) {
            return 1;
        }
    }
    if (check_rights(access, (stb->st_mode & S_IRWXO))) {
        return 1;
    }
    return 0;  
}

int main (void){
    struct Task task;
    struct stat fl;
    task.uid = 501;
    task.gid_count = 1;
    task.gids[0] = 20;

    char s[] = "test.txt";
    if (lstat(s, &fl) < 0) {
        printf("%d\n", -1);
    }
    printf("%d\n", myaccess(&fl, &task, 2));
    return 0;
}