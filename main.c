#include <stdint.h>
#include <unistd.h>

#define RTE_LITTLE_ENDIAN 0
#define RTE_BYTE_ORDER RTE_LITTLE_ENDIAN

struct rte_gre_hdr {
#if RTE_BYTE_ORDER == RTE_LITTLE_ENDIAN
	uint16_t res2:4; 
	uint16_t s:1;    
	uint16_t k:1;    
	uint16_t res1:1; 
	uint16_t c:1;    
	uint16_t ver:3;  
	uint16_t res3:5; 
#elif RTE_BYTE_ORDER == RTE_BIG_ENDIAN
	uint16_t c:1;    
	uint16_t res1:1; 
	uint16_t k:1;    
	uint16_t s:1;    
	uint16_t res2:4; 
	uint16_t res3:5; 
	uint16_t ver:3;  
#endif
};

void main(void) {
	struct rte_gre_hdr h = {
		.c = 1,
		.k = 1,
		.ver = 7,
	};

	write(1, &h, 2);
}
