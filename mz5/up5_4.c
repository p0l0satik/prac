#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

struct Task
{
    unsigned uid;
    int gid_count;
    unsigned * gids;
};

enum 
{
    GROUP_OFFSET = 3,
    USER_OFFSET = 6
};

static int check_rights(unsigned rights, unsigned access){
    return (access & rights) == access;
}

static int is_in_group(const unsigned gid, const struct Task *task) {
    for (int t = 0; t < task->gid_count; t++){
        if (task->gids[t] == gid){
            return 1;
        }
    }
    return 0;
}
int myaccess(const struct stat *stb, const struct Task *task, int access) {

    if (!task->uid) {
        return 1;
    }
    if (task->uid == stb->st_uid) {
        return check_rights((stb->st_mode & S_IRWXU) >> USER_OFFSET, access);
    }
    if (is_in_group(stb->st_gid, task)) {
        return check_rights((stb->st_mode & S_IRWXG) >> GROUP_OFFSET, access);
    }
    return check_rights(stb->st_mode & S_IRWXO, access);
}










