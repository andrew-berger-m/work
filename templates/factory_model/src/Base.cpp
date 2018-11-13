#include <string>
#include <pthread.h>

#include "Base.h"

Base::Base() {
}

Base::~Base() {
}

std::string Base::ping() {
    return "Base class was pinged.";
}

// returns true, if object is on heap
bool Base::deleteRequired() {
//  this is check whether we are on heap or stack
//  pthread_t self = pthread_self();
//  pthread_attr_t attr;
//  void *stack;
//  size_t stacksize;
//  pthread_getattr_np(self, &attr);
//  pthread_attr_getstack(&attr, &stack, &stacksize);
//  return ((uintptr_t) this >= (uintptr_t) stack && (uintptr_t) this < (uintptr_t) stack + stacksize);
  return false;
}
