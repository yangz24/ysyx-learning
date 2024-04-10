#include <common.h>
#include <utils.h>
#include <device/map.h>

#ifdef CONFIG_DTRACE

void trace_device_read(paddr_t addr, int len, IOMap *map) {
    Log("dtrace: read %10s in " FMT_PADDR " len = %d.\n", map->name, addr, len);
};

void trace_device_write(paddr_t addr, int len, IOMap *map) {
    Log("dtrace: write %10s in " FMT_PADDR " len = %d.\n", map->name, addr, len);
};

#endif