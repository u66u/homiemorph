#pragma once
#include <spinlock.h>
#include "talloc.h"

typedef struct [[rc::refined_by("sizes : {list nat}")]]
               [[rc::typedef("alloc_entry_t : {maybe2 cons sizes} @ optionalO<λ (size, l) : {(nat * _)}. &own<...>>")]]
               [[rc::size("{Layout size 3}")]]
               [[rc::constraints("{(8 | size)}")]] alloc_entry {
    [[rc::field("size @ int<size_t>")]]
    size_t size;

    [[rc::field("l @ alloc_entry_t")]]
    struct alloc_entry *next;
}* alloc_entry_t;

struct [[rc::typedef("alloc_state : ...")]]
       [[rc::exists("lid: lock_id")]] alloc_state {
    [[rc::field("spinlock<lid>")]]
    struct spinlock lock;

    [[rc::field("tylocked<lid, {\"data\"}, alloc_entry_t>")]]
    alloc_entry_t data;
};

[[rc::requires("[global_with_type \"allocator_state\" Own (uninit struct_alloc_state)]")]]
[[rc::ensures("[talloc_initialized]")]]
void init_talloc();
