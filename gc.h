/*
 *	Copyright (c) 2008 , 
 *		Cloud Wu . All rights reserved.
 *
 *		http://www.codingnow.com
 *
 *	Use, modification and distribution are subject to the "New BSD License"
 *	as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 */

#ifndef MANUAL_GARBAGE_COLLECTOR_H
#define MANUAL_GARBAGE_COLLECTOR_H

#ifdef _WIN32
#   ifdef DLLEXPORT
#       define GCEXPORT __declspec(dllexport)
#   elif defined(DLLIMPORT)
#       define GCEXPORT __declspec(dllimport)
#   else
#       define GCEXPORT
#   endif
#else
#   define GCEXPORT extern
#endif


#include <stddef.h>

struct gc_weak_table;

GCEXPORT void gc_init();
GCEXPORT void gc_exit();

GCEXPORT void gc_enter();
GCEXPORT void gc_leave(void *p,...);

GCEXPORT void* gc_malloc(size_t sz,void *parent,void (*finalizer)(void *));
GCEXPORT void* gc_realloc(void *p,size_t sz,void *parent);
GCEXPORT void gc_link(void *parent,void *prev,void *now);
GCEXPORT void gc_collect();

GCEXPORT void* gc_clone(void *from,size_t sz);

GCEXPORT void gc_dryrun();

GCEXPORT struct gc_weak_table* gc_weak_table(void *parent);
GCEXPORT void* gc_weak_next(struct gc_weak_table *cont,int *iter);

#endif
