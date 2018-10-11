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

static int check_rights(unsigned rights, unsigned access){
    for(int t = 0; t < 3; t++){
        if ((access & 1) == 1 && (rights & 1) == 0){
            return 0;
        }
        access >>= 1;
        rights >>= 1;
    }
    return 1;
}

static int is_in_group(const unsigned gid, const struct Task *task) {
    for (int t = 0; t < task->gid_count; t++){
        if (task->gids[t] == gid){
            return 1;
        }
    }
    return 0;
}
int myaccess(const struct stat *stb, const struct Task *task, int access){
    int users_rights = 0;
    if (task->uid == stb->st_uid){
        users_rights |= (stb->st_mode & S_IRWXU) >> USER_OFFSET;
    }
    if (is_in_group(stb->st_gid, task)){
        users_rights |= (stb->st_mode & S_IRWXG) >> GROUP_OFFSET;
    }

    users_rights |= stb->st_mode & S_IRWXO;
    return check_rights(users_rights, access);
}









