#pragma once
#include <stddef.h>

//@rc::inlined Definition talloc_initialized := initialized "allocator_state" ().

[[rc::parameters("size : nat")]]
[[rc::args("size @ int<size_t>")]]
[[rc::requires("{size + 16 ≤ max_int size_t}", "{(8 | size)}",
               "[talloc_initialized]")]]
[[rc::returns("&own<uninit<{Layout size 3}>>")]]
void *talloc(size_t size);
[[rc::parameters("size : nat")]]
[[rc::requires("[talloc_initialized]", "{(8 | size)}")]]
[[rc::args("size @ int<size_t>", "&own<uninit<{Layout size 3}>>")]]
void tfree(size_t size, void *ptr);

[[rc::parameters("size : nat", "n : nat")]]
[[rc::args("size @ int<size_t>", "n @ int<size_t>")]]
[[rc::requires("{size * n + 16 ≤ max_int size_t}", "{(8 | size)}", "[talloc_initialized]")]]
[[rc::returns("&own<array<{Layout size 3}, {replicate n (uninit (Layout size 3))}>>")]]
void *talloc_array(size_t size, size_t n);

[[rc::parameters("size : nat", "n : nat")]]
[[rc::requires("[talloc_initialized]")]]
[[rc::requires("{size * n ≤ max_int size_t}", "{(8 | size)}")]]
[[rc::args("size @ int<size_t>", "n @ int<size_t>", "&own<array<{Layout size 3}, {replicate n (uninit (Layout size 3))}>>")]]
void tfree_array(size_t size, size_t n, void *ptr);
