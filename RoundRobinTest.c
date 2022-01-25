#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    setPolicy(0);
    int Ws[10];
    int CBs[10];
    int PIDs[10];
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
                // if(j % 50 == 0)
                printf(1, "/PID/: /%d/\n", pid);
            }
            // for(int z = 0; z < 200000; z++);
            exit();
        }
    }

    for (int i = 0; i < 10; i++)
    {
        int pid = wait();
        Ws[i] = getInformation(0);
        CBs[i] = getInformation(1);
        mean_CBT += CBs[i];
        mean_WT += Ws[i];
        mean_TT += Ws[i] + CBs[i];
        PIDs[i] = pid;
    }
    for (int i = 0; i < 10; i++)
    {
        printf(1, "/PID/: /%d/, /WT/ :/%d/, /TT/ :/%d/, /CBT/: /%d/\n", PIDs[i], Ws[i], Ws[i] + CBs[i], CBs[i]);
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
    printf(1, "\n");
    exit();
}
