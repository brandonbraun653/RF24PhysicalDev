#ifdef DEBUG
#include "SysprogsProfiler.h"
#endif

#include <Chimera/chimera.hpp>
#include <Chimera/config.hpp>
#include <Chimera/threading.hpp>
#include <Chimera/utilities.hpp>

#include "clientThread.hpp"
#include "helloworld_tx.hpp"

using namespace Chimera::Threading;

TaskHandle_t helloTask;
TaskHandle_t senderTask;
TaskHandle_t ledTask;


int main(void)
{
    ChimeraInit();

    #ifdef DEBUG
    //InitializeSamplingProfiler();
    InitializeInstrumentingProfiler();
    #endif

    addThread(ledThread, "led", 200, NULL, 2, &ledTask);
    addThread(helloWorldTXThread, "sender", 1500, NULL, 2, &helloTask);
    startScheduler();

    /* Should never reach here as scheduler should be running */
    for(;;)
    {

    }
}


