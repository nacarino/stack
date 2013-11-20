/*
 * RINA Queues
 *
 *    Francesco Salvestrini <f.salvestrini@nextworks.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef RINA_RQUEUE_H
#define RINA_RQUEUE_H

struct rqueue;

struct rqueue * rqueue_create(void);
struct rqueue * rqueue_create_ni(void);

/* NOTE: dtor has the ownership of freeing the passed element */
int             rqueue_destroy(struct rqueue * q,
                               void         (* dtor)(void * e));

/*
 * NOTE: We allow pushing NULL entries in the fifo but the dtor passed to
 *       rfifo_destroy() has to handle them opportunely
 */
int             rqueue_tail_push(struct rqueue * q, void * e);
int             rqueue_tail_push_ni(struct rqueue * q, void * e);
void *          rqueue_tail_pop(struct rqueue * q);

int             rqueue_head_push(struct rqueue * q, void * e);
int             rqueue_head_push_ni(struct rqueue * q, void * e);
void *          rqueue_head_pop(struct rqueue * q);

bool            rqueue_is_empty(struct rqueue * q);

#endif