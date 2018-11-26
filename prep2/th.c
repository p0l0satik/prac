int sigaction(int num, struct sigaction * act, struct sigaction *old)
struct sigaction{
    void (*sa_handler)(int);
    int sa_flags;
}
sigaction(SIGUSR1, &(struct sigaction){.sa_handler = handler, .sa_flags = SA_RESTART}, NULL);
int sigemptyset(sigset_t *pset);
sigset_t s1, s2;
sigemptyset(& s1);
int sigaddset(sigset_t * pset, int num);
sigaddset(&s1, SIGUSR1);
int sigprocmask(int mode, sigset_t *pset, sigset_t *old);
sigprocmask(SIG_BLOCK, &s1, &s2); //заблокировать сигнла/ разблокировать  sig_setmask копируется, 
//в s2 сохраниться старое


while(1)sigsuspend(&s1);


