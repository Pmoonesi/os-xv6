#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    double mean_CBT= 0.0;
    double mean_WT = 0.0;
    double mean_TT = 0.0;

    for (int i = 0;i < 10;i++)
    {
        if (fork() == 0)
        {
            int pid = getpid();
            for (int j = 0; j < 1000; j++)
            {
                if(j % 500 == 0)
                    printf(1, "/PID/: /%d/\n", pid);
            }
            exit();
        }
    }

    for (int i = 0; i < 10; i++)
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
    mean_CBT = mean_CBT / 10.0;
    mean_WT = mean_WT / 10.0;
    mean_TT = mean_TT / 10.0;
    printf(1, "\n/Mean_CBT/: ");
    printfloat(1, mean_CBT);
    printf(1, "\n/Mean_WT/: ");
    printfloat(1, mean_WT);
    printf(1, "\n/Mean_TT/: ");
    printfloat(1, mean_TT);
    exit();
}
