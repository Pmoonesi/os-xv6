#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    double mean_CBT= 0.0;
    double mean_WT = 0.0;
    double mean_TT = 0.0;
    int pid = getpid();
    setPriority(1);
    for (int i = 34; i > 4; i--)
    {
        if (pid)
        {
            if(!(pid = fork()))
            {
                setPriority(7-i/5);
                sleep(100);
            }
        }
    }

    if(!pid){
        int childNumber = getpid();
        int priority = getPriority();
        printf(1, "in child #%d with p%d\n", childNumber, priority);
        for(int i = 0; i < 250; i++)
            printf(1, "/%d/ : /%d/\n", priority, i);
            ;
        exit();
    }else{
        for (int i = 0; i < 30; i++)
        {
            int pid = wait();
            int info[2];
            info[0] = getInformation(0);
            info[1] = getInformation(1);
            printf(1, "/PID/: /%d/, /WT/ :/%d/, /TT/ :/%d/, /CBT/: /%d/\n", pid, info[0], info[0] + info[1], info[1]);
            mean_CBT += info[1];
            mean_WT += info[0];
            mean_TT += info[0] + info[1];
        }
        mean_CBT = mean_CBT / 30.0;
        mean_WT = mean_WT / 30.0;
        mean_TT = mean_TT / 30.0;
        printf(1, "\n/Mean_CBT/: ");
        printfloat(1, mean_CBT);
        printf(1, "\n/Mean_WT/: ");
        printfloat(1, mean_WT);
        printf(1, "\n/Mean_TT/: ");
        printfloat(1, mean_TT);
        printf(1, "\n");
        exit();
    }
}
