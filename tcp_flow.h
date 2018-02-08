#ifndef TCP_FLOW_H
#define TCP_FLOW_H


#include <linux/kernel.h>
#include <linux/list.h>

struct tcp_flow {
    struct list_head list;
    u16 sport, dport;
    u32 saddr, daddr;
    struct list_head list_of_packets;
    int size;
    void *a_pointer;
};

struct packet {
    struct list_head list;
    u32 sequence_number;
};

int get_size(struct tcp_flow *flow);

void add_packet_to_flow(struct list_head *new, struct list_head *head);

#endif
