#include <ultra64.h>
#include "hardware.h"

OSTask D_803638B0;
#define _osVirtualToPhysical(ptr)       \
    if (ptr != NULL)                    \
    {                                   \
        ptr = osVirtualToPhysical(ptr); \
    }

OSTask *_VirtualToPhysicalTask(OSTask *task)
{
    OSTask *physicalTask;
    physicalTask = &D_803638B0;
    bcopy(task, physicalTask, sizeof(OSTask));
    _osVirtualToPhysical(physicalTask->t.ucode);
    _osVirtualToPhysical(physicalTask->t.ucode_data);
    _osVirtualToPhysical(physicalTask->t.dram_stack);
    _osVirtualToPhysical(physicalTask->t.output_buff);
    _osVirtualToPhysical(physicalTask->t.output_buff_size);
    _osVirtualToPhysical(physicalTask->t.data_ptr);
    _osVirtualToPhysical(physicalTask->t.yield_data_ptr);
    return physicalTask;
}
extern void __osPiGetAccess();
void osSpTaskLoad(OSTask *task)
{
    OSTask *physicalTask;
    physicalTask = _VirtualToPhysicalTask(task);
    if (physicalTask->t.flags & M_TASK_FLAG0)
    {
        physicalTask->t.ucode_data = physicalTask->t.yield_data_ptr;
        physicalTask->t.ucode_data_size = physicalTask->t.yield_data_size;
        task->t.flags &= ~M_TASK_FLAG0;
    }
    osWritebackDCache(physicalTask, sizeof(OSTask));
    __osSpSetStatus(SPSTATUS_CLEAR_SIGNAL0 |
                    SPSTATUS_CLEAR_SIGNAL1 |
                    SPSTATUS_CLEAR_SIGNAL2 |
                    SPSTATUS_SET_INTR_ON_BREAK);
    while (__osSpSetPc(SP_IMEM_START) == -1)
        ;
    while (__osSpRawStartDma(1, SP_IMEM_START - sizeof(OSTask), physicalTask, sizeof(OSTask)) == -1)
        ;
    while (__osSpDeviceBusy())
        ;
    while (__osSpRawStartDma(1, SP_IMEM_START, physicalTask->t.ucode_boot, physicalTask->t.ucode_boot_size) == -1)
        ;
}
s32 osSpTaskStartGo(OSTask *task)
{
    while (__osSpDeviceBusy())
        ;
    return __osSpSetStatus(SPSTATUS_SET_INTR_ON_BREAK |
                           SPSTATUS_CLEAR_SSTEP |
                           SPSTATUS_CLEAR_BROKE |
                           SPSTATUS_CLEAR_HALT);
}
