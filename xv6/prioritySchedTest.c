#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    setPolicy(1);
    int Ws[30];
    int CBs[30];
    int PIDs[30];
    double mean_CBT= 0.0;
    double mean_WT = 0.0;
    double mean_TT = 0.0;
    int pid = getpid();
    setPriority(1);
    int j = 0;
    for (int i = 34; i > 4; i--)
    {
        if (pid)
        {
            if(!(pid = fork()))
            {
                setPriority(7-i/5);
                sleep(100);
                j = i - 4;
            }
        }
    }

    if(!pid){
        // int childNumber = getpid();
        // int priority = getPriority();
        for(int i = 0; i < 250; i++)
            printf(1, "/%d/ : /%d/\n", j, i);
        exit();
    }else{
        for (int i = 0; i < 30; i++)
        {
            int pid = wait();
            Ws[i] = getInformation(0);
            CBs[i] = getInformation(1);
            mean_CBT += CBs[i];
            mean_WT += Ws[i];
            mean_TT += Ws[i] + CBs[i];
            PIDs[i] = pid;
        }
        for (int i = 0; i < 30; i++)
        {
            printf(1, "/PID/: /%d/, /WT/ :/%d/, /TT/ :/%d/, /CBT/: /%d/\n", PIDs[i], Ws[i], Ws[i] + CBs[i], CBs[i]);
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
